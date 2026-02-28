/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Joachim Breitner
-/

module

prelude
public import Lean.Meta.Basic

namespace Lean.Meta

@[extern "lean_instantiate_expr_mvars_all"]
private opaque instantiateAllMVarsImp (mctx : MetavarContext) (e : Expr) :
  Option (MetavarContext × Expr)

/-- Like `instantiateMVars` but throws if an unassigned mvar is encountered
    under an active fvar substitution. Use at call sites where all mvars are
    known to be assigned — a throw indicates a wrong assumption. -/
public def instantiateAllMVars (e : Expr) : MetaM Expr := do
  if !e.hasMVar then return e
  match instantiateAllMVarsImp (← getMCtx) e with
  | some (mctx, eNew) => modifyMCtx fun _ => mctx; return eNew
  | none => throwError "instantiateAllMVars: unexpected unassigned mvar in {e}"

end Lean.Meta
