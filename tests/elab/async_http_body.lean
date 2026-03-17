import Std.Internal.Http.Data.Body

open Std.Internal.IO Async
open Std.Http
open Std.Http.Body

/-! ## Channel tests -/

-- Test send and recv on channel

def channelSendRecv : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel
  let chunk := Chunk.ofByteArray "hello".toUTF8

  let sendTask ← async (t := AsyncTask) <| outgoing.send chunk
  let result ← incoming.recv

  assert! result.isSome
  assert! result.get!.data == "hello".toUTF8
  await sendTask

#eval channelSendRecv.block


-- Test tryRecv on empty channel returns none

def channelTryRecvEmpty : Async Unit := do
  let (_outgoing, incoming) ← Body.mkChannel
  let result ← incoming.tryRecv
  assert! result.isNone

#eval channelTryRecvEmpty.block

-- Test tryRecv consumes a waiting producer

def channelTryRecvWithPendingSend : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel

  let sendTask ← async (t := AsyncTask) <| outgoing.send (Chunk.ofByteArray "data".toUTF8)
  let mut result := none
  let mut fuel := 100
  while result.isNone && fuel > 0 do
    result ← incoming.tryRecv
    if result.isNone then
      let _ ← Selectable.one #[
        .case (← Selector.sleep 1) pure
      ]
    fuel := fuel - 1

  assert! result.isSome
  assert! result.get!.data == "data".toUTF8
  await sendTask

#eval channelTryRecvWithPendingSend.block

-- Test close sets closed flag

def channelClose : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel
  assert! !(← outgoing.isClosed)
  outgoing.close
  assert! (← incoming.isClosed)

#eval channelClose.block

-- Test recv on closed channel returns none

def channelRecvAfterClose : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel
  outgoing.close
  let result ← incoming.recv
  assert! result.isNone

#eval channelRecvAfterClose.block

-- Test for-in iteration collects chunks until close

def channelForIn : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel

  let producer ← async (t := AsyncTask) <| do
    outgoing.send (Chunk.ofByteArray "a".toUTF8)
    outgoing.send (Chunk.ofByteArray "b".toUTF8)
    outgoing.close

  let mut acc : ByteArray := .empty
  for chunk in incoming do
    acc := acc ++ chunk.data

  assert! acc == "ab".toUTF8
  await producer

#eval channelForIn.block

-- Test chunk extensions are preserved

def channelExtensions : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel
  let chunk := { data := "hello".toUTF8, extensions := #[(.mk "key", some (Chunk.ExtensionValue.ofString! "value"))] : Chunk }

  let sendTask ← async (t := AsyncTask) <| outgoing.send chunk
  let result ← incoming.recv

  assert! result.isSome
  assert! result.get!.extensions.size == 1
  assert! result.get!.extensions[0]! == (Chunk.ExtensionName.mk "key", some <| .ofString! "value")
  await sendTask

#eval channelExtensions.block

-- Test known size metadata

def channelKnownSize : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel
  outgoing.setKnownSize (some (.fixed 100))
  let size ← incoming.getKnownSize
  assert! size == some (.fixed 100)

#eval channelKnownSize.block

-- Test known size decreases when a chunk is consumed

def channelKnownSizeDecreases : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel
  outgoing.setKnownSize (some (.fixed 5))

  let sendTask ← async (t := AsyncTask) <| outgoing.send (Chunk.ofByteArray "hello".toUTF8)
  let _ ← incoming.recv
  await sendTask

  let size ← incoming.getKnownSize
  assert! size == some (.fixed 0)

#eval channelKnownSizeDecreases.block

-- Test only one blocked producer is allowed

def channelSingleProducerRule : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel
  let send1 ← async (t := AsyncTask) <| outgoing.send (Chunk.ofByteArray "one".toUTF8)

  -- Yield so `send1` can occupy the single pending-producer slot.
  let _ ← Selectable.one #[
    .case (← Selector.sleep 5) pure
  ]

  let send2Failed ←
    try
      outgoing.send (Chunk.ofByteArray "two".toUTF8)
      pure false
    catch _ =>
      pure true
  assert! send2Failed

  let first ← incoming.recv
  assert! first.isSome
  assert! first.get!.data == "one".toUTF8

  await send1

#eval channelSingleProducerRule.block

-- Test only one blocked consumer is allowed

def channelSingleConsumerRule : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel

  let recv1 ← async (t := AsyncTask) <| incoming.recv

  let hasInterest ← Selectable.one #[
    .case outgoing.interestSelector pure
  ]
  assert! hasInterest

  let recv2Failed ←
    try
      let _ ← incoming.recv
      pure false
    catch _ =>
      pure true

  assert! recv2Failed

  let sendTask ← async (t := AsyncTask) <| outgoing.send (Chunk.ofByteArray "ok".toUTF8)
  let r1 ← await recv1

  assert! r1.isSome
  assert! r1.get!.data == "ok".toUTF8
  await sendTask

#eval channelSingleConsumerRule.block

-- Test hasInterest reflects blocked receiver state

def channelHasInterest : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel
  assert! !(← outgoing.hasInterest)

  let recvTask ← async (t := AsyncTask) <| incoming.recv

  let hasInterest ← Selectable.one #[
    .case outgoing.interestSelector pure
  ]
  assert! hasInterest
  assert! (← outgoing.hasInterest)

  let sendTask ← async (t := AsyncTask) <| outgoing.send (Chunk.ofByteArray "x".toUTF8)
  let _ ← await recvTask
  await sendTask

  assert! !(← outgoing.hasInterest)

#eval channelHasInterest.block

-- Test interestSelector resolves false when channel closes first

def channelInterestSelectorClose : Async Unit := do
  let (outgoing, _incoming) ← Body.mkChannel

  let waitInterest ← async (t := AsyncTask) <|
    Selectable.one #[
      .case outgoing.interestSelector pure
    ]

  outgoing.close
  let interested ← await waitInterest
  assert! interested == false

#eval channelInterestSelectorClose.block

-- Test incomplete sends are buffered and merged into one chunk on the final send

def channelIncompleteChunks : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel

  let sendTask ← async (t := AsyncTask) <| do
    outgoing.send (Chunk.ofByteArray "hel".toUTF8) (incomplete := true)
    outgoing.send (Chunk.ofByteArray "lo".toUTF8)

  let result ← incoming.recv

  assert! result.isSome
  assert! result.get!.data == "hello".toUTF8
  await sendTask

#eval channelIncompleteChunks.block

-- Test sending to a closed channel raises an error

def channelSendAfterClose : Async Unit := do
  let (outgoing, _incoming) ← Body.mkChannel
  outgoing.close

  let failed ←
    try
      outgoing.send (Chunk.ofByteArray "test".toUTF8)
      pure false
    catch _ =>
      pure true
  assert! failed

#eval channelSendAfterClose.block

-- Test Body.stream runs producer and returns the receive handle

def channelStreamHelper : Async Unit := do
  let incoming ← Body.stream fun outgoing => do
    outgoing.send (Chunk.ofByteArray "hello".toUTF8)

  let result ← incoming.recv
  assert! result.isSome
  assert! result.get!.data == "hello".toUTF8

  let eof ← incoming.recv
  assert! eof.isNone

#eval channelStreamHelper.block

-- Test Body.fromBytes creates an Incoming with correct known-size metadata

def channelFromBytesHelper : Async Unit := do
  let incoming ← Body.fromBytes "world".toUTF8

  let size ← incoming.getKnownSize
  assert! size == some (.fixed 5)

  let result ← incoming.recv
  assert! result.isSome
  assert! result.get!.data == "world".toUTF8

#eval channelFromBytesHelper.block

-- Test Body.empty creates an already-closed Incoming

def channelEmptyHelper : Async Unit := do
  let incoming ← Body.empty
  assert! (← incoming.isClosed)

  let result ← incoming.recv
  assert! result.isNone

#eval channelEmptyHelper.block

-- Test Incoming.readAll concatenates all chunks

def channelReadAll : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel

  let sendTask ← async (t := AsyncTask) <| do
    outgoing.send (Chunk.ofByteArray "foo".toUTF8)
    outgoing.send (Chunk.ofByteArray "bar".toUTF8)
    outgoing.close

  let result : ByteArray ← incoming.readAll
  assert! result == "foobar".toUTF8
  await sendTask

#eval channelReadAll.block

-- Test Incoming.readAll enforces a maximum size limit

def channelReadAllMaxSize : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel

  let sendTask ← async (t := AsyncTask) <| do
    outgoing.send (Chunk.ofByteArray "abcdefgh".toUTF8)
    outgoing.close

  let failed ←
    try
      let _ : ByteArray ← incoming.readAll (maximumSize := some 4)
      pure false
    catch _ =>
      pure true
  assert! failed
  await sendTask

#eval channelReadAllMaxSize.block

-- Test Outgoing.getKnownSize reflects the value set via setKnownSize

def channelOutgoingKnownSize : Async Unit := do
  let (outgoing, _incoming) ← Body.mkChannel
  outgoing.setKnownSize (some (.fixed 42))

  let size ← outgoing.getKnownSize
  assert! size == some (.fixed 42)

#eval channelOutgoingKnownSize.block

/-! ## Full tests -/

-- Test Full.recv returns content once then EOF

def fullRecvConsumesOnce : Async Unit := do
  let full ← Body.Full.ofString "hello"
  let first ← full.recv
  let second ← full.recv

  assert! first.isSome
  assert! first.get!.data == "hello".toUTF8
  assert! second.isNone

#eval fullRecvConsumesOnce.block

-- Test Full known-size metadata tracks consumption

def fullKnownSizeLifecycle : Async Unit := do
  let data := ByteArray.mk #[0x01, 0x02, 0x03, 0x04]
  let full ← Body.Full.ofByteArray data

  assert! (← full.getKnownSize) == some (.fixed 4)
  let chunk ← full.tryRecv
  assert! chunk.isSome
  assert! chunk.get!.data == data
  assert! (← full.getKnownSize) == some (.fixed 0)

#eval fullKnownSizeLifecycle.block

-- Test Full.close discards remaining content

def fullClose : Async Unit := do
  let full ← Body.Full.ofString "bye"
  assert! !(← full.isClosed)
  full.close
  assert! (← full.isClosed)
  assert! (← full.tryRecv).isNone

#eval fullClose.block

-- Test Full from an empty ByteArray returns none on the first recv

def fullEmptyBytes : Async Unit := do
  let full ← Body.Full.ofByteArray ByteArray.empty
  let result ← full.recv
  assert! result.isNone

#eval fullEmptyBytes.block

-- Test Full.recvSelector resolves immediately with the stored chunk

def fullRecvSelectorResolves : Async Unit := do
  let full ← Body.Full.ofString "world"
  let result ← Selectable.one #[
    .case full.recvSelector pure
  ]
  assert! result.isSome
  assert! result.get!.data == "world".toUTF8

#eval fullRecvSelectorResolves.block

-- Test Full.getKnownSize returns 0 after close

def fullKnownSizeAfterClose : Async Unit := do
  let full ← Body.Full.ofString "data"
  assert! (← full.getKnownSize) == some (.fixed 4)
  full.close
  assert! (← full.getKnownSize) == some (.fixed 0)

#eval fullKnownSizeAfterClose.block

-- Test Full.tryRecv succeeds once and returns none thereafter

def fullTryRecvIdempotent : Async Unit := do
  let full ← Body.Full.ofString "once"
  let first ← full.tryRecv
  let second ← full.tryRecv
  assert! first.isSome
  assert! first.get!.data == "once".toUTF8
  assert! second.isNone

#eval fullTryRecvIdempotent.block

/-! ## Empty tests -/

-- Test Empty.recv always returns none

def emptyBodyRecv : Async Unit := do
  let body : Body.Empty := {}
  let result ← body.recv
  assert! result.isNone

#eval emptyBodyRecv.block

-- Test Empty.isClosed is always true

def emptyBodyIsClosed : Async Unit := do
  let body : Body.Empty := {}
  assert! (← body.isClosed)

#eval emptyBodyIsClosed.block

-- Test Empty.close is a no-op: still closed and recv still returns none

def emptyBodyClose : Async Unit := do
  let body : Body.Empty := {}
  body.close
  assert! (← body.isClosed)
  let result ← body.recv
  assert! result.isNone

#eval emptyBodyClose.block

-- Test Empty.recvSelector resolves immediately with none

def emptyBodyRecvSelector : Async Unit := do
  let body : Body.Empty := {}
  let result ← Selectable.one #[
    .case body.recvSelector pure
  ]
  assert! result.isNone

#eval emptyBodyRecvSelector.block

/-! ## Any tests -/

-- Test Any wrapping a Full body forwards recv correctly

def anyFromFull : Async Unit := do
  let full ← Body.Full.ofString "hello"
  let any : Body.Any := full
  let result ← any.recv
  assert! result.isSome
  assert! result.get!.data == "hello".toUTF8

#eval anyFromFull.block

-- Test Any wrapping an Empty body returns none and reports closed

def anyFromEmpty : Async Unit := do
  let empty : Body.Empty := {}
  let any : Body.Any := empty
  let result ← any.recv
  assert! result.isNone
  assert! (← any.isClosed)

#eval anyFromEmpty.block

-- Test Any wrapping an Incoming channel receives chunks

def anyFromChannel : Async Unit := do
  let (outgoing, incoming) ← Body.mkChannel
  let any := Body.Any.ofBody incoming

  let sendTask ← async (t := AsyncTask) <| outgoing.send (Chunk.ofByteArray "data".toUTF8)
  let result ← any.recv
  assert! result.isSome
  assert! result.get!.data == "data".toUTF8
  await sendTask

#eval anyFromChannel.block

-- Test Any.close closes the underlying body

def anyCloseForwards : Async Unit := do
  let full ← Body.Full.ofString "test"
  let any : Body.Any := full
  any.close
  assert! (← any.isClosed)
  let result ← any.recv
  assert! result.isNone

#eval anyCloseForwards.block

-- Test Any.recvSelector resolves immediately for a Full body

def anyRecvSelectorFromFull : Async Unit := do
  let full ← Body.Full.ofString "sel"
  let any : Body.Any := full
  let result ← Selectable.one #[
    .case any.recvSelector pure
  ]
  assert! result.isSome
  assert! result.get!.data == "sel".toUTF8

#eval anyRecvSelectorFromFull.block

/-! ## Request.Builder body tests -/

private def recvBuiltBody (body : Body.Full) : Async (Option Chunk) :=
  body.recv

-- Test Request.Builder.text sets correct headers

def requestBuilderText : Async Unit := do
  let req ← Request.post (.originForm! "/api")
    |>.text "Hello, World!"

  assert! req.line.headers.get? Header.Name.contentType == some (Header.Value.ofString! "text/plain; charset=utf-8")
  assert! req.line.headers.get? Header.Name.contentLength == none

  let body ← recvBuiltBody req.body
  assert! body.isSome
  assert! body.get!.data == "Hello, World!".toUTF8

#eval requestBuilderText.block

-- Test Request.Builder.json sets correct headers

def requestBuilderJson : Async Unit := do
  let req ← Request.post (.originForm! "/api")
    |>.json "{\"key\": \"value\"}"

  assert! req.line.headers.get? Header.Name.contentType == some (Header.Value.ofString! "application/json")
  assert! req.line.headers.get? Header.Name.contentLength == none
  let body ← recvBuiltBody req.body
  assert! body.isSome
  assert! body.get!.data == "{\"key\": \"value\"}".toUTF8

#eval requestBuilderJson.block

-- Test Request.Builder.fromBytes sets body

def requestBuilderFromBytes : Async Unit := do
  let data := ByteArray.mk #[0x01, 0x02, 0x03]
  let req ← Request.post (.originForm! "/api")
    |>.fromBytes data

  assert! req.line.headers.get? Header.Name.contentLength == none
  let body ← recvBuiltBody req.body
  assert! body.isSome
  assert! body.get!.data == data

#eval requestBuilderFromBytes.block

-- Test Request.Builder.noBody creates empty body

def requestBuilderNoBody : Async Unit := do
  let req ← Request.get (.originForm! "/api")
    |>.noBody

  assert! req.body == {}

#eval requestBuilderNoBody.block

-- Test Request.Builder.bytes sets application/octet-stream content type

def requestBuilderBytes : Async Unit := do
  let data := ByteArray.mk #[0xde, 0xad, 0xbe, 0xef]
  let req ← Request.post (.originForm! "/api")
    |>.bytes data

  assert! req.line.headers.get? Header.Name.contentType == some (Header.Value.ofString! "application/octet-stream")
  let body ← recvBuiltBody req.body
  assert! body.isSome
  assert! body.get!.data == data

#eval requestBuilderBytes.block

-- Test Request.Builder.html sets text/html content type

def requestBuilderHtml : Async Unit := do
  let req ← Request.post (.originForm! "/api")
    |>.html "<h1>Hello</h1>"

  assert! req.line.headers.get? Header.Name.contentType == some (Header.Value.ofString! "text/html; charset=utf-8")
  let body ← recvBuiltBody req.body
  assert! body.isSome
  assert! body.get!.data == "<h1>Hello</h1>".toUTF8

#eval requestBuilderHtml.block

-- Test Request.Builder.stream creates a streaming body

def requestBuilderStream : Async Unit := do
  let req ← Request.post (.originForm! "/api")
    |>.stream fun outgoing => do
      outgoing.send (Chunk.ofByteArray "streamed".toUTF8)

  let result ← req.body.recv
  assert! result.isSome
  assert! result.get!.data == "streamed".toUTF8

#eval requestBuilderStream.block

-- Test Request.Builder.noBody body is always closed and returns none

def requestBuilderNoBodyAlwaysClosed : Async Unit := do
  let req ← Request.get (.originForm! "/api")
    |>.noBody

  assert! (← req.body.isClosed)
  let result ← req.body.recv
  assert! result.isNone

#eval requestBuilderNoBodyAlwaysClosed.block

/-! ## Response.Builder body tests -/

-- Test Response.Builder.text sets correct headers

def responseBuilderText : Async Unit := do
  let res ← Response.ok
    |>.text "Hello, World!"

  assert! res.line.headers.get? Header.Name.contentType == some (Header.Value.ofString! "text/plain; charset=utf-8")
  assert! res.line.headers.get? Header.Name.contentLength == none

  let body ← recvBuiltBody res.body
  assert! body.isSome
  assert! body.get!.data == "Hello, World!".toUTF8

#eval responseBuilderText.block

-- Test Response.Builder.json sets correct headers

def responseBuilderJson : Async Unit := do
  let res ← Response.ok
    |>.json "{\"status\": \"ok\"}"

  assert! res.line.headers.get? Header.Name.contentType == some (Header.Value.ofString! "application/json")
  assert! res.line.headers.get? Header.Name.contentLength == none
  let body ← recvBuiltBody res.body
  assert! body.isSome
  assert! body.get!.data == "{\"status\": \"ok\"}".toUTF8

#eval responseBuilderJson.block

-- Test Response.Builder.fromBytes sets body

def responseBuilderFromBytes : Async Unit := do
  let data := ByteArray.mk #[0xaa, 0xbb]
  let res ← Response.ok
    |>.fromBytes data

  assert! res.line.headers.get? Header.Name.contentLength == none
  let body ← recvBuiltBody res.body
  assert! body.isSome
  assert! body.get!.data == data

#eval responseBuilderFromBytes.block

-- Test Response.Builder.noBody creates empty body

def responseBuilderNoBody : Async Unit := do
  let res ← Response.ok
    |>.noBody

  assert! res.body == {}

#eval responseBuilderNoBody.block

-- Test Response.Builder.bytes sets application/octet-stream content type

def responseBuilderBytes : Async Unit := do
  let data := ByteArray.mk #[0xca, 0xfe]
  let res ← Response.ok
    |>.bytes data

  assert! res.line.headers.get? Header.Name.contentType == some (Header.Value.ofString! "application/octet-stream")
  let body ← recvBuiltBody res.body
  assert! body.isSome
  assert! body.get!.data == data

#eval responseBuilderBytes.block

-- Test Response.Builder.html sets text/html content type

def responseBuilderHtml : Async Unit := do
  let res ← Response.ok
    |>.html "<p>OK</p>"

  assert! res.line.headers.get? Header.Name.contentType == some (Header.Value.ofString! "text/html; charset=utf-8")
  let body ← recvBuiltBody res.body
  assert! body.isSome
  assert! body.get!.data == "<p>OK</p>".toUTF8

#eval responseBuilderHtml.block

-- Test Response.Builder.stream creates a streaming body

def responseBuilderStream : Async Unit := do
  let res ← Response.ok
    |>.stream fun outgoing => do
      outgoing.send (Chunk.ofByteArray "streamed".toUTF8)

  let result ← res.body.recv
  assert! result.isSome
  assert! result.get!.data == "streamed".toUTF8

#eval responseBuilderStream.block

-- Test Response.Builder.noBody body is always closed and returns none

def responseBuilderNoBodyAlwaysClosed : Async Unit := do
  let res ← Response.ok
    |>.noBody

  assert! (← res.body.isClosed)
  let result ← res.body.recv
  assert! result.isNone

#eval responseBuilderNoBodyAlwaysClosed.block
