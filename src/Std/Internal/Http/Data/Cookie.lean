/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Std.Sync.Mutex
public import Std.Internal.Http.Data.URI
public import Std.Internal.Http.Data.Cookie.Parser
public import Std.Internal.Http.Data.Headers
public import Init.Data.String
public import Init.Data.Array.Basic
public import Init.Data.List.Basic

public section

/-!
# Cookie

This module defines the `Cookie` and `Jar` types, a minimal RFC 6265-compliant
implementation for managing HTTP cookies.

Cookies are parsed from `Set-Cookie` response headers, stored in a thread-safe jar, and
injected as a `Cookie` request header on outgoing requests.

Supported `Set-Cookie` attributes: `Domain`, `Path`, `Secure`.

Unsupported: `Expires`, `Max-Age`, `HttpOnly`, `SameSite`. All cookies persist for the
lifetime of the jar regardless of any expiry directives.

Reference: https://www.rfc-editor.org/rfc/rfc6265
-/

namespace Std.Http

set_option linter.all true

open Internal Char

namespace Cookie

/--
Proposition asserting that a string is a valid cookie name: a non-empty HTTP token.
Cookie names are case-sensitive.

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-4.1.1
-/
abbrev IsValidCookieName (s : String) : Prop :=
  isToken s

/--
A validated HTTP cookie name. Cookie names are case-sensitive HTTP tokens.

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-4.1.1
-/
@[ext]
structure Name where
  /--
  The cookie name string.
  -/
  value : String

  /--
  Proof that the name is a valid HTTP token.
  -/
  isValidCookieName : IsValidCookieName value := by decide
deriving BEq, DecidableEq, Repr

namespace Name

instance : Inhabited Name where
  default := ⟨"_", by decide⟩

/--
Attempts to create a `Cookie.Name` from a `String`, returning `none` if the string is
not a valid HTTP token or is empty.
-/
def ofString? (s : String) : Option Name :=
  let val := s.trimAscii.toString
  if h : IsValidCookieName val then
    some ⟨val, h⟩
  else
    none

/--
Creates a `Cookie.Name` from a string, panicking if the string is not a valid HTTP token.
-/
def ofString! (s : String) : Name :=
  match ofString? s with
  | some res => res
  | none => panic! s!"invalid cookie name: {s.quote}"

instance : ToString Name where
  toString n := n.value

end Name

/--
`cookie-octet = %x21 / %x23-2B / %x2D-3A / %x3C-5B / %x5D-7E`

US-ASCII visible characters excluding SP, DQUOTE, comma, semicolon, and backslash.

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-4.1.1
-/
def isCookieOctet (c : Char) : Bool :=
  c = '!' ∨
  ('#' ≤ c ∧ c ≤ '+') ∨
  ('-' ≤ c ∧ c ≤ ':') ∨
  ('<' ≤ c ∧ c ≤ '[') ∨
  (']' ≤ c ∧ c ≤ '~')

/--
Proposition asserting that a string is a valid cookie value: all characters are
`cookie-octet` characters. Empty values are permitted.

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-4.1.1
-/
abbrev IsValidCookieValue (s : String) : Prop :=
  s.toList.all isCookieOctet

/--
A validated HTTP cookie value. Empty values are permitted.

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-4.1.1
-/
@[ext]
structure Value where
  /--
  The cookie value string.
  -/
  value : String

  /--
  Proof that the value contains only valid cookie-octet characters.
  -/
  isValidCookieValue : IsValidCookieValue value := by decide
deriving BEq, DecidableEq, Repr

namespace Value

instance : Inhabited Value where
  default := ⟨"", by decide⟩

/--
Attempts to create a `Cookie.Value` from a `String`, returning `none` if the string
contains characters not permitted in cookie values.
-/
def ofString? (s : String) : Option Value :=
  let val := s.trimAscii.toString
  if h : IsValidCookieValue val then
    some ⟨val, h⟩
  else
    none

/--
Creates a `Cookie.Value` from a string, panicking if the string contains characters not
permitted in cookie values.
-/
def ofString! (s : String) : Value :=
  match ofString? s with
  | some res => res
  | none => panic! s!"invalid cookie value: {s.quote}"

instance : ToString Value where
  toString v := v.value

end Value

end Cookie

/--
An HTTP cookie with its matching attributes.

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-4.1
-/
structure Cookie where
  /--
  The cookie name.
  -/
  name : Cookie.Name

  /--
  The cookie value.
  -/
  value : Cookie.Value

  /--
  The effective domain for this cookie. When `Set-Cookie` carries no `Domain` attribute this
  equals the origin host and `hostOnly` is `true` — only that exact host will receive the
  cookie. When `Domain` is set, `hostOnly` is `false` and subdomains also match.
  -/
  domain : URI.Host

  /--
  `true` when the cookie must only be sent to the exact origin host (no subdomain matching).
  -/
  hostOnly : Bool

  /--
  Path prefix for which the cookie is valid. Defaults to `"/"`.
  -/
  path : URI.Path

  /--
  When `true` the cookie must only be sent over a secure (HTTPS) channel.
  -/
  secure : Bool

  /--
  When `true` the cookie must not be exposed to non-HTTP APIs.
  Stored for completeness; no client-side script enforcement applies here.
  -/
  httpOnly : Bool

/--
A HTTP cookie jar.

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-5
-/
structure Cookie.Jar where
  private mk ::
  private cookies : Mutex (Array Cookie)

namespace Cookie.Jar

/--
Creates an empty cookie jar.
-/
def new : BaseIO Jar := do
  let cookies ← Mutex.new #[]
  return .mk cookies

/--
Domain matching per RFC 6265 §5.1.3.
-/
private def domainMatches (cookieDomain : URI.Host) (hostOnly : Bool) (host : URI.Host) : Bool :=
  if hostOnly then
    host == cookieDomain
  else
    let d := cookieDomain
    host == d || (toString host).endsWith ("." ++ toString d)

/--
Path matching per RFC 6265 §5.1.4.

A request path matches a cookie path when they are identical, or when the cookie path is a
strict segment-wise prefix of the request path. Segment boundaries correspond to `/`, so
`/foo` never prefix-matches `/foobar` (different segments).

A trailing `/` in the cookie path is normalised away before the prefix test; this covers
both RFC conditions:
- cookie-path ends with `/` → its meaningful segments are a strict prefix of request-path.
- first char after prefix is `/` → satisfied automatically at segment boundaries.
-/
private def pathMatches (cookiePath : URI.Path) (requestPath : URI.Path) : Bool :=
  requestPath == cookiePath ||
  let cp :=
    if cookiePath.hasTrailingSlash && !cookiePath.isEmpty
    then cookiePath.segments.pop
    else cookiePath.segments
  requestPath.segments.size > cp.size &&
  requestPath.startsWith { cookiePath with segments := cp }

/--
Parses a single `Set-Cookie` header value and stores the resulting cookie.
`host` is the origin host of the response (used as the effective domain when no
`Domain` attribute is present).

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-5.2
-/
def processSetCookie (jar : Jar) (host : URI.Host) (headerValue : String) : BaseIO Unit := do
  let .ok parsed := Cookie.Parser.parseSetCookie.run headerValue.toUTF8
    | return ()

  let some cookieName  := Cookie.Name.ofString?  parsed.name
    | return ()

  let some cookieValue := Cookie.Value.ofString? parsed.value
    | return ()

  let cookiePath : URI.Path :=
    if let some p := parsed.path then URI.Path.parseOrRoot p
    else URI.Path.parseOrRoot "/"

  -- RFC 6265 §5.2.3: resolve domain; missing or invalid Domain → host-only
  let (domain, hostOnly) :=
    match parsed.domain with
    | some d =>
      match URI.DomainName.ofString? d with
      | some name => (URI.Host.name name, false)
      | none      => (host, true)
    | none => (host, true)

  -- RFC 6265 §5.3 step 6: if domain attribute is set, the origin host must domain-match it.
  -- This prevents a server at api.example.com from setting Domain=evil.com or Domain=com.
  if !hostOnly && !domainMatches domain false host then
    return ()

  -- RFC 6265 §5.2.2: Max-Age ≤ 0 signals deletion — remove any matching cookie and stop.
  if let some maxAgeVal := parsed.maxAge then
    if maxAgeVal ≤ 0 then
      jar.cookies.atomically do
        let cs ← get
        set (cs.filter fun c => !(c.name == cookieName && c.domain == domain && c.path == cookiePath))
      return ()

  let cookie : Cookie := {
    name := cookieName
    value := cookieValue
    domain
    hostOnly
    path := cookiePath
    secure := parsed.secure
    httpOnly := parsed.httpOnly
  }

  -- Limit the total cookie count to prevent unbounded memory growth.
  -- RFC 6265 §6.1 recommends supporting at least 3000 cookies total.
  let maxCookies := 3000
  jar.cookies.atomically do
    let cs ← get
    let cs := cs.filter fun c => !(c.name == cookie.name && c.domain == cookie.domain && c.path == cookie.path)
    if cs.size < maxCookies then
      set (cs.push cookie)

/--
Returns the `Cookie` header value for all cookies that should be sent for a request to `host`
at `path`. Pass `secure := true` when the request channel is HTTPS. Returns `none` when no
cookies match.

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-5.4
-/
def cookiesFor
    (jar : Jar) (host : URI.Host) (path : URI.Path)
    (secure : Bool := false) : BaseIO (Option Header.Value) :=
  jar.cookies.atomically do
    let cs ← get
    let matching := cs.filter fun c =>
      domainMatches c.domain c.hostOnly host &&
      pathMatches c.path path &&
      (!c.secure || secure)
    if matching.isEmpty then
      return none
    else
      return Header.Value.ofString? (String.intercalate "; " (matching.map (fun c => c.name.value ++ "=" ++ c.value.value)).toList)

end Std.Http.Cookie.Jar
