/-
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Std.Sync.Mutex
public import Std.Internal.Http.Data.URI
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
A thread-safe HTTP cookie jar.

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
-/
private def pathMatches (cookiePath : URI.Path) (requestPath : String) : Bool :=
  let s := toString cookiePath
  requestPath == s ||
  (requestPath.startsWith s &&
   (s.endsWith "/" || requestPath.startsWith (s ++ "/")))

/--
Splits `s` at the first occurrence of `sep`, returning `(before, after)`.
Returns `(s, "")` when `sep` does not appear in `s`.
-/
private def splitFirst (s : String) (sep : String) : String × String :=
  match s.splitOn sep with
  | [] | [_] => (s, "")
  | first :: rest => (first, String.intercalate sep rest)

/--
Attempts to parse a host string into a `URI.Host`, trying IPv4, bracketed IPv6, and
domain name forms in order.
-/
private def parseHostStr (s : String) : Option URI.Host :=
  if let some ip := Net.IPv4Addr.ofString s then
    some (.ipv4 ip)
  else if s.startsWith "[" && s.endsWith "]" && s.length > 2 then
    let inner := s.dropEnd 1 |>.drop 1 |>.toString
    (Net.IPv6Addr.ofString inner).map .ipv6
  else
    (URI.DomainName.ofString? s).map .name

/--
Parses a single `Set-Cookie` header value and stores the resulting cookie.
`host` is the origin host of the response (used as the effective domain when no
`Domain` attribute is present).

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-5.2
-/
def processSetCookie (jar : Jar) (host : URI.Host) (headerValue : String) : BaseIO Unit := do
  let rawParts := (headerValue.splitOn ";").map String.trimAscii

  let some rawNameValue := rawParts[0]?
    | return ()

  let (rawName, rawValue) := splitFirst rawNameValue.toString "="

  let some cookieName := Cookie.Name.ofString? rawName | return ()
  let some cookieValue := Cookie.Value.ofString? rawValue | return ()

  let mut cookieDomain : Option URI.Host := none
  let mut cookiePath : URI.Path := URI.Path.parseOrRoot "/"
  let mut secure := false

  for attr in rawParts.drop 1 do
    let (attrName, attrVal) := splitFirst attr.toString "="
    match attrName.trimAscii.toString.toLower with
    | "domain" =>
      let d := if attrVal.startsWith "." then attrVal.drop 1 else attrVal
      let d := d.trimAscii.toString
      if !d.isEmpty then
        cookieDomain := (URI.DomainName.ofString? d).map URI.Host.name
    | "path" =>
      let p := attrVal.trimAscii.toString
      if !p.isEmpty then cookiePath := URI.Path.parseOrRoot p
    | "secure" => secure := true
    | _ => pure ()

  let (domain, hostOnly) ← match cookieDomain with
    | some d => pure (d, false)
    | none => pure (host, true)

  let cookie : Cookie := { name := cookieName, value := cookieValue, domain, hostOnly, path := cookiePath, secure }

  jar.cookies.atomically do
    let cs ← get
    let cs := cs.filter fun c =>
      !(c.name == cookie.name && c.domain == cookie.domain && c.path == cookie.path)
    set (cs.push cookie)

/--
Returns all cookies that should be sent for a request to `host` at `path`.
Pass `secure := true` when the request channel is HTTPS.

Reference: https://www.rfc-editor.org/rfc/rfc6265#section-5.4
-/
def cookiesFor
    (jar : Jar) (host : URI.Host) (path : String)
    (secure : Bool := false) : BaseIO (Array Cookie) :=
  jar.cookies.atomically do
    let cs ← get
    return cs.filter fun c =>
      domainMatches c.domain c.hostOnly host &&
      pathMatches c.path path &&
      (!c.secure || secure)

/--
Formats an array of cookies into a `Cookie` header value string.
Returns `none` when the array is empty.
-/
def toCookieHeader (cookies : Array Cookie) : Option String :=
  if cookies.isEmpty then
    none
  else
    some (String.intercalate "; " (cookies.map (fun c => c.name.value ++ "=" ++ c.value.value)).toList)

end Std.Http.Cookie.Jar
