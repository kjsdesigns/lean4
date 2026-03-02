import Lean
import Lean.Meta.InstMVarsAll

open Lean Meta

/-
Minimal test for sharing in `instantiateAllMVars` and `instantiateAllMVarsSharing`.

We construct the metavariable assignment graph for the goal
`∀ s, (s = s → (s = s) ∧ (s = s)) ∧ (s = s)`:

  ?root    :=  fun (s : Nat) => ?rootAux #0
  ?rootAux delayed [s_fvar] := ?body
  ?body    :=  @And.intro leftTy rightTy ?left right
  ?left    :=  fun (h : eq_ss) => ?leftAux #0
  ?leftAux delayed [h_fvar] := ?inner
  ?inner   :=  @And.intro eq_ss eq_ss h_fvar h_fvar

where

  eq_ss   := @Eq Nat s_fvar s_fvar            ← single shared object
  andTy   := And eq_ss eq_ss                  ← contains eq_ss
  leftTy  := eq_ss → andTy                    ← forallE body contains eq_ss
  rightTy := eq_ss
  right   := @Eq.refl Nat s_fvar
-/

private def mkTestRoot : MetaM Expr := do
  let nat := mkConst ``Nat
  withLocalDeclD `s nat fun s_fvar => do
    let eq_ss ← mkEq s_fvar s_fvar            -- shared object

    let andTy := mkApp2 (mkConst ``And) eq_ss eq_ss  -- (s=s) ∧ (s=s)
    let leftTy ← mkArrow eq_ss andTy          -- s=s → (s=s) ∧ (s=s)
    let rightTy := eq_ss                       -- s=s
    let bodyTy := mkApp2 (mkConst ``And) leftTy rightTy

    let body ← mkFreshExprMVar bodyTy
    let left ← mkFreshExprMVar leftTy

    withLocalDeclD `h eq_ss fun h_fvar => do
      -- ?inner : (s=s) ∧ (s=s), proved by And.intro eq_ss eq_ss h h
      let inner ← mkFreshExprMVar andTy
      let leftDecl ← left.mvarId!.getDecl
      let leftAux ← mkFreshExprMVarAt leftDecl.lctx leftDecl.localInstances
                       leftDecl.type .syntheticOpaque
      assignDelayedMVar leftAux.mvarId! #[h_fvar] inner.mvarId!
      left.mvarId!.assign (Lean.mkLambda `h .default eq_ss (mkApp leftAux (.bvar 0)))
      inner.mvarId!.assign (mkApp4 (mkConst ``And.intro) eq_ss eq_ss h_fvar h_fvar)

      let right := mkApp2 (mkConst ``Eq.refl [1]) nat s_fvar
      body.mvarId!.assign (mkApp4 (mkConst ``And.intro) leftTy rightTy left right)

      let rootTy ← mkForallFVars #[s_fvar] bodyTy
      let root ← mkFreshExprMVar rootTy
      let rootDecl ← root.mvarId!.getDecl
      let rootAux ← mkFreshExprMVarAt rootDecl.lctx rootDecl.localInstances
                       rootDecl.type .syntheticOpaque
      assignDelayedMVar rootAux.mvarId! #[s_fvar] body.mvarId!
      root.mvarId!.assign (Lean.mkLambda `s .default nat (mkApp rootAux (.bvar 0)))
      return root

-- Both variants now produce the same result with the same sharing
run_meta do
  let root ← mkTestRoot

  let saved ← saveState
  let eSharing ← instantiateAllMVarsSharing root
  let nSharing ← eSharing.numObjs
  saved.restore

  let saved ← saveState
  let eAll ← instantiateAllMVars root
  let nAll ← eAll.numObjs
  saved.restore

  guard (eSharing == eAll)
  guard (nAll == nSharing)

-- instantiateAllMVarsSharing produces the same result as instantiateMVars
run_meta do
  let root ← mkTestRoot

  let saved ← saveState
  let eStd ← instantiateMVars root
  saved.restore

  let saved ← saveState
  let eSharing ← instantiateAllMVarsSharing root
  saved.restore

  guard (eStd == eSharing)
