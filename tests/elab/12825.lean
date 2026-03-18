module

import all Init.Data.String.Slice

set_option pp.notation false
set_option pp.privateNames true

/--
info: private def String.Slice.dropEndWhile.go.match_1.splitter.{u_1} : (s : String.Slice) →
  (curr : s.Pos) →
    (motive : Option (s.sliceTo curr).Pos → Sort u_1) →
      (x : Option (s.sliceTo curr).Pos) →
        ((nextCurr : (s.sliceTo curr).Pos) → motive (some nextCurr)) →
          ((x : Option (s.sliceTo curr).Pos) →
              (∀ (nextCurr : (s.sliceTo curr).Pos), Eq x (some nextCurr) → False) → motive x) →
            motive x :=
fun s curr motive x h_1 h_2 =>
  _private.Init.Data.String.Slice.0.String.Slice.dropWhile.go._sparseCasesOn_1 x (fun val => h_1 val) fun h => h_2 x ⋯
-/
#guard_msgs in
#print String.Slice.dropEndWhile.go.match_1.splitter

def foo := @String.Slice.dropEndWhile.go.induct

-- After generating the induction principle, the splitter should still reference
-- the same _sparseCasesOn, not create a new one with a different module prefix.
/--
info: private def String.Slice.dropEndWhile.go.match_1.splitter.{u_1} : (s : String.Slice) →
  (curr : s.Pos) →
    (motive : Option (s.sliceTo curr).Pos → Sort u_1) →
      (x : Option (s.sliceTo curr).Pos) →
        ((nextCurr : (s.sliceTo curr).Pos) → motive (some nextCurr)) →
          ((x : Option (s.sliceTo curr).Pos) →
              (∀ (nextCurr : (s.sliceTo curr).Pos), Eq x (some nextCurr) → False) → motive x) →
            motive x :=
fun s curr motive x h_1 h_2 =>
  _private.Init.Data.String.Slice.0.String.Slice.dropWhile.go._sparseCasesOn_1 x (fun val => h_1 val) fun h => h_2 x ⋯
-/
#guard_msgs in
#print String.Slice.dropEndWhile.go.match_1.splitter
