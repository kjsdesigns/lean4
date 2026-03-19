/-
Copyright (c) 2025 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Std.Internal.Async
public import Std.Internal.Http.Data
public import Std.Internal.Async.ContextAsync

public section

namespace Std.Http.Server

open Std.Internal.IO.Async

set_option linter.all true

/--
A type class for handling HTTP server requests. Implement this class to define how the server
responds to incoming requests, failures, and `Expect: 100-continue` headers.
-/
class Handler (σ : Type) where
  /--
  Concrete body type produced by `onRequest`.
  Defaults to `Body.Any`, but handlers may override it with any reader/writer-compatible body.
  -/
  ResponseBody : Type := Body.Any

  /--
  Body instance required by the connection loop for receiving response chunks.
  -/
  [responseBodyInstance : Body ResponseBody]

  /--
  Called for each incoming HTTP request.
  -/
  onRequest (self : σ) (request : Request Body.Incoming) : ContextAsync (Response ResponseBody)

  /--
  Called when an I/O or transport error occurs while processing a request (e.g. broken socket,
  handler exception). This is a **notification only**: the connection will close regardless of
  the handler's response. Use this for logging and metrics. The default implementation does nothing.
  -/
  onFailure (self : σ) (error : IO.Error) : Async Unit :=
    pure ()

  /--
  Called when a request includes an `Expect: 100-continue` header. Return `true` to send a
  `100 Continue` response and accept the body. If `false` is returned the server sends
  `417 Expectation Failed`, disables keep-alive, and closes the request body reader.
  This function is guarded by `Config.lingeringTimeout` and may be cancelled on server shutdown.
  The default implementation always returns `true`.
  -/
  onContinue (self : σ) (request : Request.Head) : Async Bool :=
    pure true

end Std.Http.Server
