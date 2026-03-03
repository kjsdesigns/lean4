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
This module provides a two-pass variant of `instantiateMVars` with improved sharing.

Pass 1 (`instantiate_direct_fn`):
  Standard `instantiateMVars`-like traversal that resolves direct mvar assignments
  with write-back and a single persistent cache. For delayed assignments, it
  pre-normalizes the pending value (resolving its direct chain) but leaves the
  delayed mvar application in the expression. Unassigned mvars are left in place.

Pass 2 (`instantiate_delayed_fn`):
  Fused traversal that resolves delayed assignments by carrying a fvar substitution.
  Since pass 1 has pre-normalized all direct chains, each pending value is compact
  and visited once, avoiding the O(n³) sharing loss that occurs when the fused
  approach must also chase direct chains. Unassigned mvars are left as-is (matching
  the original `instantiateMVars` behavior).

The combination preserves sharing (O(n²) output for the pathological nested-delayed
case) while avoiding the separate `replace_fvars` calls of the standard approach.
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
    /* Mapping from delayed-assigned mvar head to its pending mvar name.
       Collected during traversal; used after pass 1 to compute the set of
       resolvable delayed assignments without adding per-entry overhead. */
    name_hash_map<name> m_delayed_head_to_pending;

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
            m_has_delayed = true;
            name mid_pending(cnstr_get(d.get_val().raw(), 1), true);
            m_delayed_head_to_pending.insert(mk_pair(mid, mid_pending));
            /* Pre-normalize the pending value so pass 2 finds it ready. */
            (void)get_assignment(mid_pending);
            return visit_mvar_app_args(e);
        }
        /* Not delayed: unassigned mvar. */
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
            m_has_delayed = true;
            name mid_pending(cnstr_get(d.get_val().raw(), 1), true);
            m_delayed_head_to_pending.insert(mk_pair(mid, mid_pending));
            /* Pre-normalize the pending value so pass 2 finds it ready. */
            (void)get_assignment(mid_pending);
        }
        return e;
    }

public:
    instantiate_direct_fn(metavar_ctx & mctx)
        : m_mctx(mctx), m_level_fn(mctx), m_has_delayed(false) {}
    bool has_delayed() const { return m_has_delayed; }
    name_hash_map<name> const & head_to_pending() const { return m_delayed_head_to_pending; }

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
   Resolvability computation (between pass 1 and pass 2).
   Determines which delayed assignments can be fully resolved by pass 2.
   A pending mvar is resolvable if:
     1. It is directly assigned, AND
     2. Its assigned value (normalized by pass 1) has no remaining mvars,
        OR all remaining mvars are delayed-assigned heads appearing in app
        position with enough arguments, whose own pending values are resolvable.
   Uses fixpoint iteration over the dependency graph.
   ============================================================================ */

struct pending_info {
    bool assigned;
    bool trivially_resolvable; /* assigned and has_expr_mvar is false */
    bool has_unresolvable_mvar; /* has a mvar that can never be resolved by pass 2 */
    name_set delayed_deps; /* delayed head names appearing with enough args */
};

/* Analyze an expression for mvar occurrences that affect resolvability.
   Sets info.has_unresolvable_mvar if any mvar is found that pass 2 cannot resolve.
   Adds delayed head names to info.delayed_deps for mvars in app position with
   enough arguments (these might be resolvable depending on the fixpoint). */
static void analyze_pending_mvars(
    expr const & e,
    name_hash_map<name> const & head_to_pending,
    metavar_ctx & mctx,
    pending_info & info)
{
    if (!has_expr_mvar(e) || info.has_unresolvable_mvar) return;

    switch (e.kind()) {
    case expr_kind::MVar:
        /* Bare mvar — pass 2's visit_mvar only checks direct assignments,
           which pass 1 already resolved. So this mvar is stuck. */
        info.has_unresolvable_mvar = true;
        return;
    case expr_kind::App: {
        expr const & f = get_app_fn(e);
        if (is_mvar(f)) {
            name const & mid = mvar_name(f);
            /* Check if this is a known delayed head. */
            auto it = head_to_pending.find(mid);
            if (it == head_to_pending.end()) {
                /* Not a delayed head — unassigned mvar left by pass 1. */
                info.has_unresolvable_mvar = true;
                return;
            }
            /* Check arg count against fvar count. */
            option_ref<delayed_assignment> d = get_delayed_mvar_assignment(mctx, mid);
            if (!d) {
                info.has_unresolvable_mvar = true;
                return;
            }
            array_ref<expr> fvars(cnstr_get(d.get_val().raw(), 0), true);
            if (fvars.size() > get_app_num_args(e)) {
                /* Not enough args — pass 2 can't resolve this. */
                info.has_unresolvable_mvar = true;
                return;
            }
            /* Record this as a dependency on the delayed head. */
            info.delayed_deps.insert(mid);
            /* Also check the arguments for unresolvable mvars. */
            expr const * curr = &e;
            while (is_app(*curr)) {
                analyze_pending_mvars(app_arg(*curr), head_to_pending, mctx, info);
                if (info.has_unresolvable_mvar) return;
                curr = &app_fn(*curr);
            }
            return;
        }
        /* Non-mvar app head — recurse normally. */
        analyze_pending_mvars(app_fn(e), head_to_pending, mctx, info);
        if (info.has_unresolvable_mvar) return;
        analyze_pending_mvars(app_arg(e), head_to_pending, mctx, info);
        return;
    }
    case expr_kind::Lambda: case expr_kind::Pi:
        analyze_pending_mvars(binding_domain(e), head_to_pending, mctx, info);
        if (info.has_unresolvable_mvar) return;
        analyze_pending_mvars(binding_body(e), head_to_pending, mctx, info);
        return;
    case expr_kind::Let:
        analyze_pending_mvars(let_type(e), head_to_pending, mctx, info);
        if (info.has_unresolvable_mvar) return;
        analyze_pending_mvars(let_value(e), head_to_pending, mctx, info);
        if (info.has_unresolvable_mvar) return;
        analyze_pending_mvars(let_body(e), head_to_pending, mctx, info);
        return;
    case expr_kind::MData:
        analyze_pending_mvars(mdata_expr(e), head_to_pending, mctx, info);
        return;
    case expr_kind::Proj:
        analyze_pending_mvars(proj_expr(e), head_to_pending, mctx, info);
        return;
    default:
        return;
    }
}

static name_set compute_resolvable_delayed(
    metavar_ctx & mctx,
    name_hash_map<name> const & head_to_pending)
{
    if (head_to_pending.empty())
        return name_set();

    /* Step 1: For each unique pending mvar, check its assignment and
       analyze the structure for mvar dependencies. */
    name_hash_map<pending_info> infos;
    for (auto & kv : head_to_pending) {
        name const & pending = kv.second;
        if (infos.find(pending) != infos.end())
            continue;
        option_ref<expr> r = get_mvar_assignment(mctx, pending);
        if (!r) {
            infos[pending] = {false, false, false, {}};
            continue;
        }
        expr val(r.get_val());
        if (!has_expr_mvar(val)) {
            infos[pending] = {true, true, false, {}};
            continue;
        }
        pending_info info = {true, false, false, {}};
        analyze_pending_mvars(val, head_to_pending, mctx, info);
        infos[pending] = std::move(info);
    }

    /* Step 2: Fixpoint iteration.
       A pending is resolvable if assigned, has no unresolvable mvars,
       and all delayed_deps have resolvable pending values. */
    name_set resolvable;
    /* Seed with trivially resolvable (no mvars at all). */
    for (auto & kv : infos) {
        if (kv.second.trivially_resolvable)
            resolvable.insert(kv.first);
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (auto & kv : head_to_pending) {
            name const & pending = kv.second;
            if (resolvable.contains(pending)) continue;
            auto it = infos.find(pending);
            if (it == infos.end()) continue;
            auto & info = it->second;
            if (!info.assigned || info.has_unresolvable_mvar) continue;

            bool all_ok = true;
            info.delayed_deps.for_each([&](name const & dep_head) {
                if (!all_ok) return;
                auto ht = head_to_pending.find(dep_head);
                if (ht == head_to_pending.end()) {
                    all_ok = false;
                    return;
                }
                if (!resolvable.contains(ht->second)) {
                    all_ok = false;
                }
            });
            if (all_ok) {
                resolvable.insert(pending);
                changed = true;
            }
        }
    }
    return resolvable;
}

/* ============================================================================
   Pass 2: Resolve delayed assignments with fused fvar substitution.
   Direct mvar chains have been pre-resolved by pass 1.

   Uses a flat (ptr, depth)-keyed cache with generation-based staleness.
   Each visit_delayed scope gets a unique generation number; cache entries
   record the scope level and generation at insertion. Validity is O(1):
   entry valid iff level <= m_scope && m_scope_gens[level] == entry.scope_gen.
   ============================================================================ */

struct fvar_subst_entry {
    unsigned depth;
    unsigned scope;
    expr     value;
};

class instantiate_delayed_fn {
    struct key_hasher {
        std::size_t operator()(std::pair<lean_object *, unsigned> const & p) const {
            return hash((size_t)p.first >> 3, p.second);
        }
    };

    struct cache_entry { expr result; unsigned scope_level; unsigned scope_gen; };

    typedef lean::unordered_map<std::pair<lean_object *, unsigned>, cache_entry, key_hasher> flat_cache;

    metavar_ctx & m_mctx;
    name_set const & m_resolvable_delayed;
    name_hash_map<fvar_subst_entry> m_fvar_subst;
    unsigned m_depth;

    /* Single flat cache with generation-based staleness detection. */
    flat_cache m_cache;
    std::vector<unsigned> m_scope_gens;  /* m_scope_gens[level] = generation */
    unsigned m_gen_counter;
    unsigned m_scope;

    /* After visit() returns, this holds the maximum fvar-substitution
       scope that contributed to the result — i.e., the outermost scope at which the
       result is valid and can be cached. Updated monotonically (via max) through
       the save/reset/restore pattern in visit(). */
    unsigned m_result_scope;

    /* Global cache for fvar-free expressions — scope-independent. */
    lean::unordered_map<lean_object *, expr> m_global_cache;

    /* Write-back support: when fvar_subst is empty, normalize and write back
       mvar assignments to match the original instantiateMVars mctx side effects.
       Downstream code (e.g. MutualDef.mkInitialUsedFVarsMap) reads stored
       assignments and expects them to be normalized. */
    name_set m_already_normalized;
    std::vector<expr> m_saved;

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

    /* Cache lookup — O(1) with generation-based staleness check.
       An entry at scope_level 0 (no fvar dependency) is valid at any scope.
       An entry at scope_level > 0 is only valid at exactly that scope level,
       because an inner scope may shadow the fvars it depends on. */
    optional<expr> cache_lookup(lean_object * ptr) {
        auto key = mk_pair(ptr, m_depth);
        auto it = m_cache.find(key);
        if (it == m_cache.end()) return {};
        auto & entry = it->second;
        if ((entry.scope_level == 0 || entry.scope_level == m_scope) &&
            m_scope_gens[entry.scope_level] == entry.scope_gen) {
            m_result_scope = std::max(m_result_scope, entry.scope_level);
            return optional<expr>(entry.result);
        }
        return {};
    }

    void cache_insert(lean_object * ptr, expr const & result) {
        auto key = mk_pair(ptr, m_depth);
        m_cache[key] = { result, m_result_scope, m_scope_gens[m_result_scope] };
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
            if (!has_mvar(a))
                return optional<expr>(a);
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
            if (!has_mvar(a) && !has_fvar(a))
                return optional<expr>(a);
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

        /* Push: bump generation so stale entries at this scope level are detected. */
        m_gen_counter++;
        if (m_scope >= m_scope_gens.size())
            m_scope_gens.push_back(m_gen_counter);
        else
            m_scope_gens[m_scope] = m_gen_counter;

        expr val_new = visit(mk_mvar(mid_pending));

        /* Pop: just decrement scope — stale entries are detected by generation mismatch. */
        m_scope--;

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
        /* Direct assignment takes precedence. */
        if (auto f_new = get_assignment(mid)) {
            buffer<expr> args;
            return visit_args_and_beta(*f_new, e, args);
        }
        /* Check delayed assignment. */
        option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
        if (!d) {
            return visit_mvar_app_args(e);
        }
        array_ref<expr> fvars(cnstr_get(d.get_val().raw(), 0), true);
        name mid_pending(cnstr_get(d.get_val().raw(), 1), true);
        if (fvars.size() > get_app_num_args(e)) {
            return visit_mvar_app_args(e);
        }
        /* Only resolve the delayed assignment when the resolvability
           computation determined the pending value is fully resolvable
           (assigned and all nested delayed mvars also resolvable). This
           matches the original instantiateMVars behavior. */
        if (!m_resolvable_delayed.contains(mid_pending)) {
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

    expr visit_mvar(expr const & e) {
        name const & mid = mvar_name(e);
        if (auto r = get_assignment(mid)) {
            return *r;
        }
        return e;
    }

    expr visit_fvar(expr const & e) {
        name const & fid = fvar_name(e);
        if (auto r = lookup_fvar(fid)) {
            return *r;
        }
        return e;
    }

public:
    instantiate_delayed_fn(metavar_ctx & mctx, name_set const & resolvable_delayed)
        : m_mctx(mctx), m_resolvable_delayed(resolvable_delayed),
          m_depth(0), m_gen_counter(0), m_scope(0), m_result_scope(0) {
        m_scope_gens.push_back(0); /* scope 0 has generation 0 */
    }

    expr visit(expr const & e) {
        if (fvar_subst_empty()) {
            if (!has_mvar(e))
                return e;
        } else {
            if (!has_mvar(e) && !has_fvar(e))
                return e;
        }

        bool use_global = !has_fvar(e) && !has_expr_mvar(e);
        bool shared = false;
        if (is_shared(e)) {
            if (use_global) {
                auto it = m_global_cache.find(e.raw());
                if (it != m_global_cache.end())
                    return it->second;
            } else {
                if (auto r = cache_lookup(e.raw()))
                    return *r;
            }
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
            r = visit_mvar(e);
            goto done; /* mvar results are not (ptr, depth)-cacheable */
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
            if (use_global)
                m_global_cache.insert(mk_pair(e.raw(), r));
            else
                cache_insert(e.raw(), r);
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
        name_set resolvable = compute_resolvable_delayed(mctx, pass1.head_to_pending());
        instantiate_delayed_fn pass2(mctx, resolvable);
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
