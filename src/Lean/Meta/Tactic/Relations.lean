/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Kyle Miller
-/
module

prelude
public import Lean.Meta.WHNF
public import Lean.Meta.CollectFVars

public section

/-!
# Support for binary relation recognition

This module provides an environment extension for recording information about binary relations.
In particular, in a type `R x1 x2 ... xn`, what prefix `R x1 ... xm` is "the" relation,
and which arguments `xi` and `xj` are the left and right objects being related.
The objects do not need to come in order.
Relations also do not need the objects to have the same type (e.g. `Membership.mem` has both
heterogeneous types and objects in reverse order).

These are used by the `Lean.MVarId.applyRfl` and `Lean.MVarId.applySymm` tactics.
-/

namespace Lean.Meta

/--
Structure recording the way in which a declaration is a binary relation.
-/
structure RelationInfo where
  /-- Number of arguments total to expect. -/
  numArgs : Nat
  /-- Size of prefix of arguments that should be used for relation identification. -/
  relArgs : Nat
  /-- The index for the logical "left" argument. -/
  lhsIdx : Nat
  /-- The index for the logical "right" argument. -/
  rhsIdx : Nat
  deriving Inhabited

/-- Environment extension for relation information. -/
initialize relationExt :
    SimpleScopedEnvExtension (Name × RelationInfo) (NameMap RelationInfo) ←
  registerSimpleScopedEnvExtension {
    addEntry := fun st (n, i) => st.insert n i
    initial := {}
  }

/--
Looks up the relation information for a given declaration, if present.
-/
def getRelationInfo? [Monad m] [MonadEnv m] (declName : Name) : m (Option RelationInfo) :=
  return (relationExt.getState (← getEnv)).find? declName

/--
Registers the declaration as a relation with the given `RelationInfo`.
-/
def registerRelation [Monad m] [MonadResolveName m] [MonadEnv m]
    (declName : Name) (info : RelationInfo) (kind : AttributeKind) : m Unit := do
  relationExt.add (declName, info) kind

/--
Infers plausible relation information for the given declaration, or else throws an error.
-/
def inferRelationInfo (declName : Name) (args : Array Syntax) : MetaM RelationInfo := do
  if args.size > 0 && args.size != 2 then
    throwErrorAt (mkNullNode args) "Must have exactly two arguments if arguments are provided"
  let declInfo ← getConstVal declName
  withLCtx {} {} do
  forallTelescopeReducing declInfo.type fun xs ty => do
    if ← findExprDependsOn ty (pf := fun _ => true) then
      throwError "Invalid relation: type `{inlineExpr ty}` in `{.ofConstName declName}` depends on arguments"
    let argNames ← xs.mapM fun x => x.fvarId!.getUserName
    let bis ← xs.mapM fun x => x.fvarId!.getBinderInfo
    let mut operands : Array Nat := #[]
    for arg in args do
      if let some idx := arg.isNatLit? then
        if idx == 0 then throwErrorAt arg "Invalid argument index `0`: Index must be greater than 0"
        let idx := idx - 1
        if idx >= argNames.size then
          throwErrorAt arg "Invalid argument index `{idx}`: `{.ofConstName declName}` has only {argNames.size} arguments"
        else
          if operands.contains idx then throwErrorAt arg "Invalid argument index `{idx + 1}`: \
            The argument at this index (`{argNames[idx]!}`) has already been specified as an argument"
          operands := operands.push idx
      else
        let argName := arg.getId
        if let some idx := argNames.idxOf? argName then
          if operands.contains idx then throwErrorAt arg "Invalid argument name `{argName}`: \
            It has already been specified as an argument"
          operands := operands.push idx
        else
          throwErrorAt arg "Invalid argument name `{argName}`: `{.ofConstName declName}` does not have an argument with this name"
    if operands.size < 2 then
      let explicits := bis.zipIdx.filter fun (bi, _) => bi.isExplicit
      if explicits.size < 2 then
        throwError "Invalid relation: `{.ofConstName declName}` does not have at least two explicit arguments"
      operands := explicits[explicits.size-2:].toArray.map (·.2)
    assert! operands.size == 2
    let lhsIdx := operands[0]!
    let rhsIdx := operands[1]!
    if lhsIdx == rhsIdx then
      throwError "Invalid argument indices: They are both `{lhsIdx + 1}` but must be different"
    -- We now analyze which arguments parameterize the relation itself.
    -- We assume `relArgs ≤ min lhsIdx rhsIdx`.
    -- Some of the parameters setting up the lhs or rhs might come before both the lhs and rhs.
    -- Heuristic: the arguments that both or neither depend on parameterize the relation.
    let lhsDeps ← (Lean.collectFVars {} xs[lhsIdx]!).addDependencies
    let rhsDeps ← (Lean.collectFVars {} xs[rhsIdx]!).addDependencies
    let mut relArgs := 0
    for x in xs[:min lhsIdx rhsIdx] do
      if lhsDeps.fvarSet.contains x.fvarId! = rhsDeps.fvarSet.contains x.fvarId! then
        relArgs := relArgs + 1
      else
        break
    let info : RelationInfo := { numArgs := xs.size, relArgs, lhsIdx, rhsIdx }
    trace[Meta.Tactic.relation] "Relation `{declName}` has {info.numArgs} arguments. \
      The first {info.relArgs} argument(s) identify the relation. \
      The lhs and rhs are argument numbers {info.lhsIdx+1} and {info.rhsIdx+1}."
    return info


/--
Marks a definition to be a binary relation.

`@[relation]` can take additional arguments for the parameter names or indices (starting at 1) of
the parameters that should be used as the left and right arguments.
By default, the last two explicit arguments are used, in order.
-/
@[builtin_doc]
builtin_initialize registerBuiltinAttribute {
  name := `relation
  descr := "Registers a declaration as a relation."
  add := fun decl stx kind => MetaM.run' do
    if let some _ ← getRelationInfo? decl then
      throwError "The relation `{.ofConstName decl}` has already been registered"
    let info ← inferRelationInfo decl stx[1].getArgs
    registerRelation decl info kind
}

structure RelationMatch extends RelationInfo where
  declName : Name
  rel : Expr
  lhs : Expr
  rhs : Expr

private def decomposeRelation (declName : Name) (info : RelationInfo) (e : Expr) :
    Option RelationMatch :=
  if e.getAppNumArgs == info.numArgs then
    let rel := e.getAppPrefix info.relArgs
    let lhs := e.getArg! info.lhsIdx
    let rhs := e.getArg! info.rhsIdx
    some { info with declName, rel, lhs, rhs }
  else
    none

/--
If `e` is a relation expression, returns information about it along with a decomposition
of the expression into the left and right operands and the relation itself.
-/
def matchesRelation? [Monad m] [MonadEnv m] (e : Expr) : m (Option RelationMatch) := do
  let .const declName _ := e.getAppFn | return none
  let some info ← getRelationInfo? declName | return none
  return decomposeRelation declName info e

/--
Like `matchesRelation?`, but infers `RelationInfo` if `e` does not represent a known relation
expression. Applies `whnfCore` to `e`. -/
def matchesPotentialRelation? (e : Expr) : MetaM (Option RelationMatch) := do
  let e ← whnfCore e
  if let .const declName _ := e.getAppFn then
    if let some info ← getRelationInfo? declName then
      return decomposeRelation declName info e
    try
      let info ← withoutModifyingState <| inferRelationInfo declName #[]
      return decomposeRelation declName info e
    catch _ =>
      return none
  else
    return none

builtin_initialize
  registerTraceClass `Meta.Tactic.relation

end Lean.Meta
