/-
Copyright (c) 2025 Lean FRO. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Authors: Sebastian Ullrich
-/
module

prelude
public import Lean.Elab.Command
public import Lean.Elab.Tactic.Basic
public import Lean.Elab.Task
public meta import Lean.Elab.Command
public meta import Lean.Elab.Tactic.Basic
public meta import Lean.Elab.Task

public section

/-!
Helpers for testing cancellation in interactive tests. Put here because of `initialize` restrictions
and to avoid repeated elaboration overhead per test.
-/

namespace Lean.Server.Test.Cancel

meta initialize onceRef : IO.Ref (Option (Task Unit)) ← IO.mkRef none

/--
On first invocation, sends a diagnostics "blocked", blocks until cancelled, and then eprints
"cancelled!"; further invocations complete when this wait is done but do not wait for their own
cancellation. Thus all document versions should complete strictly after the printing has completed
and we avoid terminating the server too early to see the message.
-/
scoped syntax "wait_for_cancel_once" : tactic
@[incremental]
elab_rules : tactic
| `(tactic| wait_for_cancel_once) => do
  let prom ← IO.Promise.new
  if let some t := (← onceRef.modifyGet (fun old => (old, old.getD prom.result!))) then
    IO.wait t
    return

  dbg_trace "blocked!"
  log "blocked"
  let ctx ← readThe Elab.Term.Context
  let some tacSnap := ctx.tacSnap? | unreachable!
  tacSnap.new.resolve {
    diagnostics := (← Language.Snapshot.Diagnostics.ofMessageLog (← Core.getMessageLog))
    stx := default
    finished := default
  }

  let ctx ← readThe Core.Context
  let some cancelTk := ctx.cancelTk? | unreachable!
  -- TODO: `CancelToken` should probably use `Promise`
  while true do
    if (← cancelTk.isSet) then
      break
    IO.sleep 30
  IO.eprintln "cancelled!"
  log "cancelled (should never be visible)"
  prom.resolve ()
  Core.checkInterrupted

-- can't use a naked promise in `initialize` as marking it persistent would block
meta initialize unblockedCancelTk : IO.CancelToken ← IO.CancelToken.new

/--
Waits for `unblock` to be called, which is expected to happen in a subsequent document version that
does not invalidate this tactic. Complains if cancellation token was set before unblocking, i.e. if
the tactic was invalidated after all.
-/
scoped syntax "wait_for_unblock" : tactic
@[incremental]
elab_rules : tactic
| `(tactic| wait_for_unblock) => do
  let ctx ← readThe Core.Context
  let some cancelTk := ctx.cancelTk? | unreachable!

  dbg_trace "blocked!"
  log "blocked"
  let ctx ← readThe Elab.Term.Context
  let some tacSnap := ctx.tacSnap? | unreachable!
  tacSnap.new.resolve {
    diagnostics := (← Language.Snapshot.Diagnostics.ofMessageLog (← Core.getMessageLog))
    stx := default
    finished := default
  }

  while true do
    if (← unblockedCancelTk.isSet) then
      break
    IO.sleep 30
  if (← cancelTk.isSet) then
    IO.eprintln "cancelled!"
    log "cancelled (should never be visible)"

/--
Spawns a `logSnapshotTask` that waits for `unblock` to be called, which is expected to happen in a
subsequent document version that does not invalidate this tactic. Complains if cancellation token
was set before unblocking, i.e. if the tactic was invalidated after all.
-/
elab "wait_for_unblock_async" : tactic => do
  let cancelTk ← IO.CancelToken.new
  let act ← Elab.Term.wrapAsyncAsSnapshot (cancelTk? := cancelTk) fun _ => do
    let ctx ← readThe Core.Context
    let some cancelTk := ctx.cancelTk? | unreachable!
    while true do
      if (← unblockedCancelTk.isSet) then
        break
      IO.sleep 30
    if (← cancelTk.isSet) then
      IO.eprintln "cancelled!"
      log "cancelled (should never be visible)"
  let t ← BaseIO.asTask (act ())
  Core.logSnapshotTask { stx? := none, task := t, cancelTk? := cancelTk }

  log "blocked"

/-- Unblocks a `wait_for_unblock*` task. -/
scoped elab "unblock" : tactic => do
  dbg_trace "unblocking!"
  unblockedCancelTk.set

/--
Like `wait_for_cancel_once` but does the waiting in a separate task and waits for its
cancellation.
-/
scoped syntax "wait_for_cancel_once_async" : tactic
@[incremental]
elab_rules : tactic
| `(tactic| wait_for_cancel_once_async) => do
  let prom ← IO.Promise.new
  if let some t := (← onceRef.modifyGet (fun old => (old, old.getD prom.result!))) then
    IO.wait t
    return

  let cancelTk ← IO.CancelToken.new
  let act ← Elab.Term.wrapAsyncAsSnapshot (cancelTk? := cancelTk) fun _ => do
    let ctx ← readThe Core.Context
    let some cancelTk := ctx.cancelTk? | unreachable!
    -- TODO: `CancelToken` should probably use `Promise`
    while true do
      if (← cancelTk.isSet) then
        break
      IO.sleep 30
    IO.eprintln "cancelled!"
    log "cancelled (should never be visible)"
    prom.resolve ()
    Core.checkInterrupted
  let t ← BaseIO.asTask (act ())
  Core.logSnapshotTask { stx? := none, task := t, cancelTk? := cancelTk }

  dbg_trace "blocked!"
  log "blocked"

/--
Like `wait_for_cancel_once_async` but waits for the main thread's cancellation token. This is useful
to test main thread cancellation in non-incremental contexts because we otherwise wouldn't be able
to send out the "blocked" message from there.
-/
scoped syntax "wait_for_main_cancel_once_async" : tactic
@[incremental]
elab_rules : tactic
| `(tactic| wait_for_main_cancel_once_async) => do
  let prom ← IO.Promise.new
  if let some t := (← onceRef.modifyGet (fun old => (old, old.getD prom.result!))) then
    IO.wait t
    return

  let some cancelTk := (← readThe Core.Context).cancelTk? | unreachable!
  let act ← Elab.Term.wrapAsyncAsSnapshot (cancelTk? := none) fun _ => do
    let ctx ← readThe Core.Context
    -- TODO: `CancelToken` should probably use `Promise`
    while true do
      if (← cancelTk.isSet) then
        break
      IO.sleep 30
    IO.eprintln "cancelled!"
    log "cancelled (should never be visible)"
    prom.resolve ()
    Core.checkInterrupted
  let t ← BaseIO.asTask (act ())
  Core.logSnapshotTask { stx? := none, task := t, cancelTk? := cancelTk }

  dbg_trace "blocked!"
  log "blocked"

/-! ## Helpers for testing `asTask` subtask cancellation -/

meta initialize parOnceRef : IO.Ref (Option (Task Unit)) ← IO.mkRef none

/--
Like `wait_for_cancel_once`, but spawns a parallel subtask via `TacticM.asTask'` that waits for
cancellation. This tests whether subtasks spawned via `asTask'` (as used by `TacticM.par` in `try?`)
inherit their parent's cancellation token.

The subtask gets a fresh cancel token from `asTask'` (via `Core.wrapAsync`), so the parent's
cancellation token is NOT propagated. The test expects to see "leaked!" if the bug exists,
or "subtask-cancelled!" if the fix is in place.
-/
scoped syntax "wait_for_cancel_once_par_subtask" : tactic
@[incremental]
elab_rules : tactic
| `(tactic| wait_for_cancel_once_par_subtask) => do
  let prom ← IO.Promise.new
  if let some t := (← parOnceRef.modifyGet (fun old => (old, old.getD prom.result!))) then
    IO.wait t
    return

  -- Send "blocked" diagnostic (like wait_for_cancel_once)
  dbg_trace "blocked!"
  log "blocked"
  let ctx ← readThe Elab.Term.Context
  let some tacSnap := ctx.tacSnap? | unreachable!
  tacSnap.new.resolve {
    diagnostics := (← Language.Snapshot.Diagnostics.ofMessageLog (← Core.getMessageLog))
    stx := default
    finished := default
  }

  -- Now spawn a subtask via asTask' (same mechanism used by TacticM.par in try?)
  -- This subtask gets a FRESH cancel token, disconnected from the server's token
  let subtask ← Elab.Tactic.TacticM.asTask' do
    -- Poll for cancellation (checks the FRESH token, not the server's)
    let mut cancelled := false
    for _ in List.range 100 do -- 100 * 50ms = 5s max
      IO.sleep 50
      let ctx ← readThe Core.Context
      if let some cancelTk := ctx.cancelTk? then
        if (← cancelTk.isSet) then
          cancelled := true
          break
    if cancelled then
      IO.eprintln "subtask-cancelled!"
    else
      IO.eprintln "leaked!"
    prom.resolve ()

  -- Block the main thread waiting for the subtask
  -- The server's cancellation sets the PARENT token, but the main thread is blocked in IO.wait
  -- and can only check checkInterrupted after the subtask completes
  discard <| IO.wait subtask

  -- If we reach here (subtask didn't throw), resolve and check interrupted
  prom.resolve ()
  Core.checkInterrupted

meta initialize cmdOnceRef : IO.Ref (Option (Task Unit)) ← IO.mkRef none

/--
Like `wait_for_main_cancel_once_async` but for commands. Takes a `num` parameter so that its syntax
can be changed (via `change:`) to trigger re-elaboration. Sends "blocked" as a diagnostic and spawns
an async task that waits for the command's cancellation token to be set.
-/
scoped syntax "wait_for_cancel_once_command" num : command
elab_rules : command
| `(command| wait_for_cancel_once_command $_n) => Elab.Command.liftCoreM do
  let prom ← IO.Promise.new
  if let some t := (← cmdOnceRef.modifyGet (fun old => (old, old.getD prom.result!))) then
    IO.wait t
    return
  let some cancelTk := (← read).cancelTk? | unreachable!
  let act ← Core.wrapAsyncAsSnapshot (cancelTk? := none) fun _ => do
    while true do
      if (← cancelTk.isSet) then
        break
      IO.sleep 30
    IO.eprintln "cancelled!"
    logInfo "cancelled (should never be visible)"
    prom.resolve ()
    Core.checkInterrupted
  let t ← BaseIO.asTask (act ())
  (Core.logSnapshotTask { stx? := none, task := t, cancelTk? := cancelTk })
  logInfo "blocked"
