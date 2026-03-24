-- Test that grind can solve equations over Fin 2 using PowCharIdentity
-- The PowCharIdentity instance for Fin 2 gives x^2 = x, which the ring solver
-- uses to reduce high-degree polynomials.

example (x y : Fin 2) : (x + y)^2 = x + y := by grind
example (x : Fin 2) : x^2 = x := by grind
example (x y : Fin 2) : x^2 + y^2 = x + y := by grind
example (x y : Fin 2) : x * y + x * y = 0 := by grind
example (x y : Fin 2) : (x + y)^2 = x^2 + y^2 := by grind

-- High-degree examples that are reduced by PowCharIdentity
-- Note: x^128 does not yet work because the ToInt module expands it
-- before the ring solver can reduce it. See #12842.
example (x : Fin 2) : x^4 = x := by grind
example (x : Fin 2) : x^8 = x := by grind
