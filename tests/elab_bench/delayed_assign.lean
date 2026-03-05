import Lean

/-!
This benchmark exercises `instantiateMVars` on a large metavariable
assignment graph with many nested delayed assignments.

We construct a goal of the form
  `∀ x₁ … xₙ, ((0 ≤ x₁) ∧ … ∧ True) ∧ … ∧ ((0 ≤ xₙ) ∧ … ∧ True)`
as a single mvar, solve it (creating O(n²) delayed mvars), and then
call `instantiateMVars` to fully resolve the result.
-/

set_option maxHeartbeats 40000000

open Lean Meta

def mkLE (i : Nat) : Expr :=
  mkNatLE (mkNatLit 0) (mkBVar i)

partial def solve (mvarId : MVarId) : MetaM Unit := do
  let type ← instantiateMVars (← mvarId.getType)
  if type.isForall then
    let (_, mvarId) ← mvarId.intro1
    solve mvarId
  else if type.isAppOf ``And then
    let [mvarId₁, mvarId₂] ← mvarId.applyConst ``And.intro | failure
    solve mvarId₁
    solve mvarId₂
  else if type.isAppOf ``LE.le then
    let [] ← mvarId.applyConst ``Nat.zero_le | failure
  else
    let [] ← mvarId.applyConst ``True.intro | failure

def mkBench (n : Nat) : MetaM MVarId := do
  let type := mkType n
  return (← mkFreshExprSyntheticOpaqueMVar type).mvarId!
where
  mkResultType (i : Nat) : Expr :=
    match i with
    | 0 => mkConst ``True
    | i+1 => mkAnd (mkLE i) (mkResultType i)

  mkType (i : Nat) : Expr :=
    match i with
    | 0 => mkResultType n
    | i+1 => .forallE `x Nat.mkType (mkAnd (mkType i) (mkLE (n - i - 1))) .default

-- Size calibrated to take roughly 1s total elaboration time.
run_meta do
  let n := 700
  let mvarId ← mkBench n
  solve mvarId
  let result ← instantiateMVars (mkMVar mvarId)
  let numObjs ← result.numObjs
  IO.println s!"n={n} numObjs={numObjs}"
