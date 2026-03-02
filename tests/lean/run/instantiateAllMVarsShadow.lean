import Lean
import Lean.Meta.InstMVarsAll

open Lean Meta

/-
Test: fvar shadowing in nested delayed mvars.

Two delayed mvars bind the same fvar `x_fvar` to different values.
A shared subexpression `succ_x := Nat.succ x_fvar` appears in both scopes.

  ?root    := fun (a : Nat) => ?d1_aux #0
  ?d1_aux  delayed [x_fvar] := ?body
  ?body    := Prod.mk succ_x (?d2_aux succ_x)     ← succ_x is shared
  ?d2_aux  delayed [x_fvar] := ?inner
  ?inner   := succ_x                                ← same shared object

Expected result:
  fun (a : Nat) => (Nat.succ a, Nat.succ (Nat.succ a))

When resolving ?d1_aux with arg `a`:
  - succ_x with x_fvar → a  gives  Nat.succ a           (first component)
  - ?d2_aux gets arg (Nat.succ a), so x_fvar → Nat.succ a
    succ_x with x_fvar → Nat.succ a  gives  Nat.succ (Nat.succ a)  (second component)

A buggy cache could return the cached scope-1 result (Nat.succ a) for the scope-2
visit, producing (Nat.succ a, Nat.succ a) instead.
-/

private def mkShadowTest : MetaM Expr := do
  let nat := mkConst ``Nat
  withLocalDeclD `x nat fun x_fvar => do
    -- shared object referencing x_fvar
    let succ_x := mkApp (mkConst ``Nat.succ) x_fvar

    -- ?inner := succ_x
    let inner ← mkFreshExprMVar nat
    inner.mvarId!.assign succ_x

    -- ?d2_aux delayed [x_fvar] := ?inner
    let d2_ty ← mkArrow nat nat
    let d2_aux ← mkFreshExprMVar d2_ty (kind := .syntheticOpaque)
    assignDelayedMVar d2_aux.mvarId! #[x_fvar] inner.mvarId!

    -- ?body := ⟨succ_x, ?d2_aux succ_x⟩
    let pairTy := mkApp2 (mkConst ``Prod [.succ .zero, .succ .zero]) nat nat
    let body ← mkFreshExprMVar pairTy
    body.mvarId!.assign
      (mkApp4 (mkConst ``Prod.mk [.succ .zero, .succ .zero]) nat nat
        succ_x (mkApp d2_aux succ_x))

    -- ?d1_aux delayed [x_fvar] := ?body
    let d1_ty ← mkArrow nat pairTy
    let d1_aux ← mkFreshExprMVar d1_ty (kind := .syntheticOpaque)
    assignDelayedMVar d1_aux.mvarId! #[x_fvar] body.mvarId!

    -- ?root := fun (a : Nat) => ?d1_aux a
    let rootTy ← mkArrow nat pairTy
    let root ← mkFreshExprMVar rootTy
    root.mvarId!.assign (Lean.mkLambda `a .default nat (mkApp d1_aux (.bvar 0)))
    return root

-- Expected: fun (a : Nat) => (Nat.succ a, Nat.succ (Nat.succ a))
private def mkExpected : Expr :=
  let nat := mkConst ``Nat
  let succ := mkConst ``Nat.succ
  let pairTy := mkApp2 (mkConst ``Prod [.succ .zero, .succ .zero]) nat nat
  -- #0 refers to the lambda-bound `a`
  let succ_a := mkApp succ (.bvar 0)
  let succ_succ_a := mkApp succ succ_a
  let body := mkApp4 (mkConst ``Prod.mk [.succ .zero, .succ .zero]) nat nat succ_a succ_succ_a
  Lean.mkLambda `a .default nat body

private def check (label : String) (result : Expr) : MetaM Unit := do
  let expected := mkExpected
  unless result == expected do
    throwError "{label}: expected {expected}, got {result}"

-- Both implementations must produce the expected result
run_meta do
  let root ← mkShadowTest

  let saved ← saveState
  let eOrig ← instantiateMVarsOriginal root
  saved.restore
  check "instantiateMVarsOriginal" eOrig

  let saved ← saveState
  let eNew ← instantiateAllMVars root
  saved.restore
  check "instantiateAllMVars" eNew
