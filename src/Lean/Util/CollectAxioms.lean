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
  visited : NameSet    := {}
  axioms  : Array Name := #[]

abbrev M := ReaderT Environment $ StateM State

/--
Core axiom collection logic, parameterized on a cache lookup function.
The cache is checked first; on a miss, walks the constant's body/type from `env.checked.get`.
-/
private partial def collectCore (lookupCache : Environment → Name → Option (Array Name))
    (c : Name) : M Unit := do
  let collectExpr (e : Expr) : M Unit := e.getUsedConstants.forM (collectCore lookupCache)
  let s ← get
  unless s.visited.contains c do
    modify fun s => { s with visited := s.visited.insert c }
    let env ← read
    if let some axioms := lookupCache env c then
      for ax in axioms do
        if ax == c then
          modify fun s => { s with axioms := s.axioms.push c }
        else
          collectCore lookupCache ax
      return
    -- We should take the constant from the kernel env, which may differ from the one in the elab
    -- env in case of (async) errors.
    match env.checked.get.find? c with
    | some (ConstantInfo.axiomInfo v)  =>
        modify fun s => { s with axioms := (s.axioms.push c) }
        collectExpr v.type
    | some (ConstantInfo.defnInfo v)   => collectExpr v.type *> collectExpr v.value
    | some (ConstantInfo.thmInfo v)    => collectExpr v.type *> collectExpr v.value
    | some (ConstantInfo.opaqueInfo v) => collectExpr v.type *> collectExpr v.value
    | some (ConstantInfo.quotInfo _)   => pure ()
    | some (ConstantInfo.ctorInfo v)   => collectExpr v.type
    | some (ConstantInfo.recInfo v)    => collectExpr v.type
    | some (ConstantInfo.inductInfo v) => collectExpr v.type *> v.ctors.forM (collectCore lookupCache)
    | none                             => pure ()

end CollectAxioms

/--
Extension state that holds a merged lookup map built from all imported modules' extension entries.
This map is built once at import time by `addImportedFn`, making it available to both
`exportEntriesFnEx` (at export time) and `collect` (at query time) without circular references.
-/
private structure ExportedAxiomsState where
  /-- Merged lookup map from all imported modules' extension entries. -/
  importedLookup : NameMap (Array Name) := {}

instance : Inhabited ExportedAxiomsState := ⟨{}⟩

/--
Environment extension that records axiom dependencies for declarations whose bodies are stripped
when exported under the module system. Entries are computed lazily at olean export time by
`exportEntriesFn`, not during elaboration. During elaboration, `collectAxioms` walks bodies
directly. Downstream modules look up pre-computed entries for imported stripped declarations.

At export time, the collection uses the same logic as `#print axioms`: imported stripped
declarations are resolved via the extension's imported lookup map (built at import time from
upstream modules' entries). This ensures the recorded axioms are exactly the real, user-visible
axioms, and that the extension data is stable across body-only changes.
-/
private builtin_initialize exportedAxiomsExt :
    PersistentEnvExtension (Name × Array Name) (Name × Array Name) ExportedAxiomsState ←
  registerPersistentEnvExtension {
    mkInitial     := pure {}
    addImportedFn := fun importedEntries => do
      let lookup := importedEntries.foldl (init := ({} : NameMap (Array Name))) fun map moduleEntries =>
        moduleEntries.foldl (init := map) fun map (name, axioms) =>
          map.insert name axioms
      pure { importedLookup := lookup }
    addEntryFn    := fun s _ => s -- No entries added during elaboration
    exportEntriesFnEx env s level :=
      -- At `.private` level, all bodies are preserved; no axiom recording needed.
      if level == .private then #[]
      else
        -- At export time, all async tasks are complete, so `env.checked.get` is safe.
        -- Find current-module constants whose bodies are stripped in the exported view
        -- (they appear as axioms in the exported view but have bodies in the private view).
        let privateEnv := env.setExporting false
        let strippedNames : Array Name := env.checked.get.constants.foldStage2
          (fun names name _ =>
            match env.find? name, privateEnv.find? name with
            | some exported, some private_ =>
              if exported.isAxiom && !private_.isAxiom then names.push name
              else names
            | _, _ => names) #[]
        -- Compute axioms for each stripped constant. We accumulate a cache of already-computed
        -- results so that local declarations shared between multiple stripped defs are not
        -- traversed more than once.
        let (_, result) := strippedNames.foldl
          (fun (cache, result) name =>
            let lookupWithCache (_ : Environment) (c : Name) : Option (Array Name) :=
              (s.importedLookup.find? c).orElse fun _ => cache.find? c
            let (_, st) := ((CollectAxioms.collectCore lookupWithCache name).run privateEnv).run {}
            let axioms := st.axioms.qsort Name.lt
            (cache.insert name axioms, result.push (name, axioms)))
          (({} : NameMap (Array Name)), #[])
        result
    asyncMode     := .mainOnly
  }

namespace CollectAxioms

/-- Collect axioms, consulting `exportedAxiomsExt` for imported stripped declarations. -/
private partial def collect (c : Name) : M Unit :=
  let lookup := (exportedAxiomsExt.getState (asyncMode := .mainOnly) · |>.importedLookup.find? ·)
  collectCore lookup c

end CollectAxioms

public def collectAxioms [Monad m] [MonadEnv m] (constName : Name) : m (Array Name) := do
  let env ← getEnv
  let (_, s) := ((CollectAxioms.collect constName).run env).run {}
  pure s.axioms

end Lean
