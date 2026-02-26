import Std.Internal.Http
import Std.Internal.Async

open Std.Internal.IO Async
open Std Http

abbrev TestHandler := Request Body.Incoming → ContextAsync (Response Body.AnyBody)

instance : Std.Http.Server.Handler TestHandler where
  onRequest handler request := handler request

instance : Coe (ContextAsync (Response Body.Incoming)) (ContextAsync (Response Body.AnyBody)) where
  coe action := do
    let response ← action
    pure { response with body := Body.Internal.incomingToOutgoing response.body }

instance : Coe (Async (Response Body.Incoming)) (ContextAsync (Response Body.AnyBody)) where
  coe action := do
    let response ← action
    pure { response with body := Body.Internal.incomingToOutgoing response.body }


def sendRaw
    (client : Mock.Client)
    (server : Mock.Server)
    (raw : ByteArray)
    (handler : TestHandler)
    (config : Config := { lingeringTimeout := 1000, generateDate := false }) : IO ByteArray := Async.block do
  client.send raw
  Std.Http.Server.serveConnection server handler config
    |>.run
  let res ← client.recv?
  pure <| res.getD .empty


def assertStatus (name : String) (response : ByteArray) (status : String) : IO Unit := do
  let text := String.fromUTF8! response
  unless text.startsWith status do
    throw <| IO.userError s!"Test '{name}' failed:\nExpected {status}\nGot:\n{text.quote}"


def assertExact (name : String) (response : ByteArray) (expected : String) : IO Unit := do
  let text := String.fromUTF8! response
  if text != expected then
    throw <| IO.userError s!"Test '{name}' failed:\nExpected:\n{expected.quote}\nGot:\n{text.quote}"


def assertContains (name : String) (response : ByteArray) (needle : String) : IO Unit := do
  let text := String.fromUTF8! response
  unless text.contains needle do
    throw <| IO.userError s!"Test '{name}' failed:\nMissing {needle.quote}\nGot:\n{text.quote}"


def echoHandler : TestHandler :=
  fun req => do
    let body : String ← req.body.readAll
    Response.ok |>.text body

def okHandler : TestHandler :=
  fun _ => Response.ok |>.text "ok"

def bad400 : String :=
  "HTTP/1.1 400 Bad Request\x0d\nServer: LeanHTTP/1.1\x0d\nConnection: close\x0d\nContent-Length: 0\x0d\n\x0d\n"

def bad501 : String :=
  "HTTP/1.1 501 Not Implemented\x0d\nServer: LeanHTTP/1.1\x0d\nConnection: close\x0d\nContent-Length: 0\x0d\n\x0d\n"

-- Baseline: normal chunked request is accepted and body is delivered.
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertStatus "TE: chunked baseline" response "HTTP/1.1 200"
  assertContains "TE: chunked body delivered" response "hello"


-- TE: gzip alone (chunked not last) → 501 unsupported transfer encoding.
-- The server can only frame bodies with chunked; an unknown-only coding has no supported framing.
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: gzip\x0d\nConnection: close\x0d\n\x0d\nbody".toUTF8
  let response ← sendRaw client server raw okHandler
  assertExact "TE: gzip alone → 501" response bad501


-- TE: deflate alone → 501 (chunked not last).
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: deflate\x0d\nConnection: close\x0d\n\x0d\nbody".toUTF8
  let response ← sendRaw client server raw okHandler
  assertExact "TE: deflate alone → 501" response bad501


-- TE: identity alone → 501 (chunked not last).
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: identity\x0d\nConnection: close\x0d\n\x0d\nbody".toUTF8
  let response ← sendRaw client server raw okHandler
  assertExact "TE: identity alone → 501" response bad501


-- TE: chunked, gzip → 400. Chunked is not last; Validate rejects this.
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked, gzip\x0d\nConnection: close\x0d\n\x0d\nbody".toUTF8
  let response ← sendRaw client server raw okHandler
  assertExact "TE: chunked not last → 400" response bad400


-- TE: gzip, chunked → 200. Unknown coding before chunked is accepted; body is framed as chunked.
-- The server reads the raw chunked bytes without applying the gzip layer.
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: gzip, chunked\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertStatus "TE: gzip, chunked → 200" response "HTTP/1.1 200"
  assertContains "TE: gzip, chunked body delivered" response "hello"


-- TE: br, chunked → 200. Same as above with a different preceding coding.
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: br, chunked\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertStatus "TE: br, chunked → 200" response "HTTP/1.1 200"


-- TE + Content-Length → 400 (request smuggling prevention, RFC 9112 §6.1).
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nContent-Length: 5\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw okHandler
  assertExact "TE + Content-Length → 400 (smuggling)" response bad400


-- TE: chunked, chunked → 400 (duplicate chunked, Validate rejects).
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked, chunked\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw okHandler
  assertExact "TE: chunked, chunked → 400" response bad400


-- Mixed case: Chunked (capital C) is accepted (codings are lowercased when parsed).
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: Chunked\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertStatus "TE: Chunked (mixed case) → 200" response "HTTP/1.1 200"
  assertContains "TE: Chunked body delivered" response "hello"


-- NUL byte inside TE value → 400 (non-token character).
#eval show IO _ from do
  let (client, server) ← Mock.new
  let before := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunk".toUTF8
  let after := "ed\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server (before ++ ByteArray.mk #[0x00] ++ after) okHandler
  assertExact "NUL in TE value → 400" response bad400


-- Control character (0x01) inside TE value → 400.
#eval show IO _ from do
  let (client, server) ← Mock.new
  let before := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunk".toUTF8
  let after := "ed\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server (before ++ ByteArray.mk #[0x01] ++ after) okHandler
  assertExact "Control char in TE value → 400" response bad400


-- Empty TE value → 400 (empty coding list is invalid per TransferEncoding.Validate).
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: \x0d\nConnection: close\x0d\n\x0d\nbody".toUTF8
  let response ← sendRaw client server raw okHandler
  assertStatus "TE: empty value → error" response "HTTP/1.1 4"


-- TE: chunked with trailing OWS is accepted (OWS is stripped before parsing).
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked \x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertStatus "TE: chunked with trailing OWS → 200" response "HTTP/1.1 200"
