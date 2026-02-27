import Lean

set_option maxHeartbeats 800000

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

partial def bench1 (n : Nat) : MetaM Unit := do
  -- Test instantiateMVars (C++)
  let mvarId1 ← mkBench1 n
  solve mvarId1
  let t0 ← IO.monoNanosNow
  let r1 ← instantiateMVars (mkMVar mvarId1)
  let t1 ← IO.monoNanosNow
  let instMs := (t1 - t0).toFloat / 1000000.0

  -- Test instantiateMVarsNoUpdate (C++) with fresh mvars
  let mvarId2 ← mkBench1 n
  solve mvarId2
  let t2 ← IO.monoNanosNow
  let r2 ← instantiateMVarsNoUpdate (mkMVar mvarId2)
  let t3 ← IO.monoNanosNow
  let nuCppMs := (t3 - t2).toFloat / 1000000.0

  -- Test instantiateMVarsNoUpdateLean with fresh mvars
  let mvarId3 ← mkBench1 n
  solve mvarId3
  let t4 ← IO.monoNanosNow
  let r3 ← instantiateMVarsNoUpdateLean (mkMVar mvarId3)
  let t5 ← IO.monoNanosNow
  let nuLeanMs := (t5 - t4).toFloat / 1000000.0

  -- Verify correctness
  unless Expr.eqv r1 r2 do
    IO.println s!"ERROR: instantiateMVars vs NoUpdate(C++) differ for n={n}"
  unless Expr.eqv r1 r3 do
    IO.println s!"ERROR: instantiateMVars vs NoUpdate(Lean) differ for n={n}"

  IO.println s!"bench1_{n}: instantiateMVars {instMs} ms, NoUpdate(C++) {nuCppMs} ms, NoUpdate(Lean) {nuLeanMs} ms"

run_meta do
  IO.println "Example (n = 5):"
  let ex ← (← mkBench1 5).getType
  IO.println s!"{← ppExpr ex}"
  IO.println ""
  for i in [10, 20, 40, 80, 100, 200, 300, 400, 500] do
    bench1 i
