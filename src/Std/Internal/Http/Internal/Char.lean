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
def isAscii (ch : Char) : Bool :=
  ch.toNat < 128

/--
Checks if a byte represents an ASCII character (value < 128).
-/
@[expose]
def isAsciiByte (ch : Char) : Bool :=
  isAscii ch

/--
tchar = "!" / "#" / "$" / "%" / "&" / "'" / "*"
  / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~"
  / DIGIT / ALPHA
  ; Visible token characters used to build `token`.
-/
def tchar (ch : Char) : Bool :=
  ch matches '!' | '#' | '$' | '%' | '&' | '\'' | '*' |
    '+' | '-' | '.' | '^' | '_' | '`' | '|' | '~' ||
    Char.isDigit ch || Char.isAlpha ch

/--
Checks if a character is a valid HTTP token character per RFC 9110 §5.6.2.

token = 1*tchar
-/
def token (ch : Char) : Bool :=
  ch matches '!' | '#' | '$' | '%' | '&' | '\'' | '*' |
    '+' | '-' | '.' | '^' | '_' | '`' | '|' | '~' ||
    Char.isDigit ch || Char.isAlpha ch

/--
vchar = %x21-7E
; Visible (printing) ASCII characters.
-/
def vchar (ch : Char) : Bool :=
  ch ≥ '!' && ch ≤ '~'

/--
qdtext = HTAB / SP / %x21 / %x23-5B / %x5D-7E
; ASCII-only variant (no obs-text).
-/
def qdtext (ch : Char) : Bool :=
  ch matches '\t' | ' ' | '!' ||
    ('#' ≤ ch && ch ≤ '[') ||
    (']' ≤ ch && ch ≤ '~')

/--
quoted-pair = "\" ( HTAB / SP / VCHAR )
; ASCII-only variant (no obs-text).
-/
def quotedPairChar (ch : Char) : Bool :=
  ch matches '\t' | ' ' || vchar ch

/--
quoted-string body character class:
( qdtext / quoted-pair payload ) in ASCII-only mode.
-/
def quotedStringChar (ch : Char) : Bool :=
  qdtext ch || quotedPairChar ch

/--
field-vchar = VCHAR
; ASCII-only variant (no obs-text).
-/
def fieldVchar (ch : Char) : Bool :=
  vchar ch

/--
field-content character class:
field-vchar / SP / HTAB
; ASCII-only variant (no obs-text).
-/
def fieldContent (ch : Char) : Bool :=
  fieldVchar ch || ch matches ' ' | '\t'

/--
ctext = HTAB / SP / %x21-27 / %x2A-5B / %x5D-7E
; ASCII-only variant (no obs-text).
-/
def ctext (ch : Char) : Bool :=
  ch matches '\t' | ' ' ||
    ('!' ≤ ch && ch ≤ '\'') ||
    ('*' ≤ ch && ch ≤ '[') ||
    (']' ≤ ch && ch ≤ '~')

/--
etagc = "!" / %x23-7E
; ASCII-only variant (no obs-text).
-/
def etagc (ch : Char) : Bool :=
  ch matches '!' || ('#' ≤ ch && ch ≤ '~')

/--
OWS = *( SP / HTAB )  (character class only)
-/
def ows (ch : Char) : Bool :=
  ch matches ' ' | '\t'

/--
BWS = OWS (character class alias)
-/
def bws (ch : Char) : Bool :=
  ows ch

/--
RWS = 1*( SP / HTAB ) (character class is identical to `ows`)
-/
def rws (ch : Char) : Bool :=
  ows ch

/--
obs-text = %x80-FF (and higher Unicode scalar values in this library's `Char` model).
-/
def obsText (ch : Char) : Bool :=
  0x80 ≤ ch.toNat

/--
reason-phrase character class:
HTAB / SP / VCHAR
; ASCII-only variant (no obs-text).

Reference: https://httpwg.org/specs/rfc9110.html#reason.phrase
-/
def reasonPhraseChar (ch : Char) : Bool :=
  ch matches '\t' | ' ' || vchar ch

/--
Checks if a byte is a hexadecimal digit (0-9, a-f, or A-F).
-/
@[expose]
def isHexDigit (ch : Char) : Bool :=
  (ch ≥ '0' && ch ≤ '9') ||
  (ch ≥ 'a' && ch ≤ 'f') ||
  (ch ≥ 'A' && ch ≤ 'F')

/--
Checks if a character is a hexadecimal digit (0-9, a-f, or A-F).
-/
@[expose]
def isHexDigitByte (ch : Char) : Bool :=
  isHexDigit ch

/--
Checks if `c` is an ASCII alphanumeric character.
-/
@[inline, expose]
def isAsciiAlphaNumChar (ch : Char) : Bool :=
  isAscii ch && Char.isAlphanum ch

/--
Checks if a character is valid after the first character of a URI scheme.
Valid characters are ASCII alphanumeric, `+`, `-`, and `.`.
-/
@[expose]
def isValidSchemeChar (ch : Char) : Bool :=
  isAsciiAlphaNumChar ch || ch matches '+' | '-' | '.'

/--
Checks if a character is valid for use in a domain name.
Valid characters are ASCII alphanumeric, hyphens, and dots.
-/
@[expose]
def isValidDomainNameChar (ch : Char) : Bool :=
  isAsciiAlphaNumChar ch || ch matches '-' | '.'

/--
Checks if a character is an unreserved character according to RFC 3986. Unreserved characters are:
alphanumeric, hyphen, period, underscore, and tilde.
-/
@[expose]
def isUnreserved (ch : Char) : Bool :=
  Char.isAlphanum ch || ch matches '-' | '.' | '_' | '~'


/--
Checks if a character is a sub-delimiter character according to RFC 3986.
Sub-delimiters are: `!`, `$`, `&`, `'`, `(`, `)`, `*`, `+`, `,`, `;`, `=`.
-/
@[expose]
def isSubDelims (ch : Char) : Bool :=
  ch matches '!' | '$' | '&' | '\'' | '(' | ')' | '*' | '+' | ',' | ';' | '='

/--
Checks if a character is a valid path character (`pchar`) according to RFC 3986.
`pchar = unreserved / pct-encoded / sub-delims / ":" / "@"`

Note: The percent-encoding (`pct-encoded`) is handled separately by `isEncodedChar`,
so this predicate only covers the non-percent characters.
-/
@[expose]
def isPChar (ch : Char) : Bool :=
  isUnreserved ch || isSubDelims ch || ch matches ':' | '@'


/--
Checks if a character is a valid character in a URI query component according to RFC 3986.
`query = *( pchar / "/" / "?" )`
-/
@[expose]
def isQueryChar (ch : Char) : Bool :=
  isPChar ch || ch matches '/' | '?'


/--
Checks if a character is a valid character in a URI fragment component according to RFC 3986.
`fragment = *( pchar / "/" / "?" )`
-/
@[expose]
def isFragmentChar (ch : Char) : Bool :=
  isPChar ch || ch matches '/' | '?'

/--
Checks if a character is a valid character in a URI userinfo component according to RFC 3986.
`userinfo = *( unreserved/ sub-delims / ":" )`

Note: It avoids the pct-encoded of the original grammar because it is used with `Encoding.lean`
that provides it.
-/
@[expose]
def isUserInfoChar (ch : Char) : Bool :=
  isUnreserved ch || isSubDelims ch || ch matches ':'

end Std.Http.Internal.Char
