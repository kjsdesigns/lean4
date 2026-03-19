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
#check @foo._f

-- Equation theorems should work
#check @foo.eq_def
#check @foo.eq_1

-- Computation should work
/-- info: [1] -/
#guard_msgs in #eval foo [1,2] [] [3]
