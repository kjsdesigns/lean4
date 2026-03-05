/*
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Authors: Joachim Breitner
*/
#pragma once
#include <deque>
#include <vector>
#include "util/alloc.h"
#include "runtime/optional.h"

namespace lean {

/*
A scope-aware cache for use in traversals that carry a substitution
through nested scopes (e.g., delayed mvar resolution).

Supports push/pop of scopes and caches Key → Value results.
Each scope gets a unique generation number. Cache entries store a
single snapshot of the scope generation list (a persistent linked
list) at insert time. On lookup, entries are lazily degraded by
walking the snapshot and current lists in lockstep, evicting entries
whose result depends on popped or re-entered scopes.

The caller maintains a `result_scope` watermark: the maximum scope
level that contributed to a cached result. On insert, the caller
provides its `result_scope`; on lookup hit, the stored `result_scope`
is propagated back via a reference parameter.
*/
template<typename Key, typename Value, typename Hash = std::hash<Key>>
class scope_cache {
    struct scope_gen_node {
        unsigned gen;
        scope_gen_node * tail; /* parent scope, or nullptr for scope -1 */
    };

    struct cache_entry {
        Value result;
        unsigned scope_level;       /* scope at which this entry is (currently) valid */
        scope_gen_node * scope_gens; /* snapshot of scope_gens list at store time */
        unsigned result_scope;      /* maximum scope that contributed to the result */
    };

    typedef lean::unordered_map<Key, std::vector<cache_entry>, Hash> cache_map;

    cache_map m_cache;
    std::deque<scope_gen_node> m_gen_arena;
    scope_gen_node * m_scope_gens_list;
    unsigned m_gen_counter;
    unsigned m_scope;

public:
    scope_cache() : m_scope_gens_list(nullptr), m_gen_counter(0), m_scope(0) {
        m_gen_arena.push_back({0, nullptr});
        m_scope_gens_list = &m_gen_arena.back();
    }

    unsigned scope() const { return m_scope; }

    /* Enter a new scope. Bumps the generation counter so that stale
       entries at the new scope level are detected on lookup. */
    void push() {
        m_scope++;
        m_gen_counter++;
        m_gen_arena.push_back({m_gen_counter, m_scope_gens_list});
        m_scope_gens_list = &m_gen_arena.back();
    }

    /* Leave the current scope. Follows the tail of the persistent
       generation list back to the parent scope. */
    void pop() {
        m_scope--;
        m_scope_gens_list = m_scope_gens_list->tail;
    }

    /* Lazily clean up the top of a per-key entry stack: degrade entries
       whose scopes were popped and evict entries that are stale due to
       popped result scopes or scope re-entry.  After rewind, either the
       stack is empty or its top entry satisfies scope_level <= m_scope
       with a matching scope generation. */
    void rewind(std::vector<cache_entry> & stack) {
        while (!stack.empty()) {
            auto & top = stack.back();
            /* Discard entries whose result depends on popped scopes. */
            if (top.result_scope > m_scope) {
                stack.pop_back();
                continue;
            }
            /* Degrade: follow tail pointers for scopes that were popped. */
            while (top.scope_level > m_scope) {
                top.scope_gens = top.scope_gens->tail;
                top.scope_level--;
            }
            /* scope_level < m_scope: entry is at a lower scope, stop. */
            if (top.scope_level < m_scope) return;
            /* scope_level == m_scope: check generation. */
            if (top.scope_gens->gen == m_scope_gens_list->gen) return;
            /* Generation mismatch: scope was re-entered. Walk both lists
               in lockstep to find a valid level or exhaust to result_scope. */
            scope_gen_node * entry_node = top.scope_gens;
            scope_gen_node * current_node = m_scope_gens_list;
            unsigned level = top.scope_level;
            while (level > top.result_scope) {
                entry_node = entry_node->tail;
                current_node = current_node->tail;
                level--;
                if (entry_node->gen == current_node->gen) {
                    top.scope_level = level;
                    top.scope_gens = entry_node;
                    return; /* now scope_level < m_scope */
                }
            }
            /* No valid level found → discard. */
            stack.pop_back();
        }
    }

    /* Look up a cached result for the given key at the current scope.
       On hit, updates `result_scope = max(result_scope, entry.result_scope)`
       and returns the cached result. On miss, returns none. */
    optional<Value> lookup(Key const & key, unsigned & result_scope) {
        auto it = m_cache.find(key);
        if (it == m_cache.end()) return {};
        auto & stack = it->second;
        rewind(stack);
        if (stack.empty()) return {};
        auto & top = stack.back();
        if (top.scope_level != m_scope) return {};
        result_scope = std::max(result_scope, top.result_scope);
        return optional<Value>(top.result);
    }

    /* Insert a result for the given key at the current scope.
       `result_scope` is the maximum scope that contributed to the result;
       the entry is only valid when all scopes up to result_scope are unchanged.
       If a valid entry with the same `result_scope` already exists, its value
       is reused for sharing; the returned reference is the stored value. */
    Value const & insert(Key const & key, Value const & result, unsigned result_scope) {
        auto & stack = m_cache[key];
        rewind(stack);
        Value shared = result;
        if (!stack.empty() && stack.back().result_scope == result_scope) {
            shared = stack.back().result;
        }
        while (!stack.empty() && stack.back().scope_level >= result_scope) {
            stack.pop_back();
        }
        stack.push_back({std::move(shared), m_scope, m_scope_gens_list, result_scope});
        return stack.back().result;
    }
};

}
