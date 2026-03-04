import Lean
import Lean.Meta.InstMVarsAll
import Lean.Meta.InstMVarsNU

set_option maxHeartbeats 4000000

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

def mkBench1 (n : Nat) : MetaM MVarId := do
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

/-- Run a single implementation on a fresh copy of the benchmark, return (result, time_ms). -/
def runImpl (n : Nat) (f : Expr → MetaM Expr) : MetaM (Expr × Float) := do
  let mvarId ← mkBench1 n
  solve mvarId
  let t0 ← IO.monoNanosNow
  let r ← f (mkMVar mvarId)
  let t1 ← IO.monoNanosNow
  let ms := (t1 - t0).toFloat / 1000000.0
  return (r, ms)

partial def bench1 (n : Nat) : MetaM Unit := do
  let (rDefault, msDefault) ← runImpl n instantiateMVars
  let (rOriginal, msOriginal) ← runImpl n instantiateMVarsOriginal
  let (rAll, msAll) ← runImpl n instantiateAllMVars
  let (rNUCpp, msNUCpp) ← runImpl n instantiateMVarsNoUpdate
  let (rNULean, msNULean) ← runImpl n instantiateMVarsNoUpdateLean

  -- Verify correctness
  unless Expr.eqv rDefault rOriginal do
    IO.println s!"ERROR: instantiateMVars vs Original differ for n={n}"
  unless Expr.eqv rDefault rAll do
    IO.println s!"ERROR: instantiateMVars vs AllMVars differ for n={n}"
  unless Expr.eqv rDefault rNUCpp do
    IO.println s!"ERROR: instantiateMVars vs NoUpdate(C++) differ for n={n}"
  unless Expr.eqv rDefault rNULean do
    IO.println s!"ERROR: instantiateMVars vs NoUpdate(Lean) differ for n={n}"

  IO.println s!"bench1_{n}: instantiateMVars {msDefault} ms, Original {msOriginal} ms, AllMVars {msAll} ms, NoUpdate(C++) {msNUCpp} ms, NoUpdate(Lean) {msNULean} ms"

run_meta do
  IO.println "Example (n = 5):"
  let ex ← (← mkBench1 5).getType
  IO.println s!"{← ppExpr ex}"
  IO.println ""
  for i in [10, 20, 40, 80, 100, 200, 300, 400, 500] do
    bench1 i
