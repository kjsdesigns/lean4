/-
Copyright (c) 2025 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Std.Internal.Http.Client.Pool

public section

namespace Std
namespace Http
namespace Client

set_option linter.all true

open Std Internal IO Async TCP Protocol
open Time

/-!
# Client

A top-level HTTP client backed by a connection pool, similar to `reqwest::Client`.
Use `Client.builder` to construct, then `client.get "https://..."` etc.

```lean
let client ← Client.builder
  |>.proxy! "http://proxy.example.com:8080"
  |>.build

let res ← client.get "https://api.example.com/data"
  |>.header! "Accept" "application/json"
  |>.send
```
-/

/--
A top-level HTTP client backed by a connection pool.
-/
abbrev Client := Agent.Pool

/--
Builder for `Client`. Chain configuration setters then call `.build`.
-/
public structure Client.Builder where
  /-- Configuration applied to all sessions created by this client. -/
  config : Config := {}
  /-- Maximum number of pooled connections per host. -/
  maxPerHost : Nat := 4

namespace Client.Builder

/--
Routes all connections through a proxy.
`host` is the proxy hostname, `port` is the proxy port.
Only HTTP proxies are supported.
-/
def proxy (b : Client.Builder) (host : String) (port : UInt16) : Client.Builder :=
  { b with config := { b.config with proxy := some (host, port) } }

/--
Routes all connections through a proxy specified as a URL string.
Returns `none` if the URL is invalid or has no authority component.
-/
def proxy? (b : Client.Builder) (url : String) : Option Client.Builder := do
  let uri ← URI.parse? url
  let auth ← uri.authority
  let host := toString auth.host
  let defaultPort : UInt16 := if uri.scheme.val == "https" then 443 else 80
  let port : UInt16 := match auth.port with
    | .value p => p
    | _ => defaultPort
  pure { b with config := { b.config with proxy := some (host, port) } }

/--
Sets the total request timeout (connect + send + receive).
-/
def timeout (b : Client.Builder) (ms : Time.Millisecond.Offset) : Client.Builder :=
  if h : 0 < ms then
    { b with config := { b.config with requestTimeout := ⟨ms, h⟩ } }
  else b

/--
Sets the `User-Agent` header sent with every request.
-/
def userAgent (b : Client.Builder) (ua : String) : Client.Builder :=
  { b with config := { b.config with userAgent := Header.Value.ofString? ua } }

/--
Sets the maximum number of pooled connections per host.
-/
def maxConnectionsPerHost (b : Client.Builder) (n : Nat) : Client.Builder :=
  { b with maxPerHost := n }

/--
Sets the maximum number of redirects to follow automatically.
-/
def maxRedirects (b : Client.Builder) (n : Nat) : Client.Builder :=
  { b with config := { b.config with maxRedirects := n } }

/--
Sets the predicate that decides whether a response status is acceptable.
When set, the final response status is passed to `f`; if `f` returns `false`
an `IO.Error` is thrown with the numeric status code.
-/
def validateStatus (b : Client.Builder) (f : Status → Bool) : Client.Builder :=
  { b with config := { b.config with validateStatus := some f } }

/--
Builds the `Client`.
-/
def build (b : Client.Builder) : Async Client := do
  Agent.Pool.new b.config b.maxPerHost

end Client.Builder

/--
A request builder bound to a `Client`. Build up headers, query parameters, and body,
then dispatch with one of the `send*` methods.
-/
public structure Client.RequestBuilder where
  /--
  The client that will dispatch this request.
  -/
  client : Client
  /--
  Resolved hostname for this request.
  -/
  host : URI.Host
  /--
  Target port.
  -/
  port : UInt16
  /--
  The underlying request builder.
  -/
  builder : Request.Builder

namespace Client.RequestBuilder

/--
Injects a `Host` header if not already present.
-/
private def withHostHeader (rb : Client.RequestBuilder) : Client.RequestBuilder :=
  if rb.builder.line.headers.contains Header.Name.host then rb
  else
    -- Use the scheme derived from the port to pick the correct default.
    let scheme := URI.Scheme.ofPort rb.port
    let defaultPort := URI.Scheme.defaultPort scheme
    let hostValue :=
      if rb.port == defaultPort then toString rb.host
      else s!"{rb.host}:{rb.port}"
    { rb with builder := rb.builder.header! "Host" hostValue }

/--
Adds a typed header to the request.
-/
def header (rb : Client.RequestBuilder) (key : Header.Name) (value : Header.Value) : Client.RequestBuilder :=
  { rb with builder := rb.builder.header key value }

/--
Adds a header to the request. Panics if the name or value is invalid.
-/
def header! (rb : Client.RequestBuilder) (key : String) (value : String) : Client.RequestBuilder :=
  { rb with builder := rb.builder.header! key value }

/--
Adds a header to the request. Returns `none` if the name or value is invalid.
-/
def header? (rb : Client.RequestBuilder) (key : String) (value : String) : Option Client.RequestBuilder := do
  let builder ← rb.builder.header? key value
  pure { rb with builder }

/--
Sets the request URI from a string. Panics if the string is not a valid request target.
-/
def uri! (rb : Client.RequestBuilder) (u : String) : Client.RequestBuilder :=
  { rb with builder := rb.builder.uri! u }

/--
Adds a query parameter to the request URI.
-/
def queryParam (rb : Client.RequestBuilder) (key : String) (value : String) : Client.RequestBuilder :=
  let newTarget := match rb.builder.line.uri with
    | .originForm o =>
        .originForm { o with query := some ((o.query.getD URI.Query.empty).insert key value) }
    | .absoluteForm af =>
        .absoluteForm { af with uri := { af.uri with query := af.uri.query.insert key value } }
    | other => other
  { rb with builder := { rb.builder with line := { rb.builder.line with uri := newTarget } } }

/--
Sends the request with an empty body.
-/
def send (rb : Client.RequestBuilder) : Async (Response Body.Incoming) := do
  let rb := rb.withHostHeader
  rb.client.send rb.host rb.port (← rb.builder.blank)

/--
Sends the request with a plain-text body. Sets `Content-Type: text/plain; charset=utf-8`.
-/
def text (rb : Client.RequestBuilder) (content : String) : Async (Response Body.Incoming) := do
  let rb := rb.withHostHeader
  rb.client.send rb.host rb.port (← rb.builder.text content)

/--
Sends the request with a JSON body. Sets `Content-Type: application/json`.
-/
def json (rb : Client.RequestBuilder) (content : String) : Async (Response Body.Incoming) := do
  let rb := rb.withHostHeader
  rb.client.send rb.host rb.port (← rb.builder.json content)

/--
Sends the request with a raw binary body. Sets `Content-Type: application/octet-stream`.
-/
def bytes (rb : Client.RequestBuilder) (content : ByteArray) : Async (Response Body.Incoming) := do
  let rb := rb.withHostHeader
  rb.client.send rb.host rb.port (← rb.builder.bytes content)

/--
Sends the request with a streaming body produced by `gen`.
-/
def sendStream (rb : Client.RequestBuilder) (gen : Body.Outgoing → Async Unit) : Async (Response Body.Incoming) := do
  let rb := rb.withHostHeader
  rb.client.send rb.host rb.port (← rb.builder.stream gen)

end Client.RequestBuilder

/--
Returns a `Client.Builder` with default configuration.
-/
def builder : Client.Builder := {}

/--
Parses `url` into `(host, port, origin-form target)`.
Returns `none` if the URL is invalid or has no authority component.
-/
private def mkRequest
    (method : Request.Builder → Request.Builder)
    (client : Client) (url : URI.AuthorityForm) : Client.RequestBuilder :=
  let target : RequestTarget :=
    .originForm (RequestTarget.OriginForm.mk url.path (if url.query.isEmpty then none else some url.query))
  { client, host := url.host, port := url.port,
    builder := method (Request.new |>.uri target) }

/--
Creates a GET request builder for `url`.
-/
def get (client : Client) (url : URI.AuthorityForm) : Client.RequestBuilder :=
  mkRequest (·.method .get) client url

/--
Creates a POST request builder for `url`.
-/
def post (client : Client) (url : URI.AuthorityForm) : Client.RequestBuilder :=
  mkRequest (·.method .post) client url

/--
Creates a PUT request builder for `url`.
-/
def put (client : Client) (url : URI.AuthorityForm) : Client.RequestBuilder :=
  mkRequest (·.method .put) client url

/--
Creates a DELETE request builder for `url`.
-/
def delete (client : Client) (url : URI.AuthorityForm) : Client.RequestBuilder :=
  mkRequest (·.method .delete) client url

/--
Creates a PATCH request builder for `url`.
-/
def patch (client : Client) (url : URI.AuthorityForm) : Client.RequestBuilder :=
  mkRequest (·.method .patch) client url

/--
Creates a HEAD request builder for `url`.
-/
def head (client : Client) (url : URI.AuthorityForm) : Client.RequestBuilder :=
  mkRequest (·.method .head) client url

/--
Creates an OPTIONS request builder for `url`.
-/
def options (client : Client) (url : URI.AuthorityForm) : Client.RequestBuilder :=
  mkRequest (·.method .options) client url

end Client
end Http
end Std
