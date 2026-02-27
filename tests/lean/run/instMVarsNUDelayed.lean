import Lean
/-!
# Tests for `instantiateMVarsNoUpdate` handling of unassigned metavariables

These tests verify that `instantiateMVarsNoUpdate` correctly creates delayed-assigned
metavariables when encountering unassigned mvars with an active fvar substitution.
This is essential for using `instantiateMVarsNoUpdate` as a drop-in replacement
for `instantiateMVars` in contexts like `mkForallFVars`/`mkLambdaFVars`.
-/

open Lean Meta

/-- Test 1: Basic delayed assignment with unassigned pending mvar.

When `?m [x] := ?pending` and `?pending` is unassigned,
`instantiateMVarsNoUpdate` should create a new delayed mvar
that captures the fvar substitution. -/
def test1 : MetaM Unit := do
  withLocalDecl `x .default (mkConst ``Nat) fun x => do
    let pending ← mkFreshExprSyntheticOpaqueMVar (mkConst ``Nat)
    let m ← mkFreshExprSyntheticOpaqueMVar (mkConst ``Nat)
    assignDelayedMVar m.mvarId! #[x] pending.mvarId!

    -- Apply ?m to a concrete value (not x)
    let e := mkApp m (mkNatLit 7)

    -- instantiateMVarsNoUpdate should produce an expression without fvar x
    let e_nu ← instantiateMVarsNoUpdate e
    unless !e_nu.hasFVar do
      throwError "test1: result should not have free variables, got {← ppExpr e_nu}"

    -- Assign pending to x + 1
    pending.mvarId!.assign (mkApp2 (mkConst ``Nat.add) x (mkNatLit 1))

    -- After assignment, both should resolve to the same thing
    let e_nu_final ← instantiateMVars e_nu
    let e_inst_final ← instantiateMVars e
    unless Expr.eqv e_nu_final e_inst_final do
      throwError "test1: results differ:\n  NoUpdate:      {← ppExpr e_nu_final}\n  instantiate:   {← ppExpr e_inst_final}"

/-- Test 2: Nested delayed assignments.

`?outer [x, y] := ?inner`, `?inner` assigned to expression containing `?leaf`,
where `?leaf` is unassigned. -/
def test2 : MetaM Unit := do
  withLocalDecl `x .default (mkConst ``Nat) fun x => do
  withLocalDecl `y .default (mkConst ``Nat) fun y => do
    let leaf ← mkFreshExprSyntheticOpaqueMVar (mkConst ``Nat)
    let inner ← mkFreshExprSyntheticOpaqueMVar (mkConst ``Nat)
    -- inner := leaf (a simple assignment)
    inner.mvarId!.assign leaf

    let outer ← mkFreshExprSyntheticOpaqueMVar (mkConst ``Nat)
    assignDelayedMVar outer.mvarId! #[x, y] inner.mvarId!

    -- Apply outer to concrete values
    let e := mkApp (mkApp outer (mkNatLit 3)) (mkNatLit 5)

    let e_nu ← instantiateMVarsNoUpdate e
    unless !e_nu.hasFVar do
      throwError "test2: result should not have free variables, got {e_nu}"

    -- Assign leaf to x + y
    leaf.mvarId!.assign (mkApp2 (mkConst ``Nat.add) x y)

    let e_nu_final ← instantiateMVars e_nu
    let e_inst_final ← instantiateMVars e
    unless Expr.eqv e_nu_final e_inst_final do
      throwError "test2: results differ:\n  NoUpdate:      {← ppExpr e_nu_final}\n  instantiate:   {← ppExpr e_inst_final}"

/-- Test 3: Multiple unassigned mvars under a single delayed assignment. -/
def test3 : MetaM Unit := do
  withLocalDecl `x .default (mkConst ``Nat) fun x => do
    let m1 ← mkFreshExprSyntheticOpaqueMVar (mkConst ``Nat)
    let m2 ← mkFreshExprSyntheticOpaqueMVar (mkConst ``Nat)

    -- inner is assigned to And.intro m1 m2
    let innerType := mkApp2 (mkConst ``And) (mkConst ``Nat) (mkConst ``Nat)
    let inner ← mkFreshExprSyntheticOpaqueMVar innerType
    inner.mvarId!.assign (mkApp4 (mkConst ``And.intro [.zero, .zero]) (mkConst ``Nat) (mkConst ``Nat) m1 m2)

    let outer ← mkFreshExprSyntheticOpaqueMVar innerType
    assignDelayedMVar outer.mvarId! #[x] inner.mvarId!

    let e := mkApp outer (mkNatLit 10)

    let e_nu ← instantiateMVarsNoUpdate e
    unless !e_nu.hasFVar do
      throwError "test3: result should not have free variables, got {e_nu}"

    -- Assign both mvars
    m1.mvarId!.assign x
    m2.mvarId!.assign (mkApp2 (mkConst ``Nat.add) x (mkNatLit 1))

    let e_nu_final ← instantiateMVars e_nu
    let e_inst_final ← instantiateMVars e
    unless Expr.eqv e_nu_final e_inst_final do
      throwError "test3: results differ:\n  NoUpdate:      {← ppExpr e_nu_final}\n  instantiate:   {← ppExpr e_inst_final}"

/-- Test 4: Unassigned mvar whose context does NOT include the substituted fvar. -/
def test4 : MetaM Unit := do
  withLocalDecl `x .default (mkConst ``Nat) fun x => do
  withLocalDecl `y .default (mkConst ``Nat) fun y => do
    -- Create pending mvar in full context (has both x and y)
    let pending ← mkFreshExprSyntheticOpaqueMVar (mkConst ``Nat)

    -- Delayed assignment only over x
    let outer ← mkFreshExprSyntheticOpaqueMVar (mkConst ``Nat)
    assignDelayedMVar outer.mvarId! #[x] pending.mvarId!

    let e := mkApp outer (mkNatLit 42)

    let e_nu ← instantiateMVarsNoUpdate e

    -- Assign pending to y (doesn't use x, the substituted fvar)
    pending.mvarId!.assign y

    let e_nu_final ← instantiateMVars e_nu
    let e_inst_final ← instantiateMVars e
    unless Expr.eqv e_nu_final e_inst_final do
      throwError "test4: results differ:\n  NoUpdate:      {← ppExpr e_nu_final}\n  instantiate:   {← ppExpr e_inst_final}"

-- Run all tests
run_meta do
  test1
  IO.println "test1 passed"
  test2
  IO.println "test2 passed"
  test3
  IO.println "test3 passed"
  test4
  IO.println "test4 passed"
  IO.println "All tests passed!"
