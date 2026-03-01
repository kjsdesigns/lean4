/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Paul Reichert
-/
module

prelude
public import Init.Data.Iterators.Consumers.Access
public import Init.Data.Iterators.Consumers.Collect
public import Init.Data.Iterators.Consumers.Loop
public import Init.Data.Iterators.Combinators.Take
public import Std.Data.Iterators.Combinators.StepSize
import Init.Data.Iterators.Lemmas.Basic
import Init.Omega
import Init.Data.Iterators.Lemmas.Consumers.Access
import Init.Data.Iterators.Lemmas.Consumers.Collect
import Init.Data.Iterators.Lemmas.Consumers.Loop
import Init.Data.Iterators.Lemmas.Consumers.Monadic.Access
import Init.Data.Iterators.Lemmas.Consumers.Monadic.Loop
import Init.Data.Iterators.Lemmas.Monadic.Basic
import all Init.Data.Iterators.Consumers.Monadic.Access
import all Std.Data.Iterators.Combinators.StepSize

public section
open Std Std.Iterators Std.Iterators.Types

namespace Std.Iter


instance [Iterator α Id β] [LawfulDeterministicIterator α Id] {it : IterM (α := α) Id β} :
    Subsingleton it.Step where
  allEq s s' := by
    obtain ⟨s'', hs''⟩ := LawfulDeterministicIterator.isPlausibleStep_eq_eq it
    obtain ⟨s, hs⟩ := s
    obtain ⟨s', hs'⟩ := s'
    simp only [hs''] at hs hs'
    have := hs.trans hs'.symm
    rwa [Subtype.mk.injEq]

instance [Iterator α Id β] [LawfulDeterministicIterator α Id] {it : Iter (α := α) β} :
    Subsingleton it.Step where
  allEq s s' := by
    obtain ⟨s'', hs''⟩ := LawfulDeterministicIterator.isPlausibleStep_eq_eq it.toIterM
    obtain ⟨s, hs⟩ := s
    obtain ⟨s', hs'⟩ := s'
    simp only [Iter.IsPlausibleStep, hs''] at hs hs'
    have := hs.trans hs'.symm
    rw [IterStep.mapIterator_inj (fun _ _ => toIterM_inj.mp) ] at this
    rwa [Subtype.mk.injEq]

theorem IsPlausibleStep.eq_step [Iterator α Id β] [LawfulDeterministicIterator α Id]
    {it : Iter (α := α) β} {step} (h : it.IsPlausibleStep step) :
    step = it.step.val := by
  have : ⟨step, h⟩ = it.step := Subsingleton.allEq _ _
  simp [← this]

theorem _root_.Std.IterM.IsPlausibleStep.eq_step [Iterator α Id β] [LawfulDeterministicIterator α Id]
    {it : IterM (α := α) Id β} {step} (h : it.IsPlausibleStep step) :
    step = it.step.run.inflate.val := by
  have : ⟨step, h⟩ = it.step.run.inflate := Subsingleton.allEq _ _
  simp [← this]

theorem _root_.Std.IterM.eq_of_isPlausibleNthOutputStep_of_isPlausibleNthOutputStep [Iterator α Id β]
    [LawfulDeterministicIterator α Id]
    {it : IterM (α := α) Id β} {s s'}
    (hs : it.IsPlausibleNthOutputStep n s)
    (hs' : it.IsPlausibleNthOutputStep n s') :
    s = s' := by
  induction hs
  case zero_yield h =>
    match hs' with
    | .zero_yield h' ..
    | .skip h' ..
    | .done h' =>
      replace h' := h'.eq_step
      rw [← h.eq_step] at h'
      cases h'
      all_goals simp
  case done h =>
    match hs' with
    | .zero_yield h' ..
    | .yield h' ..
    | .skip h' .. =>
      replace h := h.eq_step
      replace h' := h'.eq_step
      rw [← h] at h'
      cases h'
    | .done h' => simp
  case yield h _ ih =>
    match hs' with
    | .yield h' ..
    | .skip h' ..
    | .done h' =>
      replace h' := h'.eq_step
      rw [← h.eq_step] at h'
      cases h'
      all_goals apply ih ‹_›
  case skip h _ ih =>
    match hs' with
    | .zero_yield h' ..
    | .yield h' ..
    | .skip h' ..
    | .done h' =>
      replace h' := h'.eq_step
      rw [← h.eq_step] at h'
      cases h'
      all_goals apply ih ‹_›

instance [Iterator α Id β] [LawfulDeterministicIterator α Id] {it : IterM (α := α) Id β} :
    Subsingleton (PlausibleIterStep (it.IsPlausibleNthOutputStep n)) where
  allEq s s' := by
    obtain ⟨s, hs⟩ := s
    obtain ⟨s', hs'⟩ := s'
    have := IterM.eq_of_isPlausibleNthOutputStep_of_isPlausibleNthOutputStep hs hs'
    rwa [Subtype.mk.injEq]

instance instLawfulDeterministicIteratorStepSizeIterator
    [Iterator α Id β] [LawfulDeterministicIterator α Id] [IteratorAccess α Id] :
    LawfulDeterministicIterator (Types.StepSizeIterator α Id β) Id where
  isPlausibleStep_eq_eq it := by
    refine ⟨it.step.run.inflate.val, ?_⟩
    have hp := it.step.run.inflate.property
    ext step
    constructor
    · intro ⟨h₁, h₂⟩
      obtain ⟨hp₁, hp₂⟩ := hp
      simp only [IterStep.mapIterator] at h₁ hp₁
      have heq := IterM.eq_of_isPlausibleNthOutputStep_of_isPlausibleNthOutputStep h₁ hp₁
      generalize it.step.run.inflate.val = cstep at heq hp₁ hp₂ ⊢
      cases step with
      | skip _ => exact IterM.not_isPlausibleNthOutputStep_skip.elim (by simpa using h₁)
      | done =>
        cases cstep with
        | done => simp
        | yield _ _ => simp at heq
        | skip _ => exact IterM.not_isPlausibleNthOutputStep_skip.elim (by simpa using hp₁)
      | yield it₁ out₁ =>
        cases cstep with
        | done => simp at heq
        | skip _ => exact IterM.not_isPlausibleNthOutputStep_skip.elim (by simpa using hp₁)
        | yield it₂ out₂ =>
          rcases it₁ with ⟨⟨_, _, _⟩⟩
          rcases it₂ with ⟨⟨_, _, _⟩⟩
          simp_all
    · simp +contextual [hp]

theorem _root_.Std.IterM.nextAtIdx?_eq_nextAtIdxSlow? [Iterator α Id β] [Productive α Id]
    [LawfulDeterministicIterator α Id] [IteratorAccess α Id] {it : IterM (α := α) Id β} {n : Nat} :
    it.nextAtIdx? n = it.nextAtIdxSlow? n := by
  ext
  apply Subsingleton.allEq

theorem nextAtIdx?_eq_nextAtIdxSlow? [Iterator α Id β] [Productive α Id] [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] {it : Iter (α := α) β} {n : Nat} :
    it.nextAtIdx? n = it.nextAtIdxSlow? n := by
  simp [Iter.nextAtIdx?, Iter.nextAtIdxSlow?, IterM.nextAtIdx?_eq_nextAtIdxSlow?]

theorem _root_.Std.IterM.nextAtIdxSlow?_stepSize_aux [Iterator α Id β] [Productive α Id] [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] {it : IterM (α := α) Id β} {n : Nat} :
    (IterM.Intermediate.stepSize it i n).nextAtIdxSlow? 0 = (do
      match (← it.nextAtIdxSlow? i) with
      | .yield it' out h =>
        return .yield (IterM.Intermediate.stepSize it' (n - 1) n) out (by
          refine .zero_yield ?_
          simpa [IterM.IsPlausibleStep, Iterator.IsPlausibleStep, IterM.Intermediate.stepSize,
            IterM.Intermediate.stepSize])
      | .skip it' h => return IterM.not_isPlausibleNthOutputStep_skip.elim h
      | .done h =>
        return .done (by
          refine .done ?_
          simpa [IterM.IsPlausibleStep, Iterator.IsPlausibleStep, Intermediate.stepSize,
            IterM.Intermediate.stepSize])) := by
  induction it, i using IterM.atIdxSlow?.induct_unfolding
  rw [IterM.nextAtIdxSlow?_eq_match]
  simp only [IterM.Intermediate.stepSize, IterM.step_eq, IterM.internalState_mk,
    IterM.nextAtIdx?_eq_nextAtIdxSlow?, bind_pure_comp, bind_map_left, Shrink.inflate_deflate]
  apply bind_congr; intro step
  cases step using PlausibleIterStep.casesOn
  · simp
  · exact IterM.not_isPlausibleNthOutputStep_skip.elim ‹_›
  · simp

@[simp]
theorem Not.elim_eq {hP : P} {hnP : ¬ P} :
    hnP.elim hP = x ↔ True :=
  hnP.elim hP

theorem _root_.Std.IterM.length_nextAtIdxSlow? [Monad m] [LawfulMonad m] [Iterator α m β] [Finite α m] [IteratorLoop α m m] [LawfulIteratorLoop α m m]
    {it : IterM (α := α) m β} :
    (do match ← it.nextAtIdxSlow? n with
      | .yield it' _out _ => it'.length
      | .skip _it' h => IterM.not_isPlausibleNthOutputStep_skip.elim h
      | .done _h => return .up 0) = (fun len => .up (len.down - n - 1)) <$> it.length := by
  induction it using IterM.inductSteps generalizing n with | step it ihy ihs
  rw [it.nextAtIdxSlow?_eq_match, it.length_eq_match_step]
  simp only [map_eq_pure_bind, bind_assoc]
  apply bind_congr; intro step
  cases step.inflate using PlausibleIterStep.casesOn
  · simp only [bind_pure_comp, Functor.map_map]
    split
    · simp only [pure_bind, Nat.sub_zero, Nat.add_one_sub_one, id_map']
    · simp only [Nat.succ_eq_add_one, Nat.add_sub_add_right, bind_map_left]
      rw [← ihy ‹_›]
      apply bind_congr; intro step
      cases step using PlausibleIterStep.casesOn <;> simp
  · simp only [bind_pure_comp, bind_map_left, id_map']
    rw [← ihs ‹_›]
    apply bind_congr; intro step
    cases step using PlausibleIterStep.casesOn <;> simp
  · simp

-- TODO: rename
theorem length_nextAtIdxSlow? [Iterator α Id β] [Finite α Id] [IteratorLoop α Id Id] [LawfulIteratorLoop α Id Id]
    {it : Iter (α := α) β} :
    (match it.nextAtIdxSlow? n with
      | .yield it' _out _ => it'.length
      | .skip _it' h => IterM.not_isPlausibleNthOutputStep_skip.elim h
      | .done _h => 0) = it.length - n - 1 := by
  have := IterM.length_nextAtIdxSlow? (it := it.toIterM) (n := n)
  replace this := congrArg (fun x => ULift.down (Id.run x)) this
  simp only [Id.run_bind, Id.run_map] at this
  simp only [nextAtIdxSlow?, length, ← this]
  split at this
  · simp [*]
  · exact IterM.not_isPlausibleNthOutputStep_skip.elim ‹_›
  · simp [*]

theorem nextAtIdxSlow?_zero_intermediate_stepSize [Iterator α Id β] [Productive α Id]
    [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] {it : Iter (α := α) β} {i n : Nat} :
    (Intermediate.stepSize it i n).nextAtIdxSlow? 0 =
      match it.nextAtIdxSlow? i with
      | .yield it' out h =>
        .yield (Intermediate.stepSize it' (n - 1) n) out (by
          refine .zero_yield ?_
          simpa [IterM.IsPlausibleStep, Iterator.IsPlausibleStep,
            Intermediate.stepSize, IterM.Intermediate.stepSize])
      | .skip it' h => IterM.not_isPlausibleNthOutputStep_skip.elim h
      | .done h =>
        .done (by
          refine .done ?_
          simpa [IterM.IsPlausibleStep, Iterator.IsPlausibleStep,
            Intermediate.stepSize, IterM.Intermediate.stepSize]) := by
  simp only [Iter.nextAtIdxSlow?, Intermediate.stepSize, toIterM_toIter,
    IterM.nextAtIdxSlow?_stepSize_aux, Id.run_bind]
  apply Subtype.ext
  let step := (it.toIterM.nextAtIdxSlow? i).run
  cases hs : step using PlausibleIterStep.casesOn
  · simp [hs, step]
  · exact IterM.not_isPlausibleNthOutputStep_skip.elim ‹_›
  · simp [hs, step]

private theorem atIdxSlow?_eq_of_nextAtIdxSlow? [Iterator α Id β] [Productive α Id]
    {it : Iter (α := α) β} {i : Nat} :
    it.atIdxSlow? i = match (it.nextAtIdxSlow? i).val with
    | .yield _ out => some out
    | .skip _ => none
    | .done => none := by
  induction i, it using Iter.atIdxSlow?.induct_unfolding <;>
    (rw [nextAtIdxSlow?_eq_match]; simp [*])

private theorem atIdxSlow?_none_of_nextAtIdxSlow?_done [Iterator α Id β] [Productive α Id]
    {it : Iter (α := α) β} {i j : Nat}
    (h : (it.nextAtIdxSlow? i).val = .done) (hij : i ≤ j) :
    it.atIdxSlow? j = none := by
  induction j generalizing it i with
  | zero =>
    cases show i = 0 from Nat.le_antisymm hij (Nat.zero_le _)
    rw [atIdxSlow?_eq_of_nextAtIdxSlow?, h]
  | succ j ih =>
    induction it using Iter.inductSkips with | step it ih_skip
    rw [atIdxSlow?_eq_match]
    cases hstep : it.step using PlausibleIterStep.casesOn with
    | yield it' out hp =>
      rw [nextAtIdxSlow?_eq_match] at h
      simp only [hstep, PlausibleIterStep.yield] at h
      cases i with
      | zero => cases h
      | succ i => exact ih h (Nat.le_of_succ_le_succ hij)
    | skip it' hp =>
      rw [nextAtIdxSlow?_eq_match] at h
      simp only [hstep] at h
      exact ih_skip hp h
    | done hp => simp

private theorem atIdxSlow?_succ_of_nextAtIdxSlow?_yield [Iterator α Id β] [Productive α Id]
    {it it' : Iter (α := α) β} {i j : Nat} {out : β}
    (h : (it.nextAtIdxSlow? i).val = .yield it' out) :
    it.atIdxSlow? (i + 1 + j) = it'.atIdxSlow? j := by
  induction i, it using Iter.atIdxSlow?.induct_unfolding generalizing j with
  | yield_zero it it'' out' hp hs =>
    rw [nextAtIdxSlow?_eq_match] at h
    simp only [hs, PlausibleIterStep.yield, IterStep.yield.injEq] at h
    obtain ⟨rfl, rfl⟩ := h
    show atIdxSlow? (0 + 1 + j) it = atIdxSlow? j it''
    rw [show (0 : Nat) + 1 + j = j + 1 from by omega, atIdxSlow?_eq_match]
    simp [hs]
  | yield_succ it it'' out' hp hs k ih =>
    rw [nextAtIdxSlow?_eq_match, Nat.succ_eq_add_one, hs] at h
    rw [show k + 1 + 1 + j = (k + 1 + j) + 1 from by omega, atIdxSlow?_eq_match]
    simpa [hs] using ih h
  | skip_case n it it'' hp hs ih =>
    rw [nextAtIdxSlow?_eq_match, hs] at h
    rw [atIdxSlow?_eq_match, hs]
    simpa using ih h
  | done_case n it hp hs =>
    rw [nextAtIdxSlow?_eq_match] at h; simp [hs] at h

private theorem nextAtIdxSlow?_zero_intermediate_stepSize_val [Iterator α Id β] [Productive α Id]
    [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] {it : Iter (α := α) β} {i n : Nat} :
    ((Intermediate.stepSize it i n).nextAtIdxSlow? 0).val =
      (it.nextAtIdxSlow? i).val.mapIterator (fun it' => Intermediate.stepSize it' (n - 1) n) := by
  have h := congrArg Subtype.val (nextAtIdxSlow?_zero_intermediate_stepSize (it := it) (i := i) (n := n))
  simp only at h
  rw [h]
  cases (it.nextAtIdxSlow? i) using PlausibleIterStep.casesOn with
  | yield => simp [IterStep.mapIterator]
  | skip _ h => exact IterM.not_isPlausibleNthOutputStep_skip.elim h
  | done => simp [IterStep.mapIterator]

theorem atIdxSlow?_intermediate_stepSize [Iterator α Id β] [Productive α Id]
    [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] {it : Iter (α := α) β} {i k n : Nat} :
    (Intermediate.stepSize it i n).atIdxSlow? k = it.atIdxSlow? (i + (n - 1 + 1) * k) := by
  induction k generalizing it i with
  | zero =>
    simp only [Nat.mul_zero, Nat.add_zero]
    rw [atIdxSlow?_eq_of_nextAtIdxSlow?, nextAtIdxSlow?_zero_intermediate_stepSize_val]
    rw [atIdxSlow?_eq_of_nextAtIdxSlow?]
    cases (it.nextAtIdxSlow? i).val with
    | yield => simp [IterStep.mapIterator]
    | skip => simp [IterStep.mapIterator]
    | done => simp [IterStep.mapIterator]
  | succ k ih =>
    cases hstep : (it.nextAtIdxSlow? i).val with
    | yield it' out =>
      have hss : ((Intermediate.stepSize it i n).nextAtIdxSlow? 0).val =
          .yield (Intermediate.stepSize it' (n - 1) n) out := by
        rw [nextAtIdxSlow?_zero_intermediate_stepSize_val, hstep]; rfl
      have h1 : (Intermediate.stepSize it i n).atIdxSlow? (0 + 1 + k) =
          (Intermediate.stepSize it' (n - 1) n).atIdxSlow? k :=
        atIdxSlow?_succ_of_nextAtIdxSlow?_yield hss
      have h2 : (Intermediate.stepSize it i n).atIdxSlow? (k + 1) =
          (Intermediate.stepSize it i n).atIdxSlow? (0 + 1 + k) := by
        congr 1; omega
      have h3 : it.atIdxSlow? (i + 1 + ((n - 1) + (n - 1 + 1) * k)) =
          it'.atIdxSlow? ((n - 1) + (n - 1 + 1) * k) :=
        atIdxSlow?_succ_of_nextAtIdxSlow?_yield hstep
      have h4 : i + (n - 1 + 1) * (k + 1) = i + 1 + ((n - 1) + (n - 1 + 1) * k) := by
        rw [Nat.mul_succ]; omega
      rw [h2, h1, ih, ← h3, h4]
    | skip it' =>
      exfalso
      have := (it.nextAtIdxSlow? i).property
      rw [hstep] at this
      exact IterM.not_isPlausibleNthOutputStep_skip this
    | done =>
      have hss : ((Intermediate.stepSize it i n).nextAtIdxSlow? 0).val = .done := by
        rw [nextAtIdxSlow?_zero_intermediate_stepSize_val, hstep]; rfl
      rw [atIdxSlow?_none_of_nextAtIdxSlow?_done hss (by omega)]
      exact (atIdxSlow?_none_of_nextAtIdxSlow?_done hstep (by omega)).symm

theorem atIdxSlow?_stepSize [Iterator α Id β] [Productive α Id]
    [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] {it : Iter (α := α) β} {k n : Nat} :
    (it.stepSize n).atIdxSlow? k = it.atIdxSlow? ((n - 1 + 1) * k) := by
  show (Intermediate.stepSize it 0 n).atIdxSlow? k = _
  rw [atIdxSlow?_intermediate_stepSize]; simp

theorem getElem?_toList_stepSize [Iterator α Id β] [Productive α Id]
    [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] [Finite α Id]
    {it : Iter (α := α) β} {k n : Nat} :
    (it.stepSize n).toList[k]? = it.toList[(n - 1 + 1) * k]? := by
  simp only [getElem?_toList_eq_atIdxSlow?, atIdxSlow?_stepSize]

private theorem step_eq_nextAtIdxSlow?_zero_val [Iterator α Id β] [Productive α Id]
    {it : Iter (α := α) β} :
    (∀ (it' : Iter (α := α) β), ¬ it.IsPlausibleStep (.skip it')) →
    it.step.val = (it.nextAtIdxSlow? 0).val := by
  intro hno_skip
  rw [nextAtIdxSlow?_eq_match]
  cases it.step using PlausibleIterStep.casesOn with
  | yield => simp
  | skip _ hp => exact absurd hp (hno_skip _)
  | done => simp

private theorem not_isPlausibleStep_skip_intermediate_stepSize [Iterator α Id β]
    [IteratorAccess α Id] {it : Iter (α := α) β} {i n : Nat}
    {it' : Iter (α := Types.StepSizeIterator α Id β) β} :
    ¬ (Intermediate.stepSize it i n).IsPlausibleStep (.skip it') := by
  simp only [Iter.IsPlausibleStep, IterM.IsPlausibleStep, Iterator.IsPlausibleStep,
    IterStep.mapIterator, Intermediate.stepSize, IterM.Intermediate.stepSize]
  intro ⟨h, _⟩
  exact IterM.not_isPlausibleNthOutputStep_skip h

private theorem step_intermediate_stepSize_val [Iterator α Id β] [Productive α Id]
    [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] {it : Iter (α := α) β} {i n : Nat} :
    (Intermediate.stepSize it i n).step.val =
      (it.nextAtIdxSlow? i).val.mapIterator (fun it' => Intermediate.stepSize it' (n - 1) n) := by
  rw [step_eq_nextAtIdxSlow?_zero_val (fun _ => not_isPlausibleStep_skip_intermediate_stepSize),
    nextAtIdxSlow?_zero_intermediate_stepSize_val]

private theorem lt_length_of_nextAtIdxSlow?_yield [Iterator α Id β] [Finite α Id]
    [Productive α Id] [IteratorLoop α Id Id] [LawfulIteratorLoop α Id Id]
    {it it' : Iter (α := α) β} {i : Nat} {out : β}
    (h : (it.nextAtIdxSlow? i).val = .yield it' out) :
    i < it.length := by
  induction it using Iter.inductSteps generalizing i it' out with
  | step it ihy ihs =>
    rw [Std.Iter.length_eq_match_step]
    rw [nextAtIdxSlow?_eq_match] at h
    cases hstep : it.step using PlausibleIterStep.casesOn with
    | yield it'' out'' hp =>
      simp only [hstep] at h
      simp only
      cases i with
      | zero => omega
      | succ k =>
        simp only at h
        exact Nat.succ_lt_succ (ihy hp h)
    | skip it'' hp =>
      simp only [hstep] at h
      simp only
      exact ihs hp h
    | done hp =>
      simp [hstep] at h

private theorem length_le_of_nextAtIdxSlow?_done [Iterator α Id β] [Finite α Id]
    [Productive α Id] [IteratorLoop α Id Id] [LawfulIteratorLoop α Id Id]
    {it : Iter (α := α) β} {i : Nat}
    (h : (it.nextAtIdxSlow? i).val = .done) :
    it.length ≤ i := by
  induction it using Iter.inductSteps generalizing i with
  | step it ihy ihs =>
    rw [Std.Iter.length_eq_match_step]
    rw [nextAtIdxSlow?_eq_match] at h
    cases hstep : it.step using PlausibleIterStep.casesOn with
    | yield it'' out'' hp =>
      simp only [hstep] at h
      simp only
      cases i with
      | zero => simp at h
      | succ k =>
        simp only at h
        have := ihy hp h
        omega
    | skip it'' hp =>
      simp only [hstep] at h
      simp only
      have := ihs hp h
      omega
    | done hp =>
      simp only
      omega

theorem Intermediate.length_stepSize [Iterator α Id β] [Finite α Id]
    [Productive α Id] [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] [IteratorLoop α Id Id] [LawfulIteratorLoop α Id Id]
    {it : Iter (α := α) β} {i n : Nat} :
    (Intermediate.stepSize it i n).length = (it.length + (n - 1) - i) / (n - 1 + 1) := by
  generalize hsit : Intermediate.stepSize it i n = sit
  replace hsit := hsit.symm
  induction sit using Iter.inductSteps generalizing it i with
  | step oit ih_yield ih_skip =>
    rw [Std.Iter.length_eq_match_step]
    subst hsit
    rw [step_intermediate_stepSize_val]
    cases h : (it.nextAtIdxSlow? i) using PlausibleIterStep.casesOn with
    | yield it' out hp =>
      simp only [IterStep.mapIterator]
      rw [ih_yield (it := it') (i := n - 1) (out := out) _ rfl]
      · have hlength := length_nextAtIdxSlow? (it := it) (n := i)
        simp only [h] at hlength
        simp only [hlength, Nat.add_sub_cancel, Nat.zero_lt_succ, ← Nat.add_div_right]
        have hi := lt_length_of_nextAtIdxSlow?_yield (by rw [h])
        congr 1; omega
      · have := (Intermediate.stepSize it i n).step.property
        simpa [step_intermediate_stepSize_val, h, IterStep.mapIterator]
    | skip _ hp => exact IterM.not_isPlausibleNthOutputStep_skip.elim hp
    | done hp =>
      simp only [IterStep.mapIterator]
      apply Nat.div_eq_of_lt _ |>.symm
      have hi := length_le_of_nextAtIdxSlow?_done (by rw [h])
      omega

theorem stepSize_eq_intermediateStepSize [Iterator α Id β] [IteratorAccess α Id]
    {it : Iter (α := α) β} {n : Nat} :
    it.stepSize n = Intermediate.stepSize it 0 n :=
  rfl

theorem length_stepSize [Iterator α Id β] [Finite α Id] [LawfulDeterministicIterator α Id]
    [IteratorAccess α Id] [IteratorLoop α Id Id] [LawfulIteratorLoop α Id Id]
    {it : Iter (α := α) β} {n : Nat} :
    (it.stepSize n).length = (it.length + (n - 1)) / (n - 1 + 1) := by
  simp [stepSize_eq_intermediateStepSize, Intermediate.length_stepSize]

end Std.Iter
