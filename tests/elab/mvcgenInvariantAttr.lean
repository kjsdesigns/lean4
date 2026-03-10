import Std.Tactic.Do
import Std
set_option backward.do.legacy false

open Std Do

set_option grind.warning false
set_option mvcgen.warning false

-- Test that existing `Std.Do.Invariant` behavior is preserved (via hard-coded fallback).
-- This is the same as a test in `mvcgenInvariantsWith.lean` to verify no regression.
def nodup (l : List Int) : Bool := Id.run do
  let mut seen : HashSet Int := ∅
  for x in l do
    if x ∈ seen then
      return false
    seen := seen.insert x
  return true

theorem nodup_correct (l : List Int) : nodup l ↔ l.Nodup := by
  generalize h : nodup l = r
  apply Id.of_wp_run_eq h
  mvcgen invariants
  · Invariant.withEarlyReturn
      (onReturn := fun ret seen => ⌜ret = false ∧ ¬l.Nodup⌝)
      (onContinue := fun traversalState seen =>
        ⌜(∀ x, x ∈ seen ↔ x ∈ traversalState.prefix) ∧ traversalState.prefix.Nodup⌝)
  all_goals grind

-- Test that `@[mvcgen_invariant_type]` can be applied.
@[mvcgen_invariant_type]
abbrev MyInvariant {α : Type u₁} (xs : List α) (β : Type u₂) (ps : PostShape.{max u₁ u₂}) :=
  PostCond (List.Cursor xs × β) ps
