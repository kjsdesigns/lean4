/-!
# Tests of relation-related attributes
-/

set_option trace.Meta.Tactic.relation true
set_option warn.sorry false

/-!
## @[relation] attribute
-/

/-!
Infer lhs and rhs
-/
/--
trace: [Meta.Tactic.relation] Relation `MyIff1` has 2 arguments. The first 0 argument(s) identify the relation. The lhs and rhs are argument numbers 1 and 2.
-/
#guard_msgs in
@[relation]
def MyIff1 (p q : Prop) : Prop := p ↔ q

/-!
Provide lhs and rhs
-/
/--
trace: [Meta.Tactic.relation] Relation `MyIff2` has 2 arguments. The first 0 argument(s) identify the relation. The lhs and rhs are argument numbers 1 and 2.
-/
#guard_msgs in
@[relation p q]
def MyIff2 (p q : Prop) : Prop := p ↔ q

/-!
Provide lhs and rhs using indices, this time in reverse order
-/
/--
trace: [Meta.Tactic.relation] Relation `MyIff3` has 2 arguments. The first 0 argument(s) identify the relation. The lhs and rhs are argument numbers 2 and 1.
-/
#guard_msgs in
@[relation 2 1]
def MyIff3 (p q : Prop) : Prop := p ↔ q

/-!
Checks that the relation hasn't already been registered
-/
/-- error: The relation `MyIff1` has already been registered -/
#guard_msgs in
attribute [relation] MyIff1

/-!
Checks that must have exactly two arguments, and they can't be same
-/
def MyIff4 (p q : Prop) : Prop := p ↔ q
/-- error: Must have exactly two arguments if arguments are provided -/
#guard_msgs in
attribute [relation p] MyIff4
/-- error: Must have exactly two arguments if arguments are provided -/
#guard_msgs in
attribute [relation p q p] MyIff4
/-- error: Invalid argument name `p`: It has already been specified as an argument -/
#guard_msgs in
attribute [relation p p] MyIff4
/--
error: Invalid argument index `1`: The argument at this index (`p`) has already been specified as an argument
-/
#guard_msgs in
attribute [relation 1 1] MyIff4

/-!
Inference fails for non-relations
-/
/-- error: Invalid relation: `IsZero` does not have at least two explicit arguments -/
#guard_msgs in
@[relation]
def IsZero (n : Nat) : Prop := n = 0

/-!
The @[relation] attribute takes the *last* two explicit arguments by default.
-/
/--
trace: [Meta.Tactic.relation] Relation `ModEq` has 3 arguments. The first 1 argument(s) identify the relation. The lhs and rhs are argument numbers 2 and 3.
-/
#guard_msgs in
@[relation]
def ModEq (n : Int) (a b : Int) : Prop := (a - b) % n == 0

/-!
## @[refl] attribute
-/

/-!
The @[refl] attribute can auto-register relations.
-/
inductive MyEq1 {α : Sort _} : α → α → Prop where
  | rfl (x : α) : MyEq1 x x
/--
trace: [Meta.Tactic.relation] ✅️ adding [refl] lemma `MyEq1.rfl`
  [Meta.Tactic.relation] ✅️ Unknown relation, inferring [relation] for `MyEq1`.
    [Meta.Tactic.relation] Relation `MyEq1` has 3 arguments. The first 1 argument(s) identify the relation. The lhs and rhs are argument numbers 2 and 3.
-/
#guard_msgs in
attribute [refl] MyEq1.rfl

/-!
The @[refl] attribute also supports pre-registered relations.
Here's a relation with reversed argumnents.
-/
inductive MyEq2 {α : Sort _} : α → α → Prop where
  | rfl (x : α) : MyEq2 x x
/--
trace: [Meta.Tactic.relation] Relation `MyEq2` has 3 arguments. The first 1 argument(s) identify the relation. The lhs and rhs are argument numbers 3 and 2.
-/
#guard_msgs in
attribute [relation 3 2] MyEq2
/-- trace: [Meta.Tactic.relation] ✅️ adding [refl] lemma `MyEq2.rfl` -/
#guard_msgs in
attribute [refl] MyEq2.rfl

/-!
The @[refl] attribute checks whether the lemma proves something reflexive.
-/

theorem ModEq.symm (n a b : Int) (h : ModEq n b a) : ModEq n a b := sorry

/--
error: `[refl]` attribute only applies to lemmas concluding with `x ∼ x`, but the left-hand side
  a
is not definitionally equal to the right-hand side
  b
---
trace: [Meta.Tactic.relation] 💥️ adding [refl] lemma `ModEq.symm`
-/
#guard_msgs in
attribute [refl] ModEq.symm

/-!
The @[refl] attribute checks applicability of the lemma.
-/

/--
error: `[refl]` lemma has unsolved goals when applied to its own conclusion
case h
n a : Int
h : n > 0
⊢ n > 0
---
trace: [Meta.Tactic.relation] 💥️ adding [refl] lemma `rfl_bad`
-/
#guard_msgs in
@[refl]
theorem ModEq.rfl_bad (n a : Int) (h : n > 0) : ModEq n a a := sorry


/-!
## @[symm] attribute
-/

/-!
Validates that the conclusion is a constant application
-/
/--
error: `[symm]` attribute only applies to lemmas proving `x ∼ y → y ~ x`, where the relation is a constant application, but the relation is not a constant application: `Type`
---
trace: [Meta.Tactic.relation] 💥️ adding [symm] lemma `symm_bad1`
-/
#guard_msgs in
@[symm] def symm_bad1 : Type := Nat

/-!
The @[symm] attribute can auto-register relations.
-/
inductive MyEq3 {α : Sort _} : α → α → Prop where
  | rfl (x : α) : MyEq3 x x
def MyEq3.symm {α} (x y : α) : MyEq3 x y → MyEq3 y x
  | .rfl _ => .rfl _
/--
trace: [Meta.Tactic.relation] ✅️ adding [symm] lemma `MyEq3.symm`
  [Meta.Tactic.relation] ✅️ Unknown relation, inferring [relation] for `MyEq3`.
    [Meta.Tactic.relation] Relation `MyEq3` has 3 arguments. The first 1 argument(s) identify the relation. The lhs and rhs are argument numbers 2 and 3.
-/
#guard_msgs in
attribute [symm] MyEq3.symm

/-!
The @[refl] attribute also supports pre-registered relations.
Here's a relation with reversed argumnents.
-/
inductive MyEq4 {α : Sort _} : α → α → Prop where
  | rfl (x : α) : MyEq4 x x
def MyEq4.symm {α} (x y : α) : MyEq4 x y → MyEq4 y x
  | .rfl _ => .rfl _
/--
trace: [Meta.Tactic.relation] Relation `MyEq4` has 3 arguments. The first 1 argument(s) identify the relation. The lhs and rhs are argument numbers 3 and 2.
-/
#guard_msgs in
attribute [relation 3 2] MyEq4
/-- trace: [Meta.Tactic.relation] ✅️ adding [symm] lemma `MyEq4.symm` -/
#guard_msgs in
attribute [symm] MyEq4.symm

/-!
The @[symm] attribute checks whether the lemma proves something symmetric-like.
-/

/-- trace: [Meta.Tactic.relation] ✅️ adding [symm] lemma `ModEq.symm` -/
#guard_msgs in attribute [symm] ModEq.symm

/--
error: `[symm]` attribute only applies to lemmas proving `x ~ y → y ∼ x`, but the conclusion's left-hand side
  a
is not definitionally equal to the hypothesis's right-hand side
  b
---
trace: [Meta.Tactic.relation] 💥️ adding [symm] lemma `symm_bad`
-/
#guard_msgs in @[symm] theorem ModEq.symm_bad (n a b : Int) (h : ModEq n a b) : ModEq n a b := sorry

/--
error: `[symm]` attribute only applies to lemmas proving `x ~ y → y ∼ x`, but the conclusion's right-hand side
  b
is not definitionally equal to the hypothesis's left-hand side
  a
---
trace: [Meta.Tactic.relation] 💥️ adding [symm] lemma `symm_bad'`
-/
#guard_msgs in @[symm] theorem ModEq.symm_bad' (n a b : Int) (h : ModEq n a a) : ModEq n a b := sorry

/-!
The @[symm] attribute doesn't check that the lemma is morally symmetric.
-/

/-- trace: [Meta.Tactic.relation] ✅️ adding [symm] lemma `symm_questionable` -/
#guard_msgs in @[symm] theorem ModEq.symm_questionable (n a : Int) (h : ModEq n a a) : ModEq n a a := sorry

/-!
The @[symm] attribute checks applicability of the lemma.
-/

/--
error: `[symm]` lemma has unsolved goals when applied to its own conclusion
case h
n a b : Int
h : n > 0
h' : ModEq n b a
⊢ n > 0
---
trace: [Meta.Tactic.relation] 💥️ adding [symm] lemma `symm_bad2`
-/
#guard_msgs in
@[symm]
theorem ModEq.symm_bad2 (n a b : Int) (h : n > 0) (h' : ModEq n b a) : ModEq n a b := sorry
