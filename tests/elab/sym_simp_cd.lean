/-
Test for `contextDependent` two-tier cache in Sym.simp.

Uses `dischargeAssumption` (context-dependent) to verify:
- Context-independent results land in persistent cache and survive across invocations.
- Context-dependent results land in transient cache and are re-computed on second invocation.
-/
import Lean

open Lean Elab Tactic Meta

/-- Invoke simp twice on the same goal, threading the persistent cache. -/
elab "sym_simp_twice" "[" declNames:ident,* "]" : tactic => do
  let rewrite ← Sym.mkSimprocFor (← declNames.getElems.mapM fun s => realizeGlobalConstNoOverload s.raw) Sym.Simp.dischargeAssumption
  let methods : Sym.Simp.Methods := {
    pre  := Sym.Simp.simpControl.andThen Sym.Simp.simpArrowTelescope
    post := Sym.Simp.evalGround.andThen rewrite
  }
  liftMetaTactic1 fun mvarId => Sym.SymM.run do
    let mvarId ← Sym.preprocessMVar mvarId
    let target := (← mvarId.getDecl).type
    -- First invocation: builds the cache from scratch
    let (_, state) ← Sym.Simp.SimpM.run (Sym.Simp.simp target) methods
    -- Second invocation: persistent cache carries over, transient cache is cleared
    let (result, _) ← Sym.Simp.SimpM.run (Sym.Simp.simp target) methods (s := state)
    (← result.toSimpGoalResult mvarId).toOption

-- Test 1: Ground evaluation is context-independent.
-- The second invocation should hit the persistent cache for the whole expression.
set_option trace.sym.simp.debug.cache true in
/--
trace: [sym.simp.debug.cache] persistent cache hit: 2 + 3 = 5
-/
#guard_msgs in
example : 2 + 3 = 5 := by
  sym_simp_twice []

-- Test 2: Conditional rewrite using a hypothesis is context-dependent.
-- `dischargeAssumption` uses local hypothesis `h : 0 < n`, so the result is context-dependent
-- and lands in the transient cache. On the second invocation, the transient cache is
-- cleared, so there should be NO persistent cache hit for the overall expression.
-- Only context-independent sub-expressions (literals, fvars) get persistent cache hits.
theorem Nat.add_comm_of_pos (a b : Nat) (_h : 0 < a) : a + b = b + a := Nat.add_comm a b

set_option trace.sym.simp.debug.cache true in
/--
trace: [sym.simp.debug.cache] persistent cache hit: 2
[sym.simp.debug.cache] persistent cache hit: n
[sym.simp.debug.cache] transient cache hit: 2 + n
[sym.simp.debug.cache] persistent cache hit: n
[sym.simp.debug.cache] persistent cache hit: 2
[sym.simp.debug.cache] persistent cache hit: 2
[sym.simp.debug.cache] persistent cache hit: n
[sym.simp.debug.cache] transient cache hit: 2 + n
-/
#guard_msgs in
example (n : Nat) (h : 0 < n) : n + 2 = 2 + n := by
  sym_simp_twice [Nat.add_comm_of_pos]
