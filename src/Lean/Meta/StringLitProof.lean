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
`List Char` comparison. It reduces to `List Char` via `String.ofList_injective`, then
proves the lists differ using one of two strategies depending on whether the strings
share a common prefix of the shorter string's full length:

- **Different characters at position `i`**: Uses `congrArg (List.get!Internal · i)` to extract
  the differing `Char` values, then `of_decide_eq_true rfl` for a single character comparison.
  Uses `get!Internal` (not `get?Internal`) to compare `Char` directly without the `Option` wrapper.

- **One string is a prefix of the other**: Uses `congrArg (List.drop n ·)` where `n` is the
  shorter string's length, then `List.cons_ne_nil` to prove the non-empty tail differs from `[]`.
  This avoids `decide` entirely since `cons_ne_nil` is a definitional proof.
-/
def mkStringLitNeProof (s₁ s₂ : String) : MetaM Expr := do
  let l₁ := s₁.toList
  let l₂ := s₂.toList
  let l₁Expr := toExpr l₁
  let l₂Expr := toExpr l₂
  let charConst := mkConst ``Char
  let listCharTy := mkApp (mkConst ``List [.zero]) charConst
  -- Find the first differing character index
  let minLen := min l₁.length l₂.length
  let diffIdx := Id.run do
    for i in [:minLen] do
      if l₁[i]! ≠ l₂[i]! then return i
    return minLen
  -- Build the list inequality proof, dispatching on whether it's a character
  -- difference or a prefix/length difference
  let listEq := mkApp3 (mkConst ``Eq [.succ .zero]) listCharTy l₁Expr l₂Expr
  let listNeProof ←
    if diffIdx < minLen then
      -- Both lists have a character at diffIdx: compare with get!Internal (Char, no Option)
      let inhabCharExpr := mkConst ``Char.instInhabited
      let iExpr := toExpr diffIdx
      let projFn := mkLambda `l .default listCharTy
        (mkApp4 (mkConst ``List.get!Internal [.zero]) charConst inhabCharExpr (mkBVar 0) iExpr)
      let projL1 := mkApp4 (mkConst ``List.get!Internal [.zero]) charConst inhabCharExpr l₁Expr iExpr
      let projL2 := mkApp4 (mkConst ``List.get!Internal [.zero]) charConst inhabCharExpr l₂Expr iExpr
      let projEq := mkApp3 (mkConst ``Eq [.succ .zero]) charConst projL1 projL2
      let congrArgFn := mkApp5 (mkConst ``congrArg [.succ .zero, .succ .zero])
        listCharTy charConst l₁Expr l₂Expr projFn
      let projNe := mkApp (mkConst ``Not) projEq
      let d ← mkDecide projNe
      let projNeProof := mkApp3 (mkConst ``of_decide_eq_true) projNe d.appArg!
        (← mkEqRefl (mkConst ``true))
      pure <| mkApp4 (mkConst ``mt) listEq projEq congrArgFn projNeProof
    else
      -- One list is a prefix of the other: use drop + cons_ne_nil
      let nExpr := toExpr minLen
      let dropFn := mkLambda `l .default listCharTy
        (mkApp3 (mkConst ``List.drop [.zero]) charConst nExpr (mkBVar 0))
      let dropL1 := mkApp3 (mkConst ``List.drop [.zero]) charConst nExpr l₁Expr
      let dropL2 := mkApp3 (mkConst ``List.drop [.zero]) charConst nExpr l₂Expr
      let dropEq := mkApp3 (mkConst ``Eq [.succ .zero]) listCharTy dropL1 dropL2
      let congrArgFn := mkApp5 (mkConst ``congrArg [.succ .zero, .succ .zero])
        listCharTy listCharTy l₁Expr l₂Expr dropFn
      -- The longer list's drop has a head element; the shorter list's drop is []
      let (hdChar, tlList) :=
        if l₁.length ≤ l₂.length then
          let dropped := l₂.drop minLen
          (dropped.head!, dropped.tail!)
        else
          let dropped := l₁.drop minLen
          (dropped.head!, dropped.tail!)
      let hdExpr := toExpr hdChar
      let tlExpr := toExpr tlList
      -- cons_ne_nil hd tl : hd :: tl ≠ []
      let consNeNil := mkApp3 (mkConst ``List.cons_ne_nil [.zero]) charConst hdExpr tlExpr
      let dropNeProof :=
        if l₁.length ≤ l₂.length then
          -- l₁ is shorter: drop l₁ = [], drop l₂ = hd :: tl, need [] ≠ hd :: tl
          mkApp4 (mkConst ``Ne.symm [.succ .zero]) listCharTy
            (mkApp3 (mkConst ``List.cons [.zero]) charConst hdExpr tlExpr)
            (mkApp (mkConst ``List.nil [.zero]) charConst)
            consNeNil
        else
          -- l₂ is shorter: drop l₁ = hd :: tl, drop l₂ = [], need hd :: tl ≠ []
          consNeNil
      pure <| mkApp4 (mkConst ``mt) listEq dropEq congrArgFn dropNeProof
  -- strNeProof : String.ofList l₁ ≠ String.ofList l₂   via   mt ofList_injective listNeProof
  let strType := mkConst ``String
  let strEq := mkApp3 (mkConst ``Eq [.succ .zero]) strType
    (mkApp (mkConst ``String.ofList) l₁Expr) (mkApp (mkConst ``String.ofList) l₂Expr)
  return mkApp4 (mkConst ``mt) strEq listEq
    (mkApp2 (mkConst ``String.ofList_injective) l₁Expr l₂Expr) listNeProof

end Lean.Meta
