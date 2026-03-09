module

import Lean

open Lean Meta

/-
Test: a shared delayed MVar application `?d (.bvar 0)` used twice should
resolve to pointer-equal results.

  ?root    := fun (a : Nat) => Prod.mk (?d a) (?d a)
  ?d       delayed [x] := ?pending
  ?pending := Nat.succ x

The expression `?d (.bvar 0)` is a single shared object used twice.
After instantiation, both resolve to `Nat.succ a`. They should be
pointer-equal (same object) thanks to caching.
-/

private def mkTest : MetaM Expr := do
  let nat := mkConst ``Nat
  withLocalDeclD `x nat fun x_fvar => do
    let pending ← mkFreshExprMVar nat
    pending.mvarId!.assign (mkApp (mkConst ``Nat.succ) x_fvar)
    let d_ty ← mkArrow nat nat
    let d ← mkFreshExprMVar d_ty (kind := .syntheticOpaque)
    assignDelayedMVar d.mvarId! #[x_fvar] pending.mvarId!
    let d_app := mkApp d (.bvar 0)  -- single shared object
    let pairTy := mkApp2 (mkConst ``Prod [.succ .zero, .succ .zero]) nat nat
    let body := mkApp4 (mkConst ``Prod.mk [.succ .zero, .succ .zero]) nat nat d_app d_app
    let rootTy ← mkArrow nat pairTy
    let root ← mkFreshExprMVar rootTy
    root.mvarId!.assign (Lean.mkLambda `a .default nat body)
    return root

-- Extract the two components from: fun (a : Nat) => @Prod.mk Nat Nat fst snd
private def extractComponents (e : Expr) : Expr × Expr :=
  let body := e.bindingBody!
  let snd := body.appArg!
  let fst := body.appFn!.appArg!
  (fst, snd)

run_meta do
  let root ← mkTest
  let result ← instantiateMVars root
  let (fst, snd) := extractComponents result
  let shared := unsafe ptrEq fst snd
  IO.println s!"instantiateMVars: shared delayed mvar ptr sharing = {shared}"
  guard shared
