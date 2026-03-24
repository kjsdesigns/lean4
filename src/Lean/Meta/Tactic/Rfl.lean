/-
Copyright (c) 2022 Newell Jensen. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Newell Jensen, Thomas Murrills, Joachim Breitner
-/
module

prelude
public import Lean.Elab.Tactic.Basic
public import Lean.Meta.Tactic.Refl
public import Lean.Meta.Tactic.Relations
public import Lean.Meta.Tactic.Replace
public import Lean.Meta.CongrTheorems

public section

/-!
# `rfl` tactic extension for reflexive relations

This extends the `rfl` tactic so that it works on any reflexive relation,
provided the reflexivity lemma has been marked as `@[refl]`.
-/

namespace Lean.Meta.Rfl

open Lean Meta Elab Tactic

/-- Environment extensions for `refl` lemmas -/
initialize reflExt :
    SimpleScopedEnvExtension (Name × Array DiscrTree.Key) (DiscrTree Name) ←
  registerSimpleScopedEnvExtension {
    addEntry := fun dt (n, ks) => dt.insertKeyValue ks n
    initial := {}
  }

/-- Returns the refl lemmas that match the given relation. -/
def getReflLemmas (rel : Expr) : MetaM (Array Name) := do
  (reflExt.getState (← getEnv)).getMatch rel

/--
Tags reflexivity lemmas to be used by the `rfl` tactic.

A reflexivity lemma should have the conclusion `r x x` where `r` is an arbitrary relation.

Tagging reflexivity lemmas for `=` is not allowed using this attribute. These are handled as a
special case in the `rfl` tactic.

Relations can be declared first using the `@[relation]` attribute, which may be necessary
if the left-hand, but `@[refl]` will
-/
@[builtin_doc]
builtin_initialize registerBuiltinAttribute {
  name := `refl
  descr := "reflexivity lemma for a relation"
  add := fun decl _ kind => MetaM.run' do
    withTraceNode `Meta.Tactic.relation (fun _ => return m!"adding [refl] lemma `{.ofConstName decl}`") do
      let declTy := (← getConstInfo decl).type
      forallTelescope declTy fun _ targetTy => do
        let targetTy ← whnfCore targetTy
        let .const relName _ := targetTy.getAppFn
          | throwError "\
              `[refl]` attribute only applies to lemmas concluding with `x ∼ x`, where the relation is \
              a constant application, but the conclusion is not a constant application:\
              {inlineExprTrailing targetTy}"
        if relName == ``Eq then
          throwError "`[refl]` attribute may not be used on `Eq`"
        -- If the this isn't a registered relation, automatically infer and register it.
        if (← getRelationInfo? relName).isNone then
          withTraceNode `Meta.Tactic.relation (fun _ => return m!"Unknown relation, inferring [relation] for `{.ofConstName relName}`.") do
            let info ← inferRelationInfo relName #[]
            registerRelation relName info kind
        let some info ← matchesRelation? targetTy | unreachable!
        -- Validate the conclusion of the lemma
        unless ← withNewMCtxDepth <| isDefEq info.lhs info.rhs do
          let (lhs, rhs) ← addPPExplicitToExposeDiff info.lhs info.rhs
          throwError "\
            `[refl]` attribute only applies to lemmas concluding with `x ∼ x`,
            but the left-hand side{indentExpr lhs}\nis not definitionally equal to the right-hand side{indentExpr rhs}"
        -- Validate applicability of the lemma
        let g ← mkFreshExprSyntheticOpaqueMVar declTy
        let gs ← g.mvarId!.apply (← mkConstWithFreshMVarLevels decl) (term? := m!"'{.ofConstName decl}'")
        unless gs.isEmpty do
          throwError "`[refl]` lemma cannot be applied, has unsolved goals\n{goalsToMessageData gs}"
      let (_, _, targetTy) ← forallMetaTelescope declTy
      let some info ← matchesRelation? (← whnfCore targetTy) | unreachable!
      let key ← DiscrTree.mkPath info.rel
      reflExt.add (decl, key) kind
}

private def noRflLemmaMsg (rel : Expr) : MessageData :=
  m!"No `[refl]` lemma registered for relation{indentExpr rel}"
    ++ MessageData.hint' m!"Add the `[refl]` attribute to reflexivity lemmas for{inlineExpr rel}to use this tactic"

private def throwNoRflLemma {α} (tacticName : Name) (goal : MVarId) (rel : Expr) : MetaM α :=
  throwTacticEx tacticName goal <| noRflLemmaMsg rel

private def throwRelError {α} (tacticName : Name) (goal : MVarId) : MetaM α := do
  let t ← goal.getType
  throwTacticEx tacticName goal <| MessageData.ofLazyM (es := #[t]) do
    if let some info ← matchesPotentialRelation? t then
      return noRflLemmaMsg info.rel
    else
      return m!"Expecting a goal that is a binary relation"

def throwNotDefEqError (tacticName : Name) (goal : MVarId) (lhs rhs : Expr) (thing : MessageData := m!"side") : MetaM Unit := do
  throwTacticEx tacticName goal <| MessageData.ofLazyM (es := #[lhs, rhs]) do
    let (lhs, rhs) ← addPPExplicitToExposeDiff lhs rhs
    return m!"The left-hand {thing}{indentExpr lhs}\nis not definitionally equal to the right-hand {thing}{indentExpr rhs}"

private def applyLemmas (tacticName : Name) (goal : MVarId) (rel : Expr) (lems : Array Name) : MetaM Unit := do
  let mut ex? := none
  let s ← saveState
  for lem in lems do
    try
      let gs ← goal.apply (← mkConstWithFreshMVarLevels lem) (term? := m!"'{.ofConstName lem}'")
      unless gs.isEmpty do
        throwError MessageData.tagged `Tactic.unsolvedGoals <| m!"unsolved goals\n{goalsToMessageData gs}"
      -- Success!
      return ()
    catch e =>
      unless ex?.isSome do
        ex? := some (← saveState, e) -- stash the first failure
    s.restore
  if let some (sErr, e) := ex? then
    sErr.restore
    throw e
  else
    s.restore
    throwNoRflLemma tacticName goal rel

/--
Finds a `@[refl]` lemma that applies.
The type `t` is defeq to the type of `goal`.
Unfolds `t` step-by-step looking for lemmas.
-/
private partial def applyRflCore (goal : MVarId) (t : Expr) : MetaM Unit := do
  let t ← whnfCore t
  if !t.getAppFn.isConst then
    throwRelError `rfl goal
  else if t.isAppOfArity ``Eq 3 then
    -- The common case is equality: just use `Eq.refl`
    let_expr Eq α lhs rhs := t | unreachable!
    checkDefEq lhs rhs
    let us := t.getAppFn.constLevels!
    goal.assign (mkApp2 (mkConst ``Eq.refl us) α lhs)
  else if t.isAppOfArity ``HEq 4 then
    -- `HEq` is less common, but we can give a more precise error report than for general relations
    let_expr HEq α lhs β rhs := t | unreachable!
    let us := t.getAppFn.constLevels!
    checkDefEq α β "side's type"
    checkDefEq lhs rhs
    goal.assign (mkApp2 (mkConst ``HEq.refl us) α lhs)
  else if t.isAppOfArity ``Iff 2 then
    -- This is unnecessary, but it's a common case.
    let_expr Iff lhs rhs := t | unreachable!
    checkDefEq lhs rhs
    goal.assign (mkApp (mkConst ``Iff.refl []) lhs)
  else if let some info@{ rel, lhs, rhs, .. } ← matchesRelation? t then
    -- Search through `[refl]` keyed by the relation
    let lems ← getReflLemmas rel
    if lems.isEmpty then
      tryUnfold goal t (throwNoRflLemma `rfl goal rel)
    else
      checkDefEq lhs rhs
      -- We change the type to `lhs ~ lhs` so that we don't do the (possibly costly) `lhs =?= rhs`
      -- check again.
      let t := t.withApp fun f args => mkAppN f (args.set! info.rhsIdx lhs)
      goal.setType t
      applyLemmas `rfl goal rel lems
  else
    tryUnfold goal t (throwRelError `rfl goal)
where
  checkDefEq (lhs rhs : Expr) (thing : MessageData := m!"side") := do
    withTraceNode `Meta.Tactic.relation (fun _ => return m!"applyRflCore: {lhs} =?= {rhs} at {repr (← getTransparency)}") do
      unless ← approxDefEq <| isDefEq lhs rhs do
        throwNotDefEqError `rfl goal lhs rhs thing
  tryUnfold (goal : MVarId) (t : Expr) (err : MetaM Unit) : MetaM Unit := do
    if let some t' ← withReducible <| unfoldDefinition? t then
      applyRflCore goal t'
    else
      err

/-- `MetaM` version of the `rfl` tactic.

This tactic applies to a goal whose target has the form `x ~ x`, where `~` is a reflexive
relation, that is, equality or another relation which has a reflexive lemma tagged with the
attribute [refl].
-/
def _root_.Lean.MVarId.applyRfl (goal : MVarId) : MetaM Unit :=
  goal.withContext do
    goal.checkNotAssigned `rfl
    let t ← goal.getType
    applyRflCore goal t

/--
Finds a `@[refl]` lemma that applies to lift `x ~ y` to `x = y` or `x ≍ y`.
The type `t` is defeq to the type of `goal`.
Unfolds `t` step-by-step looking for lemmas.

This is a congruence task. The key problems are:
1. Taking `x ~ y` and finding a way to turn it into `x ~ x` (the relation might be heterogeneous,
   and there might be typeclass instances).
2. Proving that `x = y → (x ~ x = x ~ y)`.
-/
private partial def liftReflToEqHEqCore (goal : MVarId) (t : Expr) (allowHEq : Bool := true) (failIfUnchanged : Bool) : MetaM MVarId := do
  let t ← whnfCore t
  if !t.getAppFn.isConst then
    throwRelError `liftReflToEq goal
  else if t.isAppOfArity ``Eq 3 then
    -- Already Eq
    if failIfUnchanged then
      throwTacticEx `liftReflToEq goal "Goal is already an equality"
    goal.setType t
    return goal
  else if t.isAppOfArity ``HEq 4 then
    -- Already HEq.
    goal.setType t
    let goal ← goal.heqOfEq
    unless !failIfUnchanged && allowHEq do
      if let some (lhsTy, _, rhsTy, _) := (← goal.getType).heq? then
        throwNotDefEqError `liftReflToEq goal lhsTy rhsTy (thing := "side's type")
    return goal
  else if t.isAppOfArity ``Iff 2 then
    -- There is a meta tactic for this, so may as well use it for this common case.
    goal.setType t
    goal.iffOfEq
  else if let some info@{ rel, lhs, rhs, .. } ← matchesRelation? t then
    -- Search through `[refl]` keyed by the relation
    let lems ← getReflLemmas rel
    if lems.isEmpty then
      tryUnfold goal t (throwNoRflLemma `liftReflToEq goal rel)
    else
      let lhsTy ← inferType lhs
      let lhsU ← getLevel lhsTy
      let rhsTy ← inferType rhs
      let rhsU ← getLevel rhsTy
      unless ← isLevelDefEq lhsU rhsU do
        -- If the universe levels are different, then they can't be Eq or HEq.
        throwTacticEx `liftReflToEq goal "The universe level of left-hand type{indentExpr lhsTy}\n\
          is not definitionally equal to the universe level of right-hand type{indentExpr rhsTy}"
      -- Try unifying the types
      let typesEq ← approxDefEq <| isDefEq lhsTy rhsTy
      if !allowHEq && !typesEq then
        throwNotDefEqError `liftReflToEq goal lhsTy rhsTy (thing := "type")
      if typesEq && info.rhsIdx == info.numArgs - 1 then
        -- Common case: `Eq` where rhs is the last argument.
        -- The `@[relation]` attribute validates that the type of the relation doesn't depend on the arguments
        let goalEq ← mkFreshExprSyntheticOpaqueMVar (tag := ← goal.getTag) (← mkEq lhs rhs)
        let pf ← mkCongrArg t.appFn! goalEq  -- Proof that `lhs ~ lhs = lhs ~ rhs`
        let t' := Expr.app t.appFn! lhs
        let goal ← goal.replaceTargetEq t' (← mkEqSymm pf)
        applyLemmas `liftReflToEq goal rel lems
        return goalEq.mvarId!
      else
        -- Otherwise, use a congruence lemma.
        let congr ← mkHCongr rel
        let throwCongrError {α} (_ : Unit) : MetaM α :=
          throwTacticEx `liftReflToEq goal m!"Failed to construct equation to rewrite relation{indentExpr t}\nto be reflexive"
        unless congr.argKinds[info.rhsIdx - info.relArgs]! matches .eq | .heq do
          throwCongrError ()
        let (args, _, teq) ← forallMetaTelescope congr.type
        -- We're going for `teq : lhs ~ lhs = lhs ~ rhs`
        -- This way, the congruence goal `goalEq` is `lhs = rhs` (or `lhs ≍ rhs`).
        let some (ty1, trfl, ty2, t') := teq.heq? | throwCongrError ()
        unless ← isDefEq t' t do throwCongrError ()  -- sets all arguments for `t` (*)
        unless ← isDefEq ty1 ty2 do throwCongrError ()
        -- Locate where the arguments for each kind are in `args`
        let (kindArgIdxs, _) := congr.argKinds.foldl (init := (#[], 0)) fun (kindArgIdxs, idx) kind =>
          (kindArgIdxs.push idx,
            match kind with
            | .eq | .heq        => idx + 3
            | _                 => unreachable!)
        -- Three arguments: trfl's lhs, t's lhs, and eq/heq. t's lhs already set at (*)
        let lhsArgIdx := kindArgIdxs[info.lhsIdx - info.relArgs]!
        -- Three arguments: trfl's rhs, t's rhs, and eq/heq. t's rhs already set at (*)
        let rhsArgIdx := kindArgIdxs[info.rhsIdx - info.relArgs]! -- lhs =/≍ rhs
        -- Set up `trfl` as `lhs ~ lhs`, and prove the eq/heq for the lhs using refl
        unless ← approxDefEq <| isDefEq args[lhsArgIdx]! lhs do throwCongrError ()
        try (← args[lhsArgIdx+2]!.mvarId!.heqOfEq).refl catch _ => throwCongrError ()
        unless ← approxDefEq <| isDefEq args[rhsArgIdx]! lhs do throwCongrError ()
        -- This is the goal we want to reduce the relation to:
        let goalEq := args[rhsArgIdx+2]!.mvarId!
        goalEq.setKind .syntheticOpaque
        goalEq.setTag (← goal.getTag)
        -- Reduce the main goal to proving reflexivity:
        let goal ← goal.replaceTargetEq trfl (← mkEqSymm (← mkEqOfHEq (mkAppN congr.proof args) (check := false)))
        -- Apply reflexivity lemmas. This will also ensure remaining trfl arguments are synthesized.
        applyLemmas `liftReflToEq goal rel lems
        -- Now prove remaining equality goals
        let goalEq ← goalEq.heqOfEq
        if !allowHEq then
          -- Consistency check. This should be an Eq already since in this case `typesEq` must be true here.
          assert! (← goalEq.getType).isEq
        let mut unsolved := #[]
        for kind in congr.argKinds, idx in kindArgIdxs do
          if idx != lhsArgIdx && idx != rhsArgIdx && kind matches .eq | .heq then
            let g ← pure args[idx+2]!.mvarId!
            let g ← g.heqOfEq
            try
              g.refl
                <|> do (guard <| ← g.proofIrrelHeq)
                <|> do (guard <| ← g.subsingletonElim)
                <|> do
                      let pf ← mkAppM ``type_eq_of_heq #[.mvar goalEq]
                      guard <| ← isDefEq (.mvar g) pf
                      g.assign pf
            catch _ =>
              unsolved := unsolved.push g
        unless unsolved.isEmpty do
          throwError MessageData.tagged `Tactic.unsolvedGoals <| m!"Failed rewrite relation{indentExpr t}\nto be reflexive. Unsolved goals\n{goalsToMessageData unsolved.toList}"
        return goalEq
  else
    tryUnfold goal t (throwRelError `liftReflToEq goal)
where
  tryUnfold (goal : MVarId) (t : Expr) (err : MetaM MVarId) : MetaM MVarId := do
    if let some t' ← withReducible <| unfoldDefinition? t then
      liftReflToEqHEqCore goal t' (failIfUnchanged := false)
    else
      err

/--
Convert a goal of the form `x ~ y` into the form `x = y`, where `~` is a reflexive
relation, that is, a relation which has a reflexive lemma tagged with the attribute `@[refl]`.

Options:
- If `failIfUnchanged = true` (default: `false`) then if this can't be done, returns the original `MVarId`.
- If `allowHEq = true` (default: `false`) then allows converting the goal to `x ≍ y`.
-/
def _root_.Lean.MVarId.liftReflToEq (goal : MVarId) (allowHEq : Bool := false) (failIfUnchanged : Bool := false) : MetaM MVarId := do
  goal.withContext do
    goal.checkNotAssigned `liftReflToEq
    let t ← goal.getType
    let act := liftReflToEqHEqCore goal t (allowHEq := allowHEq) (failIfUnchanged := failIfUnchanged)
    if failIfUnchanged then
      act
    else
      return (← observing? act).getD goal

end Lean.Meta.Rfl
