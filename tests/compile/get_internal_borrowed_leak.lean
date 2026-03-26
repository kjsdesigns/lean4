module

@[noinline]
def test (n w : Nat) (x : Array (Vector String (w +1))) :=
  let value := x[n]!
  value[0]

public def main : IO Unit := do
  let mut acc := 0
  for i in 0...(100 : Nat) do
    acc := acc + (test 0 i #[]).length
  IO.println acc
