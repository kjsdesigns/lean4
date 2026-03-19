-- Test that structural recursion with named _f helper works for complex cases
set_option linter.unusedVariables false

def foo (xs ys zs : List Nat) : List Nat :=
  match (xs, ys) with
  | (xs', ys')   =>
    match zs with
    | z::zs => foo xs ys zs
    | _ => match ys' with
     | [] => [1]
     | _  => [2]

-- foo._f should exist
/-- info: foo._f : List Nat → List Nat → (zs : List Nat) → List.below zs → List Nat -/
#guard_msgs in #check @foo._f

-- Equation theorems should work
/--
info: foo.eq_def : ∀ (xs ys zs : List Nat),
  foo xs ys zs =
    match (xs, ys) with
    | (xs', ys') =>
      match zs with
      | z :: zs => foo xs ys zs
      | x =>
        match ys' with
        | [] => [1]
        | x => [2]
-/
#guard_msgs in #check @foo.eq_def

/-- info: foo.eq_1 : ∀ (xs ys : List Nat) (z : Nat) (zs_2 : List Nat), foo xs ys (z :: zs_2) = foo xs ys zs_2 -/
#guard_msgs in #check @foo.eq_1

-- Computation should work
/-- info: [1] -/
#guard_msgs in #eval foo [1,2] [] [3]
