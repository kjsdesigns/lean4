/-
Copyright (c) 2022 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/
module

prelude
public import Lean.Elab.App
public import Lean.Meta.Tactic.Relations

public section

namespace Lean.Elab.Term
open Meta

/--
Decomposes the type `e` into `(r, lhs, rhs)` using three methods:
- Using the `@[relation]` system,
- Taking the last two explicit arguments as the operands,
- Or it might be an arrow.

Throws an error if it's not a relation or if the relation won't be useable by `Trans`.

Note: we are careful not to unfold definitions while determining the relation.
We want to avoid LHS/RHS swapping meanings. For example, GT.gt is an abbreviation for LT.lt
with reversed argument order! We also avoid unfolding local let definitions for similar reasons.
-/
def getCalcRelation (e : Expr) (extraMsg : MessageData := m!"") :
    MetaM (Expr × Expr × Expr) := do
  let e ← withConfig ({ · with zeta := false }) <| whnfCore e
  if let some info ← matchesRelation? e then
    processMatch info.numArgs info.lhsIdx info.rhsIdx
  else if e.isArrow then
    let lhs := e.bindingDomain!
    let rhs := e.bindingBody!
    withLocalDeclD `lhs (← inferType lhs) fun lhsVar => do
    withLocalDeclD `rhs (← inferType rhs) fun rhsVar => do
      let rel ← mkLambdaFVars #[lhsVar, rhsVar] <| ← mkArrow lhsVar rhsVar
      return (rel, lhs, rhs)
  else
    let numArgs := e.getAppNumArgs
    forallBoundedTelescope (← inferType e.getAppFn) numArgs fun xs _ => do
      let bis ← xs.mapM fun x => x.fvarId!.getBinderInfo
      let explicits := bis.zipIdx |>.filter (fun (bi, _) => bi.isExplicit) |>.map Prod.snd
      if explicits.size < 2 then
        throwNotRelation
      else
        processMatch numArgs explicits[explicits.size-2]! explicits[explicits.size-1]!
where
  throwNotRelation {α} : MetaM α :=
    throwError "invalid 'calc' step, relation expected{extraMsg}{indentExpr e}"
  processMatch (numArgs lhsIdx rhsIdx : Nat) : MetaM (Expr × Expr × Expr) := do
    -- Currently we only support the cases where the lhs/rhs are the last two arguments,
    -- since this is what `Trans` supports.
    if lhsIdx == numArgs - 2 && rhsIdx == numArgs - 1 then
      return (e.appFn!.appFn!, e.appFn!.appArg!, e.appArg!)
    else if lhsIdx == numArgs - 1 && rhsIdx == numArgs - 2 then
      let lhs := e.appArg!
      let rhs := e.appFn!.appArg!
      withLocalDeclD `lhs (← inferType lhs) fun lhsVar => do
      withLocalDeclD `rhs (← inferType rhs) fun rhsVar => do
        let rel ← mkLambdaFVars #[lhsVar, rhsVar] (mkApp2 e.appFn!.appFn! rhsVar lhsVar)
        return (rel, lhs, rhs)
    else
      throwError "invalid 'calc' step, relation{extraMsg} has unsupported left-hand side and right-hand side argument positions {lhsIdx+1} and {rhsIdx+1}{indentExpr e}"

private def getRelUniv (r : Expr) : MetaM Level := do
  let rType ← inferType r
  forallTelescopeReducing rType fun _ sort => do
    let .sort u ← whnf sort | throwError "unexpected relation type{indentExpr rType}"
    return u

def mkCalcTrans (result resultType step stepType : Expr) : MetaM (Expr × Expr) := do
  let (r, a, b) ← getCalcRelation resultType
  let (s, _, c) ← getCalcRelation (← instantiateMVars stepType)
  let u ← getRelUniv r
  let v ← getRelUniv s
  let (α, β, γ)       := (← inferType a, ← inferType b, ← inferType c)
  let (u_1, u_2, u_3) := (← getLevel α, ← getLevel β, ← getLevel γ)
  let w ← mkFreshLevelMVar
  let t ← mkFreshExprMVar (← mkArrow α (← mkArrow γ (mkSort w)))
  let selfType := mkAppN (Lean.mkConst ``Trans [u, v, w, u_1, u_2, u_3]) #[α, β, γ, r, s, t]
  match (← trySynthInstance selfType) with
  | .some self =>
    let result := mkAppN (Lean.mkConst ``Trans.trans [u, v, w, u_1, u_2, u_3]) #[α, β, γ, r, s, t, self, a, b, c, result, step]
    let resultType := (← instantiateMVars (← inferType result)).headBeta
    discard <| getCalcRelation resultType (extraMsg := m!" for step result")
    return (result, resultType)
  | _ => throwError "invalid 'calc' step, failed to synthesize `Trans` instance{indentExpr selfType}{useDiagnosticMsg}"

/--
Adds a type annotation to a hole that occurs immediately at the beginning of the term.
This is so that coercions can trigger when elaborating the term.
See https://github.com/leanprover/lean4/issues/2040 for further rationale.

- `_ < 3` is annotated
- `(_) < 3` is not, because it occurs after an atom
- in `_ < _` only the first one is annotated
- `_ + 2 < 3` is annotated (not the best heuristic, ideally we'd like to annotate `_ + 2`)
- `lt _ 3` is not, because it occurs after an identifier
-/
partial def annotateFirstHoleWithType (t : Term) (type : Expr) : TermElabM Term :=
  -- The state is true if we should annotate the immediately next hole with the type.
  return ⟨← StateT.run' (go t) true⟩
where
  go (t : Syntax) := do
    unless ← get do return t
    match t with
    | .node _ ``Lean.Parser.Term.hole _ =>
      set false
      `(($(⟨t⟩) : $(← exprToSyntax type)))
    | .node i k as => return .node i k (← as.mapM go)
    | _ => set false; return t

/-- View of a `calcStep`. -/
structure CalcStepView where
  ref : Syntax
  /-- A relation term like `a ≤ b` -/
  term : Term
  /-- A proof of `term` -/
  proof : Term
  deriving Inhabited

def mkCalcFirstStepView (step0 : TSyntax ``calcFirstStep) : TermElabM CalcStepView :=
  withRef step0 do
  match step0  with
  | `(calcFirstStep| $term:term)      => return { ref := step0, term := ← `($term = _), proof := ← ``(rfl)}
  | `(calcFirstStep| $term := $proof) => return { ref := step0, term, proof}
  | _ => throwUnsupportedSyntax

def mkCalcStepViews (steps : TSyntax ``calcSteps) : TermElabM (Array CalcStepView) :=
  match steps with
  | `(calcSteps|
        $step0:calcFirstStep
        $rest*) => do
    let mut steps := #[← mkCalcFirstStepView step0]
    for step in rest do
      let `(calcStep| $term := $proof) := step | throwUnsupportedSyntax
      steps := steps.push { ref := step, term, proof }
    return steps
  | _ => throwUnsupportedSyntax

def elabCalcSteps (steps : Array CalcStepView) : TermElabM (Expr × Expr) := do
  let mut result? := none
  let mut prevRhs? := none
  for step in steps do
    let type ← elabType <| ← do
      if let some prevRhs := prevRhs? then
        annotateFirstHoleWithType step.term (← inferType prevRhs)
      else
        pure step.term
    let (_, lhs, rhs) ← withRef step.term <| getCalcRelation type
    if let some prevRhs := prevRhs? then
      unless (← isDefEqGuarded lhs prevRhs) do
        throwErrorAt step.term "\
          invalid 'calc' step, left-hand side is{indentD m!"{lhs} : {← inferType lhs}"}\n\
          but previous right-hand side is{indentD m!"{prevRhs} : {← inferType prevRhs}"}"
    let proof ← withFreshMacroScope do elabTermEnsuringType step.proof type
    result? := some <| ← do
      if let some (result, resultType) := result? then
        synthesizeSyntheticMVarsUsingDefault
        withRef step.term do mkCalcTrans result resultType proof type
      else
        pure (proof, type)
    prevRhs? := rhs
  synthesizeSyntheticMVarsUsingDefault
  return result?.get!

def throwCalcFailure (steps : Array CalcStepView) (expectedType result : Expr) : MetaM α := do
  let resultType := (← instantiateMVars (← inferType result)).headBeta
  let (r, lhs, rhs) ← getCalcRelation resultType
  if let some (er, elhs, erhs) ← observing? <| getCalcRelation expectedType then
    if ← isDefEqGuarded r er then
      let mut failed := false
      unless ← isDefEqGuarded lhs elhs do
        let (lhs, elhs) ← addPPExplicitToExposeDiff lhs elhs
        let (lhsTy, elhsTy) ← addPPExplicitToExposeDiff (← inferType lhs) (← inferType elhs)
        logErrorAt steps[0]!.term m!"\
          invalid 'calc' step, left-hand side is{indentD m!"{lhs} : {lhsTy}"}\n\
          but is expected to be{indentD m!"{elhs} : {elhsTy}"}"
        failed := true
      unless ← isDefEqGuarded rhs erhs do
        let (rhs, erhs) ← addPPExplicitToExposeDiff rhs erhs
        let (rhsTy, erhsTy) ← addPPExplicitToExposeDiff (← inferType rhs) (← inferType erhs)
        logErrorAt steps.back!.term m!"\
          invalid 'calc' step, right-hand side is{indentD m!"{rhs} : {rhsTy}"}\n\
          but is expected to be{indentD m!"{erhs} : {erhsTy}"}"
        failed := true
      if failed then
        throwAbortTerm
  throwTypeMismatchError "'calc' expression" expectedType resultType result

/-!
Warning! It is *very* tempting to try to improve `calc` so that it makes use of the expected type
to unify with the LHS and RHS.
Two people have already re-implemented `elabCalcSteps` trying to do so and then reverted the changes,
not being aware of examples like https://github.com/leanprover/lean4/issues/2073

The problem is that the expected type might need to be unfolded to get an accurate LHS and RHS.
(Consider `≤` vs `≥`. Users expect to be able to use `calc` to prove `≥` using chained `≤`!)
Furthermore, the types of the LHS and RHS do not need to be the same (consider `x ∈ S` as a relation),
so we also cannot use the expected LHS and RHS as type hints.
-/

/-- Elaborator for the `calc` term mode variant. -/
@[builtin_term_elab Lean.calc]
def elabCalc : TermElab
  | `(calc%$tk $steps:calcSteps), expectedType? => withRef tk do
    let steps ← mkCalcStepViews steps
    let (result, _) ← elabCalcSteps steps
    ensureHasTypeWithErrorMsgs expectedType? result
      (mkImmedErrorMsg := fun _ => throwCalcFailure steps)
      (mkErrorMsg := fun _ => throwCalcFailure steps)
  | _, _ => throwUnsupportedSyntax

end Lean.Elab.Term
