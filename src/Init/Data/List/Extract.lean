/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Paul Reichert
-/
module

prelude
public import Init.Data.List.TakeDrop
public import Init.Data.List.Nat.TakeDrop
public import Init.Data.Range.Polymorphic.Basic
import Init.Data.Option.Lemmas
import Init.Omega
import Init.Data.Nat.Lemmas

public section

variable {α : Type u} {as bs : List α} {i j k i' j' : Nat}

namespace List

@[simp]
theorem take_extract :
    (as.extract i j).take k = as.extract i (min (i + k) j) := by
  simp [extract_eq_drop_take', take_drop, take_take]

@[simp]
theorem extract_take :
    (as.take i).extract j k = as.extract j (min k i) := by
  simp [extract_eq_drop_take', take_take]

@[simp]
theorem drop_extract :
    (as.extract i j).drop k = as.extract (i + k) j := by
  simp [extract_eq_drop_take', drop_drop, drop_drop]

@[simp]
theorem extract_drop :
    (as.drop i).extract j k = as.extract (i + j) (i + k) := by
  simp [extract_eq_drop_take', take_drop]

@[simp]
theorem extract_extract :
    (as.extract i j).extract i' j' = as.extract (i + i') (min (i + j') j) := by
  simp [extract_eq_drop_take', take_drop, take_take]

@[simp]
theorem length_extract :
    (as.extract i j).length = (min j as.length) - i := by
  simp [extract_eq_drop_take']

theorem length_extract_le_stop_sub_start :
    (as.extract i j).length ≤ j - i := by
  simp [extract_eq_drop_take']
  omega

theorem length_extract_le_length_sub_start :
    (as.extract i j).length ≤ j - i := by
  simp [extract_eq_drop_take']
  omega

theorem length_extract_le_stop :
    (as.extract i j).length ≤ j := by
  simp [extract_eq_drop_take']
  omega

theorem length_extract_le_length :
    (as.extract i j).length ≤ as.length := by
  simp [extract_eq_drop_take']
  omega

theorem extract_eq_nil_of_stop_le_start (h : j ≤ i) :
    as.extract i j = [] := by
  simp [eq_nil_iff_length_eq_zero]; omega

theorem extract_eq_nil_of_length_le_start (h : as.length ≤ i) :
    as.extract i j = [] := by
  simp [eq_nil_iff_length_eq_zero]; omega

@[simp]
theorem extract_length_left :
    as.extract as.length j = [] := by
  apply extract_eq_nil_of_length_le_start
  exact Nat.le_refl as.length

@[simp]
theorem extract_nil :
    ([] : List α).extract i j = [] := by
  simp [extract_eq_drop_take']

theorem getElem?_extract_of_lt (h : i + k < j) :
    (as.extract i j)[k]? = as[i + k]? := by
  simp only [extract_eq_drop_take', getElem?_drop]
  rw [getElem?_take_of_lt h]

@[simp]
theorem getElem?_extract_eq_some_of_lt (h : i + k < min j as.length) :
    (as.extract i j)[k]? = some as[i + k] := by
  rw [getElem?_extract_of_lt (by omega)]
  simp

theorem getElem?_extract_eq_none_iff :
   (as.extract i j)[k]? = none ↔ min j as.length ≤ i + k := by
  simp [extract_eq_drop_take']

theorem getElem?_extract_eq_dif :
    (as.extract i j)[k]? =
      if _ : i + k < min j as.length then some as[i + k] else none := by
  split <;> rename_i h
  · apply getElem?_extract_eq_some_of_lt h
  · simp; omega

theorem getElem?_extract_eq_if :
    (as.extract i j)[k]? =
      if i + k < j then as[i + k]? else none := by
  simp [extract_eq_drop_take', getElem?_drop, getElem?_take]

theorem head?_extract_eq_dif :
    (as.extract i j).head? =
      if _ : i < min j as.length then some as[i] else none := by
  simp [head?_eq_getElem?, getElem?_extract_eq_dif]

theorem head?_extract_eq_if :
    (as.extract i j).head? = if i < j then as[i]? else none := by
  simp [head?_eq_getElem?, getElem?_extract_eq_if]

theorem getElem_extract_aux (h : k < (as.extract i j).length) :
    i + k < as.length := by
  simp at h
  omega

@[simp]
theorem getElem_extract :
    (as.extract i j)[k]'h = as[i + k]'(getElem_extract_aux h) := by
  simp only [length_extract] at h
  simp [getElem_eq_getElem?_get, - get_getElem?, Option.get_inj]
  rw [getElem?_extract_of_lt]
  omega

theorem head_extract_aux (h : (as.extract i j) ≠ []) :
    i < as.length := by
  simp [ne_nil_iff_length_pos] at h
  omega

@[simp]
theorem head_extract :
    (as.extract i j).head h = as[i]'(head_extract_aux h) := by
  simp [head_eq_getElem]

theorem getElem_eq_getElem_extract_aux (h : k < as.length)
    (hi : i ≤ k) (hj : k < j) :
    k - i < (as.extract i j).length := by
  simp; omega

theorem getElem_eq_getElem_extract {h} (hi : i ≤ k) (hj : k < j) :
    as[k]'h = (as.extract i j)[k - i]'(getElem_eq_getElem_extract_aux h hi hj) := by
  simp [getElem_extract, Nat.add_sub_cancel' hi]

@[congr]
theorem extract_congr
    (w : as = bs) (h : i = i') (h' : j = j') :
    as.extract i j = bs.extract i' j' := by
  subst w h h'
  rfl

theorem extract_eq_extract_self_of_eq
    (h : min i (min j as.length) = min i' (min j' as.length))
    (h' : min j as.length = min j' as.length) :
    as.extract i j = as.extract i' j' := by
  simp [extract_eq_drop_take']
  simp +singlePass only [take_eq_take_min]
  simp +singlePass only [drop_eq_drop_min]
  simp_all [Nat.min_assoc]

theorem extract_eq_extract_min :
    as.extract i j = as.extract (min i (min j as.length)) (min j as.length) := by
  apply extract_eq_extract_self_of_eq <;> simp

@[simp]
theorem extract_zero_length : as.extract 0 as.length = as := by
  apply List.ext_getElem <;> simp

theorem extract_length : as.extract i as.length = as.drop i := by
  simp [List.extract_eq_drop_take']

theorem extract_eq_drop_of_le (h : as.length ≤ j) :
    as.extract i j = as.drop i := by
  simp only [extract_eq_drop_take', drop_take]
  rw [take_of_length_le]
  simp; omega

theorem extract_zero_left :
    as.extract 0 j = as.take j := by
  simp [extract_eq_drop_take']

@[simp]
theorem extract_zero_right :
    as.extract i 0 = [] := by
  simp [extract_eq_drop_take']

theorem extract_set {a : α} :
    (as.set k a).extract i j =
      if k < i then
        as.extract i j
      else
        (as.extract i j).set (k - i) a := by
  split
  · apply ext_getElem
    · simp
    · simp only [length_extract, length_set, getElem_extract]
      intros
      rw [getElem_set_ne (by omega)]
  · apply ext_getElem
    · simp
    · simp only [length_extract, length_set, getElem_extract]
      simp [getElem_set, Nat.sub_eq_iff_eq_add' (Nat.not_lt.mp ‹_›)]

theorem set_extract {a : α} :
    (as.extract i j).set k a = (as.set (i + k) a).extract i j := by
  apply ext_getElem <;> simp [getElem_set]

@[simp]
theorem extract_append :
    (as ++ bs).extract i j = as.extract i j ++ bs.extract (i - as.length) (j - as.length) := by
  apply ext_getElem
  · simp; omega
  · intro _ h₁ h₂
    simp only [length_extract, length_append] at h₁ h₂
    simp only [getElem_append, length_extract, getElem_extract]
    split
    · split
      · rfl
      · omega
    · split
      · omega
      · congr 1
        omega

theorem extract_append_left :
    (as ++ bs).extract 0 as.length = as.extract 0 as.length := by
  simp

theorem extract_append_right :
    (as ++ bs).extract as.length (as.length + i) = bs.extract 0 i := by
  simp

@[simp]
theorem map_extract {f : α → β} :
    (as.extract i j).map f = (as.map f).extract i j := by
  apply ext_getElem <;> simp

@[simp]
theorem extract_replicate {a : α} {n : Nat} :
    (replicate n a).extract i j = replicate (min j n - i) a := by
  apply ext_getElem <;> simp

/-
TODOS:
* theorem toArray_extract
-/

end List
