module

set_option backward.do.legacy false

/-! ## `let (eq := h)` in do block -/
/--
info: "hello"
-/
#guard_msgs in
#eval do
  let (eq := h) x := "hello"
  have : x = "hello" := h
  return x

/-! ## `let (eq := h)` with pattern matching -/
/--
info: (1, 2)
-/
#guard_msgs in
#eval do
  let (eq := h) (a, b) := (1, 2)
  have : (1, 2) = (a, b) := h
  return (a, b)

/-! ## `have (eq := h)` in do block -/
/--
info: 42
-/
#guard_msgs in
#eval do
  have (eq := h) x := 42
  have : x = 42 := h
  return x

/-! ## `let +zeta` inlines the binding -/
set_option trace.Elab.definition.body true in
/--
trace: [Elab.definition.body] _private.elab.doLetConfig.0.testZeta : IO Nat :=
    pure 42
-/
#guard_msgs (trace) in
def testZeta : IO Nat := do
  let +zeta x := 42
  return x

/-! ## `let +usedOnly` drops unused binding -/
set_option trace.Elab.definition.body true in
/--
trace: [Elab.definition.body] _private.elab.doLetConfig.0.testUsedOnlyUnused : IO Unit :=
    pure ()
-/
#guard_msgs (trace) in
def testUsedOnlyUnused : IO Unit := do
  let +usedOnly _x := 42
  return ()

/-! ## `let +usedOnly` keeps used binding -/
set_option trace.Elab.definition.body true in
/--
trace: [Elab.definition.body] _private.elab.doLetConfig.0.testUsedOnlyUsed : IO Nat :=
    let x := 42;
    pure x
-/
#guard_msgs (trace) in
def testUsedOnlyUsed : IO Nat := do
  let +usedOnly x := 42
  return x

/-! ## `let mut` with config is rejected -/
/--
error: configuration options are not allowed with `let mut`
-/
#guard_msgs in
#eval do
  let mut (eq := _h) x := 42
  x := x + 1
  return x

/-! ## `let mut` with +zeta is rejected -/
/--
error: configuration options are not allowed with `let mut`
-/
#guard_msgs in
#eval do
  let mut +zeta x := 42
  x := x + 1
  return x

/-! ## `+postponeValue` rejected in do block -/
/--
error: `+postponeValue` is not supported in `do` blocks
-/
#guard_msgs in
#eval do
  let +postponeValue x := 42
  return x

/-! ## config options rejected with `←` -/
/--
error: configuration options are not supported with `←`
-/
#guard_msgs in
#eval do
  let (eq := _h) x ← pure 42
  return x

/-! ## `let (eq := h)` in do-let-else -/
/--
info: 1
-/
#guard_msgs in
#eval show IO Nat from do
  let (eq := h) (some x) := (some 1 : Option Nat) | return 0
  have : some 1 = some x := h
  return x

/-! ## basic let/have still work with empty letConfig -/
/--
info: 42
-/
#guard_msgs in
#eval do
  let x := 42
  return x

/--
info: 42
-/
#guard_msgs in
#eval do
  have x := 42
  return x
