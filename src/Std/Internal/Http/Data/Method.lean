/-
Copyright (c) 2025 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Init.Data.ToString
public import Std.Internal.Http.Internal

public section

/-!
# Method

This module provides the `Method` type that represents HTTP request methods. It defines the
standard set of HTTP methods (e.g. `GET`, `POST`, `PUT`, `DELETE`). All methods are limited to
all-uppercase US-ASCII letters.

References:
* https://httpwg.org/specs/rfc9112.html#request.method
* https://httpwg.org/specs/rfc9110.html#method.overview
-/

namespace Std.Http

set_option linter.all true

open Internal

/--
A proposition stating that `s` is a valid HTTP method name: every character is an HTTP token
character, `s` is non-empty, and `s` is not one of the standard method names.

Reference: https://httpwg.org/specs/rfc9110.html#method
-/
abbrev IsValidMethodName (s : String) : Prop :=
  s.toList.all (fun c => Char.token c ∧ Char.isUpper c) ∧
  ¬s.toList.isEmpty

/--
A validated HTTP method name, ensuring all characters conform to the HTTP token specification
per RFC 9110 §9.1. Used to represent custom (non-standard) HTTP methods such as WebDAV's
`PROPFIND` or `LOCK`.

Reference: https://httpwg.org/specs/rfc9110.html#method
-/
structure MethodName where

  /--
  The method name string.
  -/
  value : String

  /--
  The proof that it is a valid HTTP method name.
  -/
  validMethodName : IsValidMethodName value := by decide
deriving Repr, DecidableEq, BEq

instance : Hashable MethodName where
  hash x := Hashable.hash x.value

instance : ToString MethodName where
  toString name := name.value

namespace MethodName

/--
Attempts to create a `MethodName` from a `String`, returning `none` if the string is empty or
contains characters that are not valid HTTP token characters.
-/
def ofString? (s : String) : Option MethodName :=
  if h : IsValidMethodName s then
    some ⟨s, h⟩
  else
    none

instance : Inhabited MethodName where
  default := ⟨"LOCK", by decide⟩

end MethodName

/--
A method is a verb that describes the action to be performed.

* Reference: https://httpwg.org/specs/rfc9110.html#methods
-/
inductive Method where
  /--
  Retrieve a resource.
  -/
  | get

  /--
  Retrieve headers for a resource, without the body.
  -/
  | head

  /--
  Submit data to be processed (e.g., form submission).
  -/
  | post

  /--
  Replace a resource with new data.
  -/
  | put

  /--
  Remove a resource.
  -/
  | delete

  /--
  Establish a tunnel to a server (often for TLS).
  -/
  | connect

  /--
  Describe communication options for a resource.
  -/
  | options

  /--
  Perform a message loop-back test.
  -/
  | trace

  /--
  Apply partial modifications to a resource.
  Source: https://www.rfc-editor.org/rfc/rfc5789.html
  -/
  | patch

  /--
  A custom, non-standard HTTP method (e.g. WebDAV methods like `PROPFIND` or `LOCK`).
  -/
  | custom (name : MethodName)
deriving Repr, Inhabited, BEq, DecidableEq

namespace Method

/--
Converts a `String` into a `Method`.
-/
def ofString? : String → Option Method
  | "GET" => some .get
  | "HEAD" => some .head
  | "POST" => some .post
  | "PUT" => some .put
  | "DELETE" => some .delete
  | "CONNECT" => some .connect
  | "OPTIONS" => some .options
  | "TRACE" => some .trace
  | "PATCH" => some .patch
  | s => (MethodName.ofString? s).map .custom

/--
Converts a `String` into a `Method`, panicking if invalid.
-/
def ofString! (s : String) : Method :=
  match ofString? s with
  | some m => m
  | none => panic! s!"invalid HTTP method: {s.quote}"

instance : ToString Method where
  toString
    | .get => "GET"
    | .head => "HEAD"
    | .post => "POST"
    | .put => "PUT"
    | .delete => "DELETE"
    | .connect => "CONNECT"
    | .options => "OPTIONS"
    | .trace => "TRACE"
    | .patch => "PATCH"
    | .custom name => name.value

instance : Encode .v11 Method where
  encode buffer := buffer.writeString ∘ toString

end Std.Http.Method
