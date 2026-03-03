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

Between passes, a `resolvability_checker` determines which delayed assignments can
be fully resolved (assigned, mvar-free after resolution, sufficient arguments).

Pass 2 (`instantiate_delayed_fn`):
  Resolves delayed assignments using `replace_fvars`, matching the original
  `instantiateMVars` approach. Pending values are visited once (cached/written
  back), then fvar substitution is applied mechanically per-site. This preserves
  sharing of the visited pending value across multiple occurrences of the same
  delayed mvar.
*/

namespace lean {
extern "C" object * lean_get_lmvar_assignment(obj_arg mctx, obj_arg mid);
extern "C" object * lean_assign_lmvar(obj_arg mctx, obj_arg mid, obj_arg val);
extern "C" object * lean_get_mvar_assignment(obj_arg mctx, obj_arg mid);
extern "C" object * lean_get_delayed_mvar_assignment(obj_arg mctx, obj_arg mid);
extern "C" object * lean_assign_mvar(obj_arg mctx, obj_arg mid, obj_arg val);
typedef object_ref metavar_ctx;
typedef object_ref delayed_assignment;

/* Forward declaration — defined in instantiate_mvars.cpp */
expr replace_fvars(expr const & e, array_ref<expr> const & fvars, expr const * rev_args);

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
     2. Its assigned value (normalized by pass 1) would become mvar-free
        after pass 2 resolution — i.e., all remaining mvars are delayed-
        assigned heads in app position with enough arguments, whose own
        pending values are also resolvable.
   Uses a cached bottom-up traversal (no fixpoint needed since the mvar
   dependency graph is acyclic).
   ============================================================================ */

class resolvability_checker {
    metavar_ctx & m_mctx;
    name_hash_map<name> const & m_head_to_pending;

    /* Expression cache: is this subexpression fully resolvable?
       Keyed by raw pointer — safe because we only traverse normalized
       values from mctx that outlive this checker. */
    lean::unordered_map<lean_object *, bool> m_expr_cache;

    /* Pending mvar cache: 0 = in-progress, 1 = resolvable, 2 = not. */
    name_hash_map<unsigned> m_pending_cache;

    bool is_pending_resolvable(name const & pending) {
        auto it = m_pending_cache.find(pending);
        if (it != m_pending_cache.end())
            return it->second == 1;
        /* Mark in-progress (cycle guard — shouldn't happen). */
        m_pending_cache[pending] = 0;
        option_ref<expr> r = get_mvar_assignment(m_mctx, pending);
        if (!r) {
            m_pending_cache[pending] = 2;
            return false;
        }
        bool ok = is_resolvable(expr(r.get_val()));
        m_pending_cache[pending] = ok ? 1 : 2;
        return ok;
    }

    bool is_resolvable(expr const & e) {
        if (!has_expr_mvar(e)) return true;
        if (is_shared(e)) {
            auto it = m_expr_cache.find(e.raw());
            if (it != m_expr_cache.end())
                return it->second;
        }
        bool r = is_resolvable_core(e);
        if (is_shared(e))
            m_expr_cache[e.raw()] = r;
        return r;
    }

    bool is_resolvable_core(expr const & e) {
        switch (e.kind()) {
        case expr_kind::MVar:
            /* Bare mvar — pass 2's visit_mvar only checks direct
               assignments, which pass 1 already resolved. Stuck. */
            return false;
        case expr_kind::App: {
            expr const & f = get_app_fn(e);
            if (is_mvar(f)) {
                name const & mid = mvar_name(f);
                auto it = m_head_to_pending.find(mid);
                if (it == m_head_to_pending.end())
                    return false; /* not a delayed head */
                option_ref<delayed_assignment> d =
                    get_delayed_mvar_assignment(m_mctx, mid);
                if (!d) return false;
                array_ref<expr> fvars(cnstr_get(d.get_val().raw(), 0), true);
                if (fvars.size() > get_app_num_args(e))
                    return false; /* not enough args */
                if (!is_pending_resolvable(it->second))
                    return false;
                /* Check args too. */
                expr const * curr = &e;
                while (is_app(*curr)) {
                    if (!is_resolvable(app_arg(*curr)))
                        return false;
                    curr = &app_fn(*curr);
                }
                return true;
            }
            return is_resolvable(app_fn(e)) && is_resolvable(app_arg(e));
        }
        case expr_kind::Lambda: case expr_kind::Pi:
            return is_resolvable(binding_domain(e)) &&
                   is_resolvable(binding_body(e));
        case expr_kind::Let:
            return is_resolvable(let_type(e)) &&
                   is_resolvable(let_value(e)) &&
                   is_resolvable(let_body(e));
        case expr_kind::MData:
            return is_resolvable(mdata_expr(e));
        case expr_kind::Proj:
            return is_resolvable(proj_expr(e));
        default:
            return true;
        }
    }

public:
    resolvability_checker(metavar_ctx & mctx,
                          name_hash_map<name> const & head_to_pending)
        : m_mctx(mctx), m_head_to_pending(head_to_pending) {}

    name_set compute() {
        name_set resolvable;
        for (auto & kv : m_head_to_pending) {
            if (is_pending_resolvable(kv.second))
                resolvable.insert(kv.second);
        }
        return resolvable;
    }
};

/* ============================================================================
   Pass 2: Resolve delayed assignments using replace_fvars.
   Direct mvar chains have been pre-resolved by pass 1, and the resolvability
   checker has determined which delayed assignments can be fully resolved.

   Uses the same replace_fvars approach as the original instantiateMVars:
   pending values are visited once (cached/written back), then fvar substitution
   is applied mechanically per-site via replace_fvars. This preserves sharing
   of the visited pending value across multiple occurrences of the same delayed
   mvar.
   ============================================================================ */

class instantiate_delayed_fn {
    metavar_ctx & m_mctx;
    name_set const & m_resolvable_delayed;
    lean::unordered_map<lean_object *, expr> m_cache;
    name_set m_already_normalized;
    std::vector<expr> m_saved;

    /* Get a direct mvar assignment. Visit it to resolve inner delayed mvars.
       Normalize and write back the result to the mctx. This matches the
       original instantiateMVars behavior: downstream code (e.g.
       MutualDef.mkInitialUsedFVarsMap) reads stored assignments and expects
       inner delayed assignments to be resolved. */
    optional<expr> get_assignment(name const & mid) {
        option_ref<expr> r = get_mvar_assignment(m_mctx, mid);
        if (!r)
            return optional<expr>();
        expr a(r.get_val());
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
        /* Get and visit the pending value (resolving inner delayed assignments).
           Uses get_assignment for write-back normalization. */
        optional<expr> val = get_assignment(mid_pending);
        lean_assert(val); /* resolvability checker verified this is assigned */
        /* Replace the delayed assignment's fvars with the visited arguments,
           matching the original instantiateMVars approach. */
        size_t fvar_count = fvars.size();
        expr val_new = replace_fvars(*val, fvars, args.data() + (args.size() - fvar_count));
        /* Use apply_beta for extra args: the fvar-substituted pending value may
           be a lambda (e.g. from assertAfter), and extra args should be beta-
           reduced into it rather than left as a redex. */
        bool preserve_data = false;
        bool zeta = true;
        return apply_beta(val_new, args.size() - fvar_count, args.data(), preserve_data, zeta);
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
            /* Normalize the pending value for mctx write-back.
               Downstream code (MutualDef.mkInitialUsedFVarsMap) reads stored
               assignments and relies on inner delayed assignments being
               resolved even when the outer one cannot be. */
            (void)get_assignment(mid_pending);
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

    inline expr cache(expr const & e, expr r, bool shared) {
        if (shared) {
            m_cache.insert(mk_pair(e.raw(), r));
        }
        return r;
    }

public:
    instantiate_delayed_fn(metavar_ctx & mctx, name_set const & resolvable_delayed)
        : m_mctx(mctx), m_resolvable_delayed(resolvable_delayed) {}

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
        case expr_kind::Sort:  case expr_kind::Const:
            /* Levels already resolved by pass 1. */
            return e;
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
   Entry points: run pass 1 then pass 2.
   ============================================================================ */

static object * run_instantiate_all(object * m, object * e) {
    metavar_ctx mctx(m);

    /* Pass 1: resolve direct mvar assignments, pre-normalize pending values. */
    instantiate_direct_fn pass1(mctx);
    expr e1 = pass1(expr(e));

    /* Pass 2: resolve delayed assignments using replace_fvars.
       Skip if pass 1 found no delayed assignments at all — the expression
       has no delayed mvars that need resolution or write-back. */
    expr e2;
    if (!pass1.has_delayed()) {
        e2 = e1;
    } else {
        resolvability_checker checker(mctx, pass1.head_to_pending());
        name_set resolvable = checker.compute();
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
