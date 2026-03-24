import Init.Tactics

/-!
# Tests of the @[symm] attribute and `symm` tactic

See also `tests/elab/relationAttrs.lean`
-/

set_option autoImplicit true
set_option linter.missingDocs false
-- For testing:
--set_option trace.Meta.Tactic.relation true

/-! Basic tests of symmetry for `Eq`. -/
/--
trace: a b : Nat
a✝ : a = b
⊢ a = b
-/
#guard_msgs in
example (a b : Nat) : a = b → b = a := by intros; symm; trace_state; assumption
/--
trace: a b : Nat
h : b = a
a✝ : True
⊢ b = a
-/
#guard_msgs in
example (a b : Nat) : a = b → True → b = a := by intro h _; symm at h; trace_state; assumption

/-! Basic tests of symmetry for `Iff`. -/
/--
trace: a b : Prop
a✝ : a ↔ b
⊢ a ↔ b
-/
#guard_msgs in
example (a b : Prop) : (a ↔ b) → (b ↔ a) := by intros; symm; trace_state; assumption
/--
trace: a b : Prop
h : b ↔ a
a✝ : True
⊢ b ↔ a
-/
#guard_msgs in
example (a b : Prop) : (a ↔ b) → True → (b ↔ a) := by intro h _; symm at h; trace_state; assumption

/-! Basic tests of symmetry for `Eq`. -/
/--
trace: α β : Type u
a : α
b : β
a✝ : a ≍ b
⊢ a ≍ b
-/
#guard_msgs in
example {α β : Type u} (a : α) (b : β) : a ≍ b → b ≍ a := by intros; symm; trace_state; assumption
/--
trace: α β : Type u
a : α
b : β
h : b ≍ a
a✝ : True
⊢ b ≍ a
-/
#guard_msgs in
example {α β : Type u} (a : α) (b : β) : a ≍ b → True → b ≍ a := by intro h _; symm at h; trace_state; assumption

/-! Basic tests with a custom relation. -/
def sameParity : Nat → Nat → Prop
  | n, m => n % 2 = m % 2

@[symm] def sameParity_symm (n m : Nat) : sameParity n m → sameParity m n := Eq.symm

example (a b : Nat) : sameParity a b → sameParity b a := by intros; symm; assumption

/-! Basic tests with a custom relation. -/
def MyEq (n m : Nat) := ∃ k, n + k = m ∧ m + k = n

@[symm] theorem MyEq.symm {n m : Nat} (h : MyEq n m) : MyEq m n := by
  rcases h with ⟨k, h1, h2⟩
  exact ⟨k, h2, h1⟩

/--
trace: n m : Nat
h : MyEq n m
⊢ MyEq n m
-/
#guard_msgs in
example {n m : Nat} (h : MyEq n m) : MyEq m n := by
  symm
  trace_state
  assumption

/--
trace: n m : Nat
h : MyEq m n
⊢ MyEq m n
-/
#guard_msgs in
example {n m : Nat} (h : MyEq n m) : MyEq m n := by
  symm at h
  trace_state
  assumption

/-! Contraposition -/
/--
trace: n m : Nat
h : ¬MyEq n m
⊢ ¬MyEq n m
-/
#guard_msgs in
theorem MyEq.nsymm {n m : Nat} (h : ¬ MyEq n m) : ¬ MyEq m n := by
  symm
  trace_state
  exact h

/-- info: 'MyEq.nsymm' does not depend on any axioms -/
#guard_msgs in #print axioms MyEq.nsymm

/-! Contraposition at a local hypothesis -/
/--
trace: n m : Nat
h : ¬MyEq m n
⊢ ¬MyEq m n
-/
#guard_msgs in
theorem MyEq.nsymm' {n m : Nat} (h : ¬ MyEq n m) : ¬ MyEq m n := by
  symm at h
  trace_state
  exact h

/-- info: 'MyEq.nsymm'' does not depend on any axioms -/
#guard_msgs in #print axioms MyEq.nsymm'


/-! Unfolding abbreviations -/
abbrev MyNEq (n m : Nat) := ¬ MyEq m n

/--
trace: n m : Nat
h : MyNEq n m
⊢ ¬MyEq m n
-/
#guard_msgs in
example {n m : Nat} (h : MyNEq n m) : MyNEq m n := by
  symm
  trace_state
  exact h

/--
trace: n m : Nat
h : ¬MyEq n m
⊢ MyNEq m n
-/
#guard_msgs in
example {n m : Nat} (h : MyNEq n m) : MyNEq m n := by
  symm at h
  trace_state
  exact h
