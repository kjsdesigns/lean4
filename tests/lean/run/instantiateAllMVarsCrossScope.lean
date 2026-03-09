import Lean

open Lean Meta

/-
Test: cross-scope sharing in scope_cache insert.

A shared expression `succ_x := Nat.succ x_fvar` is visited at scope 1
(as d2's argument, before scope 2 is pushed) and then at scope 2
(inside d2's pending value). The insert optimization should reuse the
scope-1 result when inserting at scope 2, since result_scope=1 and
scope 1 hasn't changed.

  ?root  := fun (a : Nat) => ?d1 a
  ?d1    delayed [x] := ?body
  ?body  := ?d2 succ_x                       ← succ_x visited at scope 1 as d2's arg
  ?d2    delayed [z] := ?inner
  ?inner := Prod.mk z succ_x                 ← z = R1, succ_x visited at scope 2

The ordering guarantee comes from visit_delayed's control flow: args
are visited before pushing the new scope, the pending value is visited
after. This does not depend on the order in which application arguments
are traversed.

Expected result: fun (a : Nat) => (Nat.succ a, Nat.succ a)

With insert sharing, both Nat.succ a subexpressions in the result are
the same object (ptrEq). Without it, they are structurally equal but
distinct objects.
-/

private def mkCrossScopeTest : MetaM Expr := do
  let nat := mkConst ``Nat
  withLocalDeclD `x nat fun x_fvar =>
  withLocalDeclD `z nat fun z_fvar => do
    let succ_x := mkApp (mkConst ``Nat.succ) x_fvar

    -- ?inner := Prod.mk z succ_x
    let pairTy := mkApp2 (mkConst ``Prod [.succ .zero, .succ .zero]) nat nat
    let inner ← mkFreshExprMVar pairTy
    inner.mvarId!.assign
      (mkApp4 (mkConst ``Prod.mk [.succ .zero, .succ .zero]) nat nat z_fvar succ_x)

    -- ?d2 delayed [z] := ?inner, takes one Nat arg
    let d2_ty ← mkArrow nat pairTy
    let d2 ← mkFreshExprMVar d2_ty (kind := .syntheticOpaque)
    assignDelayedMVar d2.mvarId! #[z_fvar] inner.mvarId!

    -- ?body := ?d2 succ_x
    let body ← mkFreshExprMVar pairTy
    body.mvarId!.assign (mkApp d2 succ_x)

    -- ?d1 delayed [x] := ?body
    let d1_ty ← mkArrow nat pairTy
    let d1 ← mkFreshExprMVar d1_ty (kind := .syntheticOpaque)
    assignDelayedMVar d1.mvarId! #[x_fvar] body.mvarId!

    -- ?root := fun (a : Nat) => ?d1 a
    let rootTy ← mkArrow nat pairTy
    let root ← mkFreshExprMVar rootTy
    root.mvarId!.assign (Lean.mkLambda `a .default nat (mkApp d1 (.bvar 0)))
    return root

-- Expected: fun (a : Nat) => (Nat.succ a, Nat.succ a)
private def mkExpected : Expr :=
  let nat := mkConst ``Nat
  let succ_a := mkApp (mkConst ``Nat.succ) (.bvar 0)
  let body := mkApp4 (mkConst ``Prod.mk [.succ .zero, .succ .zero]) nat nat succ_a succ_a
  Lean.mkLambda `a .default nat body

-- Extract the two components from the result
-- Result shape: fun (a : Nat) => @Prod.mk Nat Nat fst snd
private def extractComponents (e : Expr) : Expr × Expr :=
  let body := e.bindingBody!
  let snd := body.appArg!
  let fst := body.appFn!.appArg!
  (fst, snd)

run_meta do
  let root ← mkCrossScopeTest
  let expected := mkExpected
  let result ← instantiateMVars root
  unless result == expected do
    throwError "instantiateMVars: wrong result, got {result}"
  let (fst, snd) := extractComponents result
  let shared := unsafe ptrEq fst snd
  IO.println s!"instantiateMVars: cross-scope sharing = {shared}"
  guard shared
