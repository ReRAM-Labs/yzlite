// This is an autogenerated config file, any changes to this file will be
// overwritten

#ifndef MBEDTLS_CONFIG_AUTOGEN_H
#define MBEDTLS_CONFIG_AUTOGEN_H

#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_PLATFORM_CALLOC_MACRO sl_calloc
#define MBEDTLS_PLATFORM_FREE_MACRO sl_free
#define MBEDTLS_PSA_CRYPTO_C
#define MBEDTLS_USE_PSA_CRYPTO
#define MBEDTLS_CIPHER_C
#define MBEDTLS_PSA_CRYPTO_CONFIG
#define MBEDTLS_PSA_CRYPTO_DRIVERS
#define MBEDTLS_PSA_CRYPTO_STORAGE_C

#if defined(SL_TRUSTZONE_NONSECURE)

#endif // #if defined(SL_TRUSTZONE_NONSECURE)

#if defined(SL_TRUSTZONE_SECURE)

#endif // #if defined(SL_TRUSTZONE_SECURE)

#include "config-device-acceleration.h"

// By default MBEDTLS_PLATFORM_CALLOC_MACRO and MBEDTLS_PLATFORM_FREE_MACRO are
// defined in mbedtls_platform_dynamic_memory_allocation_config_default.slcc.
// Alternative implementations can configure MBEDTLS_PLATFORM_CALLOC_MACRO and
// MBEDTLS_PLATFORM_FREE_MACRO to use other platform specific implementations.
// Alternatively some use cases may select runtime initialisation in the
// application by explicitly calling mbedtls_platform_set_calloc_free() by
// selecting mbedtls_platform_dynamic_memory_allocation_config_init_runtime.

#if defined(MBEDTLS_PLATFORM_CALLOC_MACRO) &&                                  \
    defined(MBEDTLS_PLATFORM_FREE_MACRO)
#include <stddef.h> // size_t
extern void *MBEDTLS_PLATFORM_CALLOC_MACRO(size_t n, size_t size);
extern void MBEDTLS_PLATFORM_FREE_MACRO(void *ptr);
#endif

#endif
