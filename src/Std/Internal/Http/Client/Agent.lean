/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Std.Internal.Http.Client.Session
public import Std.Internal.Http.Data.Cookie
import Init.Data.Array

public section

namespace Std
namespace Http
namespace Client

set_option linter.all true

open Std Internal IO Async TCP Protocol
open Time

/-!
# Agent

This module defines `Client.Agent`, a transport-agnostic HTTP user-agent that wraps a `Session`
and adds automatic redirect following, cookie jar support, response interceptors, and configurable
retries.

`Agent` is parameterized by the transport type `α` and contains no TCP-specific code.
Use `Agent.ofTransport` to create an `Agent` from any connected transport. Pass a `connectTo`
factory to enable cross-host redirect following and automatic reconnection on error.

On each redirect the `Location` header is parsed as a URI. If the redirect targets a different
host or port the agent closes the current session and opens a new one using `connectTo` (when
available). A `Array URI` tracks every URI visited in the current redirect chain so that cycles
are detected and broken immediately.

When crossing to a different host the `Authorization` header is stripped from the redirected
request to prevent credential leakage.
-/

/--
An HTTP user-agent that manages a connection to a host. It follows redirects, maintains a cookie
jar for automatic cookie handling, applies response interceptors, and retries on connection errors.
-/
public structure Agent (α : Type) where
  /--
  The underlying HTTP session over the transport.
  -/
  session : Session α

  /--
  URI scheme for this connection (e.g., `"http"` or `"https"`).
  Used when constructing absolute-form request URIs for proxy requests and some redirects.
  -/
  scheme : URI.Scheme

  /--
  The hostname this agent is currently connected to.
  -/
  host : URI.Host

  /--
  The port this agent is currently connected to.
  -/
  port : UInt16

  /--
  Cookie jar shared across all requests and redirects through this agent.
  -/
  cookieJar : Cookie.Jar

  /--
  Response interceptors applied (in order) after every response, including intermediate
  redirect responses.  Each interceptor receives the response and returns a (possibly
  modified) response.  Interceptors run before cookie processing and redirect evaluation
  so they can, e.g., unwrap envelopes or transparently decompress bodies.
  -/
  interceptors : Array (Response Body.Incoming → Async (Response Body.Incoming)) := #[]

  /--
  Optional factory for opening a new session to `(host, port)`. Used for:
  * Automatic retry after connection errors (`maxRetries`): reconnects to the same host.
  * Cross-host redirects: connects to the new host.
  `none` for agents created via `Agent.ofTransport` without a factory; cross-host redirects
  are not followed and connection errors are not retried automatically for such agents.
  -/
  connectTo : Option (URI.Host → UInt16 → Async (Session α)) := none

  /--
  Called when a connection error is confirmed (i.e., `session.send` threw and all retries
  are committed to using a fresh session).  Receives the broken session together with the
  host and port so the caller can:
  * For pool agents: evict every session to that host so the next retry gets a fresh one.
  * For standalone agents: close the session's request channel so the background loop exits.
  The default closes the session channel; pool agents set this to an eviction function.
  -/
  onBrokenSession : Session α → URI.Host → UInt16 → Async Unit :=
    fun s _ _ => discard <| s.close

namespace Agent

/--
Returns `true` for HTTP methods that are safe to retry on connection failure.
Non-idempotent methods (POST, PATCH) must not be retried automatically because
the server may have already processed the request before the connection dropped.
-/
private def isIdempotentMethod (m : Method) : Bool :=
  m == .get || m == .head || m == .put || m == .delete || m == .options || m == .trace

/--
Rewrites an origin-form request target to absolute-form for proxy forwarding.
`GET /path?q=1 HTTP/1.1` becomes `GET http://host:port/path?q=1 HTTP/1.1`.
No-op for targets that are already in absolute-form or do not carry a path.
-/
def toAbsoluteFormRequest
    (request : Request Body.AnyBody)
    (scheme : URI.Scheme) (host : URI.Host) (port : UInt16) : Request Body.AnyBody :=
  match request.line.uri with
  | .originForm o =>
    { request with
        line := { request.line with uri := .absoluteForm {
          scheme,
          path := o.path,
          query := o.query.getD .empty,
          authority := some { host, port := .value port }
        }
      }
    }
  | _ => request

/--
Creates an `Agent` from an already-connected transport `socket`.
Pass a `connectTo` factory to enable automatic reconnection on error and cross-host redirect
following; omit it (or pass `none`) to disable both.
-/
def ofTransport [Transport α] (socket : α) (scheme : URI.Scheme)
    (host : URI.Host) (port : UInt16)
    (connectTo : Option (URI.Host → UInt16 → Async (Session α)) := none)
    (config : Config := {}) : Async (Agent α) := do

  let session ← Session.new socket config
  let cookieJar ← Cookie.Jar.new
  pure { session, scheme, host, port, cookieJar, connectTo }

/--
Injects matching cookies from `cookieJar` into the request headers for `host`.
Does nothing if the jar contains no matching cookies.
-/
def injectCookies (cookieJar : Cookie.Jar) (host : URI.Host) (scheme : URI.Scheme)
    (request : Request Body.AnyBody) : Async (Request Body.AnyBody) := do

  -- Respect an explicit Cookie header set by the caller.
  if request.line.headers.contains .cookie then return request

  let path := match request.line.uri with
    | .originForm o => o.path
    | .absoluteForm af => af.path
    | _ => URI.Path.parseOrRoot "/"

  match ← cookieJar.cookiesFor host path (secure := scheme.val == "https") with
  | none => return request
  | some cookieValue =>
    let newHeaders := request.line.headers.insert .cookie cookieValue
    return { request with line := { request.line with headers := newHeaders } }

/--
Reads all `Set-Cookie` headers from `responseHeaders` and stores the cookies in `cookieJar`.
-/
def processCookies (cookieJar : Cookie.Jar) (host : URI.Host)
    (responseHeaders : Headers) : BaseIO Unit := do
  if let some values := responseHeaders.getAll? Header.Name.setCookie then
    for v in values do
      cookieJar.processSetCookie host v.value

/--
Applies all response interceptors to `response` in order, returning the final result.
-/
def applyInterceptors
    (interceptors : Array (Response Body.Incoming → Async (Response Body.Incoming)))
    (response : Response Body.Incoming) : Async (Response Body.Incoming) :=
  interceptors.foldlM (init := response) (fun r f => f r)

/--
Outcome of evaluating whether a response should trigger an automatic redirect.
-/
inductive RedirectDecision where
  /--
  Response is final, should validate status and return it.
  -/
  | done

  /--
  Follow a redirect to `(host, port, scheme)` with `request`, updating `history`.
  -/
  | follow (host : URI.Host) (port : UInt16) (scheme : URI.Scheme) (request : Request Body.AnyBody)

/--
Inspects `response` and decides whether to follow a redirect.

Returns `.done` when:
- `remaining` is 0 or the response is not a redirection,
- the `Location` header is absent, or
- the `Location` value cannot be parsed.

Returns `.follow` with the rewritten request (method, body, and headers adjusted per
RFC 9110 §15.4, including `Authorization` stripped on cross-origin hops) when a valid
redirect target is found. The response body is drained (up to `drainLimit` bytes) before
returning `.follow`; if the body exceeds `drainLimit` the incoming channel is closed and
the connection is left to recover or time out.
-/
def decideRedirect
    (remaining : Nat)
    (currentHost : URI.Host) (currentPort : UInt16) (currentScheme : URI.Scheme)
    (request : Request Body.AnyBody) (response : Response Body.Incoming)
    (drainLimit : Nat)
    : Async RedirectDecision := do

  if remaining == 0 ∨ !response.line.status.isRedirection then
    return .done

  let some locationValue := response.line.headers.get? .location
    | return .done

  let locationStr := locationValue.value

  let some target := RequestTarget.parse? locationStr
    | return .done

  -- Drain
  discard <| ContextAsync.run do
    try
      discard <| response.body.readAll (α := ByteArray) (maximumSize := some drainLimit.toUInt64)
    catch _ =>
      response.body.close

  let newMethod := match response.line.status with
    | .seeOther => .get
    | .movedPermanently | .found =>
        if request.line.method == .post then .get else request.line.method
    | _ => request.line.method

  let bodyIsStreaming := match request.body with | .outgoing _ => true | _ => false

  let newBody : Body.AnyBody :=
    if newMethod == .get || newMethod == .head || newMethod != request.line.method then .empty {}
    else if bodyIsStreaming then .empty {}
    else request.body

  let (newHost, newPort, newScheme) := match target with
    | .absoluteForm af =>
      let h := af.authority.map URI.Authority.host |>.getD currentHost
      let p : UInt16 :=
        match af.authority with
        | some auth => match auth.port with
          | URI.Port.value v => v
          | _ => URI.Scheme.defaultPort af.scheme
        | none => URI.Scheme.defaultPort af.scheme
      (h, p, af.scheme)
    | _ => (currentHost, currentPort, currentScheme)

  -- Avoid SSRF.
  if newScheme.val != "http" && newScheme.val != "https" then
    return .done

  -- Strip Authorization
  let isCrossOrigin := newHost != currentHost || newPort != currentPort || newScheme != currentScheme

  let newHeaders :=
    if isCrossOrigin then
      request.line.headers
        |>.erase Header.Name.authorization
        |>.erase Header.Name.proxyAuthorization
        |>.erase Header.Name.cookie
    else request.line.headers

  return .follow newHost newPort newScheme
    { line := { request.line with uri := target, method := newMethod, headers := newHeaders }
      body := newBody
      extensions := request.extensions }

private partial def sendWithRedirects [Transport α]
    (agent : Agent α) (request : Request Body.AnyBody)
    (remaining : Nat) (retriesLeft : Nat)
    (history : Array (URI.Host × UInt16 × String) := #[]) : Async (Response Body.Incoming) := do

  -- Record the current URL in the history and detect redirect cycles.
  let currentKey := (agent.host, agent.port, toString request.line.uri)
  let history := history.push currentKey

  -- Rewrite to absolute-form when a proxy is configured.
  let request :=
    if agent.session.config.proxy.isSome then
      toAbsoluteFormRequest request agent.scheme agent.host agent.port
    else
      request

  let request ← injectCookies agent.cookieJar agent.host agent.scheme request

  let response ← try agent.session.send request
    catch err => do
      agent.onBrokenSession agent.session agent.host agent.port

      let bodyIsReplayable := match request.body with | .outgoing _ => false | _ => true

      if retriesLeft > 0 && isIdempotentMethod request.line.method && bodyIsReplayable then
        if let some factory := agent.connectTo then
          sleep agent.session.config.retryDelay
          let newSession ← factory agent.host agent.port
          return ← sendWithRedirects { agent with session := newSession } request remaining (retriesLeft - 1) history

      throw err

  let response ← applyInterceptors agent.interceptors response
  processCookies agent.cookieJar agent.host response.line.headers

  match ← decideRedirect remaining agent.host agent.port agent.scheme request response
      agent.session.config.redirectBodyDrainLimit with
  | .done =>
    if let some validate := agent.session.config.validateStatus then
      if !validate response.line.status then
        throw (.userError s!"unexpected HTTP status: {response.line.status.toCode}")
    return response
  | .follow newHost newPort newScheme newRequest =>
    if let some policy := agent.session.config.redirectPolicy then
      if !policy newHost newPort then
        return response

    let nextKey := (newHost, newPort, toString newRequest.line.uri)
    if history.contains nextKey then
      return response

    if newHost != agent.host || newPort != agent.port then

      -- For custom transports without a connectTo factory we cannot open a new
      -- connection to a different host; return the redirect response as-is.
      let some factory := agent.connectTo
        | return response

      let newSession ← factory newHost newPort

      sendWithRedirects
        { session := newSession
          scheme := newScheme
          host := newHost
          port := newPort
          cookieJar := agent.cookieJar
          interceptors := agent.interceptors
          connectTo := some factory
          onBrokenSession := agent.onBrokenSession }
        newRequest (remaining - 1) retriesLeft history
    else
      sendWithRedirects agent newRequest (remaining - 1) retriesLeft history

/--
Send a request, automatically following redirects up to `config.maxRedirects` hops and
retrying on connection errors up to `config.maxRetries` times.
For cross-host redirects the agent reconnects using its `connectTo` factory (if set).
Cookies are automatically injected from the jar and `Set-Cookie` responses are stored.
Response interceptors are applied after every response.
-/
def send {β : Type} [Coe β Body.AnyBody] [Transport α] (agent : Agent α) (request : Request β) : Async (Response Body.Incoming) :=
  sendWithRedirects
    agent
    { line := request.line, body := (request.body : Body.AnyBody), extensions := request.extensions }
    agent.session.config.maxRedirects
    agent.session.config.maxRetries

end Agent

/-!
# Agent.RequestBuilder

A fluent builder that attaches an `Agent` to a `Request.Builder`, letting callers chain header
and query-parameter setters before dispatching with a typed `send*` terminal.

```lean
let response ←
  agent.get "/api/items"
  |>.header! "Accept" "application/json"
  |>.queryParam "page" "2"
  |>.send
```
-/

/--
A `Request.Builder` bound to a specific `Agent`.  Build up headers, query parameters, and body,
then call one of the `send*` methods to dispatch the request.
-/
public structure Agent.RequestBuilder (α : Type) where
  /--
  The agent that will send this request.
  -/
  agent : Agent α

  /--
  The underlying request builder.
  -/
  builder : Request.Builder


namespace Agent.RequestBuilder

/--
Injects a `Host` header derived from the agent's `host` and `port` if no `Host` header
is already present.
-/
private def withHostHeader [Transport α] (rb : Agent.RequestBuilder α) : Agent.RequestBuilder α :=
  if rb.builder.line.headers.contains Header.Name.host then
    rb
  else
    let defaultPort := URI.Scheme.defaultPort rb.agent.scheme
    let hostValue :=
      if rb.agent.port == defaultPort then toString rb.agent.host
      else s!"{rb.agent.host}:{rb.agent.port}"
    { rb with builder := rb.builder.header! "Host" hostValue }

/--
Prepares the builder by injecting the `Host` header, then calls `f` to build and send the
request. Cookie injection is handled by `Agent.injectCookies` inside `sendWithRedirects`.
-/
private def prepare [Transport α] (rb : Agent.RequestBuilder α)
    (f : Agent.RequestBuilder α → Async (Response Body.Incoming)) : Async (Response Body.Incoming) :=
  f rb.withHostHeader

/--
Adds a typed header to the request.
-/
def header [Transport α] (rb : Agent.RequestBuilder α) (key : Header.Name) (value : Header.Value) : Agent.RequestBuilder α :=
  { rb with builder := rb.builder.header key value }

/--
Adds a header to the request. Panics if the name or value is invalid.
-/
def header! [Transport α] (rb : Agent.RequestBuilder α) (key : String) (value : String) : Agent.RequestBuilder α :=
  { rb with builder := rb.builder.header! key value }

/--
Adds a header to the request. Returns `none` if the name or value is invalid.
-/
def header? [Transport α] (rb : Agent.RequestBuilder α) (key : String) (value : String) : Option (Agent.RequestBuilder α) := do
  let builder ← rb.builder.header? key value
  pure { rb with builder }

/--
Sets the request URI from a string. Panics if the string is not a valid request target.
-/
def uri! [Transport α] (rb : Agent.RequestBuilder α) (u : String) : Agent.RequestBuilder α :=
  { rb with builder := rb.builder.uri! u }

/--
Adds a query parameter to the request URI.
Works for both origin-form (e.g. set by `agent.get "/path"`) and absolute-form targets.
-/
def queryParam [Transport α] (rb : Agent.RequestBuilder α) (key : String) (value : String) : Agent.RequestBuilder α :=
  let newTarget := match rb.builder.line.uri with
    | .originForm o =>
        .originForm { o with query := some ((o.query.getD URI.Query.empty).insert key value) }
    | .absoluteForm af =>
        .absoluteForm { af with query := af.query.insert key value }
    | other => other
  { rb with builder := { rb.builder with line := { rb.builder.line with uri := newTarget } } }

/--
Sends the request with an empty body.
-/
def send [Transport α] (rb : Agent.RequestBuilder α) : Async (Response Body.Incoming) :=
  rb.prepare fun rb => do rb.agent.send (← rb.builder.blank)

/--
Sends the request with a plain-text body.
Sets `Content-Type: text/plain; charset=utf-8`.
-/
def text [Transport α] (rb : Agent.RequestBuilder α) (content : String) : Async (Response Body.Incoming) :=
  rb.prepare fun rb => do rb.agent.send (← rb.builder.text content)

/--
Sends the request with a JSON body.
Sets `Content-Type: application/json`.
-/
def json [Transport α] (rb : Agent.RequestBuilder α) (content : String) : Async (Response Body.Incoming) :=
  rb.prepare fun rb => do rb.agent.send (← rb.builder.json content)

/--
Sends the request with a raw binary body.
Sets `Content-Type: application/octet-stream`.
-/
def bytes [Transport α] (rb : Agent.RequestBuilder α) (content : ByteArray) : Async (Response Body.Incoming) :=
  rb.prepare fun rb => do rb.agent.send (← rb.builder.bytes content)

/--
Sends the request with a streaming body produced by `gen`.
-/
def sendStream [Transport α]
    (rb : Agent.RequestBuilder α)
    (gen : Body.Outgoing → Async Unit) : Async (Response Body.Incoming) :=
  rb.prepare fun rb => do rb.agent.send (← rb.builder.stream gen)

end Agent.RequestBuilder

namespace Agent

/--
Creates a GET request builder for the given path or URL
-/
def get [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.get (RequestTarget.parse! path) }

/--
Creates a POST request builder for the given path or URL
-/
def post [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.post (RequestTarget.parse! path) }

/--
Creates a PUT request builder for the given path or URL
-/
def put [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.put (RequestTarget.parse! path) }

/--
Creates a DELETE request builder for the given path or URL
-/
def delete [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.delete (RequestTarget.parse! path) }

/--
Creates a PATCH request builder for the given path or URL
-/
def patch [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.patch (RequestTarget.parse! path) }

/--
Creates a HEAD request builder for the given path or URL
-/
def headReq [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.head (RequestTarget.parse! path) }

/--
Creates an OPTIONS request builder for the given path or URL.
-/
def options [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.options (RequestTarget.parse! path) }

end Std.Http.Client.Agent
