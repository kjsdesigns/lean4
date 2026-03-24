
/-!
# Tests of `lift_rfl`

This file tests the `lift_rfl` tactic, a frontend to the `Lean.MVarId.liftReflToEq` meta tactic.
-/

-- For debugging:
-- set_option trace.Meta.Tactic.relation true

set_option pp.mvars.levels false
set_option warn.sorry false

/-! It is an error if it's already an equality. -/
/--
error: Tactic `liftReflToEq` failed: Goal is already an equality

⊢ false = true
-/
#guard_msgs in
example : false = true := by
  lift_rfl

/-! Unfolding abbrevations counts as progress, even if it's an equality. -/
abbrev RevEq {α} (x y : α) := y = x
/-- trace: ⊢ true = false -/
#guard_msgs in
example : RevEq false true := by
  lift_rfl
  trace_state
  sorry

/-! HEq is converted to Eq, if possible. -/
/-- trace: ⊢ false = true -/
#guard_msgs in
example : false ≍ true := by
  lift_rfl
  trace_state
  sorry

/-! If HEq can't be converted, that's an error, since no progress is made. -/
/--
error: Tactic `liftReflToEq` failed: The left-hand side's type
  Bool
is not definitionally equal to the right-hand side's type
  Nat

⊢ false ≍ 2
-/
#guard_msgs in
example : false ≍ 2 := by
  lift_rfl

/-!
Type with reflexivity lemma
-/
inductive MyEq {α : Sort _} : α → α → Prop where
  | rfl (x : α) : MyEq x x
attribute [refl] MyEq.rfl

/-- trace: ⊢ false = true -/
#guard_msgs in
example : MyEq false true := by
  lift_rfl
  trace_state
  sorry

/-!
Heterogenous reflexivity, types first.
-/
inductive MyHEq1 : {α β : Sort _} → α → β → Prop where
  | rfl {α} (x : α) : MyHEq1 x x
attribute [refl] MyHEq1.rfl

-- Lift to eq
/-- trace: ⊢ false = true -/
#guard_msgs in
example : MyHEq1 false true := by
  lift_rfl
  trace_state
  sorry

-- Lift to HEq
/-- trace: ⊢ false ≍ 2 -/
#guard_msgs in
example : MyHEq1 false 2 := by
  lift_rfl
  trace_state
  sorry

/-!
Heterogenous reflexivity, types interlaced.
-/
inductive MyHEq2 : {α : Sort _} → α → {β : Sort _} → β → Prop where
  | rfl {α} (x : α) : MyHEq2 x x
attribute [refl] MyHEq2.rfl

-- Lift to eq
/-- trace: ⊢ false = true -/
#guard_msgs in
example : MyHEq2 false true := by
  lift_rfl
  trace_state
  sorry

-- Lift to HEq
/-- trace: ⊢ false ≍ 2 -/
#guard_msgs in
example : MyHEq2 false 2 := by
  lift_rfl
  trace_state
  sorry

/-!
Relation with proof obligations
-/
@[relation m n]
def PosEq (m : Nat) (_ : m > 0) (n : Nat) (_ : n > 0) := m - n = n - m
@[refl] theorem PosEq.rfl (m : Nat) (h : m > 0) : PosEq m h m h := Eq.refl (m - m)

/--
trace: m : Nat
hm : m > 0
n : Nat
hn : n > 0
⊢ m = n
-/
#guard_msgs in
example (m : Nat) (hm : m > 0) (n : Nat) (hn : n > 0) : PosEq m hm n hn := by
  lift_rfl
  trace_state
  sorry

/-!
Typeclasses are not currently supported.
-/
structure DecEquiv (α : Type u) (β : Type v) [DecidableEq α] [DecidableEq β] where
  toFun : α → β
  invFun : β → α
@[refl] def DecEquiv.rfl (α : Type _) [DecidableEq α] : DecEquiv α α where
  toFun := id
  invFun := id
/--
error: Failed rewrite relation
  DecEquiv (Fin n) (Fin m)
to be reflexive. Unsolved goals
case e_4
m n : Nat
⊢ instDecidableEqFin n ≍ instDecidableEqFin m
-/
#guard_msgs in
example (m : Nat) (n : Nat) : DecEquiv (Fin n) (Fin m) := by
  lift_rfl
