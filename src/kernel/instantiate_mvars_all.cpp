/*
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Authors: Joachim Breitner
*/
#include <vector>
#include <unordered_map>
#include "util/name_set.h"
#include "util/name_hash_map.h"
#include "runtime/option_ref.h"
#include "runtime/array_ref.h"
#include "kernel/instantiate.h"
#include "kernel/expr.h"

/*
Fused single-pass instantiateMVars with improved sharing.

One class, two modes:
- Outer mode (m_scope == 0, fvar_subst empty): resolves direct mvar assignments
  with write-back. When encountering a resolvable delayed mvar application,
  fires delayed resolution inline (switching to delayed mode).
- Delayed mode (m_scope > 0, fvar_subst active): carries fvar substitution,
  resolves nested delayed mvars. No direct mvar resolution needed (outer mode
  already normalized all direct chains via write-back).

The shared m_cache allows nodes not behind delayed mvars to be traversed exactly
once. In delayed mode, cache reads use the `use_global` condition (!has_fvar &&
!has_expr_mvar) to safely read scope-independent results from m_cache. Cache
writes go to m_cache when m_result_scope == 0, otherwise to the scoped cache.
*/

namespace lean {
extern "C" object * lean_get_lmvar_assignment(obj_arg mctx, obj_arg mid);
extern "C" object * lean_assign_lmvar(obj_arg mctx, obj_arg mid, obj_arg val);
extern "C" object * lean_get_mvar_assignment(obj_arg mctx, obj_arg mid);
extern "C" object * lean_get_delayed_mvar_assignment(obj_arg mctx, obj_arg mid);
extern "C" object * lean_assign_mvar(obj_arg mctx, obj_arg mid, obj_arg val);
typedef object_ref metavar_ctx;
typedef object_ref delayed_assignment;

static void assign_lmvar(metavar_ctx & mctx, name const & mid, level const & l) {
    object * r = lean_assign_lmvar(mctx.steal(), mid.to_obj_arg(), l.to_obj_arg());
    mctx.set_box(r);
}

static option_ref<level> get_lmvar_assignment(metavar_ctx & mctx, name const & mid) {
    return option_ref<level>(lean_get_lmvar_assignment(mctx.to_obj_arg(), mid.to_obj_arg()));
}

static void assign_mvar(metavar_ctx & mctx, name const & mid, expr const & e) {
    object * r = lean_assign_mvar(mctx.steal(), mid.to_obj_arg(), e.to_obj_arg());
    mctx.set_box(r);
}

static option_ref<expr> get_mvar_assignment(metavar_ctx & mctx, name const & mid) {
    return option_ref<expr>(lean_get_mvar_assignment(mctx.to_obj_arg(), mid.to_obj_arg()));
}

static option_ref<delayed_assignment> get_delayed_mvar_assignment(metavar_ctx & mctx, name const & mid) {
    return option_ref<delayed_assignment>(lean_get_delayed_mvar_assignment(mctx.to_obj_arg(), mid.to_obj_arg()));
}

/* Level metavariable instantiation. */
class instantiate_lmvars_all_fn {
    metavar_ctx & m_mctx;
    lean::unordered_map<lean_object *, level> m_cache;
    std::vector<level> m_saved;

    inline level cache(level const & l, level r, bool shared) {
        if (shared) {
            m_cache.insert(mk_pair(l.raw(), r));
        }
        return r;
    }
public:
    instantiate_lmvars_all_fn(metavar_ctx & mctx):m_mctx(mctx) {}
    level visit(level const & l) {
        if (!has_mvar(l))
            return l;
        bool shared = false;
        if (is_shared(l)) {
            auto it = m_cache.find(l.raw());
            if (it != m_cache.end()) {
                return it->second;
            }
            shared = true;
        }
        switch (l.kind()) {
        case level_kind::Succ:
            return cache(l, update_succ(l, visit(succ_of(l))), shared);
        case level_kind::Max: case level_kind::IMax:
            return cache(l, update_max(l, visit(level_lhs(l)), visit(level_rhs(l))), shared);
        case level_kind::Zero: case level_kind::Param:
            lean_unreachable();
        case level_kind::MVar: {
            option_ref<level> r = get_lmvar_assignment(m_mctx, mvar_id(l));
            if (!r) {
                return l;
            } else {
                level a(r.get_val());
                if (!has_mvar(a)) {
                    return a;
                } else {
                    level a_new = visit(a);
                    if (!is_eqp(a, a_new)) {
                        m_saved.push_back(a);
                        assign_lmvar(m_mctx, mvar_id(l), a_new);
                    }
                    return a_new;
                }
            }
        }}
    }
    level operator()(level const & l) { return visit(l); }
};

/* ============================================================================
   Fused instantiation: resolves direct and delayed mvar assignments in a
   single traversal. Outer mode handles direct assignments with write-back;
   delayed mode carries fvar substitution for delayed assignment resolution.
   ============================================================================ */

struct fvar_subst_entry {
    unsigned depth;
    unsigned scope;
    expr     value;
};

class instantiate_fused_fn {
    struct key_hasher {
        std::size_t operator()(std::pair<lean_object *, unsigned> const & p) const {
            return hash((size_t)p.first >> 3, p.second);
        }
    };

    struct cache_entry { expr result; unsigned scope_level; unsigned scope_gen; };

    typedef lean::unordered_map<std::pair<lean_object *, unsigned>, cache_entry, key_hasher> scoped_cache;

    metavar_ctx & m_mctx;
    instantiate_lmvars_all_fn m_level_fn;

    /* Direct mvar normalization tracking (outer mode). */
    name_set m_already_normalized;
    std::vector<expr> m_saved;

    /* Resolvable delayed mvars: pending value is assigned and mvar-free
       after full resolution. Built during outer-mode traversal. */
    name_set m_resolvable_delayed;

    /* Shared cache: used in outer mode (ptr → expr) and readable in
       delayed mode for scope-independent expressions. */
    lean::unordered_map<lean_object *, expr> m_cache;

    /* Scoped cache: (ptr, depth) → cache_entry with generation-based
       staleness detection. Used in delayed mode for scope-dependent results. */
    scoped_cache m_scoped_cache;

    /* Fvar substitution state (delayed mode). */
    name_hash_map<fvar_subst_entry> m_fvar_subst;
    unsigned m_depth;

    /* Scope tracking with generation-based staleness. */
    std::vector<unsigned> m_scope_gens;
    unsigned m_gen_counter;
    unsigned m_scope;

    /* After visit() returns, holds the maximum fvar-substitution scope that
       contributed to the result. Used to decide cache placement. */
    unsigned m_result_scope;

    bool in_delayed_mode() const { return m_scope > 0; }

    level visit_level(level const & l) {
        if (in_delayed_mode()) return l; /* levels already resolved by outer mode */
        return m_level_fn(l);
    }

    levels visit_levels(levels const & ls) {
        if (in_delayed_mode()) return ls;
        buffer<level> lsNew;
        for (auto const & l : ls)
            lsNew.push_back(visit_level(l));
        return levels(lsNew);
    }

    /* ---- Direct mvar assignment (outer mode) ---- */

    optional<expr> get_direct_assignment(name const & mid) {
        option_ref<expr> r = get_mvar_assignment(m_mctx, mid);
        if (!r) return optional<expr>();
        expr a(r.get_val());
        if (!has_mvar(a) || m_already_normalized.contains(mid))
            return optional<expr>(a);
        m_already_normalized.insert(mid);
        expr a_new = visit(a);
        if (!is_eqp(a, a_new)) {
            m_saved.push_back(a);
            assign_mvar(m_mctx, mid, a_new);
        }
        return optional<expr>(a_new);
    }

    /* ---- Delayed-mode mvar assignment ---- */

    /* In delayed mode, direct mvar chains are already resolved by outer-mode
       write-back. We just need to visit the value to apply fvar substitution
       and resolve nested delayed mvars. No write-back in delayed mode. */
    optional<expr> get_delayed_mode_assignment(name const & mid) {
        option_ref<expr> r = get_mvar_assignment(m_mctx, mid);
        if (!r) return optional<expr>();
        expr a(r.get_val());
        if (!has_mvar(a) && !has_fvar(a))
            return optional<expr>(a);
        return optional<expr>(visit(a));
    }

    /* ---- Resolvability check ---- */

    /* Check whether a normalized value would be mvar-free after full resolution.
       Uses m_resolvable_delayed to check inner delayed mvars. After outer-mode
       normalization, remaining mvars are either unassigned or delayed-assigned. */
    bool is_value_resolvable(expr const & e) {
        if (!has_expr_mvar(e)) return true;
        switch (e.kind()) {
        case expr_kind::BVar: case expr_kind::Lit: case expr_kind::FVar:
        case expr_kind::Sort: case expr_kind::Const:
            return true;
        case expr_kind::MVar:
            return false;
        case expr_kind::App: {
            expr const & f = get_app_fn(e);
            if (is_mvar(f)) {
                name const & mid = mvar_name(f);
                option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
                if (!d) return false;
                array_ref<expr> fvars(cnstr_get(d.get_val().raw(), 0), true);
                if (fvars.size() > get_app_num_args(e)) return false;
                name mid_pending(cnstr_get(d.get_val().raw(), 1), true);
                if (!m_resolvable_delayed.contains(mid_pending)) return false;
                expr const * curr = &e;
                while (is_app(*curr)) {
                    if (!is_value_resolvable(app_arg(*curr))) return false;
                    curr = &app_fn(*curr);
                }
                return true;
            }
            return is_value_resolvable(app_fn(e)) && is_value_resolvable(app_arg(e));
        }
        case expr_kind::Lambda: case expr_kind::Pi:
            return is_value_resolvable(binding_domain(e)) && is_value_resolvable(binding_body(e));
        case expr_kind::Let:
            return is_value_resolvable(let_type(e)) && is_value_resolvable(let_value(e))
                && is_value_resolvable(let_body(e));
        case expr_kind::MData:
            return is_value_resolvable(mdata_expr(e));
        case expr_kind::Proj:
            return is_value_resolvable(proj_expr(e));
        }
        lean_unreachable();
    }

    /* Pre-normalize a delayed assignment's pending value and record
       whether it is resolvable. Called during outer-mode traversal. */
    void normalize_delayed_pending(name const & mid_pending) {
        if (auto val = get_direct_assignment(mid_pending)) {
            if (is_value_resolvable(*val)) {
                m_resolvable_delayed.insert(mid_pending);
            }
        }
    }

    /* ---- Fvar substitution (delayed mode) ---- */

    optional<expr> lookup_fvar(name const & fid) {
        auto it = m_fvar_subst.find(fid);
        if (it == m_fvar_subst.end())
            return optional<expr>();
        m_result_scope = std::max(m_result_scope, it->second.scope);
        unsigned d = m_depth - it->second.depth;
        if (d == 0)
            return optional<expr>(it->second.value);
        return optional<expr>(lift_loose_bvars(it->second.value, d));
    }

    /* ---- Scoped cache (delayed mode) ---- */

    optional<expr> scoped_cache_lookup(lean_object * ptr) {
        auto key = mk_pair(ptr, m_depth);
        auto it = m_scoped_cache.find(key);
        if (it == m_scoped_cache.end()) return {};
        auto & entry = it->second;
        if ((entry.scope_level == 0 || entry.scope_level == m_scope) &&
            m_scope_gens[entry.scope_level] == entry.scope_gen) {
            m_result_scope = std::max(m_result_scope, entry.scope_level);
            return optional<expr>(entry.result);
        }
        return {};
    }

    void scoped_cache_insert(lean_object * ptr, expr const & result) {
        auto key = mk_pair(ptr, m_depth);
        m_scoped_cache[key] = { result, m_result_scope, m_scope_gens[m_result_scope] };
    }

    /* ---- App visitors ---- */

    expr visit_app_default(expr const & e) {
        buffer<expr> args;
        expr const * curr = &e;
        while (is_app(*curr)) {
            args.push_back(visit(app_arg(*curr)));
            curr = &app_fn(*curr);
        }
        lean_assert(!is_mvar(*curr));
        expr f = visit(*curr);
        return mk_rev_app(f, args.size(), args.data());
    }

    expr visit_mvar_app_args(expr const & e) {
        buffer<expr> args;
        expr const * curr = &e;
        while (is_app(*curr)) {
            args.push_back(visit(app_arg(*curr)));
            curr = &app_fn(*curr);
        }
        lean_assert(is_mvar(*curr));
        return mk_rev_app(*curr, args.size(), args.data());
    }

    expr visit_args_and_beta(expr const & f_new, expr const & e, buffer<expr> & args) {
        expr const * curr = &e;
        while (is_app(*curr)) {
            args.push_back(visit(app_arg(*curr)));
            curr = &app_fn(*curr);
        }
        bool preserve_data = false;
        bool zeta = true;
        return apply_beta(f_new, args.size(), args.data(), preserve_data, zeta);
    }

    /* Fire delayed resolution: push fvar substitution scope, visit pending
       value, pop scope. Uses generation-based staleness for the scoped cache. */
    expr visit_delayed(array_ref<expr> const & fvars, name const & mid_pending,
                       expr const & e, buffer<expr> & args) {
        expr const * curr = &e;
        while (is_app(*curr)) {
            args.push_back(visit(app_arg(*curr)));
            curr = &app_fn(*curr);
        }

        size_t fvar_count = fvars.size();
        size_t extra_count = args.size() - fvar_count;

        /* Save and extend the fvar substitution. */
        struct saved_entry { name key; bool had_old; fvar_subst_entry old; };
        std::vector<saved_entry> saved_entries;
        saved_entries.reserve(fvar_count);
        m_scope++;
        for (size_t i = 0; i < fvar_count; i++) {
            name const & fid = fvar_name(fvars[i]);
            auto old_it = m_fvar_subst.find(fid);
            if (old_it != m_fvar_subst.end()) {
                saved_entries.push_back({fid, true, old_it->second});
            } else {
                saved_entries.push_back({fid, false, {0, 0, expr()}});
            }
            m_fvar_subst[fid] = {m_depth, m_scope, args[args.size() - 1 - i]};
        }

        /* Bump generation so stale entries at this scope level are detected. */
        m_gen_counter++;
        if (m_scope >= m_scope_gens.size())
            m_scope_gens.push_back(m_gen_counter);
        else
            m_scope_gens[m_scope] = m_gen_counter;

        /* Visit the pending value. In delayed mode, mk_mvar(mid_pending) will
           resolve via get_delayed_mode_assignment which visits the stored
           (already-normalized) value to apply fvar substitution. */
        expr val_new = visit(mk_mvar(mid_pending));

        /* Pop scope. */
        m_scope--;

        /* Restore the fvar substitution. */
        for (auto & se : saved_entries) {
            if (!se.had_old)
                m_fvar_subst.erase(se.key);
            else
                m_fvar_subst[se.key] = se.old;
        }

        bool preserve_data = false;
        bool zeta = true;
        return apply_beta(val_new, extra_count, args.data(), preserve_data, zeta);
    }

    /* ---- Outer-mode app: resolve direct mvars, fire delayed inline ---- */

    expr visit_app_outer(expr const & e) {
        expr const & f = get_app_fn(e);
        if (!is_mvar(f))
            return visit_app_default(e);
        name const & mid = mvar_name(f);
        /* Direct assignment takes precedence. */
        if (auto f_new = get_direct_assignment(mid)) {
            buffer<expr> args;
            return visit_args_and_beta(*f_new, e, args);
        }
        /* Check delayed assignment. */
        option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
        if (!d)
            return visit_mvar_app_args(e);
        array_ref<expr> fvars(cnstr_get(d.get_val().raw(), 0), true);
        name mid_pending(cnstr_get(d.get_val().raw(), 1), true);
        /* Pre-normalize the pending value and check resolvability. */
        normalize_delayed_pending(mid_pending);
        if (fvars.size() > get_app_num_args(e))
            return visit_mvar_app_args(e);
        if (!m_resolvable_delayed.contains(mid_pending))
            return visit_mvar_app_args(e);
        /* Fire delayed resolution inline. */
        buffer<expr> args;
        return visit_delayed(fvars, mid_pending, e, args);
    }

    /* ---- Delayed-mode app: apply fvar subst, resolve nested delayed ---- */

    expr visit_app_delayed(expr const & e) {
        expr const & f = get_app_fn(e);
        if (!is_mvar(f))
            return visit_app_default(e);
        name const & mid = mvar_name(f);
        /* In delayed mode, direct chains are already resolved. Check assignment
           to apply fvar substitution to the stored value. */
        if (auto f_new = get_delayed_mode_assignment(mid)) {
            buffer<expr> args;
            return visit_args_and_beta(*f_new, e, args);
        }
        /* Check delayed assignment for nested resolution. */
        option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
        if (!d)
            return visit_mvar_app_args(e);
        array_ref<expr> fvars(cnstr_get(d.get_val().raw(), 0), true);
        name mid_pending(cnstr_get(d.get_val().raw(), 1), true);
        if (fvars.size() > get_app_num_args(e))
            return visit_mvar_app_args(e);
        if (!m_resolvable_delayed.contains(mid_pending))
            return visit_mvar_app_args(e);
        buffer<expr> args;
        return visit_delayed(fvars, mid_pending, e, args);
    }

    /* ---- Mvar visitors ---- */

    expr visit_mvar_outer(expr const & e) {
        name const & mid = mvar_name(e);
        if (auto r = get_direct_assignment(mid))
            return *r;
        /* Not directly assigned. Check if delayed-assigned and pre-normalize. */
        option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
        if (d) {
            name mid_pending(cnstr_get(d.get_val().raw(), 1), true);
            normalize_delayed_pending(mid_pending);
        }
        return e;
    }

    expr visit_mvar_delayed(expr const & e) {
        name const & mid = mvar_name(e);
        if (auto r = get_delayed_mode_assignment(mid))
            return *r;
        return e;
    }

    expr visit_fvar(expr const & e) {
        name const & fid = fvar_name(e);
        if (auto r = lookup_fvar(fid))
            return *r;
        return e;
    }

    /* ---- Outer-mode visit ---- */

    expr visit_outer(expr const & e) {
        if (!has_mvar(e))
            return e;
        bool shared = false;
        if (is_shared(e)) {
            auto it = m_cache.find(e.raw());
            if (it != m_cache.end())
                return it->second;
            shared = true;
        }

        expr r;
        switch (e.kind()) {
        case expr_kind::BVar:
        case expr_kind::Lit: case expr_kind::FVar:
            lean_unreachable();
        case expr_kind::Sort:
            r = update_sort(e, visit_level(sort_level(e)));
            break;
        case expr_kind::Const:
            r = update_const(e, visit_levels(const_levels(e)));
            break;
        case expr_kind::MVar:
            return visit_mvar_outer(e); /* don't cache mvar results */
        case expr_kind::MData:
            r = update_mdata(e, visit(mdata_expr(e)));
            break;
        case expr_kind::Proj:
            r = update_proj(e, visit(proj_expr(e)));
            break;
        case expr_kind::App:
            r = visit_app_outer(e);
            break;
        case expr_kind::Pi: case expr_kind::Lambda:
            r = update_binding(e, visit(binding_domain(e)), visit(binding_body(e)));
            break;
        case expr_kind::Let:
            r = update_let(e, visit(let_type(e)), visit(let_value(e)), visit(let_body(e)));
            break;
        }
        if (shared)
            m_cache.insert(mk_pair(e.raw(), r));
        return r;
    }

    /* ---- Delayed-mode visit ---- */

    expr visit_delayed_mode(expr const & e) {
        if (!has_mvar(e) && !has_fvar(e))
            return e;

        /* use_global: expression has no fvars and no expr mvars, so its result
           is scope-independent and can be read from/written to the shared cache. */
        bool use_global = !has_fvar(e) && !has_expr_mvar(e);
        bool shared = false;
        if (is_shared(e)) {
            if (use_global) {
                auto it = m_cache.find(e.raw());
                if (it != m_cache.end())
                    return it->second;
            } else {
                if (auto r = scoped_cache_lookup(e.raw()))
                    return *r;
            }
            shared = true;
        }

        unsigned saved_result_scope = m_result_scope;
        m_result_scope = 0;

        expr r;
        switch (e.kind()) {
        case expr_kind::BVar:
        case expr_kind::Lit:
            lean_unreachable();
        case expr_kind::FVar:
            r = visit_fvar(e);
            goto done; /* skip caching for fvars */
        case expr_kind::Sort:
            r = update_sort(e, visit_level(sort_level(e)));
            break;
        case expr_kind::Const:
            r = update_const(e, visit_levels(const_levels(e)));
            break;
        case expr_kind::MVar:
            r = visit_mvar_delayed(e);
            goto done; /* mvar results are not (ptr, depth)-cacheable */
        case expr_kind::MData:
            r = update_mdata(e, visit(mdata_expr(e)));
            break;
        case expr_kind::Proj:
            r = update_proj(e, visit(proj_expr(e)));
            break;
        case expr_kind::App:
            r = visit_app_delayed(e);
            break;
        case expr_kind::Pi: case expr_kind::Lambda: {
            expr d = visit(binding_domain(e));
            m_depth++;
            expr b = visit(binding_body(e));
            m_depth--;
            r = update_binding(e, d, b);
            break;
        }
        case expr_kind::Let: {
            expr t = visit(let_type(e));
            expr v = visit(let_value(e));
            m_depth++;
            expr b = visit(let_body(e));
            m_depth--;
            r = update_let(e, t, v, b);
            break;
        }
        }
        if (shared) {
            if (m_result_scope == 0)
                m_cache.insert(mk_pair(e.raw(), r));
            else
                scoped_cache_insert(e.raw(), r);
        }

    done:
        m_result_scope = std::max(saved_result_scope, m_result_scope);
        return r;
    }

public:
    instantiate_fused_fn(metavar_ctx & mctx)
        : m_mctx(mctx), m_level_fn(mctx),
          m_depth(0), m_gen_counter(0), m_scope(0), m_result_scope(0) {
        m_scope_gens.push_back(0);
    }

    expr visit(expr const & e) {
        if (in_delayed_mode())
            return visit_delayed_mode(e);
        else
            return visit_outer(e);
    }

    expr operator()(expr const & e) { return visit(e); }
};

/* ============================================================================
   Entry points.
   ============================================================================ */

extern "C" LEAN_EXPORT object * lean_instantiate_expr_mvars_all(object * m, object * e) {
    metavar_ctx mctx(m);
    expr e_new = instantiate_fused_fn(mctx)(expr(e));
    object * r = alloc_cnstr(0, 2, 0);
    cnstr_set(r, 0, mctx.steal());
    cnstr_set(r, 1, e_new.steal());
    return r;
}

extern "C" LEAN_EXPORT object * lean_instantiate_expr_mvars_all_sharing(object * m, object * e) {
    return lean_instantiate_expr_mvars_all(m, e);
}
}
