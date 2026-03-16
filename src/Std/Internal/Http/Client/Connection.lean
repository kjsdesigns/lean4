/-
Copyright (c) 2025 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Authors: Sofia Rodrigues
-/
module

prelude
public import Std.Internal.Async.TCP
public import Std.Internal.Async.ContextAsync
public import Std.Internal.Http.Transport
public import Std.Internal.Http.Protocol.H1
public import Std.Internal.Http.Client.Config
public import Std.Sync.Watch

public section

namespace Std.Http.Client

open Std Internal IO Async TCP Protocol
open Time

/--
Type-erased body operations for use in the request pipeline.
Captures `Reader` and `Writer` methods as closures so the connection state
is not parameterized by the body type.
-/
structure Body.Operations where
  /--
  Selector that resolves when a chunk is available or the body reaches EOF.
  -/
  recvSelector : Selector (Option Chunk)

  /--
  Returns `true` when the body is closed for reading.
  -/
  isClosed : Async Bool

  /--
  Closes the body for reading.
  -/
  close : Async Unit

  /--
  Returns the known content length if available.
  -/
  getKnownSize : Async (Option Body.Length)

namespace Body.Operations

/--
Creates a `Body.Operations` from any type with `Body.Reader` and `Body.Writer` instances.
-/
def of [Body.Reader β] [Body.Writer β] (body : β) : Body.Operations where
  recvSelector := Body.Reader.recvSelector body
  isClosed := Body.Reader.isClosed body
  close := Body.Reader.close body
  getKnownSize := Body.Writer.getKnownSize body

end Body.Operations

/-!
# Connection

This module defines the `Connection.handle` loop, used to manage one persistent HTTP/1.1 client
connection and handle sequential request/response exchanges over it.
-/

set_option linter.all true

/--
A request packet queued to the background connection loop.
-/
structure RequestPacket where
  /--
  The request to send.
  -/
  request : Request Body.Operations

  /--
  Promise resolved with the eventual response.
  -/
  responsePromise : IO.Promise (Except Error (Response Body.Incoming))

  /--
  Watch channel updated with the cumulative number of request-body bytes sent.
  `none` when the caller does not need upload-progress tracking.
  -/
  uploadProgress : Option (Watch UInt64) := none

  /--
  Watch channel updated with the cumulative number of response bytes received.
  `none` when the caller does not need download-progress tracking.
  -/
  downloadProgress : Option (Watch UInt64) := none

namespace RequestPacket

/--
Resolve the packet with an error.
-/
def onError (packet : RequestPacket) (error : Error) : BaseIO Unit :=
  discard <| packet.responsePromise.resolve (.error error)

/--
Resolve the packet with a response.
-/
def onResponse (packet : RequestPacket) (response : Response Body.Incoming) : BaseIO Unit :=
  discard <| packet.responsePromise.resolve (.ok response)

end RequestPacket

namespace Connection

/--
Events produced by the async select loop in `pollNextEvent`.
Each variant corresponds to one possible outcome of waiting for I/O.
-/
private inductive Recv
  | bytes (x : Option ByteArray)
  | requestBody (x : Option Chunk)
  | bodyInterest (x : Bool)
  | packet (x : Option RequestPacket)
  | timeout
  | shutdown
  | close

/--
The set of I/O sources to wait on during a single poll iteration.
Each `Option` field is `none` when that source is not currently active.
-/
private structure PollSources (α : Type) where
  socket : Option α
  expect : Option Nat
  requestBody : Option Body.Operations
  requestChannel : Option (Std.CloseableChannel RequestPacket)
  responseBody : Option Body.Outgoing
  timeout : Millisecond.Offset
  keepAliveTimeout : Option Millisecond.Offset
  connectionContext : CancellationContext

/--
All mutable state carried through the connection processing loop.
Bundled into a struct so it can be passed to and returned from helper functions.
-/
private structure ConnectionState where
  machine : H1.Machine .sending
  currentTimeout : Millisecond.Offset
  keepAliveTimeout : Option Millisecond.Offset
  currentRequest : Option RequestPacket
  requestBody : Option Body.Operations
  responseOutgoing : Option Body.Outgoing
  responseIncoming : Option Body.Incoming
  requiresData : Bool
  expectData : Option Nat
  waitingForRequest : Bool
  isInformationalResponse : Bool
  waitingForContinue : Bool
  pendingRequestBody : Option Body.Operations
  uploadProgress : Option (Watch UInt64) := none
  uploadBytes : UInt64 := 0
  downloadProgress : Option (Watch UInt64) := none
  downloadBytes : UInt64 := 0
  downloadBodyBytes : UInt64 := 0

@[inline]
private def requestHasExpectContinue (request : Request Body.Operations) : Bool :=
  match request.line.headers.getAll? Header.Name.expect with
  | some #[value] =>
      match Header.Expect.parse value with
      | some res => res.expect
      | none => false
  | _ => false

/--
Waits for the next I/O event across all active sources described by `sources`.
Computes the socket recv size from `config`, then races all active selectables.
Returns `.close` on transport errors.
-/
private def pollNextEvent
    [Transport α]
    (config : Config) (sources : PollSources α) : Async Recv := do

  let expectedBytes := sources.expect
    |>.getD config.defaultRequestBufferSize
    |>.min config.maxRecvChunkSize
    |>.toUInt64

  let mut selectables : Array (Selectable Recv) := #[
    .case sources.connectionContext.doneSelector (fun _ => do
      let reason ← sources.connectionContext.getCancellationReason
      match reason with
      | some .deadline => pure .timeout
      | _ => pure .shutdown)
  ]

  if let some socket := sources.socket then
    selectables := selectables.push (.case (Transport.recvSelector socket expectedBytes) (Recv.bytes · |> pure))

    if let some keepAliveTimeout := sources.keepAliveTimeout then
      selectables := selectables.push (.case (← Selector.sleep keepAliveTimeout) (fun _ => pure .timeout))
    else
      selectables := selectables.push (.case (← Selector.sleep sources.timeout) (fun _ => pure .timeout))

  if let some requestBody := sources.requestBody then
    selectables := selectables.push (.case requestBody.recvSelector (Recv.requestBody · |> pure))

  if let some requestChannel := sources.requestChannel then
    selectables := selectables.push (.case requestChannel.recvSelector (Recv.packet · |> pure))

  if let some responseBody := sources.responseBody then
    selectables := selectables.push (.case (Body.Writer.interestSelector responseBody) (Recv.bodyInterest · |> pure))

  try Selectable.one selectables catch _ => pure .close

/--
Processes all H1 events from a single machine step, updating the connection state.
Handles keep-alive resets, body-size tracking, `Expect: 100-continue`, and parse errors.
Returns the updated state and `true` if a parse failure was encountered.
-/
private def processH1Events
    (config : Config)
    (events : Array (H1.Event .sending))
    (state : ConnectionState) : Async (ConnectionState × Bool) := do

  let mut st := state
  let mut sawFailure := false

  for event in events do
    match event with
    | .needMoreData expect =>
      st := { st with requiresData := true, expectData := expect }

    -- `.needAnswer` is emitted by processWrite when the writer is in `waitingHeaders`
    -- state in `.sending` mode, signalling that the client machine needs the next request.
    -- The client loop tracks this through `waitingForRequest` instead, so this event
    -- is intentionally a no-op here.
    | .needAnswer => pure ()

    | .endHeaders head =>
      if head.status.isInformational then
        -- Informational (1xx) responses are interim; do not resolve the caller's
        -- promise. The machine loops back to read the real response.
        st := { st with isInformationalResponse := true }

        -- A `100 Continue` response authorises the body: move it from the
        -- pending slot into `requestBody` so the pump loop starts sending.
        if head.status == .continue && st.waitingForContinue then
          st := { st with
            requestBody := st.pendingRequestBody
            pendingRequestBody := none
            waitingForContinue := false
          }
      else
        st := { st with
          isInformationalResponse := false
          currentTimeout := config.readTimeout
          keepAliveTimeout := none
        }

        -- A non-informational response while we were still waiting for
        -- `100 Continue`: the server rejected (or bypassed) the expectation.
        -- Discard the pending body — it must not be sent.
        if st.waitingForContinue then
          if let some body := st.pendingRequestBody then
            if !(← body.isClosed) then body.close
          st := { st with pendingRequestBody := none, waitingForContinue := false }

        if let some body := st.responseOutgoing then
          if let some length := head.getSize true then
            Body.Writer.setKnownSize body (some length)

        if let some packet := st.currentRequest then
          if let some incoming := st.responseIncoming then
            packet.onResponse { line := head, body := incoming }

    | .closeBody =>
      -- Skip closing for informational (1xx) responses; the channel stays
      -- open for the real response body that follows.
      if !st.isInformationalResponse then
        if let some body := st.responseOutgoing then
          if ¬(← Body.Writer.isClosed body) then Body.Writer.close body

    | .next =>
      -- Reset all per-request state for the next pipelined request.
      if let some body := st.requestBody then
        if ¬(← body.isClosed) then body.close

      if let some body := st.pendingRequestBody then
        if ¬(← body.isClosed) then body.close

      if let some body := st.responseOutgoing then
        if ¬(← Body.Writer.isClosed body) then Body.Writer.close body

      if let some w := st.uploadProgress then Watch.close w
      if let some w := st.downloadProgress then Watch.close w

      st := { st with
        requestBody := none
        pendingRequestBody := none
        waitingForContinue := false
        responseOutgoing := none
        responseIncoming := none
        currentRequest := none
        isInformationalResponse := false
        waitingForRequest := true
        keepAliveTimeout := some config.keepAliveTimeout.val
        currentTimeout := config.keepAliveTimeout.val
        uploadProgress := none
        uploadBytes := 0
        downloadProgress := none
        downloadBytes := 0
        downloadBodyBytes := 0
      }

    | .failed err =>
      if let some packet := st.currentRequest then
        packet.onError (.userError (toString err))
      sawFailure := true

    | .«continue» => pure ()

    | .close => pure ()

  return (st, sawFailure)

/--
Computes the active `PollSources` for the current connection state.
Determines which I/O sources need attention and whether to include the socket.
-/
private def buildPollSources
    [Transport α]
    (socket : α) (requestChannel : Std.CloseableChannel RequestPacket)
    (connectionContext : CancellationContext) (state : ConnectionState)
    : Async (PollSources α) := do
  let requestBodySource ←
    if let some body := state.requestBody then
      if ¬(← body.isClosed) then pure (some body) else pure none
    else
      pure none

  let responseBodySource ←
    if state.machine.canPullBodyNow then
      if let some body := state.responseOutgoing then
        if ¬(← Body.Writer.isClosed body) then pure (some body) else pure none
      else
        pure none
    else
      pure none

  let pollSocket :=
    state.requiresData ∨
    state.machine.writer.sentMessage ∨
    !state.waitingForRequest ∨
    requestBodySource.isSome ∨
    state.machine.canPullBody

  return {
    socket := if pollSocket then some socket else none
    expect := state.expectData
    requestBody := requestBodySource
    requestChannel := if state.waitingForRequest then some requestChannel else none
    responseBody := responseBodySource
    timeout := state.currentTimeout
    keepAliveTimeout := state.keepAliveTimeout
    connectionContext := connectionContext
  }

/--
Processes a single async I/O event and updates the connection state.
Returns the updated state and `true` if the connection should be closed immediately.
-/
private def handleRecvEvent
    (config : Config)
    (event : Recv) (state : ConnectionState) : Async (ConnectionState × Bool) := do

  match event with
  | .bytes (some bytes) =>
    let newDownloadBytes := state.downloadBytes + bytes.size.toUInt64
    if let some w := state.downloadProgress then
      Watch.send w newDownloadBytes
    return ({ state with machine := state.machine.feed bytes, downloadBytes := newDownloadBytes }, false)

  | .bytes none =>
    return ({ state with machine := state.machine.noMoreInput }, false)

  | .requestBody (some chunk) =>
    let newUploadBytes := state.uploadBytes + chunk.data.size.toUInt64
    if let some w := state.uploadProgress then
      Watch.send w newUploadBytes
    return ({ state with machine := state.machine.sendData #[chunk], uploadBytes := newUploadBytes }, false)

  | .requestBody none =>
    if let some body := state.requestBody then
      if ¬(← body.isClosed) then body.close
    return ({ state with machine := state.machine.userClosedBody, requestBody := none }, false)

  | .bodyInterest interested =>
    if interested then
      let (newMachine, pulledChunk) := state.machine.pullBody
      let mut st := { state with machine := newMachine }

      if let some pulled := pulledChunk then
        let newBodyBytes := st.downloadBodyBytes + pulled.chunk.data.size.toUInt64
        st := { st with downloadBodyBytes := newBodyBytes }

        -- Enforce the response body size limit before writing data to the caller.
        if let some maxSize := config.maxResponseBodySize then
          if newBodyBytes > maxSize.toUInt64 then
            if let some packet := st.currentRequest then
              packet.onError (.userError "response body exceeds maximum allowed size")
            if let some body := st.responseOutgoing then
              if ¬(← Body.Writer.isClosed body) then Body.Writer.close body
            if let some w := st.downloadProgress then Watch.close w
            return ({ st with
              machine := st.machine.closeWriter.closeReader.noMoreInput
              currentRequest := none
              responseOutgoing := none
              downloadProgress := none
            }, false)

        if let some body := st.responseOutgoing then
          -- If the caller has dropped/closed the incoming side, the write fails.
          -- Silently swallowing the error is correct: the loop must continue pulling
          -- wire bytes to keep the connection in a valid state for reuse.
          try Body.Writer.send body pulled.chunk pulled.incomplete
          catch _ => pure ()

          if pulled.final then
            if ¬(← Body.Writer.isClosed body) then Body.Writer.close body
            st := { st with responseOutgoing := none }

      return (st, false)
    else
      return (state, false)

  | .packet (some packet) =>
    let mut machine := state.machine.send packet.request.line
    let mut requestBody : Option Body.Operations := none
    let mut pendingRequestBody : Option Body.Operations := none
    let mut waitingForContinue := false

    if requestHasExpectContinue packet.request then
      -- Defer body pumping until the server sends `100 Continue`, but still
      -- set the known size so that `Content-Length` is included in the request
      -- headers (required by RFC 9112; servers need it to fire checkContinue).
      if let some size ← packet.request.body.getKnownSize then
        machine := machine.setKnownSize size
      waitingForContinue := true
      pendingRequestBody := some packet.request.body
    else
      if let some size ← packet.request.body.getKnownSize then
        machine := machine.setKnownSize size
      requestBody := some packet.request.body

    let (responseOutgoing, responseIncoming) ← Body.mkChannel

    return ({ state with
      machine := machine
      currentRequest := some packet
      waitingForRequest := false
      currentTimeout := config.requestTimeout.val
      keepAliveTimeout := none
      requestBody := requestBody
      pendingRequestBody := pendingRequestBody
      waitingForContinue := waitingForContinue
      responseOutgoing := some responseOutgoing
      responseIncoming := some responseIncoming
      uploadProgress := packet.uploadProgress
      uploadBytes := 0
      downloadProgress := packet.downloadProgress
      downloadBytes := 0
    }, false)

  | .packet none => return (state, true)

  | .close => return (state, true)

  | .timeout =>
    if let some packet := state.currentRequest then
      packet.onError (.userError "request timeout")
    if let some body := state.responseOutgoing then
      if ¬(← Body.Writer.isClosed body) then Body.Writer.close body
    if let some w := state.uploadProgress then Watch.close w
    if let some w := state.downloadProgress then Watch.close w
    return ({ state with
      machine := state.machine.closeWriter.closeReader.noMoreInput
      currentRequest := none
      responseOutgoing := none
      uploadProgress := none
      downloadProgress := none
    }, false)

  | .shutdown =>
    if let some packet := state.currentRequest then
      packet.onError (.userError "connection shutdown")
    if let some body := state.responseOutgoing then
      if ¬(← Body.Writer.isClosed body) then Body.Writer.close body
    if let some w := state.uploadProgress then Watch.close w
    if let some w := state.downloadProgress then Watch.close w
    return ({ state with
      machine := state.machine.closeWriter.closeReader.noMoreInput
      currentRequest := none
      responseOutgoing := none
      uploadProgress := none
      downloadProgress := none
    }, false)

/--
Runs the main request/response processing loop for a single connection.
Drives the HTTP/1.1 state machine through four phases each iteration:
close finished readers, send buffered output, process H1 events, poll for I/O.
-/
protected def handle
    [Transport α]
    (socket : α)
    (machine : H1.Machine .sending)
    (config : Config)
    (connectionContext : CancellationContext)
    (requestChannel : Std.CloseableChannel RequestPacket) : Async Unit := do

  let mut state : ConnectionState := {
    machine := machine
    currentTimeout := config.keepAliveTimeout.val
    keepAliveTimeout := some config.keepAliveTimeout.val
    currentRequest := none
    requestBody := none
    responseOutgoing := none
    responseIncoming := none
    requiresData := false
    expectData := none
    waitingForRequest := true
    isInformationalResponse := false
    waitingForContinue := false
    pendingRequestBody := none
  }

  while ¬state.machine.halted do

    -- Phase 1: close any reader that the user has signalled is done.
    if let some body := state.requestBody then
      if ← body.isClosed then
        state := { state with machine := state.machine.userClosedBody, requestBody := none }

    -- Phase 2: advance the state machine and flush any output.
    let (newMachine, step) := state.machine.step
    state := { state with machine := newMachine }

    if step.output.size > 0 then
      try Transport.sendAll socket #[step.output.toByteArray]
      catch _ =>
        if let some packet := state.currentRequest then
          packet.onError (.userError "connection write failed")
        if let some body := state.responseOutgoing then
          if ¬(← Body.Writer.isClosed body) then Body.Writer.close body
        state := { state with
          machine := state.machine.closeWriter.closeReader.noMoreInput
          currentRequest := none
          responseOutgoing := none
        }
        break

    -- Phase 3: process all events emitted by this step.
    let (newState, sawFailure) ← processH1Events config step.events state
    state := newState
    if sawFailure then break

    -- Phase 4: wait for the next IO event when any source needs attention.
    if state.requiresData ∨ state.waitingForRequest ∨ state.currentRequest.isSome ∨ state.requestBody.isSome ∨ state.machine.canPullBody then
      let sources ← buildPollSources socket requestChannel connectionContext state
      state := { state with requiresData := false }
      let event ← pollNextEvent config sources
      let (newState, shouldClose) ← handleRecvEvent config event state
      state := newState
      if shouldClose then break

  -- Clean up: notify any in-flight request and close all open streams.
  if let some packet := state.currentRequest then
    packet.onError (.userError "connection closed")

  if let some w := state.uploadProgress then
    Watch.close w

  if let some w := state.downloadProgress then
    Watch.close w

  if let some body := state.responseOutgoing then
    if ¬(← Body.Writer.isClosed body) then Body.Writer.close body

  if let some body := state.requestBody then
    if ¬(← body.isClosed) then body.close

  if let some body := state.pendingRequestBody then
    if ¬(← body.isClosed) then body.close

  discard <| EIO.toBaseIO requestChannel.close

  -- Drain any remaining queued packets.
  repeat do
    match ← requestChannel.tryRecv with
    | some packet => packet.onError (.userError "connection closed")
    | none => break

  Transport.close socket

end Connection

end Std.Http.Client
