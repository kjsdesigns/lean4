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

/--
Collect axioms reachable from constant `c`, using `extFind?` to look up pre-computed axioms
for imported stripped declarations. Results are cached in `State.seen`.

When processing a constant not found in `extFind?` or the cache, the function temporarily
clears the axiom accumulator, recurses into the constant's dependencies, caches the result
in `seen`, and merges the collected axioms back.
-/
private partial def collect
    (extFind? : Environment → Name → Option (Array Name))
    (c : Name) : M Unit := do
  let env ← read
  -- Check extension for pre-computed axioms (imported stripped declarations)
  if let some axs := extFind? env c then
    modify fun s => { s with axioms := axs.foldl (init := s.axioms) fun acc ax => acc.insert ax }
    return
  -- Check local cache
  let s ← get
  if let some axs := s.seen.find? c then
    modify fun s => { s with axioms := axs.foldl (init := s.axioms) fun acc ax => acc.insert ax }
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
    axioms := result.foldl (init := savedAxioms) fun acc ax => acc.insert ax
  }

end CollectAxioms

/--
Extension state holding imported module entries for efficient lookup of
pre-computed axiom data for stripped declarations. Entries are stored per-module
(not merged) and looked up via `getModuleIdxFor?` + binary search.
-/
private structure ExportedAxiomsState where
  importedModuleEntries : Array (Array (Name × Array Name)) := #[]

instance : Inhabited ExportedAxiomsState := ⟨{}⟩

/-- Look up pre-computed axioms for an imported stripped declaration. -/
private def ExportedAxiomsState.find? (s : ExportedAxiomsState) (env : Environment)
    (c : Name) : Option (Array Name) :=
  match env.getModuleIdxFor? c with
  | some modIdx =>
    if h : modIdx.toNat < s.importedModuleEntries.size then
      match s.importedModuleEntries[modIdx].binSearch (c, #[]) (fun a b => Name.quickLt a.1 b.1) with
      | some entry => some entry.2
      | none       => none
    else none
  | none => none

/--
Environment extension that records axiom dependencies for declarations whose bodies are stripped
when exported under the module system. Entries are computed at olean export time by
`exportEntriesFnEx`, not during elaboration. During elaboration, `collectAxioms` walks bodies
directly. Downstream modules look up pre-computed entries for imported stripped declarations.
-/
private builtin_initialize exportedAxiomsExt :
    PersistentEnvExtension (Name × Array Name) (Name × Array Name) ExportedAxiomsState ←
  registerPersistentEnvExtension {
    mkInitial     := pure {}
    addImportedFn := fun importedEntries => pure { importedModuleEntries := importedEntries }
    addEntryFn    := fun s _ => s
    exportEntriesFnEx env s level :=
      if level == .private then #[]
      else
        let privateEnv := env.setExporting false
        -- Find current-module constants whose bodies are stripped in the exported view.
        let strippedNames := env.checked.get.constants.foldStage2
          (fun names name _ =>
            match env.find? name, privateEnv.find? name with
            | some exported, some private_ =>
              if exported.isAxiom && !private_.isAxiom then names.push name
              else names
            | _, _ => names) #[]
        -- Compute axioms for each stripped constant within a shared state (for caching).
        let (_, finalState) :=
          (strippedNames.forM (CollectAxioms.collect s.find?)).run privateEnv |>.run {}
        -- Extract results, sorted by name for binary search at import time.
        let entries := strippedNames.filterMap fun name =>
          finalState.seen.find? name |>.map (name, ·)
        entries.qsort fun a b => Name.quickLt a.1 b.1
    asyncMode     := .mainOnly
  }

/-- Collect all axioms transitively used by a constant. -/
public def collectAxioms [Monad m] [MonadEnv m] (constName : Name) : m (Array Name) := do
  let env ← getEnv
  let privateEnv := env.setExporting false
  let s := exportedAxiomsExt.getState (asyncMode := .mainOnly) env
  let (_, st) := ((CollectAxioms.collect s.find? constName).run privateEnv).run {}
  pure (st.axioms.toArray.qsort Name.lt)

end Lean
