/-
Copyright (c) 2025 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Init.Data.String

public section

/-!
# Internal Quoting Helpers

Shared string-quoting utilities for HTTP encoding paths such as header parameter values and chunk
extensions.
-/

namespace Std.Http.Internal

set_option linter.all true

/--
Returns `true` when `c` matches HTTP `qdtext`:
`HTAB / SP / %x21 / %x23-5B / %x5D-7E / obs-text`.
-/
@[inline]
def isQdTextChar (c : Char) : Bool :=
  c.toNat < 128 && Nat.testBit 0x7fffffffeffffffffffffffb00000200 c.toNat

/--
Returns `true` when `c` matches HTTP `quoted-pair` payload:
`HTAB / SP / VCHAR / obs-text`.
-/
@[inline]
def isQuotedPairChar (c : Char) : Bool :=
  c.toNat < 128 && Nat.testBit 0x7fffffffffffffffffffffff00000200 c.toNat

/--
Returns `true` when `c` can appear in an HTTP `quoted-string` body, either directly as `qdtext`
or as an escaped `quoted-pair`.
-/
@[inline]
def isQuotableStringChar (c : Char) : Bool :=
  c.toNat < 128 && Nat.testBit 0x7fffffffffffffffffffffff00000200 c.toNat

/--
Core character quoting used by `String.quote`.

In string context (`inString := true`), this emits:
- `qdtext` characters directly
- `"` and `\\` as `quoted-pair`
and panics for characters outside the grammar.
-/
def quoteCore (c : Char) (inString : Bool := false) : String :=
  if inString then
    if isQdTextChar c then
      String.singleton c
    else if c = '\\' || c = '\"' then
      String.Internal.append "\\" (String.singleton c)
    else
      panic! "invalid HTTP quoted-string content"
  else
    if isQuotedPairChar c then
      String.singleton c
    else
      panic! "invalid HTTP quoted-pair content"

/--
Attempts to quote `s` as an HTTP `quoted-string`:
`DQUOTE *( qdtext / quoted-pair ) DQUOTE`.

Returns `none` when any character in `s` cannot be represented by the grammar.
-/
def quoteHttpString? (s : String) : Option String :=
  if s.toList.all isQuotableStringChar then
    some <|
      if String.Internal.isEmpty s then "\"\""
      else
        String.Internal.append
          (String.Internal.foldl
            (fun acc c =>
              String.Internal.append acc (quoteCore c (inString := true)))
            "\""
            s)
          "\""
  else
    none

/--
Quotes `s` as an HTTP `quoted-string`, panicking if `s` contains characters that cannot be
represented by `qdtext`/`quoted-pair`.
-/
def quoteHttpString! (s : String) : String :=
  match quoteHttpString? s with
  | some res => res
  | none => panic! "invalid "

/--
Returns `s` unchanged if every character satisfies `isTokenCharacter`; otherwise returns `s`
encoded as an HTTP `quoted-string`.
-/
@[inline]
def quoteTokenOrString (isTokenCharacter : Char → Bool) (s : String) : String :=
  if s.any (fun c => !isTokenCharacter c) then
    quoteHttpString! s
  else
    s

/--
Checks whether `s` is a syntactically valid HTTP `quoted-string`.
-/
def isQuotedString (s : String) : Bool :=
  match s.toList with
  | '"' :: rest =>
      let rec go (escaped : Bool) : List Char → Bool
        | [] => false
        | [c] =>
            if escaped then
              false
            else
              c = '"'
        | c :: cs =>
            if escaped then
              if isQuotedPairChar c then go false cs else false
            else if c = '\\' then
              go true cs
            else if isQdTextChar c then
              go false cs
            else
              false
      go false rest
  | _ => false

/--
Parses an HTTP `quoted-string`, returning the unescaped content when valid.
-/
def unquoteHttpString? (s : String) : Option String :=
  match s.toList with
  | '"' :: rest =>
      let rec go (escaped : Bool) (acc : String) : List Char → Option String
        | [] => none
        | [c] =>
            if escaped then
              none
            else if c = '"' then
              some acc
            else
              none
        | c :: cs =>
            if escaped then
              if isQuotedPairChar c then
                go false (acc.push c) cs
              else
                none
            else if c = '\\' then
              go true acc cs
            else if isQdTextChar c then
              go false (acc.push c) cs
            else
              none
      go false "" rest
  | _ => none

end Std.Http.Internal
