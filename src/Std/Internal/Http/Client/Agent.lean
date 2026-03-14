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
  URIs visited in the current redirect chain, used to detect cycles.
  -/
  redirectHistory : Array URI

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

namespace Agent

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
    let pathStr := toString o.path
    let queryStr := match o.query with | none => "" | some q => toString q
    let portStr := if port == URI.Scheme.defaultPort scheme then "" else s!":{port}"
    let urlStr := s!"{scheme}://{host}{portStr}{pathStr}{queryStr}"
    match RequestTarget.parse? urlStr with
    | some target => { request with line := { request.line with uri := target } }
    | none => request
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
  pure { session, scheme, host, port, redirectHistory := #[], cookieJar, connectTo }

/--
Injects matching cookies from `cookieJar` into the request headers for `host`.
Does nothing if the jar contains no matching cookies.
-/
def injectCookies (cookieJar : Cookie.Jar) (host : URI.Host)
    (request : Request Body.AnyBody) : Async (Request Body.AnyBody) := do
  let path := match request.line.uri with
    | .originForm o   => toString o.path
    | .absoluteForm af => toString af.path
    | _ => "/"
  let cookies ← cookieJar.cookiesFor host path
  match Cookie.Jar.toCookieHeader cookies with
  | none => return request
  | some cookieValue =>
    let newHeaders :=
      request.line.headers.insert Header.Name.cookie (Header.Value.ofString! cookieValue)
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
  /-- Follow a redirect to `(host, port, scheme)` with `request`, updating `history`. -/
  | follow (host : URI.Host) (port : UInt16) (scheme : URI.Scheme)
           (request : Request Body.AnyBody) (history : Array URI)

/--
Inspects `response` and decides whether to follow a redirect.

Returns `.done` when:
- `remaining` is 0 or the response is not a redirection,
- the `Location` header is absent,
- a redirect cycle is detected, or
- the `Location` value cannot be parsed.

Returns `.follow` with the rewritten request (method, body, and headers adjusted per
RFC 9110 §15.4, including `Authorization` stripped on cross-origin hops) when a valid
redirect target is found. The response body is drained before returning `.follow`.
-/
def decideRedirect
    (remaining : Nat) (history : Array URI)
    (currentHost : URI.Host) (currentPort : UInt16) (currentScheme : URI.Scheme)
    (request : Request Body.AnyBody) (response : Response Body.Incoming)
    : Async RedirectDecision := do
  if remaining == 0 || !response.line.status.isRedirection then
    return .done

  let some locationValue := response.line.headers.get? Header.Name.location
    | return .done

  let locationStr := locationValue.value
  let locationURI := URI.parse? locationStr

  discard <| ContextAsync.run (response.body.readAll (α := ByteArray))

  if let some uri := locationURI then
    if history.contains uri then return .done

  let some target := RequestTarget.parse? locationStr
    | return .done

  let newMethod := match response.line.status with
    | .seeOther => .get
    | .movedPermanently | .found =>
        if request.line.method == .post then .get else request.line.method
    | _ => request.line.method

  let newBody : Body.AnyBody :=
    if newMethod == .get || newMethod == .head || newMethod != request.line.method then
      .empty {}
    else
      request.body

  let newHistory := match locationURI with
    | some uri => history.push uri
    | none     => history

  let (newHost, newPort, newScheme) := match locationURI with
    | some uri =>
      if let some auth := uri.authority then
        let h := auth.host
        let p : UInt16 := match auth.port with
          | .value p => p
          | _        => URI.Scheme.defaultPort uri.scheme
        (h, p, uri.scheme)
      else (currentHost, currentPort, currentScheme)
    | none => (currentHost, currentPort, currentScheme)

  -- Strip Authorization on cross-origin redirects to prevent credential leakage (RFC 9110 §15.4).
  let crossOrigin := newHost != currentHost || newPort != currentPort
  let newHeaders :=
    if crossOrigin then request.line.headers.erase Header.Name.authorization
    else request.line.headers

  return .follow newHost newPort newScheme
    { line := { request.line with uri := target, method := newMethod, headers := newHeaders }
      body := newBody
      extensions := request.extensions }
    newHistory

private partial def sendWithRedirects [Transport α]
    (agent : Agent α) (request : Request Body.AnyBody)
    (remaining : Nat) (retriesLeft : Nat) : Async (Response Body.Incoming) := do
  -- Rewrite to absolute-form when a proxy is configured.
  let request :=
    if agent.session.config.proxy.isSome then
      toAbsoluteFormRequest request agent.scheme agent.host agent.port
    else
      request

  let request ← injectCookies agent.cookieJar agent.host request

  let response ← try agent.session.send request
    catch err => do
      -- Connection error: retry with a fresh session if budget and factory allow.
      if retriesLeft > 0 then
        if let some factory := agent.connectTo then
          sleep agent.session.config.retryDelay
          let newSession ← factory agent.host agent.port
          return ← sendWithRedirects { agent with session := newSession } request remaining (retriesLeft - 1)
      throw err

  let response ← applyInterceptors agent.interceptors response
  processCookies agent.cookieJar agent.host response.line.headers

  match ← decideRedirect remaining agent.redirectHistory agent.host agent.port agent.scheme request response with
  | .done =>
    if let some validate := agent.session.config.validateStatus then
      if !validate response.line.status then
        throw (.userError s!"unexpected HTTP status: {response.line.status.toCode}")
    return response
  | .follow newHost newPort newScheme newRequest newHistory =>
    if newHost != agent.host || newPort != agent.port then
      -- For custom transports without a connectTo factory we cannot open a new
      -- connection to a different host; return the redirect response as-is.
      let some factory := agent.connectTo | return response
      let _ ← agent.session.close
      let newSession ← factory newHost newPort
      let response ← sendWithRedirects
        { session        := newSession
          scheme         := newScheme
          host           := newHost
          port           := newPort
          redirectHistory := newHistory
          cookieJar      := agent.cookieJar
          interceptors   := agent.interceptors
          connectTo      := some factory }
        newRequest (remaining - 1) retriesLeft
      -- Close the cross-host session: signals the background loop to shut down after
      -- the response body is consumed (safe because the channel is only polled once
      -- the current response is fully delivered and waitingForRequest becomes true).
      let _ ← newSession.close
      return response
    else
      sendWithRedirects { agent with redirectHistory := newHistory } newRequest (remaining - 1) retriesLeft

/--
Send a request, automatically following redirects up to `config.maxRedirects` hops and
retrying on connection errors up to `config.maxRetries` times.
For cross-host redirects the agent reconnects using its `connectTo` factory (if set).
Cookies are automatically injected from the jar and `Set-Cookie` responses are stored.
Response interceptors are applied after every response.
-/
def send {β : Type} [Coe β Body.AnyBody] [Transport α]
    (agent : Agent α) (request : Request β) : Async (Response Body.Incoming) :=
  sendWithRedirects agent
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
Injects matching cookies from the agent's jar if no `Cookie` header is already present.
-/
private def withCookies [Transport α] (rb : Agent.RequestBuilder α) : Async (Agent.RequestBuilder α) := do
  if rb.builder.line.headers.contains Header.Name.cookie then
    return rb
  let path := match rb.builder.line.uri with
    | .originForm o   => toString o.path
    | .absoluteForm af => toString af.path
    | _ => "/"
  let cookies ← rb.agent.cookieJar.cookiesFor rb.agent.host path
  match Cookie.Jar.toCookieHeader cookies with
  | none => return rb
  | some cookieValue =>
    return { rb with builder := rb.builder.header! "Cookie" cookieValue }

/--
Prepares the builder by injecting Host and Cookie headers, then calls `f` to build
and send the request.
-/
private def prepare [Transport α] (rb : Agent.RequestBuilder α)
    (f : Agent.RequestBuilder α → Async (Response Body.Incoming)) : Async (Response Body.Incoming) := do
  let rb := rb.withHostHeader
  let rb ← rb.withCookies
  f rb

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

/-- Creates a GET request builder for the given path or URL. -/
def get [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.get (RequestTarget.parse! path) }

/-- Creates a POST request builder for the given path or URL. -/
def post [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.post (RequestTarget.parse! path) }

/-- Creates a PUT request builder for the given path or URL. -/
def put [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.put (RequestTarget.parse! path) }

/-- Creates a DELETE request builder for the given path or URL. -/
def delete [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.delete (RequestTarget.parse! path) }

/-- Creates a PATCH request builder for the given path or URL. -/
def patch [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.patch (RequestTarget.parse! path) }

/-- Creates a HEAD request builder for the given path or URL. -/
def headReq [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.head (RequestTarget.parse! path) }

/-- Creates an OPTIONS request builder for the given path or URL. -/
def options [Transport α] (agent : Agent α) (path : String) : Agent.RequestBuilder α :=
  { agent, builder := Request.options (RequestTarget.parse! path) }

end Agent

end Client
end Http
end Std
