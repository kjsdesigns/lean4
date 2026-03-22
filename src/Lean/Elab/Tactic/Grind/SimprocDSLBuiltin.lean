/-
Copyright (c) 2026 Lean FRO, LLC. All Rights Reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/
module
prelude
import Lean.Elab.Tactic.Grind.SimprocDSL
import Init.Sym.Simp.SimprocDSL
import Lean.Meta.Sym.Simp.EvalGround
import Lean.Meta.Sym.Simp.Telescope
import Lean.Meta.Sym.Simp.Rewrite
namespace Lean.Elab.Tactic.Grind
open Meta Sym.Simp

-- Simproc elaborators

@[builtin_sym_simproc ground]
def elabSimprocGround : SymSimprocElab := fun _ =>
  return evalGround

@[builtin_sym_simproc telescope]
def elabSimprocTelescope : SymSimprocElab := fun _ =>
  return simpTelescope

@[builtin_sym_simproc self]
def elabSimprocSelf : SymSimprocElab := fun _ =>
  return simp

@[builtin_sym_simproc none]
def elabSimprocNone : SymSimprocElab := fun _ =>
  return fun _ => return .rfl

@[builtin_sym_simproc rewriteSet]
def elabSimprocRewriteSet : SymSimprocElab := fun stx => do
  -- syntax: "rewrite" ident (" with " sym_discharger)?
  let setName := stx[1].getId
  let some ext ← getSymSimpExtension? setName
    | throwErrorAt stx[1] "unknown Sym.simp theorem set `{setName}`"
  let thms ← ext.getTheorems
  let d ← elabWithClause stx[2]
  return thms.rewrite d

@[builtin_sym_simproc rewriteInline]
def elabSimprocRewriteInline : SymSimprocElab := fun stx => do
  -- syntax: "rewrite" " [" ident,* "]" (" with " sym_discharger)?
  let names := stx[2].getSepArgs
  let mut thms : Theorems := {}
  for name in names do
    let declName ← realizeGlobalConstNoOverload name
    thms := thms.insert (← mkTheoremFromDecl declName)
  let d ← elabWithClause stx[4]
  return thms.rewrite d

@[builtin_sym_simproc andThen]
def elabSimprocAndThen : SymSimprocElab := fun stx => do
  -- syntax: sym_simproc " >> " sym_simproc
  let left ← elabSymSimproc stx[0]
  let right ← elabSymSimproc stx[2]
  return left >> right

@[builtin_sym_simproc orElse]
def elabSimprocOrElse : SymSimprocElab := fun stx => do
  -- syntax: sym_simproc " <|> " sym_simproc
  let left ← elabSymSimproc stx[0]
  let right ← elabSymSimproc stx[2]
  return left <|> right

@[builtin_sym_simproc simprocParen]
def elabSimprocParen : SymSimprocElab := fun stx =>
  -- syntax: "(" sym_simproc ")"
  elabSymSimproc stx[1]

-- Discharger elaborators

@[builtin_sym_discharger dischSelf]
def elabDischSelf : SymDischargerElab := fun _ =>
  return dischargeSimpSelf

@[builtin_sym_discharger dischNone]
def elabDischNone : SymDischargerElab := fun _ =>
  return dischargeNone

@[builtin_sym_discharger dischParen]
def elabDischParen : SymDischargerElab := fun stx =>
  -- syntax: "(" sym_discharger ")"
  elabSymDischarger stx[1]

end Lean.Elab.Tactic.Grind
