import Std.Internal.Http
import Std.Internal.Async

open Std.Internal.IO Async
open Std Http

abbrev TestHandler := Request Body.Incoming → ContextAsync (Response Body.Any)

instance : Std.Http.Server.Handler TestHandler where
  onRequest handler request := handler request

instance : Coe (ContextAsync (Response Body.Incoming)) (ContextAsync (Response Body.Any)) where
  coe action := do
    let response ← action
    pure { response with body := Body.Internal.incomingToOutgoing response.body }

instance : Coe (Async (Response Body.Incoming)) (ContextAsync (Response Body.Any)) where
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


def echoHandler : TestHandler :=
  fun req => do
    let body : String ← req.body.readAll
    Response.ok |>.text body

def bad400 : String :=
  "HTTP/1.1 400 Bad Request\x0d\nServer: LeanHTTP/1.1\x0d\nConnection: close\x0d\nContent-Length: 0\x0d\n\x0d\n"


-- Chunk extension name length limits.
-- Default maxChunkExtNameLength = 256.
#eval show IO _ from do
  let name256 := String.ofList (List.replicate 256 'a')
  let name257 := String.ofList (List.replicate 257 'a')

  -- Name at exactly the limit → accepted.
  let (clientA, serverA) ← Mock.new
  let rawA := s!"POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;{name256}\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseA ← sendRaw clientA serverA rawA echoHandler
  assertStatus "Ext name at 256 → accepted" responseA "HTTP/1.1 200"

  -- Name one byte over the limit → rejected.
  let (clientB, serverB) ← Mock.new
  let rawB := s!"POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;{name257}\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseB ← sendRaw clientB serverB rawB echoHandler
  assertExact "Ext name at 257 → rejected" responseB bad400


-- Chunk extension value length limits (unquoted token value).
-- Default maxChunkExtValueLength = 256.
#eval show IO _ from do
  let val256 := String.ofList (List.replicate 256 'v')
  let val257 := String.ofList (List.replicate 257 'v')

  -- Token value at exactly the limit → accepted.
  let (clientA, serverA) ← Mock.new
  let rawA := s!"POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;ext={val256}\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseA ← sendRaw clientA serverA rawA echoHandler
  assertStatus "Ext token value at 256 → accepted" responseA "HTTP/1.1 200"

  -- Token value one byte over the limit → rejected.
  let (clientB, serverB) ← Mock.new
  let rawB := s!"POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;ext={val257}\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseB ← sendRaw clientB serverB rawB echoHandler
  assertExact "Ext token value at 257 → rejected" responseB bad400


-- Chunk extension value length limits (quoted string value).
-- The limit applies to the unquoted content length.
#eval show IO _ from do
  let val256 := String.ofList (List.replicate 256 'v')
  let val257 := String.ofList (List.replicate 257 'v')

  -- Quoted value at exactly the limit → accepted.
  let (clientA, serverA) ← Mock.new
  let rawA := s!"POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;ext=\"{val256}\"\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseA ← sendRaw clientA serverA rawA echoHandler
  assertStatus "Ext quoted value at 256 → accepted" responseA "HTTP/1.1 200"

  -- Quoted value one byte over the limit → rejected.
  let (clientB, serverB) ← Mock.new
  let rawB := s!"POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;ext=\"{val257}\"\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseB ← sendRaw clientB serverB rawB echoHandler
  assertExact "Ext quoted value at 257 → rejected" responseB bad400


-- Chunk extension count limits.
-- Default maxChunkExtensions = 16.
#eval show IO _ from do
  -- Build extension lists: ";ext0;ext1;...;extN"
  let exts16 := (List.range 16).foldl (fun acc i => acc ++ s!";e{i}") ""
  let exts17 := (List.range 17).foldl (fun acc i => acc ++ s!";e{i}") ""

  -- Exactly 16 extensions → accepted.
  let (clientA, serverA) ← Mock.new
  let rawA := s!"POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5{exts16}\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseA ← sendRaw clientA serverA rawA echoHandler
  assertStatus "16 extensions → accepted" responseA "HTTP/1.1 200"

  -- 17 extensions → rejected.
  let (clientB, serverB) ← Mock.new
  let rawB := s!"POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5{exts17}\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseB ← sendRaw clientB serverB rawB echoHandler
  assertExact "17 extensions → rejected" responseB bad400


-- maxChunkExtensions config override.
#eval show IO _ from do
  let cfg1 : Config := { lingeringTimeout := 1000, maxChunkExtensions := 1, generateDate := false }

  -- 1 extension with limit=1 → accepted.
  let (clientA, serverA) ← Mock.new
  let rawA := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;ext1\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseA ← sendRaw clientA serverA rawA echoHandler (config := cfg1)
  assertStatus "1 ext with limit=1 → accepted" responseA "HTTP/1.1 200"

  -- 2 extensions with limit=1 → rejected.
  let (clientB, serverB) ← Mock.new
  let rawB := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;ext1;ext2\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseB ← sendRaw clientB serverB rawB echoHandler (config := cfg1)
  assertExact "2 exts with limit=1 → rejected" responseB bad400

  -- 0 extensions with limit=1 → accepted (no extensions is always fine).
  let (clientC, serverC) ← Mock.new
  let rawC := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let responseC ← sendRaw clientC serverC rawC echoHandler (config := cfg1)
  assertStatus "0 exts with limit=1 → accepted" responseC "HTTP/1.1 200"


-- Extension with no value (name-only extension token).
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;novalue\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertStatus "Ext with no value → accepted" response "HTTP/1.1 200"
  -- Body is still correctly delivered.
  let text := String.fromUTF8! response
  unless text.contains "hello" do
    throw <| IO.userError "Body not delivered with name-only extension"


-- Extensions on the terminal (last) chunk are accepted.
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5\x0d\nhello\x0d\n0;final-ext=done\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertStatus "Extension on last chunk → accepted" response "HTTP/1.1 200"


-- Extension with name and quoted-string value.
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;ext=\"hello world\"\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertStatus "Ext with quoted-string value → accepted" response "HTTP/1.1 200"


-- Extension with non-token character in name → rejected.
#eval show IO _ from do
  let (client, server) ← Mock.new
  -- '@' is not a valid token character
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;bad@name\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertExact "Ext with non-token name char → rejected" response bad400


-- Multiple extensions with name=value pairs.
#eval show IO _ from do
  let (client, server) ← Mock.new
  let raw := "POST / HTTP/1.1\x0d\nHost: example.com\x0d\nTransfer-Encoding: chunked\x0d\nConnection: close\x0d\n\x0d\n5;a=1;b=2;c=3\x0d\nhello\x0d\n0\x0d\n\x0d\n".toUTF8
  let response ← sendRaw client server raw echoHandler
  assertStatus "Multiple name=value extensions → accepted" response "HTTP/1.1 200"
