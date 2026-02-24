/-
Copyright (c) 2025 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Init.Data.String
public import Std.Data.HashMap
public import Std.Internal.Http.Internal
public meta import Std.Internal.Http.Internal.String

public section

/-!
# Chunk

This module defines the `Chunk` type, which represents a chunk of data from a request or response.
-/

namespace Std.Http

open Internal

set_option linter.all true

namespace Chunk

/--
A proposition stating that `s` is a valid chunk-extension name: every character in `s` is an
HTTP token character and `s` is non-empty.
-/
abbrev IsValidExtensionName (s : String) : Prop :=
  s.toList.all Char.token ∧ ¬s.isEmpty

/--
A validated chunk extension name that ensures all characters conform to HTTP token standards
per RFC 9110 §5.6.2. Extension names appear in chunked transfer encoding as key-value metadata.
-/
structure ExtensionName where
  /--
  The extension name string.
  -/
  value : String

  /--
  The proof that it's a valid extension name.
  -/
  validExtensionName : IsValidExtensionName value := by decide
deriving Repr, DecidableEq, BEq

namespace ExtensionName

instance : Hashable ExtensionName where
  hash x := Hashable.hash x.value

instance : Inhabited ExtensionName where
  default := ⟨"_", by native_decide⟩

/--
Attempts to create an `ExtensionName` from a `String`, returning `none` if the string contains
invalid characters or is empty.
-/
def ofString? (s : String) : Option ExtensionName :=
  if h : IsValidExtensionName s then
    some ⟨s, h⟩
  else
    none

/--
Creates an `ExtensionName` from a string, panicking with an error message if the string contains
invalid characters or is empty.
-/
def ofString! (s : String) : ExtensionName :=
  if h : IsValidExtensionName s then
    ⟨s, h⟩
  else
    panic! ("invalid extension name: " ++ s.quote)

instance : ToString ExtensionName where
  toString name := name.value

end ExtensionName

/--
A proposition stating that `s` can be encoded as an HTTP `quoted-string`.
-/
abbrev IsValidExtensionValue (s : String) : Prop :=
  (quoteHttpString? s).isSome

/--
A validated chunk extension value that ensures the string can be encoded as an HTTP
`quoted-string` per RFC 9110 §5.6.4. Extension values appear in chunked transfer encoding as
metadata associated with extension names.
-/
structure ExtensionValue where
  /--
  The extension value string.
  -/
  value : String

  /--
  The proof that it's a valid extension value.
  -/
  validExtensionValue : IsValidExtensionValue value := by decide
deriving Repr, DecidableEq, BEq

namespace ExtensionValue

instance : Inhabited ExtensionValue where
  default := ⟨"", by native_decide⟩

/--
Attempts to create an `ExtensionValue` from a `String`, returning `none` if the string contains
characters that cannot be encoded as an HTTP quoted-string.
-/
def ofString? (s : String) : Option ExtensionValue :=
  if h : (quoteHttpString? s).isSome then
    some ⟨s, h⟩
  else
    none

/--
Creates an `ExtensionValue` from a string, panicking with an error message if the string contains
characters that cannot be encoded as an HTTP quoted-string.
-/
def ofString! (s : String) : ExtensionValue :=
  if h : (quoteHttpString? s).isSome then
    ⟨s, h⟩
  else
    panic! ("invalid extension value: " ++ s.quote)

instance : ToString ExtensionValue where
  toString v := v.value

end ExtensionValue

end Chunk

/--
Represents a chunk of data with optional extensions (key-value pairs).
-/
structure Chunk where

  /--
  The byte data contained in this chunk.
  -/
  data : ByteArray

  /--
  Optional metadata associated with this chunk as key-value pairs. Keys are validated
  `Chunk.ExtensionName` values, values are optional strings.
  -/
  extensions : Array (Chunk.ExtensionName × Option Chunk.ExtensionValue) := #[]
deriving Inhabited

namespace Chunk

/--
Quotes an extension value if it contains non-token characters, otherwise returns it as-is.
-/
def quoteExtensionValue (s : ExtensionValue) : String :=
  quoteHttpString? s.value |>.get s.validExtensionValue

/--
An empty chunk with no data and no extensions.
-/
def empty : Chunk :=
  { data := .empty, extensions := #[] }

/--
Creates a simple chunk without extensions.
-/
def ofByteArray (data : ByteArray) : Chunk :=
  { data := data, extensions := #[] }

/--
Adds an extension to a chunk.
-/
def withExtension (chunk : Chunk) (key : Chunk.ExtensionName) (value : ExtensionValue) : Chunk :=
  { chunk with extensions := chunk.extensions.push (key, some value) }

/--
Interprets the chunk data as a UTF-8 encoded string.
-/
def toString? (chunk : Chunk) : Option String :=
  String.fromUTF8? chunk.data

instance : Encode .v11 Chunk where
  encode buffer chunk :=
    let chunkLen := chunk.data.size
    let exts := chunk.extensions.foldl (fun acc (name, value)  =>
      acc ++ ";" ++ name.value.toLower ++ (value.elim "" (fun x => "=" ++ quoteExtensionValue x))) ""
    let size := Nat.toDigits 16 chunkLen |>.toArray |>.map Char.toUInt8 |> ByteArray.mk
    buffer.append #[size, exts.toUTF8, "\r\n".toUTF8, chunk.data, "\r\n".toUTF8]

end Chunk
