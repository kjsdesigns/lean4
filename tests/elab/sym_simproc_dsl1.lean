import Lean

open Lean Meta Sym.Simp

/-! Tests for `sym_simproc` and `sym_discharger` DSL elaboration -/

theorem test_zero_add : 0 + n = n := Nat.zero_add n
theorem test_add_zero : n + 0 = n := Nat.add_zero n

def runSimproc (p : Simproc) (e : Expr) : MetaM Expr := Sym.SymM.run do
  let e ← Grind.shareCommon e
  match ← SimpM.run' (p e) with
  | .rfl _ _ => return e
  | .step e' _ _ _ => return e'

def mkRewriteSimproc (names : Array Name) (d : Discharger := dischargeNone) : MetaM Simproc := do
  let mut thms : Theorems := {}
  for n in names do
    thms := thms.insert (← mkTheoremFromDecl n)
  return thms.rewrite d

-- Test `ground` evaluates concrete terms
#eval show MetaM Unit from do
  let e := mkNatAdd (mkNatLit 3) (mkNatLit 4)
  let r ← runSimproc evalGround e
  guard (r != e)

-- Test `rewrite` with inline theorems
#eval show MetaM Unit from do
  let p ← mkRewriteSimproc #[``test_zero_add]
  withLocalDeclD `x (mkConst ``Nat) fun x => do
    let e := mkNatAdd (mkNatLit 0) x
    let r ← runSimproc p e
    guard (r == x)

-- Test `>>` (andThen) combinator
#eval show MetaM Unit from do
  let p1 ← mkRewriteSimproc #[``test_zero_add]
  let p2 ← mkRewriteSimproc #[``test_add_zero]
  let combined := p1 >> p2
  withLocalDeclD `x (mkConst ``Nat) fun x => do
    let inner := mkNatAdd x (mkNatLit 0)
    let e := mkNatAdd (mkNatLit 0) inner
    let r ← runSimproc combined e
    guard (r == x)

-- Test `<|>` (orElse) combinator
#eval show MetaM Unit from do
  let p1 ← mkRewriteSimproc #[``test_zero_add]
  let p2 ← mkRewriteSimproc #[``test_add_zero]
  let combined := p1 <|> p2
  withLocalDeclD `x (mkConst ``Nat) fun x => do
    let e := mkNatAdd x (mkNatLit 0)
    let r ← runSimproc combined e
    guard (r == x)

-- Test `evalGround >> rewrite` combination
#eval show MetaM Unit from do
  let rewrite ← mkRewriteSimproc #[``test_zero_add]
  let combined := evalGround >> rewrite
  withLocalDeclD `x (mkConst ``Nat) fun x => do
    let e := mkNatAdd (mkNatLit 0) x
    let r ← runSimproc combined e
    guard (r == x)
