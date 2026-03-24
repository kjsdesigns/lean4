/-
Copyright (c) 2022 Siddhartha Gadgil. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Siddhartha Gadgil, Mario Carneiro, Kim Morrison
-/
module
prelude
public import Lean.Meta.Reduce
public import Lean.Meta.Tactic.Assert
public import Lean.Meta.DiscrTree.Main
import Lean.Meta.AppBuilder
import Lean.Meta.Tactic.Apply
import Lean.Meta.Tactic.Clear
import Lean.Meta.Tactic.Relations
import Lean.Elab.Tactic.Basic
public section

/-!
# `symm` tactic

This implements the `symm` tactic, which can apply symmetry theorems to either the goal or a
hypothesis.
-/

open Lean Meta Elab

namespace Lean.Meta.Symm

/-- Environment extensions for symm lemmas -/
builtin_initialize symmExt :
    SimpleScopedEnvExtension (Name × Array DiscrTree.Key) (DiscrTree Name) ←
  registerSimpleScopedEnvExtension {
    addEntry := fun dt (n, ks) => dt.insertKeyValue ks n
    initial := {}
  }

/-- Returns the symmetry lemmas that match the given relation. -/
def getSymmLemmas (rel : Expr) : MetaM (Array Name) := do
  (symmExt.getState (← getEnv)).getMatch rel

/--
Tags symmetry lemmas to be used by the `symm` tactic.

A symmetry lemma should be of the form `r x y → r y x` where `r` is an arbitrary relation.
-/
@[builtin_doc]
builtin_initialize registerBuiltinAttribute {
  name := `symm
  descr := "symmetric relation"
  add := fun decl _ kind => MetaM.run' do
    withTraceNode `Meta.Tactic.relation (fun _ => return m!"adding [symm] lemma `{.ofConstName decl}`") do
      let declTy := (← getConstInfo decl).type
      forallTelescope declTy fun xs targetTy => do
        let targetTy ← whnfCore targetTy
        let .const relName _ := targetTy.getAppFn
          | throwError "\
              `[symm]` attribute only applies to lemmas proving `x ∼ y → y ~ x`, where the relation is \
              a constant application, but the relation is not a constant application:\
              {inlineExprTrailing targetTy}"
        -- If the this isn't a registered relation, automatically infer and register it.
        if (← getRelationInfo? relName).isNone then
          withTraceNode `Meta.Tactic.relation (fun _ => return m!"Unknown relation, inferring [relation] for `{.ofConstName relName}`.") do
            let info ← inferRelationInfo relName #[]
            registerRelation relName info kind
        let some info ← matchesRelation? targetTy | unreachable!
        -- Validate last argument of the lemma
        if xs.isEmpty then
          throwError "`[symm]` attribute only applies to lemmas proving `x ~ y → y ~ x`, but the `{.ofConstName decl}` has no hypotheses"
        let hypTy ← whnfCore (← xs.back!.fvarId!.getType)
        unless hypTy.getAppFn.constName? == relName do
          throwError "`[symm]` attribute only applies to lemmas proving `x ~ y → y ~ x`, but the last hypothesis `{.ofConstName decl}` is not an application of the conclusion's relation{inlineExprTrailing info.rel}"
        let some hypInfo ← matchesRelation? hypTy | panic! "`[symm]` unexpectedly could not analyze hypothesis relation"
        -- Validate that symmetry is being applied
        unless ← isDefEq info.lhs hypInfo.rhs do
          let (lhs, hypRhs) ← addPPExplicitToExposeDiff info.lhs hypInfo.rhs
          throwError "\
            `[symm]` attribute only applies to lemmas proving `x ~ y → y ∼ x`, \
            but the conclusion's left-hand side{indentExpr lhs}\nis not definitionally equal to the hypothesis's right-hand side{indentExpr hypRhs}"
        unless ← isDefEq info.rhs hypInfo.lhs do
          let (rhs, hypLhs) ← addPPExplicitToExposeDiff info.rhs hypInfo.lhs
          throwError "\
            `[symm]` attribute only applies to lemmas proving `x ~ y → y ∼ x`, \
            but the conclusion's right-hand side{indentExpr rhs}\nis not definitionally equal to the hypothesis's left-hand side{indentExpr hypLhs}"
        -- Validate applicability of the lemma
        let g ← mkFreshExprSyntheticOpaqueMVar targetTy
        let gs ← g.mvarId!.apply (← mkConstWithFreshMVarLevels decl) (term? := m!"'{.ofConstName decl}'")
        unless gs.length == 1 do
          let gs ← gs.filterM fun g => not <$> withNewMCtxDepth do isDefEq (← g.getType) hypTy
          throwError "`[symm]` lemma has unsolved goals when applied to its own conclusion\n{goalsToMessageData gs}"
      let (_, _, targetTy) ← forallMetaTelescope declTy
      let some info ← matchesRelation? (← whnfCore targetTy) | unreachable!
      let key ← DiscrTree.mkPath info.rel
      symmExt.add (decl, key) kind
}

private def noSymmLemmaMsg (rel : Expr) : MessageData :=
  m!"No `[symm]` lemma registered for relation{indentExpr rel}"
    ++ MessageData.hint' m!"Add the `[sym]` attribute to symmetry lemmas for{inlineExpr rel}to use this tactic"

private def throwNoSymmLemma {α} (goal? : Option MVarId) (rel : Expr) : MetaM α :=
  throwTacticEx `symm goal? <| noSymmLemmaMsg rel

private def throwRelError {α} (goal? : Option MVarId) (t : Expr) : MetaM α := do
  throwTacticEx `symm goal? <| MessageData.ofLazyM (es := #[t]) do
    if let some info ← matchesPotentialRelation? t then
      return noSymmLemmaMsg info.rel
    else
      return m!"Expecting a goal that is a binary relation"

mutual

/--
Given `e : t`, tries applying a `@[symm]` lemma to it using forward reasoning, returning the new expression.
-/
private partial def applySymmFwd (goal? : Option MVarId) (e : Expr) (t tOrig : Expr) : MetaM Expr := do
  let t ← whnfCore t
  if !t.getAppFn.isConst then
    throwRelError goal? tOrig
  else if t.isAppOfArity ``Eq 3 then
    let_expr Eq α lhs rhs := t | unreachable!
    let us := t.getAppFn.constLevels!
    return mkApp4 (mkConst ``Eq.symm us) α lhs rhs e
  else if t.isAppOfArity ``HEq 4 then
    let_expr HEq α lhs β rhs := t | unreachable!
    let us := t.getAppFn.constLevels!
    return mkApp5 (mkConst ``HEq.symm us) α β lhs rhs e
  else if t.isAppOfArity ``Iff 2 then
    let_expr Iff lhs rhs := t | unreachable!
    return mkApp3 (mkConst ``Iff.symm []) lhs rhs e
  else if t.isAppOfArity ``Not 1 then
    -- Contrapose the symmetry.  If `t = ¬ (x ~ y)` then for
    --   ¬ (x ~ y)  ->  ¬ (y ~ x)
    -- we need
    --   y ~ x  ->  x ~ y
    -- To do this, we can use `applySymmBwd` and abstract the metavariable.
    let t' := t.appArg!
    let g1 ← mkFreshExprSyntheticOpaqueMVar t'
    let g2 ← applySymmBwd g1.mvarId! t' t'
    -- Abstract g2 from g1 to get implication
    let imp ← mkLambdaFVars #[.mvar g2] g1
    -- For safety, let's use mkAppM to validate
    mkAppM ``mt #[imp, e]
  else if let some { rel, .. } ← matchesRelation? t then
    -- Search through `[symm]` keyed by the relation
    let lems ← getSymmLemmas rel
    if lems.isEmpty then
      tryUnfold goal? t (throwNoSymmLemma goal? rel)
    else
      let mut ex? := none
      for lem in lems do
        try
          return ← withNewMCtxDepth do
            let lemE ← mkConstWithFreshMVarLevels lem
            let (args, bis, _) ← forallMetaTelescope (← inferType lemE)
            let some eArg := args.back? | throwError "Invalid symm lemma `{.ofConstName lem}`"
            unless ← isDefEq eArg e do
              let eArgTy ← instantiateMVars (← inferType eArg)
              throwError MessageData.ofLazyM (es := #[eArgTy, t]) do
                let (eArgTy, t) ← addPPExplicitToExposeDiff eArgTy t
                return m!"The last hypothesis{inlineExpr eArgTy}of the symmetry lemma `{.ofConstName lem}` is not definitionally equal to{inlineExprTrailing t}"
            synthAppInstances `symm goal? args.pop bis.pop (allowSynthFailures := false) (synthAssignedInstances := true)
            let gs ← args.pop.filterM fun arg => not <$> arg.mvarId!.isAssigned
            unless gs.isEmpty do
              throwError MessageData.tagged `Tactic.unsolvedGoals <| m!"unsolved goals\n{Elab.goalsToMessageData (gs.map Expr.mvarId!).toList}"
            instantiateMVars <| mkAppN lemE args
        catch e =>
          unless ex?.isSome do
            ex? := e -- stash first failure
      if let some e := ex? then
        throw e
      else
        throwNoSymmLemma goal? rel
  else
    tryUnfold goal? t (throwRelError goal? tOrig)
where
  tryUnfold (goal? : Option MVarId) (t : Expr) (err : MetaM Expr) : MetaM Expr := do
    if let some t' ← withReducible <| unfoldDefinition? t then
      applySymmFwd goal? e t' tOrig
    else
      err

/--
Given `goal : t`, tries applying a `@[symm]` lemma to it using backward reasoning, returning the new goal.
-/
private partial def applySymmBwd (goal : MVarId) (t tOrig : Expr) : MetaM MVarId := do
  let t ← whnfCore t
  if !t.getAppFn.isConst then
    throwRelError goal tOrig
  else if t.isAppOfArity ``Eq 3 then
    let_expr Eq α lhs rhs := t | unreachable!
    let us := t.getAppFn.constLevels!
    let goal' ← mkFreshExprSyntheticOpaqueMVar (mkApp3 (mkConst ``Eq us) α rhs lhs)
    goal.assign <| mkApp4 (mkConst ``Eq.symm us) α rhs lhs goal'
    return goal'.mvarId!
  else if t.isAppOfArity ``HEq 4 then
    let_expr HEq α lhs β rhs := t | unreachable!
    let us := t.getAppFn.constLevels!
    let goal' ← mkFreshExprSyntheticOpaqueMVar (mkApp4 (mkConst ``HEq us) β rhs α lhs)
    goal.assign <| mkApp5 (mkConst ``HEq.symm us) β α rhs lhs goal'
    return goal'.mvarId!
  else if t.isAppOfArity ``Iff 2 then
    let_expr Iff lhs rhs := t | unreachable!
    let goal' ← mkFreshExprSyntheticOpaqueMVar (mkIff rhs lhs)
    goal.assign <| mkApp3 (mkConst ``Iff.symm []) rhs lhs goal'
    return goal'.mvarId!
  else if t.isAppOfArity ``Not 1 then
    -- Contrapose the symmetry.  If `t = ¬ (x ~ y)` then we can intro `x ~ y`, apply forward
    -- reasoning to get `y ~ x`, then revert.
    let tag ← goal.getTag
    let t' := t.appArg!
    let (h, goal) ← withDefault goal.intro1
    goal.withContext do
      let esymm ← applySymmFwd goal (.fvar h) t' t'
      let goal' ← mkFreshExprSyntheticOpaqueMVar (mkApp (mkConst ``Not []) (← inferType esymm))
      goal.assign (← mkAbsurd (mkConst ``False) esymm goal')
      let goal' := goal'.mvarId!
      goal'.setTag tag
      goal'.tryClear h
  else if let some { rel, .. } ← matchesRelation? t then
    -- Search through `[symm]` keyed by the relation
    let lems ← getSymmLemmas rel
    if lems.isEmpty then
      tryUnfold goal t (throwNoSymmLemma goal rel)
    else
      let mut ex? := none
      for lem in lems do
        try
          let (pf, t') ← withNewMCtxDepth do
            let lemE ← mkConstWithFreshMVarLevels lem
            let (args, bis, targetTy) ← forallMetaTelescope (← inferType lemE)
            let some eArg := args.back? | throwError "Invalid symm lemma `{.ofConstName lem}`"
            unless ← isDefEq targetTy t do
              throwError MessageData.ofLazyM (es := #[targetTy, t]) do
                let (targetTy, t) ← addPPExplicitToExposeDiff targetTy t
                return m!"The goal{inlineExpr targetTy}of the symmetry lemma `{.ofConstName lem}` is not definitionally equal to the target{inlineExprTrailing t}"
            synthAppInstances `symm goal args.pop bis.pop (allowSynthFailures := false) (synthAssignedInstances := true)
            let gs ← args.pop.filterM fun arg => not <$> arg.mvarId!.isAssigned
            unless gs.isEmpty do
              throwError MessageData.tagged `Tactic.unsolvedGoals <| m!"unsolved goals\n{Elab.goalsToMessageData (gs.map Expr.mvarId!).toList}"
            let pf ← instantiateMVars <| mkAppN lemE args.pop
            let t' ← instantiateMVars <| (← inferType eArg)
            pure (pf, t')
          let goal' ← mkFreshExprSyntheticOpaqueMVar t' (← goal.getTag)
          goal.assign <| mkApp pf goal'
          return goal'.mvarId!
        catch e =>
          unless ex?.isSome do
            ex? := e -- stash first failure
      if let some e := ex? then
        throw e
      else
        throwNoSymmLemma goal rel
  else
    tryUnfold goal t (throwRelError goal tOrig)
where
  tryUnfold (goal : MVarId) (t : Expr) (err : MetaM MVarId) : MetaM MVarId := do
    if let some t' ← withReducible <| unfoldDefinition? t then
      applySymmBwd goal t' tOrig
    else
      err

end

end Lean.Meta.Symm

open Lean.Meta.Symm

namespace Lean.Expr

/--
Given a term `e : a ~ b`, constructs a term in `b ~ a` using `@[symm]` lemmas.

The `g?` argument is used only for error reporting.
-/
def applySymm (g? : Option MVarId) (e : Expr) : MetaM Expr := do
  let t ← inferType e
  applySymmFwd g? e t t

end Lean.Expr

namespace Lean.MVarId

/--
Apply a symmetry lemma (i.e. marked with `@[symm]`) to a metavariable.

The type of `g` should be of the form `a ~ b`, and is used to index the symm lemmas.
-/
def applySymm (g : MVarId) : MetaM MVarId :=
  g.withContext do
    let t ← g.getType
    applySymmBwd g t t

/-- Use a symmetry lemma (i.e. marked with `@[symm]`) to replace a hypothesis in a goal. -/
def applySymmAt (h : FVarId) (g : MVarId) : MetaM MVarId := do
  let h' ← g.withContext <| (Expr.fvar h).applySymm g
  pure (← g.replace h h').mvarId

/-- For every hypothesis `h : a ~ b` where a `@[symm]` lemma is available,
add a hypothesis `h_symm : b ~ a`. -/
def symmSaturate (g : MVarId) : MetaM MVarId := g.withContext do
  let mut g' := g
  let hyps ← getLocalHyps
  let types ← hyps.mapM inferType
  for h in hyps do try
    let symm ← h.applySymm g
    let symmType ← inferType symm
    if ¬ (← types.anyM (isDefEq symmType)) then
      (_, g') ← g'.note ((← h.fvarId!.getUserName).appendAfter "_symm") symm
  catch _ => g' ← pure g'
  return g'

end Lean.MVarId
