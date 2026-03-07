/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/

import Radix.Eval.Stmt
import Std.Data.HashMap

/-! # Function Inlining

Inline small functions at their call sites.
-/

namespace Radix
open Std

/-- Rough measure of statement size for inlining heuristics. -/
partial def Stmt.size : Stmt → Nat
  | .skip => 0
  | .assign _ _ => 1
  | .seq s₁ s₂ => s₁.size + s₂.size
  | .ite _ t f => 1 + t.size + f.size
  | .while _ b => 1 + b.size
  | .decl _ _ _ => 1
  | .alloc _ _ _ => 1
  | .free _ => 1
  | .arrSet _ _ _ => 1
  | .ret _ => 1
  | .block stmts => stmts.foldl (fun acc s => acc + s.size) 0
  | .callStmt _ _ => 1

/-- Maximum size for a function body to be considered for inlining. -/
def inlineThreshold : Nat := 10

/-- Check if a statement contains a call to a specific function (prevent recursive inlining). -/
partial def Stmt.containsCall (name : String) : Stmt → Bool
  | .skip | .assign _ _ | .decl _ _ _ | .alloc _ _ _ | .free _
  | .arrSet _ _ _ | .ret _ => false
  | .seq s₁ s₂ => s₁.containsCall name || s₂.containsCall name
  | .ite _ t f => t.containsCall name || f.containsCall name
  | .while _ b => b.containsCall name
  | .block stmts => stmts.any (containsCall name)
  | .callStmt f _ => f == name

/-- Substitute variables in an expression. -/
partial def Expr.substVars (params : List String) (args : List Expr) : Expr → Expr
  | .lit v => .lit v
  | .var x =>
    match params.zip args |>.find? (·.1 == x) with
    | some (_, e) => e
    | none => .var x
  | .binop op l r => .binop op (l.substVars params args) (r.substVars params args)
  | .unop op e => .unop op (e.substVars params args)
  | .call f as => .call f (as.map (substVars params args))
  | .arrGet a i => .arrGet (a.substVars params args) (i.substVars params args)
  | .arrLen a => .arrLen (a.substVars params args)
  | .strLen s => .strLen (s.substVars params args)
  | .strGet s i => .strGet (s.substVars params args) (i.substVars params args)

/-- Substitute parameter names with argument expressions in a statement body. -/
partial def Stmt.substParams (params : List String) (args : List Expr) : Stmt → Stmt
  | .skip => .skip
  | .assign x e => .assign x (e.substVars params args)
  | .seq s₁ s₂ => .seq (s₁.substParams params args) (s₂.substParams params args)
  | .ite c t f => .ite (c.substVars params args)
      (t.substParams params args) (f.substParams params args)
  | .while c b => .while (c.substVars params args) (b.substParams params args)
  | .decl x ty e => .decl x ty (e.substVars params args)
  | .alloc x ty sz => .alloc x ty (sz.substVars params args)
  | .free e => .free (e.substVars params args)
  | .arrSet a i v => .arrSet (a.substVars params args) (i.substVars params args)
      (v.substVars params args)
  | .ret e => .ret (e.substVars params args)
  | .block stmts => .block (stmts.map (substParams params args))
  | .callStmt f as => .callStmt f (as.map (Expr.substVars params args))

/-- Inline small function calls in a statement. -/
partial def Stmt.inline (funs : HashMap String FunDecl) : Stmt → Stmt
  | .skip => .skip
  | .assign x e => .assign x e
  | .seq s₁ s₂ => .seq (s₁.inline funs) (s₂.inline funs)
  | .ite c t f => .ite c (t.inline funs) (f.inline funs)
  | .while c b => .while c (b.inline funs)
  | .decl x ty e => .decl x ty e
  | .alloc x ty sz => .alloc x ty sz
  | .free e => .free e
  | .arrSet a i v => .arrSet a i v
  | .ret e => .ret e
  | .block stmts => .block (stmts.map (inline funs))
  | .callStmt name args =>
    match funs.get? name with
    | some fd =>
      if fd.body.size ≤ inlineThreshold && !fd.body.containsCall name then
        let paramNames := fd.params.map (·.1)
        .block [fd.body.substParams paramNames args |>.inline funs]
      else
        .callStmt name args
    | none => .callStmt name args

-- Correctness: inlining preserves semantics (theorem statement)
theorem Stmt.inline_correct (funs : HashMap String FunDecl) (h : BigStep σ s r) :
    BigStep σ (s.inline funs) r := by
  sorry

end Radix
