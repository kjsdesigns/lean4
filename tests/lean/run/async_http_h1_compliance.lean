import Std.Internal.Http

open Std Http
open Std.Http.Protocol.H1

private def ensure (name : String) (cond : Bool) (msg : String) : IO Unit := do
  unless cond do
    throw <| IO.userError s!"Test '{name}' failed:\n{msg}"

private def hasFailedEvent (events : Array (Event .receiving)) : Bool :=
  events.any fun
    | .failed _ => true
    | _ => false

private def runOneStep
    (payload : ByteArray)
    (config : Protocol.H1.Config := {}) :
    Machine .receiving × StepResult .receiving :=
  let machine0 : Machine .receiving := { config := config }
  (machine0.feed payload).step

private def assertFailedWith
    (name : String)
    (payload : ByteArray)
    (expected : Error)
    (config : Protocol.H1.Config := {}) : IO Unit := do
  let (machine, step) := runOneStep payload config
  ensure name (hasFailedEvent step.events) s!"expected failure event, events:\n{repr step.events}"
  ensure name (machine.error == some expected)
    s!"expected error {repr expected}, got {repr machine.error}"

private def assertMachineSucceeds
    (name : String)
    (payload : ByteArray)
    (config : Protocol.H1.Config := {}) : IO Unit := do
  let (machine, step) := runOneStep payload config
  ensure name (machine.error.isNone)
    s!"expected machine success but it failed with {repr machine.error}\nevents:\n{repr step.events}"

-- =========================================================================
-- HTTP/1.0 transfer-encoding (RFC 2068 §19.4.6)
-- Chunked transfer encoding is not defined for HTTP/1.0.
-- =========================================================================

-- HTTP/1.0 + Transfer-Encoding: chunked must be rejected.
#eval show IO Unit from do
  assertFailedWith
    "HTTP/1.0 chunked TE rejected"
    ("POST / HTTP/1.0\r\nHost: example.com\r\n" ++
     "Transfer-Encoding: chunked\r\n\r\n" ++
     "5\r\nhello\r\n0\r\n\r\n").toUTF8
    .badMessage

-- HTTP/1.0 + Transfer-Encoding: gzip, chunked (compound) must also be rejected.
#eval show IO Unit from do
  assertFailedWith
    "HTTP/1.0 compound chunked TE rejected"
    ("POST / HTTP/1.0\r\nHost: example.com\r\n" ++
     "Transfer-Encoding: gzip, chunked\r\n\r\n" ++
     "5\r\nhello\r\n0\r\n\r\n").toUTF8
    .badMessage

-- HTTP/1.1 + Transfer-Encoding: chunked must be accepted.
#eval show IO Unit from do
  assertMachineSucceeds
    "HTTP/1.1 chunked TE accepted"
    ("POST / HTTP/1.1\r\nHost: example.com\r\n" ++
     "Transfer-Encoding: chunked\r\n\r\n" ++
     "5\r\nhello\r\n0\r\n\r\n").toUTF8

-- =========================================================================
-- HTTP/1.0 Host header (RFC 2616 §14.23)
-- Host is optional in HTTP/1.0; required only in HTTP/1.1 (RFC 9112 §3.2).
-- =========================================================================

-- HTTP/1.0 GET without a Host header must be accepted.
#eval show IO Unit from do
  assertMachineSucceeds
    "HTTP/1.0 GET without Host accepted"
    "GET / HTTP/1.0\r\n\r\n".toUTF8

-- HTTP/1.0 POST without a Host header must be accepted.
#eval show IO Unit from do
  assertMachineSucceeds
    "HTTP/1.0 POST without Host accepted"
    "POST / HTTP/1.0\r\nContent-Length: 0\r\n\r\n".toUTF8

-- HTTP/1.0 with a Host header must also be accepted.
#eval show IO Unit from do
  assertMachineSucceeds
    "HTTP/1.0 with Host accepted"
    "GET / HTTP/1.0\r\nHost: example.com\r\n\r\n".toUTF8

-- HTTP/1.1 without a Host header must be rejected.
#eval show IO Unit from do
  assertFailedWith
    "HTTP/1.1 without Host rejected"
    "GET / HTTP/1.1\r\n\r\n".toUTF8
    .badMessage

-- =========================================================================
-- Keep-alive persistence
-- RFC 2616 §19.7.1: HTTP/1.0 + Connection: keep-alive requests persistence.
-- RFC 9112: HTTP/1.1 is persistent by default; Connection: close disables it.
-- =========================================================================

-- HTTP/1.0 + Connection: keep-alive must enable persistence.
#eval show IO Unit from do
  let payload :=
    "GET / HTTP/1.0\r\nHost: example.com\r\nConnection: keep-alive\r\n\r\n".toUTF8
  let machine0 : Machine .receiving := { config := {} }
  let (machine, step) := (machine0.feed payload).step
  ensure
    "HTTP/1.0 Connection: keep-alive enables keepAlive"
    machine.keepAlive
    s!"expected keepAlive=true for HTTP/1.0 + Connection: keep-alive\n{repr step.events}"

-- HTTP/1.0 without Connection: keep-alive must be non-persistent.
#eval show IO Unit from do
  let payload := "GET / HTTP/1.0\r\nHost: example.com\r\n\r\n".toUTF8
  let machine0 : Machine .receiving := { config := {} }
  let (machine, _) := (machine0.feed payload).step
  ensure
    "HTTP/1.0 bare request is non-persistent"
    (!machine.keepAlive)
    "expected keepAlive=false for plain HTTP/1.0 request"

-- HTTP/1.1 keep-alive defaults to true.
#eval show IO Unit from do
  let payload := "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n".toUTF8
  let machine0 : Machine .receiving := { config := {} }
  let (machine, step) := (machine0.feed payload).step
  ensure
    "HTTP/1.1 keepAlive defaults to true"
    machine.keepAlive
    s!"expected keepAlive=true for HTTP/1.1 request\n{repr step.events}"

-- HTTP/1.1 + Connection: close must disable keep-alive.
#eval show IO Unit from do
  let payload :=
    "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n".toUTF8
  let machine0 : Machine .receiving := { config := {} }
  let (machine, _) := (machine0.feed payload).step
  ensure
    "HTTP/1.1 Connection: close disables keepAlive"
    (!machine.keepAlive)
    "expected keepAlive=false for HTTP/1.1 + Connection: close"

-- =========================================================================
-- RFC 9112 §2.2: bare LF in header section must be rejected.
-- =========================================================================

-- Header section ending with CRLF + bare LF (instead of two CRLFs) is rejected.
#eval show IO Unit from do
  assertFailedWith
    "Bare LF blank line rejected"
    "GET / HTTP/1.1\r\nHost: example.com\r\n\n".toUTF8
    .badMessage

-- Bare LF blank line with a body following must also be rejected.
#eval show IO Unit from do
  assertFailedWith
    "Bare LF blank line with body rejected"
    ("POST / HTTP/1.1\r\nHost: example.com\r\nContent-Length: 5\r\n\nhello").toUTF8
    .badMessage

-- =========================================================================
-- Regression: well-established behaviours must not regress.
-- =========================================================================

-- Content-Length + Transfer-Encoding together must be rejected (request smuggling guard).
#eval show IO Unit from do
  assertFailedWith
    "CL + TE together rejected"
    ("POST / HTTP/1.1\r\nHost: example.com\r\n" ++
     "Content-Length: 5\r\nTransfer-Encoding: chunked\r\n\r\n" ++
     "5\r\nhello\r\n0\r\n\r\n").toUTF8
    .badMessage

-- Duplicate Host header must be rejected.
#eval show IO Unit from do
  assertFailedWith
    "Duplicate Host rejected"
    "GET / HTTP/1.1\r\nHost: a.example\r\nHost: b.example\r\n\r\n".toUTF8
    .badMessage

-- CONNECT requires authority-form target.
#eval show IO Unit from do
  assertFailedWith
    "CONNECT with non-authority target rejected"
    "CONNECT / HTTP/1.1\r\nHost: example.com\r\n\r\n".toUTF8
    .badMessage

-- Asterisk-form is reserved for OPTIONS only.
#eval show IO Unit from do
  assertFailedWith
    "GET * rejected"
    "GET * HTTP/1.1\r\nHost: example.com\r\n\r\n".toUTF8
    .badMessage

-- =========================================================================
-- Host/authority matching with default ports.
-- =========================================================================

-- https default-port equivalence: URI omits port, Host uses :443 => accepted.
#eval show IO Unit from do
  assertMachineSucceeds
    "absolute https + Host :443 accepted"
    "GET https://a.com/path HTTP/1.1\r\nHost: a.com:443\r\n\r\n".toUTF8

-- https default-port equivalence: URI uses :443, Host omits port => accepted.
#eval show IO Unit from do
  assertMachineSucceeds
    "absolute https:443 + Host omitted port accepted"
    "GET https://a.com:443/path HTTP/1.1\r\nHost: a.com\r\n\r\n".toUTF8

-- http default-port equivalence: URI omits port, Host uses :80 => accepted.
#eval show IO Unit from do
  assertMachineSucceeds
    "absolute http + Host :80 accepted"
    "GET http://a.com/path HTTP/1.1\r\nHost: a.com:80\r\n\r\n".toUTF8

-- Non-default port mismatch must be rejected.
#eval show IO Unit from do
  assertFailedWith
    "absolute https + Host :555 rejected"
    "GET https://a.com/path HTTP/1.1\r\nHost: a.com:555\r\n\r\n".toUTF8
    .badMessage

-- Explicit non-default URI port must not match omitted Host port.
#eval show IO Unit from do
  assertFailedWith
    "absolute https:444 + Host omitted port rejected"
    "GET https://a.com:444/path HTTP/1.1\r\nHost: a.com\r\n\r\n".toUTF8
    .badMessage
