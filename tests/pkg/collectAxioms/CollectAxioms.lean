module

public import CollectAxioms.Left
public import CollectAxioms.Right
public import CollectAxioms.Chain.Top
public import CollectAxioms.Chain.Middle
public import CollectAxioms.Chain.Bottom

-- Diamond: both Left and Right have `private axiom ax` used in their public theorems' proofs.
public theorem combined : True ∧ True := ⟨leftThm, rightThm⟩

/-- info: 'combined' depends on axioms: [_private.CollectAxioms.Left.0.ax, _private.CollectAxioms.Right.0.ax] -/
#guard_msgs in
#print axioms combined

/-- info: 'leftThm' depends on axioms: [_private.CollectAxioms.Left.0.ax] -/
#guard_msgs in
#print axioms leftThm

/-- info: 'rightThm' depends on axioms: [_private.CollectAxioms.Right.0.ax] -/
#guard_msgs in
#print axioms rightThm

-- Chain: Bottom has public axiom, Middle has public def (body stripped), Top has public theorem.
-- The axiom dependency propagates through the stripped def.

/-- info: 'chainThm' depends on axioms: [chainAx] -/
#guard_msgs in
#print axioms chainThm

/-- info: 'chainDef' depends on axioms: [chainAx] -/
#guard_msgs in
#print axioms chainDef
