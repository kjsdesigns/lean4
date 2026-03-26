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
  /-- Cache mapping constants to their (sorted) axiom dependencies. -/
  seen   : NameMap (Array Name) := {}
  /-- Axioms accumulated for the current constant being processed. -/
  axioms : NameSet := {}

abbrev M := ReaderT Environment $ StateM State

def runM (env : Environment) (x : M α) : α :=
  x.run env |>.run' {}

private def insertArray (s : NameSet) (axs : Array Name) : NameSet :=
  axs.foldl (init := s) fun acc ax => acc.insert ax

/--
Collect axioms reachable from constant `c`, using `extFind?` to look up pre-computed axioms
for imported declarations. Results are cached in `State.seen`.

When processing a constant not found in `extFind?` or the cache, the function temporarily
clears the axiom accumulator, recurses into the constant's dependencies, caches the result
in `seen`, and merges the collected axioms back.
-/
private partial def collect
    (extFind? : Name → Option (Array Name))
    (c : Name) : M Unit := do
  let env ← read
  -- Check extension for pre-computed axioms (imported declarations)
  if let some axs := extFind? c then
    modify fun s => { s with axioms := insertArray s.axioms axs, seen := s.seen.insert c axs }
    return
  -- Check local cache
  let s ← get
  if let some axs := s.seen.find? c then
    modify fun s => { s with axioms := insertArray s.axioms axs }
    return
  -- Recurse: temporarily clear axioms to isolate this constant's contribution.
  -- Insert sentinel to prevent infinite recursion (e.g., inductives ↔ constructors).
  let savedAxioms := s.axioms
  modify fun s => { s with axioms := {}, seen := s.seen.insert c #[] }
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
  -- Cache result (sorted for canonical order) and merge back into saved axioms
  let collected := (← get).axioms
  let result := collected.toArray.qsort Name.lt
  modify fun s => { s with
    seen   := s.seen.insert c result
    axioms := insertArray savedAxioms result
  }

/-- Collect axioms for `c` and return its sorted axiom list from the cache. -/
def collectAndGet
    (extFind? : Name → Option (Array Name))
    (c : Name) : M (Array Name) := do
  collect extFind? c
  let some axs := (← get).seen.find? c | panic! s!"collectAndGet: '{c}' not in seen after collect"
  return axs

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
  let extFind? := fun c => axiomDataExt.find? env c
  let results := CollectAxioms.runM privateEnv do
    declNames.mapM fun name =>
      return (name, ← CollectAxioms.collectAndGet extFind? name)
  modifyEnv fun env =>
    results.foldl (init := env) fun env (name, axs) =>
      axiomDataExt.insert env name axs

/-- Collect all axioms transitively used by a constant. -/
public def collectAxioms [Monad m] [MonadEnv m] (constName : Name) : m (Array Name) := do
  let env ← getEnv
  -- Check the extension (covers imported and current-module declarations)
  if let some axs := axiomDataExt.find? env constName then
    return axs
  -- Fallback: compute on the fly (bootstrap / failed declarations)
  let privateEnv := env.setExporting false
  let extFind? := fun c => axiomDataExt.find? env c
  return CollectAxioms.runM privateEnv do
    CollectAxioms.collectAndGet extFind? constName

end Lean
