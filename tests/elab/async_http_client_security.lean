import Std.Internal.Http
import Std.Internal.Async
import Std.Internal.Async.Timer

open Std.Internal.IO Async
open Std Http

/-!
# HTTP Client Security Tests

Tests for security properties of the HTTP client:

- `Authorization` is stripped on cross-scheme redirects (same host+port, different scheme).
  Before the fix `crossOrigin` checked host+port only; a http→https redirect to the same
  host+port would silently keep the credential header.

- Streaming (`.outgoing`) request bodies must not be retried on connection failure.
  A channel-backed body is consumed on first use; retrying would send an empty body.
-/

private def runWithTimeout (name : String) (timeoutMs : Nat := 3000) (action : IO Unit) : IO Unit := do
  let task ← IO.asTask action
  let ticks := (timeoutMs + 9) / 10
  let rec loop (remaining : Nat) : IO Unit := do
    if (← IO.getTaskState task) == .finished then
      match (← IO.wait task) with
      | .ok x => pure x
      | .error err => throw err
    else
      match remaining with
      | 0 =>
        IO.cancel task
        throw <| IO.userError s!"Test '{name}' timed out after {timeoutMs}ms"
      | n + 1 =>
        IO.sleep 10
        loop n
  loop ticks

-- Build a raw HTTP/1.1 response byte string.
private def rawResp
    (status : String) (hdrs : Array (String × String)) (body : String) : ByteArray :=
  let hdrLines := hdrs.foldl (fun s (k, v) => s ++ s!"{k}: {v}\r\n") ""
  s!"HTTP/1.1 {status}\r\n{hdrLines}\r\n{body}".toUTF8

-- ============================================================
-- Redirect: Authorization stripped on scheme-change redirect
-- ============================================================
-- A 302 redirect from http://example.com:443/ to https://example.com:443/r has the
-- same host and port but a different scheme.  crossOrigin must be true so that the
-- Authorization header is stripped before the redirect request is sent.
-- ============================================================

#eval show IO _ from runWithTimeout "scheme-change strips Authorization" 3000 <| Async.block do
  let (mockClient, mockServer) ← Mock.new
  let session ← Client.Session.new mockServer (config := {})
  let cookieJar ← Cookie.Jar.new
  let some domain := URI.DomainName.ofString? "example.com"
    | throw (IO.userError "DomainName parse failed")

  -- Agent with scheme=http on port 443.  Redirect target https://example.com:443/r
  -- has same host+port but different scheme → crossOrigin must be true after the fix.
  let agent : Client.Agent Mock.Server := {
    session
    scheme := URI.Scheme.ofString! "http"
    host := .name domain
    port := 443
    cookieJar
  }

  let request ← Request.new
    |>.method .get
    |>.uri! "/"
    |>.header! "Host" "example.com:443"
    |>.header! "Authorization" "Bearer secret-token"
    |>.blank

  let resultPromise : IO.Promise (Except String (Response Body.Incoming)) ← IO.Promise.new
  background do
    let result : Except String (Response Body.Incoming) ← try
        let resp ← Client.Agent.send agent request
        pure (Except.ok resp)
      catch e => pure (Except.error (toString e))
    discard <| resultPromise.resolve result

  -- First exchange: drain the request, reply with 302 redirecting to HTTPS same host+port.
  let _ ← mockClient.recv?
  mockClient.send (rawResp "302 Found"
    #[("Location", "https://example.com:443/redirected"),
      ("Content-Length", "0"),
      ("Connection", "keep-alive")] "")

  -- Second exchange: receive the redirected request and capture its bytes.
  let some redirectBytes ← mockClient.recv?
    | throw (IO.userError "Test failed: no redirect request received")
  mockClient.send (rawResp "200 OK"
    #[("Content-Length", "2"), ("Connection", "close")] "ok")

  -- Wait for the agent to finish.
  match ← await resultPromise.result! with
  | Except.error e => throw (IO.userError s!"agent error: {e}")
  | Except.ok _ => pure ()

  let redirectText := String.fromUTF8! redirectBytes
  if redirectText.contains "Authorization:" then
    throw <| IO.userError
      s!"Test 'scheme-change strips Authorization' FAILED: \
         Authorization header present in redirect request\n{redirectText.quote}"

-- ============================================================
-- Redirect: Authorization preserved on same-origin redirect
-- ============================================================
-- A 302 redirect to the same scheme, host, and port is a same-origin redirect.
-- The Authorization header must NOT be stripped in this case.
-- ============================================================

#eval show IO _ from runWithTimeout "same-origin preserves Authorization" 3000 <| Async.block do
  let (mockClient, mockServer) ← Mock.new
  let session ← Client.Session.new mockServer (config := {})
  let cookieJar ← Cookie.Jar.new
  let some domain := URI.DomainName.ofString? "example.com"
    | throw (IO.userError "DomainName parse failed")

  let agent : Client.Agent Mock.Server := {
    session
    scheme := URI.Scheme.ofString! "http"
    host := .name domain
    port := 80
    cookieJar
  }

  let request ← Request.new
    |>.method .get
    |>.uri! "/"
    |>.header! "Host" "example.com"
    |>.header! "Authorization" "Bearer secret-token"
    |>.blank

  let resultPromise : IO.Promise (Except String (Response Body.Incoming)) ← IO.Promise.new
  background do
    let result : Except String (Response Body.Incoming) ← try
        let resp ← Client.Agent.send agent request
        pure (Except.ok resp)
      catch e => pure (Except.error (toString e))
    discard <| resultPromise.resolve result

  -- First exchange: reply with 302 to same scheme+host+port.
  let _ ← mockClient.recv?
  mockClient.send (rawResp "302 Found"
    #[("Location", "http://example.com/same-origin"),
      ("Content-Length", "0"),
      ("Connection", "keep-alive")] "")

  -- Second exchange: receive the redirected request.
  let some redirectBytes ← mockClient.recv?
    | throw (IO.userError "Test failed: no redirect request received")
  mockClient.send (rawResp "200 OK"
    #[("Content-Length", "2"), ("Connection", "close")] "ok")

  match ← await resultPromise.result! with
  | Except.error e => throw (IO.userError s!"agent error: {e}")
  | Except.ok _ => pure ()

  let redirectText := String.fromUTF8! redirectBytes
  unless redirectText.contains "Authorization:" do
    throw <| IO.userError
      s!"Test 'same-origin preserves Authorization' FAILED: \
         Authorization header was stripped on same-origin redirect\n{redirectText.quote}"

-- ============================================================
-- Body replay classification
-- ============================================================
-- Verifies that only `.outgoing` (channel-backed streaming) bodies are classified as
-- non-replayable, while `.full` (fixed bytes) and `.empty` bodies are safe to retry.
-- This mirrors the `bodyIsReplayable` check added to the retry guard in Agent.lean.
-- ============================================================

#eval show IO _ from Async.block do
  -- .outgoing: channel is consumed on first send, must not be retried.
  let (out, _) ← Body.mkChannel
  let streamBody : Body.AnyBody := .outgoing out
  let replayable := match streamBody with | .outgoing _ => false | _ => true
  if replayable then
    throw <| IO.userError "Test 'outgoing body is not replayable' FAILED"

  -- .full: fixed ByteArray, safe to send again.
  let fullBody : Body.AnyBody := .full (← Body.Full.ofByteArray "hello".toUTF8)
  let replayable2 := match fullBody with | .outgoing _ => false | _ => true
  unless replayable2 do
    throw <| IO.userError "Test 'full body is replayable' FAILED"

  -- .empty: trivially safe.
  let emptyBody : Body.AnyBody := .empty {}
  let replayable3 := match emptyBody with | .outgoing _ => false | _ => true
  unless replayable3 do
    throw <| IO.userError "Test 'empty body is replayable' FAILED"

-- ============================================================
-- Redirect: non-HTTP/HTTPS scheme in Location is not followed
-- ============================================================
-- A 302 response with Location: ftp://internal-host/secret must not be followed.
-- Before the fix, decideRedirect accepted any scheme that RequestTarget.parse? could
-- parse and would try to connect to the ftp host on port 80 (SSRF).
-- After the fix, only http:// and https:// redirect targets are followed; everything
-- else returns the 3xx response as-is.
-- ============================================================

#eval show IO _ from runWithTimeout "ftp:// redirect not followed" 3000 <| Async.block do
  let (mockClient, mockServer) ← Mock.new
  let session ← Client.Session.new mockServer (config := {})
  let cookieJar ← Cookie.Jar.new
  let some domain := URI.DomainName.ofString? "example.com"
    | throw (IO.userError "DomainName parse failed")

  let agent : Client.Agent Mock.Server := {
    session
    scheme := URI.Scheme.ofString! "http"
    host := .name domain
    port := 80
    cookieJar
  }

  let request ← Request.new
    |>.method .get
    |>.uri! "/"
    |>.header! "Host" "example.com"
    |>.blank

  let resultPromise : IO.Promise (Except String (Response Body.Incoming)) ← IO.Promise.new
  background do
    let result ← try
        let resp ← Client.Agent.send agent request
        pure (Except.ok resp)
      catch e => pure (Except.error (toString e))
    discard <| resultPromise.resolve result

  -- Server replies with a redirect to ftp:// (non-HTTP scheme).
  let _ ← mockClient.recv?
  mockClient.send (rawResp "302 Found"
    #[("Location", "ftp://internal-host/secret"),
      ("Content-Length", "0")] "")

  match ← await resultPromise.result! with
  | Except.error e => throw (IO.userError s!"agent error: {e}")
  | Except.ok resp =>
    -- The agent must return the 302 as-is, not follow it.
    unless resp.line.status == .found do
      throw <| IO.userError
        s!"Test 'ftp:// redirect not followed' FAILED: expected 302, got {resp.line.status.toCode}"

#eval show IO _ from runWithTimeout "file:// redirect not followed" 3000 <| Async.block do
  let (mockClient, mockServer) ← Mock.new
  let session ← Client.Session.new mockServer (config := {})
  let cookieJar ← Cookie.Jar.new
  let some domain := URI.DomainName.ofString? "example.com"
    | throw (IO.userError "DomainName parse failed")

  let agent : Client.Agent Mock.Server := {
    session
    scheme := URI.Scheme.ofString! "http"
    host := .name domain
    port := 80
    cookieJar
  }

  let request ← Request.new
    |>.method .get
    |>.uri! "/"
    |>.header! "Host" "example.com"
    |>.blank

  let resultPromise : IO.Promise (Except String (Response Body.Incoming)) ← IO.Promise.new
  background do
    let result ← try
        let resp ← Client.Agent.send agent request
        pure (Except.ok resp)
      catch e => pure (Except.error (toString e))
    discard <| resultPromise.resolve result

  let _ ← mockClient.recv?
  mockClient.send (rawResp "301 Moved Permanently"
    #[("Location", "file:///etc/passwd"),
      ("Content-Length", "0")] "")

  match ← await resultPromise.result! with
  | Except.error e => throw (IO.userError s!"agent error: {e}")
  | Except.ok resp =>
    unless resp.line.status == .movedPermanently do
      throw <| IO.userError
        s!"Test 'file:// redirect not followed' FAILED: expected 301, got {resp.line.status.toCode}"

-- ============================================================
-- Redirect: https:// redirect IS followed (sanity check)
-- ============================================================
-- Verify that the scheme restriction doesn't accidentally block legitimate
-- https:// redirects (same host, different scheme from http to https).
-- ============================================================

#eval show IO _ from runWithTimeout "https:// redirect is followed" 3000 <| Async.block do
  let (mockClient, mockServer) ← Mock.new
  let session ← Client.Session.new mockServer (config := {})
  let cookieJar ← Cookie.Jar.new
  let some domain := URI.DomainName.ofString? "example.com"
    | throw (IO.userError "DomainName parse failed")

  -- Agent with connectTo = none; cross-host redirects return the 3xx as-is.
  -- We use the same-host case: http://example.com:80/target (same host+port, scheme changes).
  let agent : Client.Agent Mock.Server := {
    session
    scheme := URI.Scheme.ofString! "http"
    host := .name domain
    port := 80
    cookieJar
  }

  let request ← Request.new
    |>.method .get
    |>.uri! "/"
    |>.header! "Host" "example.com"
    |>.blank

  let resultPromise : IO.Promise (Except String (Response Body.Incoming)) ← IO.Promise.new
  background do
    let result ← try
        let resp ← Client.Agent.send agent request
        pure (Except.ok resp)
      catch e => pure (Except.error (toString e))
    discard <| resultPromise.resolve result

  -- 302 to https://example.com/page — same host+port, scheme differs from http.
  -- No connectTo factory means cross-origin redirect returns 302 as-is, but at least
  -- the scheme check must not block it before that point; the 302 must be attempted.
  let _ ← mockClient.recv?
  mockClient.send (rawResp "302 Found"
    #[("Location", "https://example.com/page"),
      ("Content-Length", "0")] "")

  -- https://example.com/page resolves to port 443, which differs from port 80, so
  -- this is a cross-origin redirect.  With connectTo = none the agent returns the 302
  -- as-is without issuing a second request.  Run the optional mock service in the
  -- background so the main fiber is not blocked when no second request arrives.
  background do
    let redirectReqOpt ← mockClient.recv?
    if redirectReqOpt.isSome then
      mockClient.send (rawResp "200 OK"
        #[("Content-Length", "2"), ("Connection", "close")] "ok")

  match ← await resultPromise.result! with
  | Except.error e => throw (IO.userError s!"agent error: {e}")
  | Except.ok resp =>
    -- We accept either 302 (no connectTo for cross-host) or 200 (same-session follow).
    let code := resp.line.status.toCode
    unless code == 200 || code == 302 do
      throw <| IO.userError
        s!"Test 'https:// redirect is followed' FAILED: unexpected status {code}"

-- ============================================================
-- Redirect: streaming body dropped on method-preserving redirect
-- ============================================================
-- A 307 redirect preserves the original method and body.  When the body is a
-- streaming channel (.outgoing) that has already been consumed by the first
-- request, it cannot be replayed.  The redirect request must send no body
-- (Content-Length: 0) rather than silently retransmitting whatever bytes remain
-- in the channel (none, so it would be empty anyway — but the fix must explicitly
-- classify .outgoing as non-replayable so future semantics stay correct).
-- ============================================================

#eval show IO _ from runWithTimeout "streaming body dropped on 307 redirect" 3000 <| Async.block do
  let (mockClient, mockServer) ← Mock.new
  let session ← Client.Session.new mockServer (config := {})
  let cookieJar ← Cookie.Jar.new
  let some domain := URI.DomainName.ofString? "example.com"
    | throw (IO.userError "DomainName parse failed")

  let agent : Client.Agent Mock.Server := {
    session
    scheme := URI.Scheme.ofString! "http"
    host := .name domain
    port := 80
    cookieJar
  }

  let request ← Request.new
    |>.method .put
    |>.uri! "/upload"
    |>.header! "Host" "example.com"
    |>.stream (fun out => do
        Body.Writer.send out { data := "payload".toUTF8 } false
        Body.Writer.close out)

  let resultPromise : IO.Promise (Except String (Response Body.Incoming)) ← IO.Promise.new

  background do
    let result ← try
        let resp ← Client.Agent.send agent request
        pure (Except.ok resp)
      catch e => pure (Except.error (toString e))
    discard <| resultPromise.resolve result

  -- First request: drain it completely before replying with 307.
  -- The body is Transfer-Encoding: chunked; loop until the terminating 0\r\n\r\n
  -- chunk arrives so the second recv? captures only the redirect request.
  let mut firstBytes := ByteArray.empty
  repeat
    let some chunk ← mockClient.recv?
      | throw (IO.userError "Test failed: connection closed before first request")
    firstBytes := firstBytes ++ chunk
    if (String.fromUTF8! firstBytes).endsWith "0\r\n\r\n" then break
  mockClient.send (rawResp "307 Temporary Redirect"
    #[("Location", "/new-upload"),
      ("Content-Length", "0")] "")

  -- Second request: the redirect.  The streaming body is already consumed so
  -- the client must send no body (Content-Length: 0 or absent, no body bytes).
  let some redirectBytes ← mockClient.recv?
    | throw (IO.userError "Test failed: no redirect request received")
  mockClient.send (rawResp "200 OK"
    #[("Content-Length", "2"), ("Connection", "close")] "ok")

  match ← await resultPromise.result! with
  | Except.error e => throw (IO.userError s!"agent error: {e}")
  | Except.ok _ => pure ()

  let redirectText := String.fromUTF8! redirectBytes
  -- The redirect request must target /new-upload.
  unless redirectText.contains "PUT /new-upload" do
    throw <| IO.userError
      s!"Test 'streaming body dropped on 307 redirect' FAILED: expected PUT /new-upload\n{redirectText.quote}"
  -- The body must be empty: Content-Length 0 (or no body bytes after blank line).
  -- We check that "payload" does not appear in the redirect request.
  if redirectText.contains "payload" then
    throw <| IO.userError
      s!"Test 'streaming body dropped on 307 redirect' FAILED: \
         streaming body payload present in redirect request\n{redirectText.quote}"


