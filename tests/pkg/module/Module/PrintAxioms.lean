module

prelude
public import Module.Basic  -- provides `testSorry`, `f`, `fexp`, `P`, `hP1`

/-! Tests that `#print axioms` works correctly in `module` files.

Under the module system, definition/theorem bodies are not exported. The
`exportedAxiomsExt` extension records axiom dependencies at `addDecl` time
so that `#print axioms` can report them accurately even when bodies are
no longer available.

We test: private defs, non-exposed defs, theorems, `opaque`, axioms,
and axioms whose types mention other axioms. In every case the output
must match what a non-`module` file would produce.
-/

/-! ## Axiom-free definitions -/

noncomputable def pureDef : Nat := 42

/-- info: '_private.Module.PrintAxioms.0.pureDef' does not depend on any axioms -/
#guard_msgs in
#print axioms pureDef

/-! ## Private definition using `testSorry` (an axiom from Module.Basic) -/

noncomputable def privUsingSorry : Nat := testSorry

/-- info: '_private.Module.PrintAxioms.0.privUsingSorry' depends on axioms: [testSorry] -/
#guard_msgs in
#print axioms privUsingSorry

/-! ## Non-exposed public definition using an axiom -/

public noncomputable def pubUsingSorry : Nat := testSorry

/-- info: 'pubUsingSorry' depends on axioms: [testSorry] -/
#guard_msgs in
#print axioms pubUsingSorry

/-! ## Theorem using an axiom -/

#guard_msgs(drop warning) in
public theorem thmUsingSorry : f = 1 := testSorry

/-- info: 'thmUsingSorry' depends on axioms: [testSorry] -/
#guard_msgs in
#print axioms thmUsingSorry

/-! ## Opaque declaration -/

public opaque opaqueVal : Nat := 42

/-- info: 'opaqueVal' does not depend on any axioms -/
#guard_msgs in
#print axioms opaqueVal

/-! ## Axiom -/

public axiom myAxiom : Nat

/-- info: 'myAxiom' depends on axioms: [myAxiom] -/
#guard_msgs in
#print axioms myAxiom

/-! ## Axiom whose type mentions another axiom -/

public axiom axOfAx : myAxiom = myAxiom

/-- info: 'axOfAx' depends on axioms: [axOfAx, myAxiom] -/
#guard_msgs in
#print axioms axOfAx

/-! ## Definition depending on an axiom through another definition -/

noncomputable def usesPrivUsingSorry : Nat := privUsingSorry + 1

/-- info: '_private.Module.PrintAxioms.0.usesPrivUsingSorry' depends on axioms: [testSorry] -/
#guard_msgs in
#print axioms usesPrivUsingSorry

/-! ## Definition depending on multiple axioms -/

public noncomputable def usesMultiple : Nat := pubUsingSorry + myAxiom

/-- info: 'usesMultiple' depends on axioms: [myAxiom, testSorry] -/
#guard_msgs in
#print axioms usesMultiple

/-! ## Cross-module: check axioms of definitions from Module.Basic -/

-- `testSorry` is an axiom declared in Module.Basic
/-- info: 'testSorry' depends on axioms: [testSorry] -/
#guard_msgs in
#print axioms testSorry

-- `f` is a non-exposed def in Module.Basic, should be axiom-free
/-- info: 'f' does not depend on any axioms -/
#guard_msgs in
#print axioms f

-- `fexp` is an exposed def in Module.Basic, should be axiom-free
/-- info: 'fexp' does not depend on any axioms -/
#guard_msgs in
#print axioms fexp

-- `t` is a theorem in Module.Basic using `testSorry`
/-- info: 't' depends on axioms: [testSorry] -/
#guard_msgs in
#print axioms t

-- `hP1` is an axiom in Module.Basic
/-- info: 'hP1' depends on axioms: [hP1] -/
#guard_msgs in
#print axioms hP1
