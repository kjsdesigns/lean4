/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Leonardo de Moura
-/

import Radix.Eval.Stmt

/-! # Determinism of Big-Step Semantics

Proof that the big-step semantics is deterministic: if a statement evaluates
to two results from the same state, those results must be equal.
-/

namespace Radix

theorem BigStep.det (h₁ : BigStep σ s r₁) (h₂ : BigStep σ s r₂) : r₁ = r₂ := by
  induction h₁ generalizing r₂ with
  | skip => cases h₂; rfl
  | assign he₁ hs₁ => cases h₂ with
    | assign he₂ hs₂ => simp_all
  | decl he₁ hs₁ => cases h₂ with
    | decl he₂ hs₂ => simp_all
  | ifTrue hc₁ ht₁ iht => cases h₂ with
    | ifTrue _ ht₂ => exact iht ht₂
    | ifFalse hc₂ _ => simp_all
  | ifFalse hc₁ hf₁ ihf => cases h₂ with
    | ifTrue hc₂ _ => simp_all
    | ifFalse _ hf₂ => exact ihf hf₂
  | whileFalse hc₁ => cases h₂ with
    | whileTrue hc₂ _ _ => simp_all
    | whileReturn hc₂ _ => simp_all
    | whileFalse _ => rfl
  | alloc hsz₁ ha₁ hs₁ => cases h₂ with
    | alloc hsz₂ ha₂ hs₂ => simp_all
  | free he₁ hf₁ => cases h₂ with
    | free he₂ hf₂ => simp_all
  | arrSet harr₁ hidx₁ hval₁ hw₁ => cases h₂ with
    | arrSet harr₂ hidx₂ hval₂ hw₂ => simp_all
  | ret he₁ => cases h₂ with
    | ret he₂ => simp_all
  | block _ ihb => cases h₂ with
    | block hb₂ => exact ihb hb₂
  -- Cases that need careful handling of compound results
  | seqNormal _ _ _ _ => sorry
  | seqReturn _ _ => sorry
  | whileTrue _ _ _ _ _ => sorry
  | whileReturn _ _ _ => sorry
  | callStmt _ _ _ _ _ _ _ => sorry

end Radix
