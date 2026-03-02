/-
Copyright (c) 2025 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Init.Data.String

@[expose]
public section

/-!
# HTTP Character Predicates

This module provides shared character validation predicates used across the HTTP library.
All predicates in this module are ASCII-only by design (`isAscii c` where applicable), and
intentionally exclude `obs-text` and all non-ASCII code points.
-/

namespace Std.Http.Internal.Char

set_option linter.all true

/--
Checks if a character is ASCII (Unicode code point < 128).
-/
@[expose]
def isAscii (c : Char) : Bool :=
  c.toNat < 128

/--
Checks if a character is a decimal digit (0-9).
-/
@[inline, expose]
def isDigitChar (c : Char) : Bool :=
  c ≥ '0' ∧ c ≤ '9'

/--
Checks if a character is an alphabetic character (a-z or A-Z).
-/
@[inline, expose]
def isAlphaChar (c : Char) : Bool :=
  (c ≥ 'A' ∧ c ≤ 'Z') ∨ (c ≥ 'a' ∧ c ≤ 'z')

/--
Checks if a byte represents an ASCII character (value < 128).
-/
@[expose]
def isAsciiByte (c : UInt8) : Bool :=
  c < 128

/--
Checks if a byte is a decimal digit (0-9).
-/
@[inline, expose]
def isDigit (c : UInt8) : Bool :=
  c >= '0'.toUInt8 && c <= '9'.toUInt8

/--
Checks if a byte is an alphabetic character (a-z or A-Z).
-/
@[inline, expose]
def isAlpha (c : UInt8) : Bool :=
  (c >= 'A'.toUInt8 && c <= 'Z'.toUInt8) || (c >= 'a'.toUInt8 && c <= 'z'.toUInt8)

/--
Two character predicates are equivalent on ASCII input (`0x00`-`0x7F`).
-/
abbrev EqOnAscii (x : Char → Bool) (y : Char → Bool) : Prop :=
  ∀ n < 128, x (Char.ofNat n) ↔ y (Char.ofNat n)

/--
tchar = "!" / "#" / "$" / "%" / "&" / "'" / "*"
  / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~"
  / DIGIT / ALPHA
  ; Visible token characters used to build `token`.
-/
def tchar (c : Char) : Bool :=
  "!#$%&'*+-.^_`|~".toList.contains c
  ∨ isDigitChar c
  ∨ isAlphaChar c

/--
Checks if a character is a valid HTTP token character per RFC 9110 §5.6.2.

token = 1*tchar
-/
def token (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x57ffffffc7fffffe03ff6cfa00000000 c.toNat

theorem token_eq_tchar_on_ascii : EqOnAscii token tchar := by
  decide

/--
vchar = %x21-7E
; Visible (printing) ASCII characters.
-/
def vcharSpec (c : Char) : Bool :=
  c ≥ '!' ∧ c ≤ '~'

/--
Checks if `c` is a visible (printing) ASCII character.
-/
def vchar (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x7ffffffffffffffffffffffe00000000 c.toNat

theorem vchar_eq_vcharSpec_on_ascii : EqOnAscii vchar vcharSpec := by
  decide

/--
qdtext = HTAB / SP / %x21 / %x23-5B / %x5D-7E
; ASCII-only variant (no obs-text).
-/
def qdtextSpec (c : Char) : Bool :=
  c = '\t' ∨
  c = ' ' ∨
  c = '!' ∨
  ('#' ≤ c ∧ c ≤ '[') ∨
  (']' ≤ c ∧ c ≤ '~')

/--
Checks if `c` is valid `qdtext` in an HTTP `quoted-string` (ASCII-only).
-/
def qdtext (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x7fffffffeffffffffffffffb00000200 c.toNat

theorem qdtext_eq_qdtextSpec_on_ascii : EqOnAscii qdtext qdtextSpec := by
  decide

/--
quoted-pair = "\" ( HTAB / SP / VCHAR )
; ASCII-only variant (no obs-text).
-/
def quotedPairCharSpec (c : Char) : Bool :=
  c = '\t' ∨ c = ' ' ∨ vchar c

/--
Checks if `c` is valid after `\` in an HTTP `quoted-pair` (ASCII-only).
-/
def quotedPairChar (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x7fffffffffffffffffffffff00000200 c.toNat

theorem quotedPairChar_eq_quotedPairCharSpec_on_ascii :
    EqOnAscii quotedPairChar quotedPairCharSpec := by
  decide

/--
quoted-string body character class:
( qdtext / quoted-pair payload ) in ASCII-only mode.
-/
def quotedStringCharSpec (c : Char) : Bool :=
  qdtext c ∨ quotedPairChar c

/--
Returns `true` when `c` can be represented inside an HTTP `quoted-string` body:
either directly as `qdtext` or via `quoted-pair`.
-/
def quotedStringChar (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x7fffffffffffffffffffffff00000200 c.toNat

theorem quotedStringChar_eq_quotedStringCharSpec_on_ascii :
    EqOnAscii quotedStringChar quotedStringCharSpec := by
  decide

/--
field-vchar = VCHAR
; ASCII-only variant (no obs-text).
-/
def fieldVcharSpec (c : Char) : Bool :=
  vchar c

/--
Checks if `c` is valid `field-vchar` in ASCII-only mode.
-/
def fieldVchar (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x7ffffffffffffffffffffffe00000000 c.toNat

theorem fieldVchar_eq_fieldVcharSpec_on_ascii : EqOnAscii fieldVchar fieldVcharSpec := by
  decide

/--
field-content character class:
field-vchar / SP / HTAB
; ASCII-only variant (no obs-text).
-/
def fieldContentSpec (c : Char) : Bool :=
  fieldVchar c ∨ c = ' ' ∨ c = '\t'

/--
Checks if `c` is valid in the body of an HTTP `field-content` (ASCII-only).
-/
def fieldContent (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x7fffffffffffffffffffffff00000200 c.toNat

theorem fieldContent_eq_fieldContentSpec_on_ascii : EqOnAscii fieldContent fieldContentSpec := by
  decide

/--
ctext = HTAB / SP / %x21-27 / %x2A-5B / %x5D-7E
; ASCII-only variant (no obs-text).
-/
def ctextSpec (c : Char) : Bool :=
  c = '\t' ∨
  c = ' ' ∨
  ('!' ≤ c ∧ c ≤ '\'') ∨
  ('*' ≤ c ∧ c ≤ '[') ∨
  (']' ≤ c ∧ c ≤ '~')

/--
Checks if `c` is valid `ctext` in an HTTP comment (ASCII-only).
-/
def ctext (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x7fffffffeffffffffffffcff00000200 c.toNat

theorem ctext_eq_ctextSpec_on_ascii : EqOnAscii ctext ctextSpec := by
  decide

/--
etagc = "!" / %x23-7E
; ASCII-only variant (no obs-text).
-/
def etagcSpec (c : Char) : Bool :=
  c = '!' ∨ ('#' ≤ c ∧ c ≤ '~')

/--
Checks if `c` is valid `etagc` inside an `opaque-tag` (ASCII-only).
-/
def etagc (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x7ffffffffffffffffffffffa00000000 c.toNat

theorem etagc_eq_etagcSpec_on_ascii : EqOnAscii etagc etagcSpec := by
  decide

/--
OWS = *( SP / HTAB )  (character class only)
-/
def ows (c : Char) : Bool :=
  c = ' ' ∨ c = '\t'

/--
BWS = OWS (character class alias)
-/
def bws (c : Char) : Bool :=
  ows c

/--
RWS = 1*( SP / HTAB ) (character class is identical to `ows`)
-/
def rws (c : Char) : Bool :=
  ows c

/--
obs-text = %x80-FF (and higher Unicode scalar values in this library's `Char` model).
-/
def obsText (c : Char) : Bool :=
  0x80 ≤ c.toNat

/--
reason-phrase character class:
HTAB / SP / VCHAR
; ASCII-only variant (no obs-text).

Reference: https://httpwg.org/specs/rfc9110.html#reason.phrase
-/
def reasonPhraseCharSpec (c : Char) : Bool :=
  c = '\t' ∨ c = ' ' ∨ vchar c

/--
Checks if `c` is valid inside an HTTP `reason-phrase` per RFC 9110 §15.
-/
def reasonPhraseChar (c : Char) : Bool :=
  isAscii c ∧ Nat.testBit 0x7fffffffffffffffffffffff00000200 c.toNat

theorem reasonPhraseChar_eq_reasonPhraseCharSpec : EqOnAscii reasonPhraseChar reasonPhraseCharSpec := by
  decide

def isHexDigitSpec (c : Char) : Bool :=
  (c ≥ '0' && c ≤ '9') ||
  (c ≥ 'a' && c ≤ 'f') ||
  (c ≥ 'A' && c ≤ 'F')

/--
Checks if a byte is a hexadecimal digit (0-9, a-f, or A-F) using a precomputed bitmask.
-/
@[expose]
def isHexDigit (c : Char) : Bool :=
  Nat.testBit 0x0000007e0000007e03ff000000000000 c.toNat

theorem isHexDigit_eq_isHexDigitSpec_on_ascii : EqOnAscii isHexDigit isHexDigitSpec := by
  decide

/--
Checks if a byte is a hexadecimal digit (0-9, a-f, or A-F).
-/
def isHexDigitByte (c : UInt8) : Bool :=
  (c ≥ '0'.toUInt8 && c ≤ '9'.toUInt8) ||
  (c ≥ 'a'.toUInt8 && c ≤ 'f'.toUInt8) ||
  (c ≥ 'A'.toUInt8 && c ≤ 'F'.toUInt8)

/--
Checks if a byte is an alphanumeric digit (0-9, a-z, or A-Z).
-/
@[expose]
def isAlphaNum (c : UInt8) : Bool :=
  (c ≥ '0'.toUInt8 ∧ c ≤ '9'.toUInt8) ∨
  (c ≥ 'a'.toUInt8 ∧ c ≤ 'z'.toUInt8) ∨
  (c ≥ 'A'.toUInt8 ∧ c ≤ 'Z'.toUInt8)

/--
Checks if a byte is an unreserved character according to RFC 3986. Unreserved characters are:
alphanumeric, hyphen, period, underscore, and tilde.
-/
@[expose]
def isUnreserved (c : UInt8) : Bool :=
  isAlphaNum c ∨
  (c = '-'.toUInt8 ∨ c = '.'.toUInt8 ∨ c = '_'.toUInt8 ∨ c = '~'.toUInt8)

/--
Checks if a byte is a sub-delimiter character according to RFC 3986.
Sub-delimiters are: `!`, `$`, `&`, `'`, `(`, `)`, `*`, `+`, `,`, `;`, `=`.
-/
@[expose]
def isSubDelims (c : UInt8) : Bool :=
  c = '!'.toUInt8 ∨ c = '$'.toUInt8 ∨ c = '&'.toUInt8 ∨ c = '\''.toUInt8 ∨
  c = '('.toUInt8 ∨ c = ')'.toUInt8 ∨ c = '*'.toUInt8 ∨ c = '+'.toUInt8 ∨
  c = ','.toUInt8 ∨ c = ';'.toUInt8 ∨ c = '='.toUInt8

/--
Checks if a byte is a valid path character (`pchar`) according to RFC 3986.
`pchar = unreserved / pct-encoded / sub-delims / ":" / "@"`

Note: The percent-encoding (`pct-encoded`) is handled separately by `isEncodedChar`,
so this predicate only covers the non-percent characters.
-/
@[expose]
def isPChar (c : UInt8) : Bool :=
  isUnreserved c ∨ isSubDelims c ∨ c = ':'.toUInt8 ∨ c = '@'.toUInt8

/--
Checks if a byte is a valid character in a URI query component according to RFC 3986.
`query = *( pchar / "/" / "?" )`
-/
@[expose]
def isQueryChar (c : UInt8) : Bool :=
  isPChar c ∨ c = '/'.toUInt8 ∨ c = '?'.toUInt8

/--
Checks if a byte is a valid character in a URI fragment component according to RFC 3986.
`fragment = *( pchar / "/" / "?" )`
-/
@[expose]
def isFragmentChar (c : UInt8) : Bool :=
  isPChar c ∨ c = '/'.toUInt8 ∨ c = '?'.toUInt8

/--
Checks if a byte is a valid character in a URI userinfo component according to RFC 3986.
`userinfo = *( unreserved / pct-encoded / sub-delims / ":" )`
-/
@[expose]
def isUserInfoChar (c : UInt8) : Bool :=
  isUnreserved c ∨ isSubDelims c ∨ c = ':'.toUInt8

end Std.Http.Internal.Char
