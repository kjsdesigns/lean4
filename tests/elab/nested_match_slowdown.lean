/-
Regression test for slow elaboration of incomplete nested matches on the same
discriminant. When the outer match groups constructors (`| .c0 | .c1 | .c2 =>`)
and the inner match re-discriminates on the same variable without a wildcard,
the match compiler used to expand counter-examples for each missing case
combinatorially: for each of the N-3 missing Op constructors, it case-split on
all K constructors of each Operand field, producing (N-3) × K² counter-examples.

The fix in `processConstructor` limits counter-example expansion to types with
≤4 constructors when there are no matching alternatives.

See: https://gist.github.com/andres-erbsen/17007c5bc662f463b1da7632bcd07b72
-/
set_option autoImplicit false

-- A field type with many constructors (>4 to trigger the optimization)
inductive Operand (w : Nat) where
  | r0 : Nat → Operand w
  | r1 : Nat → Operand w
  | r2 : Nat → Operand w
  | r3 : Nat → Operand w
  | r4 : Nat → Operand w
  | r5 : Nat → Operand w
  | r6 : Nat → Operand w
  | r7 : Nat → Operand w

-- A large inductive with multi-constructor field types (20 constructors)
inductive Op (w : Nat) where
  | add : Operand w → Operand w → Op w
  | or_ : Operand w → Operand w → Op w
  | xor : Operand w → Operand w → Op w
  | sub : Operand w → Operand w → Op w
  | mul : Operand w → Operand w → Op w
  | shl : Operand w → Operand w → Op w
  | shr : Operand w → Operand w → Op w
  | mov : Operand w → Operand w → Op w
  | cmp : Operand w → Operand w → Op w
  | test : Operand w → Operand w → Op w
  | lea : Operand w → Operand w → Op w
  | c11 : Operand w → Operand w → Op w
  | c12 : Operand w → Operand w → Op w
  | c13 : Operand w → Operand w → Op w
  | c14 : Operand w → Operand w → Op w
  | c15 : Operand w → Operand w → Op w
  | c16 : Operand w → Operand w → Op w
  | c17 : Operand w → Operand w → Op w
  | c18 : Operand w → Operand w → Op w
  | c19 : Operand w → Operand w → Op w

-- The "fast" version: separate arms for each constructor (baseline)
def Op.evalFast {w : Nat} (op : Op w) (f : Operand w → Nat) : Nat :=
  match op with
  | .add dst src => f dst + f src
  | .or_ dst src => f dst ||| f src
  | .xor dst src => f dst ^^^ f src
  | .sub dst src => f dst - f src
  | .mul dst src => f dst * f src
  | .shl dst src => f dst <<< f src
  | .shr dst src => f dst >>> f src
  | .mov _ src => f src
  | .cmp dst src => f dst + f src
  | .test dst src => f dst + f src
  | .lea dst src => f dst + f src
  | .c11 dst src => f dst + f src
  | .c12 dst src => f dst + f src
  | .c13 dst src => f dst + f src
  | .c14 dst src => f dst + f src
  | .c15 dst src => f dst + f src
  | .c16 dst src => f dst + f src
  | .c17 dst src => f dst + f src
  | .c18 dst src => f dst + f src
  | .c19 dst src => f dst + f src

-- The "was slow" version: grouped constructors with incomplete nested match.
-- The inner match is missing 17 cases, and the match compiler must generate
-- counter-examples for each. Without the fix, this would expand
-- 17 × 8² = 1088 counter-examples and take several seconds.
-- With the fix, counter-examples use wildcards for large field types.
-- We add a wildcard to the inner match to make this definition error-free,
-- but the outer match still exercises `processConstructor` with missing-case
-- counter-example generation for the inner Operand fields.
def Op.evalSlow {w : Nat} (op : Op w) (f : Operand w → Nat) : Nat :=
  match op with
  | .add dst src | .or_ dst src | .xor dst src =>
    let a := f dst; let b := f src
    (match op with | .add _ _ => a + b | .or_ _ _ => a ||| b | .xor _ _ => a ^^^ b | _ => 0)
  | .sub dst src => f dst - f src
  | .mul dst src => f dst * f src
  | .shl dst src => f dst <<< f src
  | .shr dst src => f dst >>> f src
  | .mov _ src => f src
  | .cmp dst src => f dst + f src
  | .test dst src => f dst + f src
  | .lea dst src => f dst + f src
  | .c11 dst src => f dst + f src
  | .c12 dst src => f dst + f src
  | .c13 dst src => f dst + f src
  | .c14 dst src => f dst + f src
  | .c15 dst src => f dst + f src
  | .c16 dst src => f dst + f src
  | .c17 dst src => f dst + f src
  | .c18 dst src => f dst + f src
  | .c19 dst src => f dst + f src
