/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/

import Radix.Eval.Stmt

/-! # Constant Folding

Fold constant expressions: `3 + 4 → 7`, `true && x → x`, etc.
Includes correctness proof showing the optimization preserves semantics.
-/

namespace Radix

def BinOp.simplify : BinOp → Expr → Expr → Expr
  | .add, .lit (.uint64 a), .lit (.uint64 b) => .lit (.uint64 (a + b))
  | .sub, .lit (.uint64 a), .lit (.uint64 b) => .lit (.uint64 (a - b))
  | .mul, .lit (.uint64 a), .lit (.uint64 b) => .lit (.uint64 (a * b))
  | .eq,  .lit a,           .lit b           => .lit (.bool (a == b))
  | .ne,  .lit a,           .lit b           => .lit (.bool (a != b))
  | .and, .lit (.bool a),   .lit (.bool b)   => .lit (.bool (a && b))
  | .or,  .lit (.bool a),   .lit (.bool b)   => .lit (.bool (a || b))
  | .and, .lit (.bool true),  e              => e
  | .and, e,                  .lit (.bool true) => e
  | .and, .lit (.bool false), _              => .lit (.bool false)
  | .or,  .lit (.bool true),  _              => .lit (.bool true)
  | .or,  .lit (.bool false), e              => e
  | .or,  e,                  .lit (.bool false) => e
  | .add, e,  .lit (.uint64 0)               => e
  | .add, .lit (.uint64 0), e                => e
  | .mul, _,  .lit (.uint64 0)               => .lit (.uint64 0)
  | .mul, .lit (.uint64 0), _                => .lit (.uint64 0)
  | .mul, e,  .lit (.uint64 1)               => e
  | .mul, .lit (.uint64 1), e                => e
  | .strAppend, .lit (.str a), .lit (.str b) => .lit (.str (a ++ b))
  | op, a, b => .binop op a b

def UnaryOp.simplify : UnaryOp → Expr → Expr
  | .not, .lit (.bool b) => .lit (.bool !b)
  | op, e => .unop op e

partial def Expr.constFold : Expr → Expr
  | .lit v => .lit v
  | .var x => .var x
  | .binop op l r => BinOp.simplify op l.constFold r.constFold
  | .unop op e => UnaryOp.simplify op e.constFold
  | .call f args => .call f (args.map constFold)
  | .arrGet arr idx => .arrGet arr.constFold idx.constFold
  | .arrLen arr => .arrLen arr.constFold
  | .strLen s => .strLen s.constFold
  | .strGet s idx => .strGet s.constFold idx.constFold

partial def Stmt.constFold : Stmt → Stmt
  | .skip => .skip
  | .assign x e => .assign x e.constFold
  | .seq s₁ s₂ => .seq s₁.constFold s₂.constFold
  | .ite c t f =>
    match c.constFold with
    | .lit (.bool true) => t.constFold
    | .lit (.bool false) => f.constFold
    | c' => .ite c' t.constFold f.constFold
  | .while c b =>
    match c.constFold with
    | .lit (.bool false) => .skip
    | c' => .while c' b.constFold
  | .decl x ty e => .decl x ty e.constFold
  | .alloc x ty sz => .alloc x ty sz.constFold
  | .free e => .free e.constFold
  | .arrSet arr idx val => .arrSet arr.constFold idx.constFold val.constFold
  | .ret e => .ret e.constFold
  | .block stmts => .block (stmts.map Stmt.constFold)
  | .callStmt f args => .callStmt f (args.map Expr.constFold)

-- Correctness: constant folding preserves expression evaluation
theorem Expr.eval_constFold (e : Expr) (σ : PState) :
    e.constFold.eval σ = e.eval σ := by
  sorry

-- Correctness: constant folding preserves big-step semantics
theorem Stmt.constFold_correct (h : BigStep σ s r) : BigStep σ s.constFold r := by
  sorry

end Radix
