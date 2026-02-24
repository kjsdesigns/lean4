/-
Copyright (c) 2025 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
import Init.Grind
public import Init.Data.String
public import Std.Internal.Http.Internal.Char

public section


/-!
# Internal Quoting Helpers

Shared string-quoting utilities for HTTP encoding paths such as header parameter values and chunk
extensions.
-/

namespace Std.Http.Internal

set_option linter.all true

/--
Core character quoting used by `String.quote`.

In string context (`inString := true`), this emits:
- `qdtext` characters directly
- `"` and `\\` as `quoted-pair`
and panics for characters outside the grammar.
-/
def quoteCore (c : Char) (inString : Bool := false) : String :=
  if inString then
    if Std.Http.Internal.Char.qdtext c then
      String.singleton c
    else if c = '\\' || c = '\"' then
      String.Internal.append "\\" (String.singleton c)
    else
      panic! "invalid HTTP quoted-string content"
  else
    if Std.Http.Internal.Char.quotedPairChar c then
      String.singleton c
    else
      panic! "invalid HTTP quoted-pair content"

/--
Attempts to quote `s` as an HTTP `quoted-string`:
`DQUOTE *( qdtext / quoted-pair ) DQUOTE`.

Returns `none` when any character in `s` cannot be represented by the grammar.
-/
@[expose]
def quoteHttpString? (s : String) : Option String :=
  if s.all Std.Http.Internal.Char.quotedStringChar then
    some (String.Internal.append
      (String.Internal.foldl (fun acc c =>
        String.Internal.append acc (quoteCore c (inString := true))) "\"" s)
      "\"")
  else
    none

/--
Quotes `s` as an HTTP `quoted-string`, panicking if `s` contains characters that cannot be
represented by `qdtext`/`quoted-pair`.
-/
def quoteHttpString! (s : String) : String :=
  match quoteHttpString? s with
  | some res => res
  | none => panic! "invalid HTTP quoted-string content"

private inductive UnquoteState where
  | start
  | valid (escaped : Bool) (acc : String)
  | done (result : String)
  | invalid

/--
Parses an HTTP `quoted-string`, returning the unescaped content when valid.
-/
def unquoteHttpString? (s : String) : Option String :=
  if s.startsWith '"' then
    match s.foldl (fun (st : UnquoteState) c =>
      match st with
      | .start =>
          if c == '"' then .valid false "" else .invalid
      | .valid false acc =>
          if c == '\\' then .valid true acc
          else if c == '"' then .done acc
          else if Std.Http.Internal.Char.qdtext c then .valid false (acc.push c)
          else .invalid
      | .valid true acc =>
          if Std.Http.Internal.Char.quotedPairChar c then .valid false (acc.push c)
          else .invalid
      | .done _ | .invalid => .invalid) .start with
    | .done result => some result
    | _ => none
  else if s.all Char.token then
    some s
  else
    none

end Std.Http.Internal
