/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/

import Radix.TypeCheck
import Std.Data.HashMap
import Radix.Eval.Stmt

/-! # Type Safety

Progress and preservation theorem statements for the Radix type system.
-/

namespace Radix
open Std

/-- A value is well-typed if it matches the expected type. -/
def Value.hasType : Value → Ty → Prop
  | .uint64 _, .uint64 => True
  | .bool _,   .bool   => True
  | .unit,     .unit    => True
  | .str _,    .string  => True
  | .addr _,   .array _ => True
  | _, _ => False

/-- Type preservation: if a well-typed expression evaluates to a value,
    that value has the expected type. -/
theorem Expr.preservation (Γ : TyEnv) (sigs : FunSigs) (σ : PState)
    (e : Expr) (ty : Ty) (v : Value)
    (henv : ∀ x ty, Γ.get? x = some ty → ∃ v, σ.getVar x = some v ∧ Value.hasType v ty)
    (hty : Expr.typeOf Γ sigs e = some ty)
    (heval : Expr.eval σ e = some v) :
    Value.hasType v ty := by
  sorry

/-- Progress: a well-typed expression in a well-typed environment can always
    be evaluated (modulo function calls and heap operations). -/
theorem Expr.progress (Γ : TyEnv) (sigs : FunSigs) (σ : PState)
    (e : Expr) (ty : Ty)
    (henv : ∀ x ty, Γ.get? x = some ty → ∃ v, σ.getVar x = some v ∧ Value.hasType v ty)
    (hty : Expr.typeOf Γ sigs e = some ty)
    (hno_call : ∀ f args, e ≠ Expr.call f args) :
    ∃ v, Expr.eval σ e = some v := by
  sorry

end Radix
