
#ifndef MBEDTLS_VERSION_H
#define MBEDTLS_VERSION_H

#include "mbedtls/build_info.h"

#if defined(MBEDTLS_VERSION_C)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get the version number.
 *
 * \return          The constructed version number in the format
 *                  MMNNPP00 (Major, Minor, Patch).
 */
unsigned int mbedtls_version_get_number( void );

/**
 * Get the version string ("x.y.z").
 *
 * \param string    The string that will receive the value.
 *                  (Should be at least 9 bytes in size)
 */
void mbedtls_version_get_string( char *string );

/**
 * Get the full version string ("mbed TLS x.y.z").
 *
 * \param string    The string that will receive the value. The mbed TLS version
 *                  string will use 18 bytes AT MOST including a terminating
 *                  null byte.
 *                  (So the buffer should be at least 18 bytes to receive this
 *                  version string).
 */
void mbedtls_version_get_string_full( char *string );

/**
 * \brief           Check if support for a feature was compiled into this
 *                  mbed TLS binary. This allows you to see at runtime if the
 *                  library was for instance compiled with or without
 *                  Multi-threading support.
 *
 * \note            only checks against defines in the sections "System
 *                  support", "mbed TLS modules" and "mbed TLS feature
 *                  support" in mbedtls_config.h
 *
 * \param feature   The string for the define to check (e.g. "MBEDTLS_AES_C")
 *
 * \return          0 if the feature is present,
 *                  -1 if the feature is not present and
 *                  -2 if support for feature checking as a whole was not
 *                  compiled in.
 */
int mbedtls_version_check_feature( const char *feature );

#ifdef __cplusplus
}
#endif

#endif /* MBEDTLS_VERSION_C */

#endif /* version.h */
