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
#include "kernel/scope_cache.h"

/*
This module provides a two-pass implementation of `instantiateMVars` with
linear complexity in the presence of nested delayed-assigned metavariables and
improved sharing.

Pass 1 (`instantiate_direct_fn`):
  First traversal that resolves **direct** mvar assignments with write-back.
  For delayed assignments, it pre-normalizes the pending value (resolving its
  direct chain) but leaves the delayed mvar application in the expression.
  Also assigns level metavariables.

Pass 2 (`instantiate_delayed_fn`):
  Second traversal that resolves delayed assignments by carrying a fvar
  substitution. Checks resolvability on-demand when encountering each delayed
  mvar (caching results across invocations). Since pass 1 has pre-normalized
  all direct chains, each pending value is compact and visited once, avoiding
  the O(n³) sharing loss that occurs when the fused approach must also chase
  direct chains.
*/

namespace lean {
extern "C" object * lean_get_lmvar_assignment(obj_arg mctx, obj_arg mid);
extern "C" object * lean_assign_lmvar(obj_arg mctx, obj_arg mid, obj_arg val);
extern "C" object * lean_get_mvar_assignment(obj_arg mctx, obj_arg mid);
extern "C" object * lean_get_delayed_mvar_assignment(obj_arg mctx, obj_arg mid);
extern "C" object * lean_delayed_mvar_assignment_fvars(obj_arg d);
extern "C" object * lean_delayed_mvar_assignment_mvar_id_pending(obj_arg d);
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

static array_ref<expr> delayed_assignment_fvars(delayed_assignment const & d) {
    return array_ref<expr>(lean_delayed_mvar_assignment_fvars(d.to_obj_arg()));
}

static name delayed_assignment_mvar_id_pending(delayed_assignment const & d) {
    return name(lean_delayed_mvar_assignment_mvar_id_pending(d.to_obj_arg()));
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
   Pass 1: Resolve direct mvar assignments with write-back.
   For delayed assignments, pre-normalize the pending value (resolving its
   direct chains) but leave the delayed mvar application in the expression.
   Unassigned mvars are left in place.
   ============================================================================ */

class instantiate_direct_fn {
    metavar_ctx & m_mctx;
    instantiate_lmvars_all_fn m_level_fn;
    name_set m_already_normalized;
    /* Set to true when any delayed assignment is encountered, even if not
       resolvable. Pass 2 is needed for write-back normalization in that case. */
    bool m_has_delayed;

    lean::unordered_map<lean_object *, expr> m_cache;
    std::vector<expr> m_saved;

    level visit_level(level const & l) {
        return m_level_fn(l);
    }

    levels visit_levels(levels const & ls) {
        buffer<level> lsNew;
        for (auto const & l : ls)
            lsNew.push_back(visit_level(l));
        return levels(lsNew);
    }

    inline expr cache(expr const & e, expr r, bool shared) {
        if (shared) {
            m_cache.insert(mk_pair(e.raw(), r));
        }
        return r;
    }

    /* Get and normalize a direct mvar assignment. Write back the normalized value. */
    optional<expr> get_assignment(name const & mid) {
        option_ref<expr> r = get_mvar_assignment(m_mctx, mid);
        if (!r) {
            return optional<expr>();
        }
        expr a(r.get_val());
        if (!has_mvar(a) || m_already_normalized.contains(mid)) {
            return optional<expr>(a);
        }
        m_already_normalized.insert(mid);
        expr a_new = visit(a);
        if (!is_eqp(a, a_new)) {
            m_saved.push_back(a);
            assign_mvar(m_mctx, mid, a_new);
        }
        return optional<expr>(a_new);
    }

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

    expr visit_app(expr const & e) {
        expr const & f = get_app_fn(e);
        if (!is_mvar(f)) {
            return visit_app_default(e);
        }
        name const & mid = mvar_name(f);
        /* Direct assignment takes precedence. */
        if (auto f_new = get_assignment(mid)) {
            buffer<expr> args;
            return visit_args_and_beta(*f_new, e, args);
        }
        /* Check for delayed assignment. */
        option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
        if (d) {
            /* Pre-normalize the pending value so pass 2 finds it ready.
               Only trigger pass 2 if the pending mvar is actually assigned;
               unassigned pending values will clearly fail the resolvability check. */
            name mid_pending = delayed_assignment_mvar_id_pending(d.get_val());
            if (get_assignment(mid_pending))
                m_has_delayed = true;
        }
        return visit_mvar_app_args(e);
    }

    expr visit_mvar(expr const & e) {
        name const & mid = mvar_name(e);
        if (auto r = get_assignment(mid)) {
            return *r;
        }
        /* Not directly assigned. Check if delayed-assigned. */
        option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
        if (d) {
            name mid_pending = delayed_assignment_mvar_id_pending(d.get_val());
            if (get_assignment(mid_pending))
                m_has_delayed = true;
        }
        return e;
    }

public:
    instantiate_direct_fn(metavar_ctx & mctx)
        : m_mctx(mctx), m_level_fn(mctx), m_has_delayed(false) {}
    bool has_delayed() const { return m_has_delayed; }

    expr visit(expr const & e) {
        if (!has_mvar(e))
            return e;
        bool shared = false;
        if (is_shared(e)) {
            auto it = m_cache.find(e.raw());
            if (it != m_cache.end()) {
                return it->second;
            }
            shared = true;
        }

        switch (e.kind()) {
        case expr_kind::BVar:
        case expr_kind::Lit:  case expr_kind::FVar:
            lean_unreachable();
        case expr_kind::Sort:
            return cache(e, update_sort(e, visit_level(sort_level(e))), shared);
        case expr_kind::Const:
            return cache(e, update_const(e, visit_levels(const_levels(e))), shared);
        case expr_kind::MVar:
            return visit_mvar(e);
        case expr_kind::MData:
            return cache(e, update_mdata(e, visit(mdata_expr(e))), shared);
        case expr_kind::Proj:
            return cache(e, update_proj(e, visit(proj_expr(e))), shared);
        case expr_kind::App:
            return cache(e, visit_app(e), shared);
        case expr_kind::Pi: case expr_kind::Lambda:
            return cache(e, update_binding(e, visit(binding_domain(e)), visit(binding_body(e))), shared);
        case expr_kind::Let:
            return cache(e, update_let(e, visit(let_type(e)), visit(let_value(e)), visit(let_body(e))), shared);
        }
    }

    expr operator()(expr const & e) { return visit(e); }
};

/* ============================================================================
   Pass 2: Resolve delayed assignments with fused fvar substitution.
   Direct mvar chains have been pre-resolved by pass 1.
   ============================================================================ */

struct fvar_subst_entry {
    unsigned depth;
    unsigned scope;
    expr     value;
};

class instantiate_delayed_fn {
    metavar_ctx & m_mctx;
    name_hash_map<fvar_subst_entry> m_fvar_subst;
    unsigned m_depth;

    /* Scope-aware cache for (ptr, depth) → expr with lazy staleness detection. */
    struct key_hasher {
        std::size_t operator()(std::pair<lean_object *, unsigned> const & p) const {
            return hash((size_t)p.first >> 3, p.second);
        }
    };
    typedef std::pair<lean_object *, unsigned> cache_key;
    scope_cache<cache_key, expr, key_hasher> m_cache;

    /* After visit() returns, this holds the maximum fvar-substitution
       scope that contributed to the result — i.e., the outermost scope at which the
       result is valid and can be cached. Updated monotonically (via max) through
       the save/reset/restore pattern in visit(). */
    unsigned m_result_scope;

    /* Write-back support: when fvar_subst is empty, normalize and write back
       mvar assignments to match the original instantiateMVars mctx side effects.
       Downstream code (e.g. MutualDef.mkInitialUsedFVarsMap) reads stored
       assignments and expects them to be normalized. */
    name_set m_already_normalized;
    std::vector<expr> m_saved;

    /* Resolvability caches — persistent across all delayed mvar resolutions.
       A pending mvar is resolvable if its assigned value (normalized by pass 1)
       would become mvar-free after resolution: all remaining mvars must be
       delayed-assigned heads in app position with enough arguments, whose own
       pending values are also resolvable. */
    lean::unordered_map<lean_object *, bool> m_resolvable_expr_cache;
    name_hash_map<unsigned> m_resolvable_pending_cache; /* 0 = in-progress, 1 = yes, 2 = no */

    bool is_resolvable_pending(name const & pending) {
        auto it = m_resolvable_pending_cache.find(pending);
        if (it != m_resolvable_pending_cache.end())
            return it->second == 1;
        /* Mark in-progress (cycle guard — shouldn't happen). */
        m_resolvable_pending_cache[pending] = 0;
        option_ref<expr> r = get_mvar_assignment(m_mctx, pending);
        if (!r) {
            m_resolvable_pending_cache[pending] = 2;
            return false;
        }
        bool ok = is_resolvable_expr(expr(r.get_val()));
        m_resolvable_pending_cache[pending] = ok ? 1 : 2;
        return ok;
    }

    bool is_resolvable_expr(expr const & e) {
        if (!has_expr_mvar(e)) return true;
        if (is_shared(e)) {
            auto it = m_resolvable_expr_cache.find(e.raw());
            if (it != m_resolvable_expr_cache.end())
                return it->second;
        }
        bool r = is_resolvable_expr_core(e);
        if (is_shared(e))
            m_resolvable_expr_cache[e.raw()] = r;
        return r;
    }

    bool is_resolvable_expr_core(expr const & e) {
        switch (e.kind()) {
        case expr_kind::MVar:
            /* Bare mvar — direct assignments were resolved by pass 1. Stuck. */
            return false;
        case expr_kind::App: {
            expr const & f = get_app_fn(e);
            if (is_mvar(f)) {
                name const & mid = mvar_name(f);
                option_ref<delayed_assignment> d =
                    get_delayed_mvar_assignment(m_mctx, mid);
                if (!d) return false;
                array_ref<expr> fvars = delayed_assignment_fvars(d.get_val());
                if (fvars.size() > get_app_num_args(e))
                    return false; /* not enough args */
                name mid_pending = delayed_assignment_mvar_id_pending(d.get_val());
                if (!is_resolvable_pending(mid_pending))
                    return false;
                /* Check args too. */
                expr const * curr = &e;
                while (is_app(*curr)) {
                    if (!is_resolvable_expr(app_arg(*curr)))
                        return false;
                    curr = &app_fn(*curr);
                }
                return true;
            }
            return is_resolvable_expr(app_fn(e)) && is_resolvable_expr(app_arg(e));
        }
        case expr_kind::Lambda: case expr_kind::Pi:
            return is_resolvable_expr(binding_domain(e)) &&
                   is_resolvable_expr(binding_body(e));
        case expr_kind::Let:
            return is_resolvable_expr(let_type(e)) &&
                   is_resolvable_expr(let_value(e)) &&
                   is_resolvable_expr(let_body(e));
        case expr_kind::MData:
            return is_resolvable_expr(mdata_expr(e));
        case expr_kind::Proj:
            return is_resolvable_expr(proj_expr(e));
        default:
            return true;
        }
    }

    bool fvar_subst_empty() const {
        return m_fvar_subst.empty();
    }

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

    /* Get a direct mvar assignment. Visit it to resolve delayed mvars
       and apply the fvar substitution.
       When fvar_subst is empty, normalize and write back the result to
       the mctx. This matches the original instantiateMVars behavior:
       downstream code (e.g. MutualDef.mkInitialUsedFVarsMap) reads stored
       assignments and expects inner delayed assignments to be resolved.
       When fvar_subst is non-empty, no write-back (values contain
       fvar-substituted terms not suitable for the mctx). */
    optional<expr> get_assignment(name const & mid) {
        option_ref<expr> r = get_mvar_assignment(m_mctx, mid);
        if (!r)
            return optional<expr>();
        expr a(r.get_val());
        if (fvar_subst_empty()) {
            if (m_already_normalized.contains(mid))
                return optional<expr>(a);
            m_already_normalized.insert(mid);
            expr a_new = visit(a);
            if (!is_eqp(a, a_new)) {
                m_saved.push_back(a);
                assign_mvar(m_mctx, mid, a_new);
            }
            return optional<expr>(a_new);
        } else {
            return optional<expr>(visit(a));
        }
    }

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

    expr visit_delayed(array_ref<expr> const & fvars, name const & mid_pending,
                       expr const & e, buffer<expr> & args) {
        expr const * curr = &e;
        while (is_app(*curr)) {
            args.push_back(visit(app_arg(*curr)));
            curr = &app_fn(*curr);
        }

        size_t fvar_count = fvars.size();
        size_t extra_count = args.size() - fvar_count;

        /* Push a new scope and extend the fvar substitution. */
        m_cache.push();
        struct saved_entry { name key; bool had_old; fvar_subst_entry old; };
        std::vector<saved_entry> saved_entries;
        saved_entries.reserve(fvar_count);
        for (size_t i = 0; i < fvar_count; i++) {
            name const & fid = fvar_name(fvars[i]);
            auto old_it = m_fvar_subst.find(fid);
            if (old_it != m_fvar_subst.end()) {
                saved_entries.push_back({fid, true, old_it->second});
            } else {
                saved_entries.push_back({fid, false, {0, 0, expr()}});
            }
            m_fvar_subst[fid] = {m_depth, m_cache.scope(), args[args.size() - 1 - i]};
        }

        /* Get the pending value directly — it must be assigned (pass 1
           pre-normalized it). No write-back needed since fvar_subst is non-empty. */
        option_ref<expr> pending_val = get_mvar_assignment(m_mctx, mid_pending);
        lean_assert(!!pending_val);
        expr val_new = visit(expr(pending_val.get_val()));

        /* Pop scope; stale entries are detected by generation mismatch on lookup. */
        m_cache.pop();

        /* Restore the fvar substitution. */
        for (auto & se : saved_entries) {
            if (!se.had_old) {
                m_fvar_subst.erase(se.key);
            } else {
                m_fvar_subst[se.key] = se.old;
            }
        }

        /* Use apply_beta instead of mk_rev_app: pass 1's beta-reduction may have
           changed delayed mvar arguments (e.g., substituting a bvar with a concrete
           value), so the resolved pending value may be a lambda that needs beta-
           reduction with the extra args, matching the original's behavior. */
        bool preserve_data = false;
        bool zeta = true;
        return apply_beta(val_new, extra_count, args.data(), preserve_data, zeta);
    }

    expr visit_app(expr const & e) {
        expr const & f = get_app_fn(e);
        if (!is_mvar(f)) {
            return visit_app_default(e);
        }
        name const & mid = mvar_name(f);
        /* Direct assignments were resolved by pass 1. */
        lean_assert(!get_mvar_assignment(m_mctx, mid));
        /* Check delayed assignment. */
        option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
        if (!d) {
            return visit_mvar_app_args(e);
        }
        array_ref<expr> fvars = delayed_assignment_fvars(d.get_val());
        name mid_pending = delayed_assignment_mvar_id_pending(d.get_val());
        if (fvars.size() > get_app_num_args(e)) {
            return visit_mvar_app_args(e);
        }
        /* Only resolve when the pending value is fully resolvable
           (assigned and all nested delayed mvars also resolvable). */
        if (!is_resolvable_pending(mid_pending)) {
            /* Still normalize the pending value for mctx write-back when
               fvar_subst is empty. Downstream code (MutualDef.mkInitialUsedFVarsMap)
               reads stored assignments and relies on inner delayed assignments
               being resolved even when the outer one cannot be. */
            if (fvar_subst_empty()) {
                (void)get_assignment(mid_pending);
            }
            return visit_mvar_app_args(e);
        }
        buffer<expr> args;
        return visit_delayed(fvars, mid_pending, e, args);
    }

    expr visit_fvar(expr const & e) {
        name const & fid = fvar_name(e);
        if (auto r = lookup_fvar(fid)) {
            return *r;
        }
        return e;
    }

public:
    instantiate_delayed_fn(metavar_ctx & mctx)
        : m_mctx(mctx), m_depth(0), m_result_scope(0) {}

    expr visit(expr const & e) {
        if ((!has_fvar(e) || fvar_subst_empty()) && !has_expr_mvar(e))
            return e;

        bool shared = false;
        if (is_shared(e)) {
            if (auto r = m_cache.lookup(cache_key(e.raw(), m_depth), m_result_scope))
                return *r;
            shared = true;
        }

        /* Save and reset the result scope for this subtree.
           After computing, cache_insert uses m_result_scope to place the entry
           at the outermost valid scope level. Then we restore the parent's
           watermark, taking the max with our contribution. */
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
            /* Bare mvars in pass 2 are unassigned: direct assignments were
               resolved by pass 1, and resolvable pending values contain no
               bare unassigned mvars. They only appear at the top level or
               during write-back normalization (both with empty fvar_subst). */
            lean_assert(fvar_subst_empty());
            lean_assert(!get_mvar_assignment(m_mctx, mvar_name(e)));
            r = e;
            goto done;
        case expr_kind::MData:
            r = update_mdata(e, visit(mdata_expr(e)));
            break;
        case expr_kind::Proj:
            r = update_proj(e, visit(proj_expr(e)));
            break;
        case expr_kind::App:
            r = visit_app(e);
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
            r = m_cache.insert(cache_key(e.raw(), m_depth), r, m_result_scope);
        }

    done:
        m_result_scope = std::max(saved_result_scope, m_result_scope);
        return r;
    }

    level visit_level(level const & l) {
        /* Pass 2 does not handle level mvars — pass 1 already resolved them.
           But we still need this for the visit_levels call in update_sort/update_const.
           Since levels have no fvars, we can just return them as-is. */
        return l;
    }

    levels visit_levels(levels const & ls) {
        return ls;
    }

    expr operator()(expr const & e) { return visit(e); }
};

/* ============================================================================
   Entry points: run pass 1 then pass 2.
   ============================================================================ */

static object * run_instantiate_all(object * m, object * e) {
    metavar_ctx mctx(m);

    /* Pass 1: resolve direct mvar assignments, pre-normalize pending values. */
    instantiate_direct_fn pass1(mctx);
    expr e1 = pass1(expr(e));

    /* Pass 2: resolve delayed assignments with fused fvar substitution.
       Skip if pass 1 found no delayed assignments at all — the expression
       has no delayed mvars that need resolution or write-back. */
    expr e2;
    if (!pass1.has_delayed()) {
        e2 = e1;
    } else {
        instantiate_delayed_fn pass2(mctx);
        e2 = pass2(e1);
    }

    /* (mctx, expr) */
    object * r = alloc_cnstr(0, 2, 0);
    cnstr_set(r, 0, mctx.steal());
    cnstr_set(r, 1, e2.steal());
    return r;
}

extern "C" LEAN_EXPORT object * lean_instantiate_expr_mvars_all(object * m, object * e) {
    return run_instantiate_all(m, e);
}

extern "C" LEAN_EXPORT object * lean_instantiate_expr_mvars_all_sharing(object * m, object * e) {
    return run_instantiate_all(m, e);
}
}
