module

/-!
# Scope Cache: Specification and Verification

This file models the `scope_cache` data structure from `src/kernel/scope_cache.h`
and verifies that the optimized implementation refines the simple conceptual model.
-/

namespace ScopeCache

/-! ## Conceptual model

The scope cache is a stack of `Key → (Value × Nat)` maps.
The `Nat` (called `resultScope`) records the outermost scope the entry depends on.

- `lookup` only considers the top map and returns entries valid at that scope.
- `insert` writes the entry into all maps from `resultScope` to the top.
  If an existing entry with the same `resultScope` is found, its value is reused.
-/
namespace Conceptual

abbrev Map (Key Value : Type) := Key → Option (Value × Nat)

structure ScopeCache (Key Value : Type) where
  /-- Stack of maps, index 0 = bottom (outermost scope). -/
  stack : List (Map Key Value)
  deriving Inhabited

def empty (Key Value : Type) : ScopeCache Key Value :=
  ⟨[fun _ => none]⟩

def scope (c : ScopeCache Key Value) : Nat :=
  c.stack.length - 1

def push (c : ScopeCache Key Value) : ScopeCache Key Value :=
  ⟨c.stack ++ [fun _ => none]⟩

def pop (c : ScopeCache Key Value) : ScopeCache Key Value :=
  ⟨c.stack.dropLast⟩

def lookup [BEq Key] (c : ScopeCache Key Value) (key : Key) : Option (Value × Nat) :=
  match c.stack.getLast? with
  | none => none
  | some m => m key

/-- Helper: find an existing value with the given resultScope in maps
    from `lo` to `hi`. -/
def findShared [BEq Key] (stack : List (Map Key Value)) (key : Key)
    (resultScope : Nat) (lo hi : Nat) : Option Value :=
  let rec go (i : Nat) (maps : List (Map Key Value)) : Option Value :=
    match maps with
    | [] => none
    | m :: rest =>
      if lo ≤ i ∧ i ≤ hi then
        match m key with
        | some (v, rs) => if rs == resultScope then some v else go (i + 1) rest
        | none => go (i + 1) rest
      else go (i + 1) rest
  go 0 stack

/-- Insert into all maps from `resultScope` to `scope c`. -/
def insert [BEq Key] (c : ScopeCache Key Value) (key : Key) (value : Value)
    (resultScope : Nat) : ScopeCache Key Value × Value :=
  let s := scope c
  -- Check if there's an existing entry we should reuse for sharing
  let shared := match findShared c.stack key resultScope resultScope s with
    | some v => v
    | none => value
  let stack' := c.stack.mapIdx fun i m =>
    if resultScope ≤ i ∧ i ≤ s then
      fun k => if k == key then some (shared, resultScope) else m k
    else m
  (⟨stack'⟩, shared)

end Conceptual

/-! ## Implementation model

Models the C++ implementation: a single map from keys to entry stacks,
generation counters, and a persistent generation list.
-/
namespace Impl

/-- Persistent linked list of generation numbers, one per scope level.
    Head = innermost scope. Stored innermost-first:
    gens[0] = gen for current scope, gens[1] = gen for parent, etc. -/
structure GenList where
  gens : List Nat  -- gens[0] = innermost scope's gen, gens[n] = outermost
  deriving Repr, BEq, Inhabited

def GenList.drop1 (gl : GenList) : GenList :=
  ⟨gl.gens.tail⟩

/-- Get generation at a given scope level, given that this GenList
    represents scopes from `topLevel` down.
    Level `topLevel` is at index 0, level `topLevel - 1` at index 1, etc. -/
def genAt (gl : GenList) (topLevel level : Nat) : Option Nat :=
  gl.gens[topLevel - level]?

structure CacheEntry (Value : Type) where
  result : Value
  scopeLevel : Nat        -- scope at which this entry is valid
  scopeGens : GenList      -- snapshot of gen list at insert time
  resultScope : Nat        -- outermost scope the result depends on
  deriving Repr

structure ScopeCache (Key Value : Type) where
  cache : Key → List (CacheEntry Value)
  genCounter : Nat
  currentGens : GenList      -- current scope gen list
  scopeN : Nat               -- current scope level
  deriving Inhabited

def empty (Key Value : Type) : ScopeCache Key Value :=
  ⟨fun _ => [], 0, ⟨[0]⟩, 0⟩

def scope (c : ScopeCache Key Value) : Nat := c.scopeN

def push (c : ScopeCache Key Value) : ScopeCache Key Value :=
  { c with
    scopeN := c.scopeN + 1
    genCounter := c.genCounter + 1
    currentGens := ⟨(c.genCounter + 1) :: c.currentGens.gens⟩ }

def pop (c : ScopeCache Key Value) : ScopeCache Key Value :=
  { c with
    scopeN := c.scopeN - 1
    currentGens := c.currentGens.drop1 }

/-- Degrade a GenList by dropping `n` entries from the front (popping inner scopes). -/
def degradeGens (gl : GenList) : Nat → GenList
  | 0 => gl
  | n + 1 => degradeGens gl.drop1 n

/-- Walk the current gen list down from currentScope to a target level. -/
def walkCurrentDown (currentGens : GenList) (currentScope targetLevel : Nat) : GenList :=
  degradeGens currentGens (currentScope - targetLevel)

/-- Rewind one entry: degrade or discard. Returns `some entry'` if valid, `none` if discarded. -/
def rewindOne (top : CacheEntry Value) (currentScope : Nat)
    (currentGens : GenList) : Option (CacheEntry Value) :=
  -- Discard entries whose result depends on popped scopes
  if top.resultScope > currentScope then
    none
  else
    -- Degrade: drop scopeGens entries for popped scopes
    let steps := top.scopeLevel - min top.scopeLevel currentScope
    let degradedGens := degradeGens top.scopeGens steps
    let degradedLevel := top.scopeLevel - steps
    -- Check generation match at degradedLevel
    let entryGen := degradedGens.gens[0]?
    let curGensAtLevel := walkCurrentDown currentGens currentScope degradedLevel
    let curGen := curGensAtLevel.gens[0]?
    match entryGen, curGen with
    | some eg, some cg =>
      if eg == cg then
        -- Valid: update the entry in place
        some { top with scopeLevel := degradedLevel, scopeGens := degradedGens }
      else
        -- Generation mismatch: walk both lists in lockstep to find a valid level
        let rec walkDown (eGens cGens : GenList) (lvl : Nat)
            (fuel : Nat) : Option (Nat × GenList) :=
          if fuel == 0 then none
          else if lvl ≤ top.resultScope then none
          else
            let eGens' := eGens.drop1
            let cGens' := cGens.drop1
            let lvl' := lvl - 1
            match eGens'.gens[0]?, cGens'.gens[0]? with
            | some eg, some cg =>
              if eg == cg then some (lvl', eGens')
              else walkDown eGens' cGens' lvl' (fuel - 1)
            | _, _ => none
        match walkDown degradedGens curGensAtLevel degradedLevel degradedLevel with
        | some (lvl', eGens') =>
          some { top with scopeLevel := lvl', scopeGens := eGens' }
        | none => none
    | _, _ => none

/-- Rewind: lazily clean up the back of a per-key entry stack.
    Models the C++ `rewind` method which processes from the back.
    After rewind, either the stack is empty or its last entry satisfies
    scope_level <= currentScope with a matching generation. -/
def rewind (entries : List (CacheEntry Value)) (currentScope : Nat)
    (currentGens : GenList) : List (CacheEntry Value) :=
  go entries.reverse currentScope currentGens []
where
  /-- Process entries from back to front (reversed list = front to back). -/
  go : List (CacheEntry Value) → Nat → GenList → List (CacheEntry Value) →
       List (CacheEntry Value)
  | [], _, _, acc => acc
  | top :: rest, currentScope, currentGens, acc =>
    match rewindOne top currentScope currentGens with
    | some top' =>
      -- Found a valid entry: done (C++ returns after first valid)
      rest.reverse ++ [top'] ++ acc
    | none =>
      -- Discard this entry and keep going
      go rest currentScope currentGens acc

def lookup [BEq Key] (c : ScopeCache Key Value) (key : Key) : Option (Value × Nat) :=
  let entries := c.cache key
  let entries' := rewind entries c.scopeN c.currentGens
  -- The C++ uses back() on a vector; in our list, the last element is at the end
  match entries'.getLast? with
  | none => none
  | some top =>
    if top.scopeLevel == c.scopeN then
      some (top.result, top.resultScope)
    else none

def insert [BEq Key] (c : ScopeCache Key Value) (key : Key) (value : Value)
    (resultScope : Nat) : ScopeCache Key Value × Value :=
  let entries := c.cache key
  let entries' := rewind entries c.scopeN c.currentGens
  -- Check for sharing with existing entry (C++ checks back())
  let shared := match entries'.getLast? with
    | some top => if top.resultScope == resultScope then top.result else value
    | none => value
  -- Remove entries at or above resultScope (C++ pops from back while >= resultScope)
  let entries'' := entries'.filter fun e => e.scopeLevel < resultScope
  -- Push new entry (C++ push_back)
  let newEntry : CacheEntry Value := {
    result := shared
    scopeLevel := c.scopeN
    scopeGens := c.currentGens
    resultScope := resultScope
  }
  let entries''' := entries'' ++ [newEntry]
  let cache' := fun k => if k == key then entries''' else c.cache k
  ({ c with cache := cache' }, shared)

end Impl

/-! ## Tests

We verify correspondence between conceptual and implementation models
by running both in lockstep on the same operation sequences.
-/
namespace Proofs

abbrev Key := Nat
abbrev Value := Nat

-- Test the conceptual model
def testConceptual : IO Unit := do
  let c := Conceptual.empty Key Value
  assert! Conceptual.scope c == 0
  assert! Conceptual.lookup c 1 == none

  -- Insert at scope 0
  let (c, _) := Conceptual.insert c 1 100 0
  assert! Conceptual.lookup c 1 == some (100, 0)

  -- Push scope
  let c := Conceptual.push c
  assert! Conceptual.scope c == 1
  -- Entry at scope 0 is NOT visible at scope 1 (only top map)
  assert! Conceptual.lookup c 1 == none

  -- Insert at scope 1 with resultScope 0 → sharing reuses old value 100
  let (c, v) := Conceptual.insert c 1 200 0
  assert! v == 100  -- sharing!
  assert! Conceptual.lookup c 1 == some (100, 0)

  -- Pop back to scope 0
  let c := Conceptual.pop c
  assert! Conceptual.scope c == 0
  -- The insert at scope 1 also wrote to scope 0
  assert! Conceptual.lookup c 1 == some (100, 0)

  IO.println "Conceptual tests passed"

-- Test the implementation model
def testImpl : IO Unit := do
  let c := Impl.empty Key Value
  assert! Impl.scope c == 0
  assert! Impl.lookup c 1 == none

  -- Insert at scope 0
  let (c, _) := Impl.insert c 1 100 0
  assert! Impl.lookup c 1 == some (100, 0)

  -- Push scope
  let c := Impl.push c
  assert! Impl.scope c == 1
  assert! Impl.lookup c 1 == none

  -- Insert at scope 1 with resultScope 0 → sharing reuses old value 100
  let (c, v) := Impl.insert c 1 200 0
  assert! v == 100  -- sharing!
  assert! Impl.lookup c 1 == some (100, 0)

  -- Pop back to scope 0
  let c := Impl.pop c
  assert! Impl.scope c == 0
  assert! Impl.lookup c 1 == some (100, 0)

  IO.println "Impl tests passed"

-- Test scope re-entry invalidation
def testReentry : IO Unit := do
  let c := Impl.empty Key Value
  let c := Impl.push c
  let (c, _) := Impl.insert c 1 100 1
  assert! Impl.lookup c 1 == some (100, 1)
  let c := Impl.pop c
  let c := Impl.push c  -- re-entered scope 1 with new generation
  assert! Impl.lookup c 1 == none
  IO.println "Re-entry test passed"

-- Test sharing: insert finds existing value
def testSharing : IO Unit := do
  let c := Impl.empty Key Value
  let (c, v1) := Impl.insert c 1 100 0
  assert! v1 == 100
  let c := Impl.push c
  let (c, v2) := Impl.insert c 1 200 0
  -- Should reuse old value 100 (same resultScope)
  assert! v2 == 100
  assert! Impl.lookup c 1 == some (100, 0)
  IO.println "Sharing test passed"

-- Test that entries with resultScope depending on inner scopes are invalidated
def testResultScopeInvalidation : IO Unit := do
  let c := Impl.empty Key Value
  let c := Impl.push c
  let c := Impl.push c
  let (c, _) := Impl.insert c 1 100 2
  assert! Impl.lookup c 1 == some (100, 2)
  let c := Impl.pop c
  assert! Impl.lookup c 1 == none
  IO.println "Result scope invalidation test passed"

-- Test degradation
def testDegradation : IO Unit := do
  let c := Impl.empty Key Value
  let c := Impl.push c
  let c := Impl.push c
  let c := Impl.push c  -- scope 3
  let (c, _) := Impl.insert c 1 100 1  -- depends on scope 1
  assert! Impl.lookup c 1 == some (100, 1)
  let c := Impl.pop c  -- scope 2
  assert! Impl.lookup c 1 == some (100, 1)
  let c := Impl.pop c  -- scope 1
  assert! Impl.lookup c 1 == some (100, 1)
  IO.println "Degradation test passed"

-- Compare conceptual and implementation on a sequence of operations
inductive Op where
  | push
  | pop
  | lookup (key : Nat)
  | insert (key : Nat) (value : Nat) (resultScope : Nat)
  deriving Repr

structure DualState where
  concept : Conceptual.ScopeCache Key Value
  impl : Impl.ScopeCache Key Value

def initDual : DualState :=
  { concept := Conceptual.empty Key Value
    impl := Impl.empty Key Value }

def runOp (s : DualState) (op : Op) : IO DualState := do
  match op with
  | .push =>
    pure { concept := Conceptual.push s.concept
           impl := Impl.push s.impl }
  | .pop =>
    if Conceptual.scope s.concept == 0 then pure s
    else
      pure { concept := Conceptual.pop s.concept
             impl := Impl.pop s.impl }
  | .lookup key => do
    let cr := Conceptual.lookup s.concept key
    let ir := Impl.lookup s.impl key
    match cr, ir with
    | none, none => pure ()
    | some (cv, cs), some (iv, is_) =>
      if cv != iv || cs != is_ then
        throw <| IO.userError s!"lookup mismatch at key {key}: conceptual=({cv},{cs}) impl=({iv},{is_})"
    | some _, none =>
      throw <| IO.userError s!"lookup mismatch at key {key}: conceptual=some, impl=none"
    | none, some _ =>
      throw <| IO.userError s!"lookup mismatch at key {key}: conceptual=none, impl=some"
    pure s
  | .insert key value resultScope => do
    if resultScope > Conceptual.scope s.concept then pure s
    else
      let (c', cv) := Conceptual.insert s.concept key value resultScope
      let (i', iv) := Impl.insert s.impl key value resultScope
      if cv != iv then
        throw <| IO.userError s!"insert sharing mismatch at key {key}: conceptual={cv} impl={iv}"
      pure { concept := c', impl := i' }

def runOps (ops : List Op) : IO Unit := do
  let mut s := initDual
  let mut i := 0
  for op in ops do
    s ← try runOp s op catch e => throw (IO.userError s!"op {i} ({repr op}): {e}")
    i := i + 1
  IO.println s!"Dual test passed ({ops.length} ops)"

def testDualComprehensive : IO Unit := do
  runOps [
    .insert 1 10 0,
    .lookup 1,
    .push,
    .lookup 1,
    .insert 1 20 0,      -- sharing: reuses value 10 from scope 0 entry
    .lookup 1,            -- should find (10, 0) due to sharing
    .insert 2 30 1,
    .lookup 2,
    .push,
    .insert 3 40 2,
    .lookup 3,
    .pop,
    .lookup 3,            -- gone (resultScope 2 popped)
    .lookup 2,            -- degrade and find
    .lookup 1,
    .pop,
    .lookup 2,            -- gone (resultScope 1 popped)
    .lookup 1,            -- found (resultScope 0)
    .push,                -- re-enter scope 1
    .lookup 1,            -- not at top
    .insert 1 50 1,
    .lookup 1
  ]

def testDualReentry : IO Unit := do
  runOps [
    .push,
    .insert 1 100 1,
    .pop,
    .push,                -- re-enter scope 1
    .lookup 1,            -- stale
    .insert 1 200 1,
    .lookup 1
  ]

def testDualDeep : IO Unit := do
  runOps [
    .push, .push, .push,
    .insert 1 100 1,
    .lookup 1,
    .pop,
    .lookup 1,
    .pop,
    .lookup 1,
    .pop,
    .lookup 1             -- gone (resultScope 1 > scope 0)
  ]

#eval testConceptual
#eval testImpl
#eval testReentry
#eval testSharing
#eval testResultScopeInvalidation
#eval testDegradation
#eval testDualComprehensive
#eval testDualReentry
#eval testDualDeep

end Proofs

end ScopeCache
