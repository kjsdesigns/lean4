/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/

import Radix.Opt.ConstFold
import Std.Data.HashMap

/-! # Constant Propagation

Track which variables hold known constant values and substitute them.
-/

namespace Radix
open Std

abbrev ConstMap := HashMap String Value

/-- Substitute known constants in an expression. -/
partial def Expr.constProp (m : ConstMap) : Expr → Expr
  | .lit v => .lit v
  | .var x => match m.get? x with
    | some v => .lit v
    | none => .var x
  | .binop op l r => .binop op (l.constProp m) (r.constProp m)
  | .unop op e => .unop op (e.constProp m)
  | .call f args => .call f (args.map (constProp m))
  | .arrGet arr idx => .arrGet (arr.constProp m) (idx.constProp m)
  | .arrLen arr => .arrLen (arr.constProp m)
  | .strLen s => .strLen (s.constProp m)
  | .strGet s idx => .strGet (s.constProp m) (idx.constProp m)

/-- Constant propagation on statements, maintaining a map of known constants.
Also applies constant folding after substitution. -/
partial def Stmt.constProp (m : ConstMap) : Stmt → Stmt × ConstMap
  | .skip => (.skip, m)
  | .assign x e =>
    let e' := (e.constProp m).constFold
    match e' with
    | .lit v => (.assign x e', m.insert x v)
    | _ => (.assign x e', m.erase x)
  | .seq s₁ s₂ =>
    let (s₁', m₁) := s₁.constProp m
    let (s₂', m₂) := s₂.constProp m₁
    (.seq s₁' s₂', m₂)
  | .ite c t f =>
    let c' := (c.constProp m).constFold
    match c' with
    | .lit (.bool true) =>
      let (t', m') := t.constProp m
      (t', m')
    | .lit (.bool false) =>
      let (f', m') := f.constProp m
      (f', m')
    | _ =>
      let (t', _) := t.constProp m
      let (f', _) := f.constProp m
      (.ite c' t' f', {})
  | .while c b =>
    let c' := (c.constProp {}).constFold
    let (b', _) := b.constProp {}
    (.while c' b', {})
  | .decl x ty e =>
    let e' := (e.constProp m).constFold
    match e' with
    | .lit v => (.decl x ty e', m.insert x v)
    | _ => (.decl x ty e', m.erase x)
  | .alloc x ty sz =>
    let sz' := (sz.constProp m).constFold
    (.alloc x ty sz', m.erase x)
  | .free e => (.free (e.constProp m), m)
  | .arrSet arr idx val =>
    (.arrSet (arr.constProp m) (idx.constProp m) (val.constProp m), m)
  | .ret e => (.ret ((e.constProp m).constFold), m)
  | .block stmts =>
    let (stmts', m') := stmts.foldl (init := ([], m)) fun (acc, m) s =>
      let (s', m') := s.constProp m
      (acc ++ [s'], m')
    (.block stmts', m')
  | .callStmt f args =>
    (.callStmt f (args.map fun a => (a.constProp m).constFold), {})

def Stmt.constPropagation (s : Stmt) : Stmt :=
  (s.constProp {}).1

-- Correctness: constant propagation preserves semantics
theorem Stmt.constPropagation_correct (h : BigStep σ s r) :
    BigStep σ s.constPropagation r := by
  sorry

end Radix
