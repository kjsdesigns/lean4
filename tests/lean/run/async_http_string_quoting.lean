import Std.Internal.Http.Internal.StringQuoting

open Std.Http.Internal

private def c (n : Nat) : Char := Char.ofNat n

#guard isQdTextChar (c 0x08) = false
#guard isQdTextChar (c 0x09) = true
#guard isQdTextChar (c 0x0a) = false
#guard isQdTextChar (c 0x1f) = false
#guard isQdTextChar (c 0x20) = true
#guard isQdTextChar (c 0x21) = true
#guard isQdTextChar (c 0x22) = false
#guard isQdTextChar (c 0x23) = true
#guard isQdTextChar (c 0x5b) = true
#guard isQdTextChar (c 0x5c) = false
#guard isQdTextChar (c 0x5d) = true
#guard isQdTextChar (c 0x7e) = true
#guard isQdTextChar (c 0x7f) = false

#guard isQuotedPairChar (c 0x08) = false
#guard isQuotedPairChar (c 0x09) = true
#guard isQuotedPairChar (c 0x1f) = false
#guard isQuotedPairChar (c 0x20) = true
#guard isQuotedPairChar (c 0x21) = true
#guard isQuotedPairChar (c 0x22) = true
#guard isQuotedPairChar (c 0x5c) = true
#guard isQuotedPairChar (c 0x7e) = true
#guard isQuotedPairChar (c 0x7f) = false

#guard isQuotableStringChar (c 0x09) = true
#guard isQuotableStringChar (c 0x20) = true
#guard isQuotableStringChar (c 0x22) = true
#guard isQuotableStringChar (c 0x5c) = true
#guard isQuotableStringChar (c 0x0a) = false
#guard isQuotableStringChar (c 0x0d) = false
#guard isQuotableStringChar (c 0x7f) = false

#guard quoteHttpString? "token" = some "\"token\""
#guard quoteHttpString? "a\t " = some "\"a\t \""
#guard quoteHttpString? "atabpo\n\t " = none
#guard quoteHttpString? "" = some "\"\""
#guard quoteHttpString? "\"" = some "\"\\\"\""
#guard quoteHttpString? "\\" = some "\"\\\\\""
#guard quoteHttpString? "\"\\\"" = some "\"\\\"\\\\\\\"\""
#guard quoteHttpString? "abc\rdef" = none
#guard quoteHttpString? "abc\ndef" = none
#guard quoteHttpString? "abc\u0000def" = none

#guard unquoteHttpString? "\"token\"" = some "token"
#guard unquoteHttpString? "\"a\\\\\\\"b\"" = some "a\\\"b"
#guard unquoteHttpString? "\"line1\nline2\"" = none
#guard unquoteHttpString? "\"\"" = some ""
#guard unquoteHttpString? "\"\\\\\"" = some "\\"
#guard unquoteHttpString? "\"\\\"\"" = some "\""
#guard unquoteHttpString? "\"a\\tb\"" = some "atb"
#guard unquoteHttpString? "\"a\tb\"" = some "a\tb"
#guard unquoteHttpString? "token" = none
#guard unquoteHttpString? "\"" = none
#guard unquoteHttpString? "\"abc" = none
#guard unquoteHttpString? "\"abc\\\"" = none
#guard unquoteHttpString? "\"abc\\\n\"" = none
#guard unquoteHttpString? "\"abc\r\"" = none

#guard isQuotedString "\"abc\"" = true
#guard isQuotedString "\"ab\\\\\\\"c\"" = true
#guard isQuotedString "\"ab\nc\"" = false
#guard isQuotedString "\"\"" = true
#guard isQuotedString "\"\\\"\"" = true
#guard isQuotedString "\"\\\\\"" = true
#guard isQuotedString "abc" = false
#guard isQuotedString "\"" = false
#guard isQuotedString "\"abc" = false
#guard isQuotedString "\"abc\\\"" = false

#guard unquoteHttpString? (quoteHttpString! "abc\t ") = some "abc\t "
#guard unquoteHttpString? (quoteHttpString! "a\\\"b") = some "a\\\"b"
#guard unquoteHttpString? (quoteHttpString! "") = some ""
#guard unquoteHttpString? (quoteHttpString! "\"") = some "\""
#guard unquoteHttpString? (quoteHttpString! "\\") = some "\\"
#guard unquoteHttpString? (quoteHttpString! " !#$%&'()*+,-./:;<=>?@[\\]^_`{|}~") = some " !#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

private def singleCharRoundTrip (ch : Char) : Bool :=
  let s := String.singleton ch
  let quotable := isQuotableStringChar ch
  match quoteHttpString? s with
  | some q =>
      quotable &&
      isQuotedString q &&
      (unquoteHttpString? q == some s)
  | none =>
      !quotable

private def allAsciiSingleCharRoundTrips : Bool :=
  (List.range 128).all (fun n => singleCharRoundTrip (c n))

#guard allAsciiSingleCharRoundTrips = true
