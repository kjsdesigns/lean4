/-
Copyright (c) 2020 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/
module

prelude
public import Lean.MonadEnv

namespace Lean

namespace CollectAxioms

structure State where
  /-- Set of constants already visited, to prevent infinite recursion (e.g., inductives ↔ constructors). -/
  visited : NameSet := {}
  /-- Axioms accumulated for the current constant being processed. -/
  axioms  : NameSet := {}

abbrev M := ReaderT Environment $ StateM State

private def insertArray (s : NameSet) (axs : Array Name) : NameSet :=
  axs.foldl (init := s) fun acc ax => acc.insert ax

/--
Collect axioms reachable from constant `c`, using `extFind?` to look up pre-computed axioms.

When processing a constant not found in `extFind?`, the function recurses into the constant's
dependencies, accumulating axioms in `State.axioms`. `State.visited` prevents infinite recursion
for mutually referential declarations (e.g., inductives ↔ constructors).
-/
private partial def collect
    (extFind? : Name → Option (Array Name))
    (c : Name) : M Unit := do
  let env ← read
  -- Check extension for pre-computed axioms
  if let some axs := extFind? c then
    modify fun s => { s with axioms := insertArray s.axioms axs }
    return
  -- Check if already visited (cycle prevention)
  if (← get).visited.contains c then
    return
  modify fun s => { s with visited := s.visited.insert c }
  let collectExpr (e : Expr) : M Unit := e.getUsedConstants.forM (collect extFind?)
  -- Take constants from the kernel env, which may differ from the elab env for (async) errors.
  match env.checked.get.find? c with
  | some (.axiomInfo v)  =>
      modify fun s => { s with axioms := s.axioms.insert c }
      collectExpr v.type
  | some (.defnInfo v)   => collectExpr v.type *> collectExpr v.value
  | some (.thmInfo v)    => collectExpr v.type *> collectExpr v.value
  | some (.opaqueInfo v) => collectExpr v.type *> collectExpr v.value
  | some (.quotInfo _)   => pure ()
  | some (.ctorInfo v)   => collectExpr v.type
  | some (.recInfo v)    => collectExpr v.type
  | some (.inductInfo v) => collectExpr v.type *> v.ctors.forM (collect extFind?)
  | none                 => pure ()

/-- Collect axioms for `c` and return its sorted axiom array. -/
def collectFor (extFind? : Name → Option (Array Name))
    (env : Environment) (c : Name) : Array Name :=
  let (_, s) := (collect extFind? c).run env |>.run {}
  s.axioms.toArray.qsort Name.lt

end CollectAxioms

/-- Extension mapping each declaration to its sorted axiom dependencies.
    Entries are added at declaration time in `addDecl`. -/
builtin_initialize axiomDataExt : MapDeclarationExtension (Array Name) ←
  mkMapDeclarationExtension (asyncMode := .async .asyncEnv)

/-- Compute and store axiom dependencies for the given declarations.
    Called from `addDecl` after the declarations are added to the kernel. -/
public def computeAndStoreAxioms [Monad m] [MonadEnv m] (declNames : List Name) : m Unit := do
  let env ← getEnv
  let privateEnv := env.setExporting false
  for name in declNames do
    let env' ← getEnv
    let extFind? := fun c => axiomDataExt.find? env' c
    let axs := CollectAxioms.collectFor extFind? privateEnv name
    modifyEnv fun env => axiomDataExt.insert env name axs

/-- Collect all axioms transitively used by a constant. -/
public def collectAxioms [Monad m] [MonadEnv m] (constName : Name) : m (Array Name) := do
  let env ← getEnv
  -- Check the extension (covers imported and current-module declarations)
  if let some axs := axiomDataExt.find? env constName then
    return axs
  -- Fallback: compute on the fly (bootstrap / failed declarations)
  let privateEnv := env.setExporting false
  let extFind? := fun c => axiomDataExt.find? env c
  return CollectAxioms.collectFor extFind? privateEnv constName

end Lean
