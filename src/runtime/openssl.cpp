/*
Copyright (c) 2026 Lean FRO, LLC. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.
Author: Sofia Rodrigues
*/
#include "runtime/openssl.h"
#include "runtime/io.h"

#include <mutex>

#ifndef LEAN_EMSCRIPTEN
#include <openssl/opensslv.h>
#include <openssl/err.h>
#include <openssl/ssl.h>

namespace lean {

static std::once_flag g_openssl_init_once;

static void initialize_openssl_once() {
    if (OPENSSL_init_ssl(0, nullptr) != 1) {
        lean_internal_panic("failed to initialize OpenSSL");
    }
}

void initialize_openssl() {
    std::call_once(g_openssl_init_once, initialize_openssl_once);
}

void finalize_openssl() {}

}

extern "C" LEAN_EXPORT lean_obj_res lean_openssl_version(lean_obj_arg o) {
    return lean_unsigned_to_nat(OPENSSL_VERSION_NUMBER);
}

#else

namespace lean {

void initialize_openssl() {}
void finalize_openssl() {}

}

extern "C" LEAN_EXPORT lean_obj_res lean_openssl_version(lean_obj_arg o) {
    return lean_box(0);
}

#endif
