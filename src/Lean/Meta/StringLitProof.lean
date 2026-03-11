/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Joachim Breitner
-/
module

prelude
public import Lean.Meta.AppBuilder

public section

namespace Lean.Meta

/--
Builds a proof of `String.ofList l₁ ≠ String.ofList l₂` for two distinct string literals.

The proof avoids both `String.decEq` (expensive UTF-8 byte array comparison) and full
`List Char` comparison. Instead, it finds the first differing character position `i` and proves
inequality via `congrArg (List.get?Internal · i)`, reducing the kernel work to O(i) list
indexing plus a single character comparison. The full proof term is:

```
mt String.ofList_injective (mt (congrArg (List.get?Internal · i)) (of_decide_eq_true rfl))
```

where `rfl` proves `decide (l₁[i]? ≠ l₂[i]?) = true` on just two `Option Char` values.
-/
def mkStringLitNeProof (s₁ s₂ : String) : MetaM Expr := do
  let l₁ := s₁.toList
  let l₂ := s₂.toList
  let l₁Expr := toExpr l₁
  let l₂Expr := toExpr l₂
  -- Find the first differing character index
  let diffIdx := Id.run do
    let minLen := min l₁.length l₂.length
    for i in [:minLen] do
      if l₁[i]! ≠ l₂[i]! then return i
    return minLen
  let charConst := mkConst ``Char
  let listCharTy := mkApp (mkConst ``List [.zero]) charConst
  let optCharTy := mkApp (mkConst ``Option [.zero]) charConst
  let iExpr := toExpr diffIdx
  -- Build f = fun l => List.get?Internal l diffIdx
  let getFn := mkLambda `l .default listCharTy
    (mkApp3 (mkConst ``List.get?Internal [.zero]) charConst (mkBVar 0) iExpr)
  -- congrArg f (partially applied): l₁ = l₂ → l₁[i]? = l₂[i]?
  let congrArgFn := mkApp5 (mkConst ``congrArg [.succ .zero, .succ .zero])
    listCharTy optCharTy l₁Expr l₂Expr getFn
  -- Prove l₁[i]? ≠ l₂[i]? via decide on Option Char (trivial: one character comparison)
  let getL1 := mkApp3 (mkConst ``List.get?Internal [.zero]) charConst l₁Expr iExpr
  let getL2 := mkApp3 (mkConst ``List.get?Internal [.zero]) charConst l₂Expr iExpr
  let getEq := mkApp3 (mkConst ``Eq [.succ .zero]) optCharTy getL1 getL2
  let getNe := mkApp (mkConst ``Not) getEq
  let d ← mkDecide getNe
  let getNeProof := mkApp3 (mkConst ``of_decide_eq_true) getNe d.appArg! (← mkEqRefl (mkConst ``true))
  -- listNeProof : l₁ ≠ l₂   via   mt (congrArg f) getNeProof
  let listEq := mkApp3 (mkConst ``Eq [.succ .zero]) listCharTy l₁Expr l₂Expr
  let listNeProof := mkApp4 (mkConst ``mt) listEq getEq congrArgFn getNeProof
  -- strNeProof : String.ofList l₁ ≠ String.ofList l₂   via   mt ofList_injective listNeProof
  let strType := mkConst ``String
  let strEq := mkApp3 (mkConst ``Eq [.succ .zero]) strType
    (mkApp (mkConst ``String.ofList) l₁Expr) (mkApp (mkConst ``String.ofList) l₂Expr)
  return mkApp4 (mkConst ``mt) strEq listEq
    (mkApp2 (mkConst ``String.ofList_injective) l₁Expr l₂Expr) listNeProof

end Lean.Meta
