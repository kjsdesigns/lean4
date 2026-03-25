/-
Copyright (c) 2020 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/
module

prelude
public import Lean.MonadEnv

namespace Lean

private builtin_initialize exportedAxiomsExt : MapDeclarationExtension (Array Name) ←
  -- Use `sync` so we can add entries from the `addDecl` main env without async restrictions
  mkMapDeclarationExtension (asyncMode := .sync)

namespace CollectAxioms

structure State where
  visited : NameSet    := {}
  axioms  : Array Name := #[]

abbrev M := ReaderT Environment $ StateM State

private partial def collect (c : Name) : M Unit := do
  let collectExpr (e : Expr) : M Unit := e.getUsedConstants.forM collect
  let s ← get
  unless s.visited.contains c do
    modify fun s => { s with visited := s.visited.insert c }
    let env ← read
    if let some axioms := exportedAxiomsExt.find? env c then
      for ax in axioms do
        if ax == c then
          modify fun s => { s with axioms := s.axioms.push c }
        else
          collect ax
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
    | some (ConstantInfo.inductInfo v) => collectExpr v.type *> v.ctors.forM collect
    | none                             => pure ()

/--
Like `collect` but does NOT access `env.checked` (which may block on async constants).
For current-module constants, uses `exportedAxiomsExt`.
For imported constants, uses `Kernel.Environment.find?` on the base env
(which is eagerly available and does not block).
-/
private partial def collectNonBlocking (c : Name) : M Unit := do
  let collectExpr (e : Expr) : M Unit := e.getUsedConstants.forM collectNonBlocking
  let s ← get
  unless s.visited.contains c do
    modify fun s => { s with visited := s.visited.insert c }
    let env ← read
    -- For current-module constants, use the pre-recorded axioms
    if let some axioms := exportedAxiomsExt.find? (asyncMode := .local) env c then
      for ax in axioms do
        if ax == c then
          modify fun s => { s with axioms := s.axioms.push c }
        else
          collectNonBlocking ax
      return
    -- For imported constants, use the base kernel env (non-blocking).
    -- `Kernel.Environment.find?` on the base env does not block because
    -- the base env is eagerly available. Note: `Environment.find?` would
    -- block due to async constant lookups, so we bypass it.
    -- For current-module async constants not yet in the extension, they are
    -- not our dependencies (since we register before their async tasks).
    match (env.importEnv?.getD env).find? c with
    | some (ConstantInfo.axiomInfo v)  =>
        modify fun s => { s with axioms := (s.axioms.push c) }
        collectExpr v.type
    | some (ConstantInfo.defnInfo v)   => collectExpr v.type *> collectExpr v.value
    | some (ConstantInfo.thmInfo v)    => collectExpr v.type *> collectExpr v.value
    | some (ConstantInfo.opaqueInfo v) => collectExpr v.type *> collectExpr v.value
    | some (ConstantInfo.quotInfo _)   => pure ()
    | some (ConstantInfo.ctorInfo v)   => collectExpr v.type
    | some (ConstantInfo.recInfo v)    => collectExpr v.type
    | some (ConstantInfo.inductInfo v) => collectExpr v.type *> v.ctors.forM collectNonBlocking
    | none                             => pure ()

/--
Collect axioms for a `ConstantInfo` that may not be in the environment yet.
Uses the non-blocking collection strategy.
-/
private def collectForInfoNonBlocking (info : ConstantInfo) : M Unit := do
  let collectExpr (e : Expr) : M Unit := e.getUsedConstants.forM collectNonBlocking
  modify fun s => { s with visited := s.visited.insert info.name }
  match info with
  | .axiomInfo v  =>
      modify fun s => { s with axioms := s.axioms.push info.name }
      collectExpr v.type
  | .defnInfo v   => collectExpr v.type *> collectExpr v.value
  | .thmInfo v    => collectExpr v.type *> collectExpr v.value
  | .opaqueInfo v => collectExpr v.type *> collectExpr v.value
  | .quotInfo _   => pure ()
  | .ctorInfo v   => collectExpr v.type
  | .recInfo v    => collectExpr v.type
  | .inductInfo v => collectExpr v.type *> v.ctors.forM collectNonBlocking

end CollectAxioms

public def collectAxioms [Monad m] [MonadEnv m] (constName : Name) : m (Array Name) := do
  let env ← getEnv
  let (_, s) := ((CollectAxioms.collect constName).run env).run {}
  pure s.axioms

/--
Registers axioms used by a `ConstantInfo` in an environment extension so they can be retrieved
even after the declaration's body becomes inaccessible (e.g., when exported as an axiom under the
module system). Does not access `env.checked`, safe for async main environments.
-/
public def registerAxiomsForInfo [Monad m] [MonadEnv m] (info : ConstantInfo) : m Unit := do
  let env ← getEnv
  let (_, s) := ((CollectAxioms.collectForInfoNonBlocking info).run env).run {}
  modifyEnv (exportedAxiomsExt.insert · info.name s.axioms)

end Lean
