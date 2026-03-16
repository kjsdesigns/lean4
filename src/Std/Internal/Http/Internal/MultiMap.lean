/-
Copyright (c) 2025 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Init.Grind
public import Init.Data.Int.OfNat
public import Std.Data.HashMap

public section

/-!
# MultiMap

This module defines a generic `MultiMap` type that maps keys to multiple values.
The implementation stores entries in a flat array for iteration and an index HashMap
for fast key lookups. Each key always has at least one associated value.
-/

namespace Std.Internal

open Std Internal

set_option linter.all true

/--
A structure for managing ordered key-value pairs where each key can have multiple values.
-/
structure MultiMap (α : Type u) (β : Type v) [BEq α] [Hashable α] where

  /--
  Flat array of all key-value entries in insertion order.
  -/
  entries : Array (α × β)

  /--
  Maps each key to its indices in `entries`. Each array is non-empty.
  -/
  indexes : HashMap α (Array Nat)

  /--
  Invariant: every key in `indexes` maps to a non-empty array of valid indices into `entries`.
  -/
  validity : ∀ k : α, (p : k ∈ indexes) →
            let idx := (indexes.get k p);
            idx.size > 0 ∧ (∀ i ∈ idx, i < entries.size)

deriving Repr

instance [BEq α] [Hashable α] [Inhabited α] [Inhabited β] : Inhabited (MultiMap α β) where
  default := ⟨#[], .emptyWithCapacity, by intro h p; simp at p⟩

namespace MultiMap

variable {α : Type u} {β : Type v} [BEq α] [Hashable α]

instance : Membership α (MultiMap α β) where
  mem map key := key ∈ map.indexes

instance (key : α) (map : MultiMap α β) : Decidable (key ∈ map) :=
  inferInstanceAs (Decidable (key ∈ map.indexes))

/--
Retrieves all values for the given key.
-/
@[inline]
def getAll (map : MultiMap α β) (key : α) (h : key ∈ map) : Array β :=
  let entries := map.indexes.get key h |>.mapFinIdx fun idx _ h₁ =>
    let proof := map.validity key h |>.right _ (Array.getElem_mem h₁)
    map.entries[(map.indexes.get key h)[idx]]'proof |>.snd

  entries

/--
Retrieves the first value for the given key.
-/
@[inline]
def get (map : MultiMap α β) (key : α) (h : key ∈ map) : β :=
  let ⟨nonEmpty, isIn⟩ := map.validity key h
  let entry := ((map.indexes.get key h)[0]'nonEmpty)

  let proof := map.validity key h |>.right
    entry
    (by simp only [entry, HashMap.get_eq_getElem, Array.getElem_mem])

  map.entries[entry]'proof |>.snd

/--
Retrieves all values for the given key, or `none` if the key is absent.
-/
@[inline]
def getAll? (map : MultiMap α β) (key : α) : Option (Array β) :=
  if h : key ∈ map then
    some (map.getAll key h)
  else
    none

/--
Retrieves the first value for the given key, or `none` if the key is absent.
-/
@[inline]
def get? (map : MultiMap α β) (key : α) : Option β :=
  if h : key ∈ map then
    some (map.get key h)
  else
    none

/--
Checks if the key-value pair is present in the map.
-/
@[inline]
def hasEntry (map : MultiMap α β) [BEq β] (key : α) (value : β) : Bool :=
  map.getAll? key
  |>.bind (fun arr => arr.find? (· == value))
  |>.isSome

/--
Retrieves the last value for the given key.
Returns `none` if the key is absent.
-/
@[inline]
def getLast? (map : MultiMap α β) (key : α) : Option β :=
  match map.getAll? key with
  | none => none
  | some idxs => idxs.back?

/--
Like `get?`, but returns a default value if absent.
-/
@[inline]
def getD (map : MultiMap α β) (key : α) (d : β) : β :=
  map.get? key |>.getD d

/--
Like `get?`, but panics if absent.
-/
@[inline]
def get! [Inhabited β] (map : MultiMap α β) (key : α) : β :=
  map.get? key |>.get!

/--
Inserts a new key-value pair into the map.
If the key already exists, appends the value to existing values.
-/
@[inline]
def insert [EquivBEq α] [LawfulHashable α] (map : MultiMap α β) (key : α) (value : β) : MultiMap α β :=
  let i := map.entries.size
  let entries := map.entries.push (key, value)

  let f := fun
    | some idxs => some (idxs.push i)
    | none => some #[i]

  let indexes := map.indexes.alter key f

  { entries, indexes, validity := ?_ }
where finally
  have _ := map.validity
  grind

/--
Inserts multiple values for a given key, appending to any existing values.
-/
@[inline]
def insertMany [EquivBEq α] [LawfulHashable α] (map : MultiMap α β) (key : α) (values : Array β) : MultiMap α β :=
  values.foldl (insert · key) map

/--
Creates an empty multimap.
-/
def empty : MultiMap α β :=
  ⟨#[], .emptyWithCapacity, by intro h p; simp at p⟩

/--
Creates a multimap from a list of key-value pairs.
-/
def ofList [EquivBEq α] [LawfulHashable α] (pairs : List (α × β)) : MultiMap α β :=
  pairs.foldl (fun acc (k, v) => acc.insert k v) empty

/--
Checks if a key exists in the map.
-/
@[inline]
def contains (map : MultiMap α β) (key : α) : Bool :=
  map.indexes.contains key

/--
Updates all values associated with `key` by applying `f` to each one.
If the key is absent, returns the map unchanged.
-/
@[inline]
def update [EquivBEq α] [LawfulHashable α] (map : MultiMap α β) (key : α) (f : β → β) : MultiMap α β :=
  if key ∉ map then
    map
  else
    map.entries.foldl (fun acc (k, v) => acc.insert k (if k == key then f v else v)) empty

/--
Replaces the last value associated with `key` with `value`.
If the key is absent, returns the map unchanged.
-/
@[inline]
def replaceLast (map : MultiMap α β) (key : α) (value : β) : MultiMap α β :=
  if h : key ∈ map then
    let idxs := map.indexes.get key h
    let ⟨nonEmpty, isIn⟩ := map.validity key h
    let lastPos : Fin idxs.size := ⟨idxs.size - 1, Nat.sub_lt nonEmpty (by omega)⟩
    let lastIdx : Nat := idxs[lastPos]
    have lastIdxValid : lastIdx < map.entries.size := isIn lastIdx (Array.getElem_mem lastPos.isLt)
    let entries := map.entries.set (Fin.mk lastIdx lastIdxValid) (key, value)
    { map with entries, validity := ?_ }
  else
    map
where finally
  have _ := map.validity
  grind

/--
Removes a key and all its values from the map. This function rebuilds the entire
`entries` array and `indexes` map from scratch by filtering out all pairs whose
key matches, then re-inserting the survivors.
-/
@[inline]
def erase [EquivBEq α] [LawfulHashable α] (map : MultiMap α β) (key : α) : MultiMap α β :=
  if key ∉ map then
    map
  else
    map.entries.filter (fun (k, _) => !(k == key))
    |>.foldl (fun acc (k, v) => acc.insert k v) empty

/--
Gets the number of entries in the map.
-/
@[inline]
def size (map : MultiMap α β) : Nat :=
  map.entries.size

/--
Checks if the map is empty.
-/
@[inline]
def isEmpty (map : MultiMap α β) : Bool :=
  map.entries.isEmpty

/--
Converts the multimap to an array of key-value pairs (flattened).
-/
def toArray (map : MultiMap α β) : Array (α × β) :=
  map.entries

/--
Converts the multimap to a list of key-value pairs (flattened).
-/
def toList (map : MultiMap α β) : List (α × β) :=
  map.entries.toList

/--
Merges two multimaps, combining values for shared keys.
-/
def merge [EquivBEq α] [LawfulHashable α] (m1 m2 : MultiMap α β) : MultiMap α β :=
  m2.entries.foldl (fun acc (k, v) => acc.insert k v) m1

instance : EmptyCollection (MultiMap α β) :=
  ⟨MultiMap.empty⟩

instance [EquivBEq α] [LawfulHashable α] : Singleton (α × β) (MultiMap α β) :=
  ⟨fun ⟨a, b⟩ => (∅ : MultiMap α β).insert a b⟩

instance [EquivBEq α] [LawfulHashable α] : Insert (α × β) (MultiMap α β) :=
  ⟨fun ⟨a, b⟩ m => m.insert a b⟩

instance [EquivBEq α] [LawfulHashable α] : Union (MultiMap α β) :=
  ⟨merge⟩

instance [Monad m] : ForIn m (MultiMap α β) (α × β) where
  forIn map b f := forIn map.entries b f

end Std.Internal.MultiMap
