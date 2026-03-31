import Lean.Server.Test.Cancel
open Lean.Server.Test.Cancel

/-!
Test that subtasks spawned via `TacticM.asTask'` (as used by `TacticM.par` in `try?`)
are cancelled when the parent command is cancelled.

The `wait_for_cancel_once_par_subtask` tactic:
1. Sends "blocked" diagnostic
2. Spawns a subtask via `asTask'` that polls its cancel token for 5 seconds
3. Blocks the main thread waiting for the subtask

When the edit invalidates this declaration, the server sets the command's cancel token.
But the subtask has a FRESH cancel token (from `asTask'`/`Core.wrapAsync`), so:
- BUG: the subtask runs for the full 5 seconds and prints "leaked!"
- FIX: the subtask detects cancellation and terminates early
-/

example : True := by
  trivial
       --^ waitFor: blocked
       --^ insert: "; skip"
       --^ collectDiagnostics

theorem t : True := by
  wait_for_cancel_once_par_subtask
  trivial
