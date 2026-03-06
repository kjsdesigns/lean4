import Lean.Runtime

-- Non-emscripten build: expect the major version of OpenSSL (3)
/-- info: 3 -/
#guard_msgs in
#eval if !System.Platform.isEmscripten then Lean.openSSLVersion >>> 28 else 3

-- Emscripten build: expect 0
/-- info: 0 -/
#guard_msgs in
#eval if System.Platform.isEmscripten then Lean.openSSLVersion >>> 28 else 0
