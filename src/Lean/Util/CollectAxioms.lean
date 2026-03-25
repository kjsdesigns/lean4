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

/--
Collect axioms without consulting any cache. Used at export time when all declaration bodies are
still available in `env.checked.get`. Imported constants whose bodies were stripped will appear as
axioms; their transitive dependencies are resolved by downstream consumers via the extension.
-/
private partial def collectDirect (c : Name) : M Unit :=
  collectCore (fun _ _ => none) c

end CollectAxioms

/--
Environment extension that records axiom dependencies for declarations whose bodies are stripped
when exported under the module system. Entries are computed lazily at olean export time by
`exportEntriesFn`, not during elaboration. During elaboration, `collectAxioms` walks bodies
directly. Downstream modules look up pre-computed entries for imported stripped declarations.
-/
private builtin_initialize exportedAxiomsExt : MapDeclarationExtension (Array Name) ←
  mkMapDeclarationExtension (asyncMode := .mainOnly) (exportEntriesFn := fun env _state level =>
    -- At `.private` level, all bodies are preserved; no axiom recording needed.
    if level == .private then #[]
    else
      -- At export time, all async tasks are complete, so `env.checked.get` is safe.
      -- Find current-module constants whose bodies are stripped in the exported view
      -- (they appear as axioms in the exported view but have bodies in the private view).
      let privateEnv := env.setExporting false
      let map : NameMap (Array Name) := env.checked.get.constants.foldStage2
        (fun map name _ =>
          match env.find? name, privateEnv.find? name with
          | some exported, some private_ =>
            if exported.isAxiom && !private_.isAxiom then
              let (_, s) := ((CollectAxioms.collectDirect name).run privateEnv).run {}
              map.insert name s.axioms
            else map
          | _, _ => map) {}
      map.toArray)

namespace CollectAxioms

/-- Collect axioms, consulting `exportedAxiomsExt` for imported stripped declarations. -/
private partial def collect (c : Name) : M Unit :=
  collectCore (fun env c => exportedAxiomsExt.find? env c) c

end CollectAxioms

public def collectAxioms [Monad m] [MonadEnv m] (constName : Name) : m (Array Name) := do
  let env ← getEnv
  let (_, s) := ((CollectAxioms.collect constName).run env).run {}
  pure s.axioms

end Lean
