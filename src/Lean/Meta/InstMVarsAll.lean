/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Joachim Breitner
-/

module

prelude
public import Lean.Meta.Basic

namespace Lean.Meta

@[extern "lean_instantiate_expr_mvars_original"]
private opaque instantiateMVarsOriginalImp (mctx : MetavarContext) (e : Expr) :
  MetavarContext × Expr

@[extern "lean_instantiate_expr_mvars_all"]
private opaque instantiateAllMVarsImp (mctx : MetavarContext) (e : Expr) :
  MetavarContext × Expr

@[extern "lean_instantiate_expr_mvars_all_sharing"]
private opaque instantiateAllMVarsSharingImp (mctx : MetavarContext) (e : Expr) :
  MetavarContext × Expr

/-- The original single-pass `instantiateMVars` implementation, exposed for benchmarking
    independently of which implementation is the default. -/
public def instantiateMVarsOriginal (e : Expr) : MetaM Expr := do
  if !e.hasMVar then return e
  let (mctx, eNew) := instantiateMVarsOriginalImp (← getMCtx) e
  modifyMCtx fun _ => mctx; return eNew

/-- Like `instantiateMVars` but uses a fused two-pass approach.
    Pass 1 resolves direct mvar assignments with write-back.
    Pass 2 resolves delayed assignments with a fused fvar substitution,
    avoiding separate `replace_fvars` calls.

    This variant may lose sharing across delayed-mvar boundaries. -/
public def instantiateAllMVars (e : Expr) : MetaM Expr := do
  if !e.hasMVar then return e
  let (mctx, eNew) := instantiateAllMVarsImp (← getMCtx) e
  modifyMCtx fun _ => mctx; return eNew

/-- Like `instantiateAllMVars` but preserves sharing across delayed-mvar boundaries
    using a scope-tracked cache stack. Results that only depend on outer-scope fvar
    substitutions are cached at the outermost valid scope, so they are reused when
    the same subexpression appears in sibling delayed-mvar resolutions.

    This produces nearly optimal output sharing (matching `instantiateMVars`) at the
    cost of O(scope_depth) cache lookups instead of O(1). -/
public def instantiateAllMVarsSharing (e : Expr) : MetaM Expr := do
  if !e.hasMVar then return e
  let (mctx, eNew) := instantiateAllMVarsSharingImp (← getMCtx) e
  modifyMCtx fun _ => mctx; return eNew

end Lean.Meta
