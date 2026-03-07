/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/

import Radix.Syntax
import Radix.Opt.ConstFold
import Radix.Opt.DeadCode
import Radix.Opt.ConstProp

/-! # Optimization Tests

Verify that optimizations transform programs correctly.
-/

namespace Radix.Tests

-- Constant folding: 3 + 4 should become 7
def test_cf_expr : Expr :=
  Expr.binop .add (Expr.lit (Value.uint64 3)) (Expr.lit (Value.uint64 4))

#eval do
  let folded := test_cf_expr.constFold
  match folded with
  | Expr.lit (Value.uint64 7) => pure ()
  | _ => IO.println "FAIL: constant folding 3+4"

-- Constant folding: true && x should become x
def test_cf_and_true : Expr :=
  Expr.binop .and (Expr.lit (Value.bool true)) (Expr.var "x")

#eval do
  let folded := test_cf_and_true.constFold
  match folded with
  | Expr.var "x" => pure ()
  | _ => IO.println "FAIL: constant folding true && x"

-- Constant folding in statements: dead branch elimination
def test_cf_stmt := `[RStmt|
  if (true) {
    x := 1;
  } else {
    x := 2;
  }
]

#eval do
  let folded := test_cf_stmt.constFold
  match folded with
  | Stmt.assign "x" (Expr.lit (Value.uint64 1)) => pure ()
  | _ => IO.println "FAIL: constant folding didn't eliminate dead branch"

-- Dead code elimination: skip sequences
def test_dce_skip :=
  Stmt.seq Stmt.skip (Stmt.assign "x" (Expr.lit (Value.uint64 1)))

#eval do
  let optimized := test_dce_skip.deadCodeElim
  match optimized with
  | Stmt.assign "x" _ => pure ()
  | _ => IO.println "FAIL: DCE didn't remove skip"

-- Dead code: false while loop
def test_dce_false_while :=
  Stmt.while (Expr.lit (Value.bool false)) (Stmt.assign "x" (Expr.lit (Value.uint64 1)))

#eval do
  let optimized := test_dce_false_while.deadCodeElim
  match optimized with
  | Stmt.skip => pure ()
  | _ => IO.println "FAIL: DCE didn't remove false while"

-- Constant propagation: x := 5; y := x + 1 → y := 6
def test_constprop := `[RStmt|
  x := 5;
  y := x + 1;
]

#eval do
  let optimized := test_constprop.constPropagation
  match optimized with
  | Stmt.seq (Stmt.assign "x" (Expr.lit (Value.uint64 5)))
             (Stmt.assign "y" (Expr.lit (Value.uint64 6))) => pure ()
  | other => IO.println s!"FAIL: unexpected const prop result: {repr other}"

-- Constant folding: 0 + x → x
def test_cf_add_zero : Expr :=
  Expr.binop .add (Expr.lit (Value.uint64 0)) (Expr.var "x")

#eval do
  let folded := test_cf_add_zero.constFold
  match folded with
  | Expr.var "x" => pure ()
  | _ => IO.println "FAIL: constant folding 0 + x"

-- Constant folding: x * 1 → x
def test_cf_mul_one : Expr :=
  Expr.binop .mul (Expr.var "x") (Expr.lit (Value.uint64 1))

#eval do
  let folded := test_cf_mul_one.constFold
  match folded with
  | Expr.var "x" => pure ()
  | _ => IO.println "FAIL: constant folding x * 1"

-- Constant folding: x * 0 → 0
def test_cf_mul_zero : Expr :=
  Expr.binop .mul (Expr.var "x") (Expr.lit (Value.uint64 0))

#eval do
  let folded := test_cf_mul_zero.constFold
  match folded with
  | Expr.lit (Value.uint64 0) => pure ()
  | _ => IO.println "FAIL: constant folding x * 0"

-- String constant folding
def test_cf_str : Expr :=
  Expr.binop .strAppend (Expr.lit (Value.str "hello")) (Expr.lit (Value.str " world"))

#eval do
  let folded := test_cf_str.constFold
  match folded with
  | Expr.lit (Value.str "hello world") => pure ()
  | _ => IO.println "FAIL: string constant folding"

end Radix.Tests
