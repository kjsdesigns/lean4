/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/

import Radix.Eval.Stmt
import Std.Data.HashMap

/-! # Copy Propagation

Replace `x := y; ... x ...` with `... y ...` when safe.
Uses a substitution map tracking which variables are copies of others.
-/

namespace Radix
open Std

abbrev CopyMap := HashMap String String

/-- Apply copy propagation to an expression using the given copy map. -/
partial def Expr.copyProp (m : CopyMap) : Expr → Expr
  | .lit v => .lit v
  | .var x => .var (m.get? x |>.getD x)
  | .binop op l r => .binop op (l.copyProp m) (r.copyProp m)
  | .unop op e => .unop op (e.copyProp m)
  | .call f args => .call f (args.map (copyProp m))
  | .arrGet arr idx => .arrGet (arr.copyProp m) (idx.copyProp m)
  | .arrLen arr => .arrLen (arr.copyProp m)
  | .strLen s => .strLen (s.copyProp m)
  | .strGet s idx => .strGet (s.copyProp m) (idx.copyProp m)

/-- Apply copy propagation to a statement. Returns the transformed statement
and an updated copy map. -/
partial def Stmt.copyProp (m : CopyMap) : Stmt → Stmt × CopyMap
  | .skip => (.skip, m)
  | .assign x (.var y) =>
    let y' := m.get? y |>.getD y
    (.assign x (.var y'), m.insert x y' |>.erase y |> fun m' =>
      m'.filter fun _ v => v != x)
  | .assign x e =>
    let e' := e.copyProp m
    let m' := m.erase x |>.filter fun _ v => v != x
    (.assign x e', m')
  | .seq s₁ s₂ =>
    let (s₁', m₁) := s₁.copyProp m
    let (s₂', m₂) := s₂.copyProp m₁
    (.seq s₁' s₂', m₂)
  | .ite c t f =>
    let c' := c.copyProp m
    let (t', _) := t.copyProp m
    let (f', _) := f.copyProp m
    (.ite c' t' f', {})
  | .while c b =>
    let c' := c.copyProp {}
    let (b', _) := b.copyProp {}
    (.while c' b', {})
  | .decl x ty e =>
    let e' := e.copyProp m
    let m' := m.erase x |>.filter fun _ v => v != x
    (.decl x ty e', m')
  | .alloc x ty sz =>
    let sz' := sz.copyProp m
    let m' := m.erase x |>.filter fun _ v => v != x
    (.alloc x ty sz', m')
  | .free e => (.free (e.copyProp m), m)
  | .arrSet arr idx val =>
    (.arrSet (arr.copyProp m) (idx.copyProp m) (val.copyProp m), m)
  | .ret e => (.ret (e.copyProp m), m)
  | .block stmts =>
    let (stmts', m') := stmts.foldl (init := ([], m)) fun (acc, m) s =>
      let (s', m') := s.copyProp m
      (acc ++ [s'], m')
    (.block stmts', m')
  | .callStmt f args =>
    (.callStmt f (args.map (Expr.copyProp m)), {})

def Stmt.copyPropagation (s : Stmt) : Stmt :=
  (s.copyProp {}).1

-- Correctness theorem statement
theorem Stmt.copyProp_correct (h : BigStep σ s r) :
    BigStep σ s.copyPropagation r := by
  sorry

end Radix
