/*
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Authors: Joachim Breitner
*/
#include <vector>
#include <unordered_map>
#include "util/name_set.h"
#include "runtime/option_ref.h"
#include "runtime/array_ref.h"
#include "kernel/instantiate.h"
#include "kernel/replace_fn.h"
#include "kernel/expr.h"

/*
This module provides an efficient C++ implementation of `instantiateMVarsNoUpdate`.

Unlike `instantiateExprMVars`, this variant does NOT update the assignments of the
metavariables it visits. Instead, it carries a substitution of free variables as it
traverses delayed-assigned metavariables, avoiding repeated substitution overhead.

Key design differences from instantiate_mvars.cpp:
1. No `assign_mvar` calls -- the mctx is not mutated (in particular, the result does
   not include an updated mctx).
2. FVar substitution: when encountering a delayed assignment `?m [x,y] := ?pending`,
   instead of doing `replace_fvars`, we extend an fvar substitution map and continue
   traversing. This avoids a second traversal.
3. Depth tracking: we track the current binder depth. Fvar substitution values are
   stored with the depth at which they were inserted; on lookup, we lift by the
   difference.
4. Cache clearing: we clear the expression cache when going under binders, because
   cache entries depend on the current depth (fvar substitutions may contain loose bvars).

When the fvar substitution is empty, we update metavar assignments with their normalized
values (like the standard instantiateMVars), since this is sound and helps future lookups.
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

/* Level metavariable instantiation -- same as in instantiate_mvars.cpp,
   but we DO update level mvar assignments (levels don't involve fvars). */
class instantiate_lmvars_nu_fn {
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
    instantiate_lmvars_nu_fn(metavar_ctx & mctx):m_mctx(mctx) {}
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

struct fvar_subst_entry {
    unsigned depth;
    expr     value;
};

class instantiate_mvars_no_update_fn {
    metavar_ctx & m_mctx;
    instantiate_lmvars_nu_fn m_level_fn;
    /* The fvar substitution, mapping fvar names to (depth, value) pairs. */
    lean::unordered_map<lean_object *, fvar_subst_entry> m_fvar_subst;
    /* Current binder depth. */
    unsigned m_depth;
    /* Expression cache. Cleared when going under binders. */
    lean::unordered_map<lean_object *, expr> m_cache;
    /* Global cache: persists across binder depths. Used for expressions that have
       no FVars, so their result is depth-independent. */
    lean::unordered_map<lean_object *, expr> m_global_cache;
    /* Prevent GC of values whose subterms may be referenced by the cache. */
    std::vector<expr> m_saved;
    /* Track which mvars have already been normalized (for the update-when-empty optimization). */
    name_set m_already_normalized;

    level visit_level(level const & l) {
        return m_level_fn(l);
    }

    levels visit_levels(levels const & ls) {
        buffer<level> lsNew;
        for (auto const & l : ls)
            lsNew.push_back(visit_level(l));
        return levels(lsNew);
    }

    bool fvar_subst_empty() const {
        return m_fvar_subst.empty();
    }

    /* Look up an fvar in our substitution. Returns none if not found. */
    optional<expr> lookup_fvar(name const & fid) {
        auto it = m_fvar_subst.find(fid.raw());
        if (it == m_fvar_subst.end())
            return optional<expr>();
        unsigned d = m_depth - it->second.depth;
        if (d == 0)
            return optional<expr>(it->second.value);
        return optional<expr>(lift_loose_bvars(it->second.value, d));
    }

    /*
    Get mvar assignment. Unlike the updating version, we do NOT normalize
    and write back by default -- unless the fvar substitution is empty,
    in which case the normalization result is identical to what instantiateMVars
    would compute, and updating is sound and beneficial.
    */
    optional<expr> get_assignment(name const & mid) {
        option_ref<expr> r = get_mvar_assignment(m_mctx, mid);
        if (!r)
            return optional<expr>();
        expr a(r.get_val());
        if (!has_mvar(a) && !has_fvar(a)) {
            return optional<expr>(a);
        }
        if (fvar_subst_empty()) {
            /* Sound to update: no fvar substitution active, so the result
               is identical to what instantiateMVars would compute. */
            if (m_already_normalized.contains(mid)) {
                return optional<expr>(a);
            }
            m_already_normalized.insert(mid);
            expr a_new = visit(a);
            if (!is_eqp(a, a_new)) {
                m_saved.push_back(a);
                assign_mvar(m_mctx, mid, a_new);
            }
            return optional<expr>(a_new);
        } else {
            /* Cannot update: fvar substitution is active. Just visit. */
            return optional<expr>(visit(a));
        }
    }

    /* Given `e` of the form `f a_1 ... a_n` where `f` is not a metavariable,
       instantiate metavariables in all positions. */
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

    /* Given `e` of the form `?m a_1 ... a_n`, visit the args but keep ?m as-is. */
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

    /* Beta-reduce `f_new` applied to the args of `e`. */
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

    /*
    Handle delayed assignment: `?m [x,y] := ?pending` applied to args.
    Instead of replace_fvars, we extend the fvar substitution and recursively visit ?pending.
    */
    expr visit_delayed(array_ref<expr> const & fvars, name const & mid_pending,
                       expr const & e, buffer<expr> & args) {
        expr const * curr = &e;
        while (is_app(*curr)) {
            args.push_back(visit(app_arg(*curr)));
            curr = &app_fn(*curr);
        }

        size_t fvar_count = fvars.size();
        size_t extra_count = args.size() - fvar_count;

        /* Save and extend the fvar substitution.
           The substitution values are the (already visited) args at indices
           [args.size()-1 .. args.size()-fvar_count] (reversed, since args is built in reverse). */
        struct saved_entry { lean_object * key; bool had_old; fvar_subst_entry old; };
        std::vector<saved_entry> saved_entries;
        saved_entries.reserve(fvar_count);
        for (size_t i = 0; i < fvar_count; i++) {
            name const & fid = fvar_name(fvars[i]);
            auto old_it = m_fvar_subst.find(fid.raw());
            if (old_it != m_fvar_subst.end()) {
                saved_entries.push_back({fid.raw(), true, old_it->second});
            } else {
                saved_entries.push_back({fid.raw(), false, {0, expr()}});
            }
            /* args is reversed: args[args.size()-1] corresponds to the first argument.
               fvars[i] should be mapped to the i-th argument, which is
               args[args.size() - 1 - i]. */
            m_fvar_subst[fid.raw()] = {m_depth, args[args.size() - 1 - i]};
        }

        /* Visit ?pending with the extended substitution */
        expr val_new = visit(mk_mvar(mid_pending));

        /* Restore the fvar substitution */
        for (size_t i = 0; i < saved_entries.size(); i++) {
            if (!saved_entries[i].had_old) {
                m_fvar_subst.erase(saved_entries[i].key);
            } else {
                m_fvar_subst[saved_entries[i].key] = saved_entries[i].old;
            }
        }

        /* Apply the extra arguments */
        return mk_rev_app(val_new, extra_count, args.data());
    }

    expr visit_app(expr const & e) {
        expr const & f = get_app_fn(e);
        if (!is_mvar(f)) {
            return visit_app_default(e);
        } else {
            name const & mid = mvar_name(f);
            /* Regular assignments take precedence over delayed ones. */
            if (auto f_new = get_assignment(mid)) {
                buffer<expr> args;
                if (is_lambda(*f_new)) {
                    return visit_args_and_beta(*f_new, e, args);
                } else {
                    /* Visit args and rebuild */
                    expr const * curr = &e;
                    while (is_app(*curr)) {
                        args.push_back(visit(app_arg(*curr)));
                        curr = &app_fn(*curr);
                    }
                    return mk_rev_app(*f_new, args.size(), args.data());
                }
            }
            option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
            if (!d) {
                return visit_mvar_app_args(e);
            }
            array_ref<expr> fvars(cnstr_get(d.get_val().raw(), 0), true);
            name mid_pending(cnstr_get(d.get_val().raw(), 1), true);
            if (fvars.size() > get_app_num_args(e)) {
                return visit_mvar_app_args(e);
            }
            /* Unlike the standard version, we always attempt to instantiate
               the delayed assignment by extending our fvar substitution. */
            buffer<expr> args;
            return visit_delayed(fvars, mid_pending, e, args);
        }
    }

    expr visit_mvar(expr const & e) {
        name const & mid = mvar_name(e);
        if (auto r = get_assignment(mid)) {
            return *r;
        } else {
            return e;
        }
    }

    expr visit_fvar(expr const & e) {
        name const & fid = fvar_name(e);
        if (auto r = lookup_fvar(fid)) {
            return *r;
        }
        return e;
    }

public:
    instantiate_mvars_no_update_fn(metavar_ctx & mctx)
        : m_mctx(mctx), m_level_fn(mctx), m_depth(0) {}

    expr visit(expr const & e) {
        if (!has_mvar(e) && !has_fvar(e))
            return e;

        /* If the expression has no FVars, the result is independent of the current
           binder depth and fvar substitution, so we can use the global cache. */
        bool use_global = !has_fvar(e);
        bool shared = false;
        if (is_shared(e)) {
            if (use_global) {
                auto it = m_global_cache.find(e.raw());
                if (it != m_global_cache.end())
                    return it->second;
            } else {
                auto it = m_cache.find(e.raw());
                if (it != m_cache.end())
                    return it->second;
            }
            shared = true;
        }

        expr r;
        switch (e.kind()) {
        case expr_kind::BVar:
        case expr_kind::Lit:
            lean_unreachable();
        case expr_kind::FVar:
            return visit_fvar(e);
        case expr_kind::Sort:
            r = update_sort(e, visit_level(sort_level(e)));
            break;
        case expr_kind::Const:
            r = update_const(e, visit_levels(const_levels(e)));
            break;
        case expr_kind::MVar:
            return visit_mvar(e);
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
            /* Clear depth-dependent cache and bump depth for the body */
            lean::unordered_map<lean_object *, expr> saved_cache;
            saved_cache.swap(m_cache);
            m_depth++;
            expr b = visit(binding_body(e));
            m_depth--;
            saved_cache.swap(m_cache);
            r = update_binding(e, d, b);
            break;
        }
        case expr_kind::Let: {
            expr t = visit(let_type(e));
            expr v = visit(let_value(e));
            lean::unordered_map<lean_object *, expr> saved_cache;
            saved_cache.swap(m_cache);
            m_depth++;
            expr b = visit(let_body(e));
            m_depth--;
            saved_cache.swap(m_cache);
            r = update_let(e, t, v, b);
            break;
        }
        }
        if (shared) {
            if (use_global)
                m_global_cache.insert(mk_pair(e.raw(), r));
            else
                m_cache.insert(mk_pair(e.raw(), r));
        }
        return r;
    }

    expr operator()(expr const & e) { return visit(e); }
};

extern "C" LEAN_EXPORT object * lean_instantiate_expr_mvars_no_update(object * m, object * e) {
    metavar_ctx mctx(m);
    expr e_new = instantiate_mvars_no_update_fn(mctx)(expr(e));
    object * r = alloc_cnstr(0, 2, 0);
    cnstr_set(r, 0, mctx.steal());
    cnstr_set(r, 1, e_new.steal());
    return r;
}
}
