/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/

import Radix.Eval.Stmt

/-! # Dead Code Elimination

Remove unreachable branches and simplify trivial control flow.
-/

namespace Radix

/-- Collect variables that are read in an expression. -/
partial def Expr.readVars : Expr → List String
  | .lit _ => []
  | .var x => [x]
  | .binop _ l r => l.readVars ++ r.readVars
  | .unop _ e => e.readVars
  | .call _ args => args.flatMap readVars
  | .arrGet a i => a.readVars ++ i.readVars
  | .arrLen a => a.readVars
  | .strLen s => s.readVars
  | .strGet s i => s.readVars ++ i.readVars

/-- Collect variables that are read in a statement. -/
partial def Stmt.readVars : Stmt → List String
  | .skip => []
  | .assign _ e => e.readVars
  | .seq s₁ s₂ => s₁.readVars ++ s₂.readVars
  | .ite c t f => c.readVars ++ t.readVars ++ f.readVars
  | .while c b => c.readVars ++ b.readVars
  | .decl _ _ e => e.readVars
  | .alloc _ _ sz => sz.readVars
  | .free e => e.readVars
  | .arrSet a i v => a.readVars ++ i.readVars ++ v.readVars
  | .ret e => e.readVars
  | .block stmts => stmts.flatMap readVars
  | .callStmt _ args => args.flatMap Expr.readVars

/-- Dead code elimination pass. -/
partial def Stmt.deadCodeElim : Stmt → Stmt
  | .skip => .skip
  | .assign x e => .assign x e
  | .seq s₁ s₂ =>
    match s₁.deadCodeElim with
    | .skip => s₂.deadCodeElim
    | s₁' =>
      match s₂.deadCodeElim with
      | .skip => s₁'
      | s₂' => .seq s₁' s₂'
  | .ite c t f =>
    match c with
    | .lit (.bool true) => t.deadCodeElim
    | .lit (.bool false) => f.deadCodeElim
    | _ =>
      match t.deadCodeElim, f.deadCodeElim with
      | .skip, .skip => .skip
      | t', f' => .ite c t' f'
  | .while c b =>
    match c with
    | .lit (.bool false) => .skip
    | _ => .while c b.deadCodeElim
  | .decl x ty e => .decl x ty e
  | .alloc x ty sz => .alloc x ty sz
  | .free e => .free e
  | .arrSet a i v => .arrSet a i v
  | .ret e => .ret e
  | .block stmts => .block (stmts.map deadCodeElim)
  | .callStmt f args => .callStmt f args

-- Correctness: DCE preserves semantics
theorem Stmt.deadCodeElim_correct (h : BigStep σ s r) : BigStep σ s.deadCodeElim r := by
  sorry

end Radix
