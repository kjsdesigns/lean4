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
#include "kernel/replace_fn.h"
#include "kernel/expr.h"

/*
This module provides an efficient C++ implementation of `instantiateAllMVars`.

Like `instantiateMVarsNoUpdate`, this variant carries a substitution of free
variables as it traverses delayed-assigned metavariables. However, unlike that
variant, when it encounters an unassigned metavariable under an active fvar
substitution, it simply fails (returning `none`) instead of calling the
expensive `elimMVarDeps` / `abstract_mvar_fvars` machinery.

Use this at call sites where all mvars are known to be assigned. A failure
indicates a wrong assumption about the call site.
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

/* Level metavariable instantiation -- same as in instantiate_mvars_no_update.cpp. */
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

struct fvar_subst_entry {
    unsigned depth;
    expr     value;
};

class instantiate_mvars_all_fn {
    metavar_ctx & m_mctx;
    instantiate_lmvars_all_fn m_level_fn;
    name_hash_map<fvar_subst_entry> m_fvar_subst;
    unsigned m_depth;
    lean::unordered_map<lean_object *, expr> m_cache;
    lean::unordered_map<lean_object *, expr> m_global_cache;
    std::vector<expr> m_saved;
    name_set m_already_normalized;
    bool m_failed = false;

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

    optional<expr> lookup_fvar(name const & fid) {
        auto it = m_fvar_subst.find(fid);
        if (it == m_fvar_subst.end())
            return optional<expr>();
        unsigned d = m_depth - it->second.depth;
        if (d == 0)
            return optional<expr>(it->second.value);
        return optional<expr>(lift_loose_bvars(it->second.value, d));
    }

    optional<expr> get_assignment(name const & mid) {
        option_ref<expr> r = get_mvar_assignment(m_mctx, mid);
        if (!r)
            return optional<expr>();
        expr a(r.get_val());
        if (fvar_subst_empty()) {
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
        } else {
            if (!has_mvar(a) && !has_fvar(a)) {
                return optional<expr>(a);
            }
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

        struct saved_entry { name key; bool had_old; fvar_subst_entry old; };
        std::vector<saved_entry> saved_entries;
        saved_entries.reserve(fvar_count);
        for (size_t i = 0; i < fvar_count; i++) {
            name const & fid = fvar_name(fvars[i]);
            auto old_it = m_fvar_subst.find(fid);
            if (old_it != m_fvar_subst.end()) {
                saved_entries.push_back({fid, true, old_it->second});
            } else {
                saved_entries.push_back({fid, false, {0, expr()}});
            }
            m_fvar_subst[fid] = {m_depth, args[args.size() - 1 - i]};
        }

        lean::unordered_map<lean_object *, expr> saved_cache;
        saved_cache.swap(m_cache);
        expr val_new = visit(mk_mvar(mid_pending));
        saved_cache.swap(m_cache);

        for (auto & se : saved_entries) {
            if (!se.had_old) {
                m_fvar_subst.erase(se.key);
            } else {
                m_fvar_subst[se.key] = se.old;
            }
        }

        return mk_rev_app(val_new, extra_count, args.data());
    }

    expr visit_app(expr const & e) {
        expr const & f = get_app_fn(e);
        if (!is_mvar(f)) {
            return visit_app_default(e);
        } else {
            name const & mid = mvar_name(f);
            if (auto f_new = get_assignment(mid)) {
                buffer<expr> args;
                return visit_args_and_beta(*f_new, e, args);
            }
            option_ref<delayed_assignment> d = get_delayed_mvar_assignment(m_mctx, mid);
            if (!d) {
                if (!fvar_subst_empty()) {
                    /* Unassigned mvar under active fvar substitution -- fail */
                    m_failed = true;
                    return e;
                }
                return visit_mvar_app_args(e);
            }
            array_ref<expr> fvars(cnstr_get(d.get_val().raw(), 0), true);
            name mid_pending(cnstr_get(d.get_val().raw(), 1), true);
            if (fvars.size() > get_app_num_args(e)) {
                if (!fvar_subst_empty()) {
                    m_failed = true;
                    return e;
                }
                return visit_mvar_app_args(e);
            }
            if (fvar_subst_empty()) {
                optional<expr> pending_val = get_assignment(mid_pending);
                if (!pending_val || has_expr_mvar(*pending_val))
                    return visit_mvar_app_args(e);
            }
            buffer<expr> args;
            return visit_delayed(fvars, mid_pending, e, args);
        }
    }

    expr visit_mvar(expr const & e) {
        name const & mid = mvar_name(e);
        if (auto r = get_assignment(mid)) {
            return *r;
        } else if (fvar_subst_empty()) {
            return e;
        } else {
            /* Unassigned mvar under active fvar substitution -- fail */
            m_failed = true;
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
    instantiate_mvars_all_fn(metavar_ctx & mctx)
        : m_mctx(mctx), m_level_fn(mctx), m_depth(0) {}

    bool failed() const { return m_failed; }

    expr visit(expr const & e) {
        if (m_failed) return e;

        if (fvar_subst_empty()) {
            if (!has_mvar(e))
                return e;
        } else {
            if (!has_mvar(e) && !has_fvar(e))
                return e;
        }

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
        if (m_failed) return e;
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

extern "C" LEAN_EXPORT object * lean_instantiate_expr_mvars_all(object * m, object * e) {
    metavar_ctx mctx(m);
    instantiate_mvars_all_fn fn(mctx);
    expr e_new = fn(expr(e));
    if (fn.failed()) {
        return box(0); /* none */
    }
    /* some (mctx, expr) */
    object * pair = alloc_cnstr(0, 2, 0);
    cnstr_set(pair, 0, mctx.steal());
    cnstr_set(pair, 1, e_new.steal());
    object * r = alloc_cnstr(1, 1, 0);
    cnstr_set(r, 0, pair);
    return r;
}
}
