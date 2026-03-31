module

/-! # Tests for `letConfig` in `do` blocks -/

/-! ## `let (eq := h)` in do block (new elaborator) -/
set_option backward.do.legacy false in
/--
info: "hello"
-/
#guard_msgs in
#eval do
  let (eq := h) x := "hello"
  have : x = "hello" := h
  return x

/-! ## `let (eq := h)` with pattern matching (new elaborator) -/
set_option backward.do.legacy false in
/--
info: (1, 2)
-/
#guard_msgs in
#eval do
  let (eq := h) (a, b) := (1, 2)
  have : (1, 2) = (a, b) := h
  return (a, b)

/-! ## `have (eq := h)` in do block (new elaborator) -/
set_option backward.do.legacy false in
/--
info: 42
-/
#guard_msgs in
#eval do
  have (eq := h) x := 42
  have : x = 42 := h
  return x

/-! ## `let +usedOnly` in do block (new elaborator) -/
set_option backward.do.legacy false in
#eval do
  let +usedOnly _x := 42
  return ()

/-! ## `let +zeta` in do block (new elaborator) -/
set_option backward.do.legacy false in
/--
info: 42
-/
#guard_msgs in
#eval do
  let +zeta x := 42
  return x

/-! ## `let mut` with config is rejected (new elaborator) -/
set_option backward.do.legacy false in
/--
error: configuration options are not allowed with `let mut`
-/
#guard_msgs in
#eval do
  let mut (eq := _h) x := 42
  x := x + 1
  return x

/-! ## `let mut` with +zeta is rejected (new elaborator) -/
set_option backward.do.legacy false in
/--
error: configuration options are not allowed with `let mut`
-/
#guard_msgs in
#eval do
  let mut +zeta x := 42
  x := x + 1
  return x

/-! ## `+postponeValue` rejected in do block (new elaborator) -/
set_option backward.do.legacy false in
/--
error: `+postponeValue` is not supported in `do` blocks
-/
#guard_msgs in
#eval do
  let +postponeValue x := 42
  return x

/-! ## config options rejected with `←` (new elaborator) -/
set_option backward.do.legacy false in
/--
error: configuration options are not supported with `←`
-/
#guard_msgs in
#eval do
  let (eq := _h) x ← pure 42
  return x

/-! ## `let (eq := h)` in do-let-else (new elaborator) -/
set_option backward.do.legacy false in
/--
info: 1
-/
#guard_msgs in
#eval show IO Nat from do
  let (eq := h) (some x) := (some 1 : Option Nat) | return 0
  have : some 1 = some x := h
  return x

/-! ## `let (eq := h)` works with legacy elaborator too -/
set_option backward.do.legacy true in
/--
info: "hello"
-/
#guard_msgs in
#eval do
  let (eq := h) x := "hello"
  have : x = "hello" := h
  return x

/-! ## basic let/have still work with empty letConfig -/
set_option backward.do.legacy false in
/--
info: 42
-/
#guard_msgs in
#eval do
  let x := 42
  return x

set_option backward.do.legacy false in
/--
info: 42
-/
#guard_msgs in
#eval do
  have x := 42
  return x
