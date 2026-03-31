-- Un-indented tactic after top-level `by` parses as empty `by` (unsolved goals)
-- followed by a command parse error for the stray tactic.
theorem byTopLevelBad (n : Nat) (h : n > 1) : n > 1 := by
exact h -- unsolved goals + unexpected identifier

-- Nested `by` without indentation: inner `by` is empty, `sorry` continues in outer scope.
theorem byNestedStrictIndent (n : Nat) (h : n > 0) : n > 1 := by
  have helper : n > 1 := by
  sorry -- part of outer `by`; inner `by` is empty (unsolved goals)
  sorry

--
theorem byNestedBad₁ (n : Nat) (h : n > 0) : n > 1 := by
  have helper : n > 1 := by
    sorry
   sorry -- expected command
  sorry

theorem byNestedBad₂ (n : Nat) (h : n > 0) : n > 1 := by
  have helper : n > 1 := by
    sorry
      sorry -- expected command
  sorry

-- When stacking multiple `by` invocations on one line, the indentation of the
-- tactic block is checked against the innermost `withPosition` point (the column
-- of the innermost `have`/`let`/etc.), not against the outermost `by`.
-- So indenting past the outer `by` is not enough if the inner `have` is further right.

-- Good: each tactic block is indented past its respective `have`
theorem byStackedGood : True := by
  have : True := by
    exact trivial
  exact this

-- Bad: tactic is indented past the outer `by` (column 0) but not past `have` (column 27)
-- Inner `by` is empty (unsolved goals), stray tactics produce command parse errors.
theorem byStackedBad₁ : True := by have : True := by
  exact trivial -- unsolved goals + unexpected identifier
  exact this

-- Bad: same issue with deeper stacking
theorem byStackedBad₂ : True := by have : True := by have : True := by
  exact trivial -- unsolved goals + unexpected identifier
  exact this
