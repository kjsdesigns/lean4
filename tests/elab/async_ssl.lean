import Std.Internal.Async.TCP.SSL
import Std.Net.Addr

open Std.Internal.IO Async TCP.SSL
open Std.Net
open Std.Internal.SSL

-- ---------------------------------------------------------------------------
-- Helpers
-- ---------------------------------------------------------------------------

def assertEqStr (actual expected : String) : IO Unit := do
  unless actual == expected do
    throw <| IO.userError s!"expected '{expected}', got '{actual}'"

def assertGt (actual : UInt64) (bound : UInt64) (label : String) : IO Unit := do
  unless actual > bound do
    throw <| IO.userError s!"{label}: expected > {bound}, got {actual}"

def assertEqN (actual expected : UInt64) (label : String) : IO Unit := do
  unless actual == expected do
    throw <| IO.userError s!"{label}: expected {expected}, got {actual}"

-- Generate a self-signed certificate for testing.
def setupTestCerts : IO (String × String) := do
  IO.FS.createDirAll "/tmp/lean_ssl_test"
  let keyFile  := "/tmp/lean_ssl_test/key.pem"
  let certFile := "/tmp/lean_ssl_test/cert.pem"
  discard <| IO.Process.output {
    cmd  := "openssl"
    args := #["genrsa", "-out", keyFile, "2048"]
  }
  discard <| IO.Process.output {
    cmd  := "openssl"
    args := #["req", "-new", "-x509", "-key", keyFile, "-out", certFile,
              "-days", "1", "-subj", "/CN=localhost"]
  }
  return (certFile, keyFile)

-- Drive one handshake step: advance both state machines and exchange encrypted
-- bytes between their memory BIOs. Returns (clientDone, serverDone).
def handshakeStep (c s : Session) : IO (Bool × Bool) := do
  let cd ← c.handshake
  let cOut ← c.drainEncrypted
  if cOut.size > 0 then
    discard <| s.feedEncrypted cOut
  let sd ← s.handshake
  let sOut ← s.drainEncrypted
  if sOut.size > 0 then
    discard <| c.feedEncrypted sOut
  return (cd, sd)

partial def runHandshake (c s : Session) : IO Unit := do
  let (cd, sd) ← handshakeStep c s
  unless cd && sd do runHandshake c s

-- Pipe all pending encrypted output from src into dst's read BIO.
def pipeEncrypted (src dst : Session) : IO Unit := do
  let bytes ← src.drainEncrypted
  if bytes.size > 0 then
    discard <| dst.feedEncrypted bytes

-- ---------------------------------------------------------------------------
-- Test 1: Context creation and configuration (smoke test)
-- ---------------------------------------------------------------------------

def testContextCreation (certFile keyFile : String) : IO Unit := do
  let serverCtx ← Context.mkServer
  serverCtx.configureServer certFile keyFile

  let clientCtx ← Context.mkClient
  clientCtx.configureClient "" false

  -- Configuring with a CA file path (non-empty) exercises the other branch.
  let clientCtx2 ← Context.mkClient
  clientCtx2.configureClient certFile false

-- ---------------------------------------------------------------------------
-- Test 2: In-process TLS handshake between two memory-BIO sessions
-- ---------------------------------------------------------------------------

def testInProcessHandshake (certFile keyFile : String) : IO Unit := do
  let serverCtx ← Context.mkServer
  serverCtx.configureServer certFile keyFile

  let clientCtx ← Context.mkClient
  clientCtx.configureClient "" false  -- skip peer verification

  let serverSess ← Session.mk serverCtx true
  let clientSess ← Session.mk clientCtx false

  -- setServerName exercises SSL_set_tlsext_host_name.
  clientSess.setServerName "localhost"

  runHandshake clientSess serverSess

  -- verifyResult: just verify the call succeeds (self-signed cert returns
  -- X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT even with VERIFY_NONE).
  discard <| clientSess.verifyResult

-- ---------------------------------------------------------------------------
-- Test 3: write / pendingEncrypted / drainEncrypted / feedEncrypted / read?
-- ---------------------------------------------------------------------------

def testDataTransfer (certFile keyFile : String) : IO Unit := do
  let serverCtx ← Context.mkServer
  serverCtx.configureServer certFile keyFile

  let clientCtx ← Context.mkClient
  clientCtx.configureClient "" false

  let serverSess ← Session.mk serverCtx true
  let clientSess ← Session.mk clientCtx false

  runHandshake clientSess serverSess

  -- write plaintext → encrypted bytes appear in the write BIO.
  let msg := "hello, tls!".toUTF8
  discard <| clientSess.write msg

  -- pendingEncrypted > 0 before draining.
  let pending ← clientSess.pendingEncrypted
  assertGt pending 0 "pendingEncrypted"

  -- Pipe to server and read back.
  pipeEncrypted clientSess serverSess
  let received ← serverSess.read? 1024
  assertEqStr (String.fromUTF8! (received.getD ByteArray.empty)) "hello, tls!"

  -- After draining, pendingEncrypted drops to 0.
  let pendingAfter ← clientSess.pendingEncrypted
  assertEqN pendingAfter 0 "pendingEncrypted after drain"

  -- read? returns none when no data is available.
  let empty ← clientSess.read? 1024
  unless empty == none do
    throw <| IO.userError "expected none when no data available"

-- ---------------------------------------------------------------------------
-- Test 4: pendingPlaintext — write 100 bytes, read 10, rest stays buffered
-- ---------------------------------------------------------------------------

def testPendingPlaintext (certFile keyFile : String) : IO Unit := do
  let serverCtx ← Context.mkServer
  serverCtx.configureServer certFile keyFile

  let clientCtx ← Context.mkClient
  clientCtx.configureClient "" false

  let serverSess ← Session.mk serverCtx true
  let clientSess ← Session.mk clientCtx false

  runHandshake clientSess serverSess

  let bigMsg := (String.mk (List.replicate 100 'x')).toUTF8
  discard <| clientSess.write bigMsg
  pipeEncrypted clientSess serverSess

  -- Read only 10 bytes; the remaining 90 stay in SSL's plaintext buffer.
  discard <| serverSess.read? 10
  let remaining ← serverSess.pendingPlaintext
  assertEqN remaining 90 "pendingPlaintext after partial read"

-- ---------------------------------------------------------------------------
-- Test 5: Full TCP/TLS round-trip
-- ---------------------------------------------------------------------------

def serverTask (server : TCP.SSL.Server) : Async Unit := do
  let client ← server.accept
  let msg ← client.recv? 1024
  client.send (msg.getD ByteArray.empty)  -- echo
  client.shutdown

def clientTask (addr : SocketAddress) (clientCtx : Context) : Async Unit := do
  let client ← TCP.SSL.Client.mk clientCtx
  client.setServerName "localhost"
  client.connect addr
  client.noDelay
  client.send "hello over tls".toUTF8
  let resp ← client.recv? 1024
  let got := String.fromUTF8! (resp.getD ByteArray.empty)
  unless got == "hello over tls" do
    throw <| IO.userError s!"round-trip mismatch: '{got}'"
  let _ ← client.getPeerName
  let _ ← client.getSockName
  let _ ← client.verifyResult
  client.shutdown

def testTCPSSL (addr : SocketAddress) (certFile keyFile : String) : IO Unit := do
  let serverCtx ← Context.mkServer
  serverCtx.configureServer certFile keyFile

  let clientCtx ← Context.mkClient
  TCP.SSL.Client.configureContext clientCtx "" false

  let server ← TCP.SSL.Server.mk serverCtx
  server.configureContext certFile keyFile  -- idempotent re-configuration
  server.bind addr
  server.listen 128

  let _ ← server.getSockName

  let srvTask ← (serverTask server).toIO
  let cliTask ← (clientTask addr clientCtx).toIO

  srvTask.block
  cliTask.block

-- ---------------------------------------------------------------------------
-- Run all tests
-- ---------------------------------------------------------------------------

#eval do
  let (certFile, keyFile) ← setupTestCerts
  testContextCreation certFile keyFile

#eval do
  let (certFile, keyFile) ← setupTestCerts
  testInProcessHandshake certFile keyFile

#eval do
  let (certFile, keyFile) ← setupTestCerts
  testDataTransfer certFile keyFile

#eval do
  let (certFile, keyFile) ← setupTestCerts
  testPendingPlaintext certFile keyFile

#eval do
  let (certFile, keyFile) ← setupTestCerts
  testTCPSSL (SocketAddressV4.mk (.ofParts 127 0 0 1) 18443) certFile keyFile

#eval do
  let (certFile, keyFile) ← setupTestCerts
  testTCPSSL (SocketAddressV6.mk (.ofParts 0 0 0 0 0 0 0 1) 18444) certFile keyFile
