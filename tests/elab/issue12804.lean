/-!
# Theorems should be completely opaque

Theorems should not be delta-reducible or carry reducibility attributes.
-/

-- Theorems defined by well-founded recursion should not get @[irreducible]
theorem wfThm : ∀ n : Nat, n = n
  | 0 => rfl
  | n + 1 => congrArg Nat.succ (wfThm n)

-- Reducibility attributes should not be applicable to theorems
/--
error: failed to set reducibility status, `wfThm` is not a definition

Note: Use `set_option allowUnsafeReducibility true` to override reducibility status validation
-/
#guard_msgs in
attribute [irreducible] wfThm

/--
error: failed to set reducibility status, `wfThm` is not a definition

Note: Use `set_option allowUnsafeReducibility true` to override reducibility status validation
-/
#guard_msgs in
attribute [reducible] wfThm

-- Regular theorems should also be opaque
theorem simpleThm : True := trivial

-- The `delta` tactic should not unfold theorems
/--
error: Tactic `delta` failed: did not delta reduce [simpleThm]

⊢ True
-/
#guard_msgs in
example : True := by delta simpleThm; trivial
