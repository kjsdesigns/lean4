/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/

import Radix.Eval.Stmt

/-! # Memory Safety

Theorem statements about heap safety: no use-after-free, no double-free,
bounds-checked array access.
-/

namespace Radix

/-- A heap is well-formed if all addresses in the environment point to
    live allocations. -/
def Heap.wellFormed (h : Heap) (liveAddrs : List Addr) : Prop :=
  ∀ a ∈ liveAddrs, h.lookup a ≠ none

/-- No use-after-free: if an address has been freed, subsequent access fails. -/
theorem Heap.no_use_after_free (h : Heap) (a : Addr)
    (hfree : h.free a = some h') :
    h'.lookup a = none := by
  sorry

/-- No double-free: freeing an already-freed address fails. -/
theorem Heap.no_double_free (h : Heap) (a : Addr)
    (hfree : h.free a = some h') :
    h'.free a = none := by
  sorry

/-- Bounds safety: array reads within bounds succeed. -/
theorem Heap.read_within_bounds (h : Heap) (a : Addr) (i : Nat)
    (hlookup : h.lookup a = some arr)
    (hbounds : i < arr.size) :
    ∃ v, h.read a i = some v := by
  sorry

end Radix
