

/**
 * \file ssl_debug_helpers_generated.c
 *
 * \brief Automatically generated helper functions for debugging
 */


#include "common.h"

#if defined(MBEDTLS_DEBUG_C)

#include "ssl_debug_helpers.h"


const char *mbedtls_ssl_named_group_to_str( uint16_t in )
{
    switch( in )
    {
    case MBEDTLS_SSL_IANA_TLS_GROUP_SECP192K1:
        return "secp192k1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_SECP192R1:
        return "secp192r1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_SECP224K1:
        return "secp224k1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_SECP224R1:
        return "secp224r1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_SECP256K1:
        return "secp256k1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_SECP256R1:
        return "secp256r1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_SECP384R1:
        return "secp384r1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_SECP521R1:
        return "secp521r1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_BP256R1:
        return "bp256r1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_BP384R1:
        return "bp384r1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_BP512R1:
        return "bp512r1";
    case MBEDTLS_SSL_IANA_TLS_GROUP_X25519:
        return "x25519";
    case MBEDTLS_SSL_IANA_TLS_GROUP_X448:
        return "x448";
    case MBEDTLS_SSL_IANA_TLS_GROUP_FFDHE2048:
        return "ffdhe2048";
    case MBEDTLS_SSL_IANA_TLS_GROUP_FFDHE3072:
        return "ffdhe3072";
    case MBEDTLS_SSL_IANA_TLS_GROUP_FFDHE4096:
        return "ffdhe4096";
    case MBEDTLS_SSL_IANA_TLS_GROUP_FFDHE6144:
        return "ffdhe6144";
    case MBEDTLS_SSL_IANA_TLS_GROUP_FFDHE8192:
        return "ffdhe8192";
    };

    return "UNKOWN";
}
const char *mbedtls_ssl_sig_alg_to_str( uint16_t in )
{
    switch( in )
    {
    case MBEDTLS_TLS1_3_SIG_RSA_PKCS1_SHA256:
        return "rsa_pkcs1_sha256";
    case MBEDTLS_TLS1_3_SIG_RSA_PKCS1_SHA384:
        return "rsa_pkcs1_sha384";
    case MBEDTLS_TLS1_3_SIG_RSA_PKCS1_SHA512:
        return "rsa_pkcs1_sha512";
    case MBEDTLS_TLS1_3_SIG_ECDSA_SECP256R1_SHA256:
        return "ecdsa_secp256r1_sha256";
    case MBEDTLS_TLS1_3_SIG_ECDSA_SECP384R1_SHA384:
        return "ecdsa_secp384r1_sha384";
    case MBEDTLS_TLS1_3_SIG_ECDSA_SECP521R1_SHA512:
        return "ecdsa_secp521r1_sha512";
    case MBEDTLS_TLS1_3_SIG_RSA_PSS_RSAE_SHA256:
        return "rsa_pss_rsae_sha256";
    case MBEDTLS_TLS1_3_SIG_RSA_PSS_RSAE_SHA384:
        return "rsa_pss_rsae_sha384";
    case MBEDTLS_TLS1_3_SIG_RSA_PSS_RSAE_SHA512:
        return "rsa_pss_rsae_sha512";
    case MBEDTLS_TLS1_3_SIG_ED25519:
        return "ed25519";
    case MBEDTLS_TLS1_3_SIG_ED448:
        return "ed448";
    case MBEDTLS_TLS1_3_SIG_RSA_PSS_PSS_SHA256:
        return "rsa_pss_pss_sha256";
    case MBEDTLS_TLS1_3_SIG_RSA_PSS_PSS_SHA384:
        return "rsa_pss_pss_sha384";
    case MBEDTLS_TLS1_3_SIG_RSA_PSS_PSS_SHA512:
        return "rsa_pss_pss_sha512";
    case MBEDTLS_TLS1_3_SIG_RSA_PKCS1_SHA1:
        return "rsa_pkcs1_sha1";
    case MBEDTLS_TLS1_3_SIG_ECDSA_SHA1:
        return "ecdsa_sha1";
    case MBEDTLS_TLS1_3_SIG_NONE:
        return "none";
    };

    return "UNKNOWN";
}
const char *mbedtls_ssl_states_str( mbedtls_ssl_states in )
{
    const char * in_to_str[]=
    {
        [MBEDTLS_SSL_HELLO_REQUEST] = "MBEDTLS_SSL_HELLO_REQUEST",
        [MBEDTLS_SSL_CLIENT_HELLO] = "MBEDTLS_SSL_CLIENT_HELLO",
        [MBEDTLS_SSL_SERVER_HELLO] = "MBEDTLS_SSL_SERVER_HELLO",
        [MBEDTLS_SSL_SERVER_CERTIFICATE] = "MBEDTLS_SSL_SERVER_CERTIFICATE",
        [MBEDTLS_SSL_SERVER_KEY_EXCHANGE] = "MBEDTLS_SSL_SERVER_KEY_EXCHANGE",
        [MBEDTLS_SSL_CERTIFICATE_REQUEST] = "MBEDTLS_SSL_CERTIFICATE_REQUEST",
        [MBEDTLS_SSL_SERVER_HELLO_DONE] = "MBEDTLS_SSL_SERVER_HELLO_DONE",
        [MBEDTLS_SSL_CLIENT_CERTIFICATE] = "MBEDTLS_SSL_CLIENT_CERTIFICATE",
        [MBEDTLS_SSL_CLIENT_KEY_EXCHANGE] = "MBEDTLS_SSL_CLIENT_KEY_EXCHANGE",
        [MBEDTLS_SSL_CERTIFICATE_VERIFY] = "MBEDTLS_SSL_CERTIFICATE_VERIFY",
        [MBEDTLS_SSL_CLIENT_CHANGE_CIPHER_SPEC] = "MBEDTLS_SSL_CLIENT_CHANGE_CIPHER_SPEC",
        [MBEDTLS_SSL_CLIENT_FINISHED] = "MBEDTLS_SSL_CLIENT_FINISHED",
        [MBEDTLS_SSL_SERVER_CHANGE_CIPHER_SPEC] = "MBEDTLS_SSL_SERVER_CHANGE_CIPHER_SPEC",
        [MBEDTLS_SSL_SERVER_FINISHED] = "MBEDTLS_SSL_SERVER_FINISHED",
        [MBEDTLS_SSL_FLUSH_BUFFERS] = "MBEDTLS_SSL_FLUSH_BUFFERS",
        [MBEDTLS_SSL_HANDSHAKE_WRAPUP] = "MBEDTLS_SSL_HANDSHAKE_WRAPUP",
        [MBEDTLS_SSL_NEW_SESSION_TICKET] = "MBEDTLS_SSL_NEW_SESSION_TICKET",
        [MBEDTLS_SSL_SERVER_HELLO_VERIFY_REQUEST_SENT] = "MBEDTLS_SSL_SERVER_HELLO_VERIFY_REQUEST_SENT",
        [MBEDTLS_SSL_HELLO_RETRY_REQUEST] = "MBEDTLS_SSL_HELLO_RETRY_REQUEST",
        [MBEDTLS_SSL_ENCRYPTED_EXTENSIONS] = "MBEDTLS_SSL_ENCRYPTED_EXTENSIONS",
        [MBEDTLS_SSL_CLIENT_CERTIFICATE_VERIFY] = "MBEDTLS_SSL_CLIENT_CERTIFICATE_VERIFY",
        [MBEDTLS_SSL_CLIENT_CCS_AFTER_SERVER_FINISHED] = "MBEDTLS_SSL_CLIENT_CCS_AFTER_SERVER_FINISHED",
        [MBEDTLS_SSL_CLIENT_CCS_BEFORE_2ND_CLIENT_HELLO] = "MBEDTLS_SSL_CLIENT_CCS_BEFORE_2ND_CLIENT_HELLO",
        [MBEDTLS_SSL_SERVER_CCS_AFTER_SERVER_HELLO] = "MBEDTLS_SSL_SERVER_CCS_AFTER_SERVER_HELLO",
        [MBEDTLS_SSL_SERVER_CCS_AFTER_HELLO_RETRY_REQUEST] = "MBEDTLS_SSL_SERVER_CCS_AFTER_HELLO_RETRY_REQUEST",
        [MBEDTLS_SSL_HANDSHAKE_OVER] = "MBEDTLS_SSL_HANDSHAKE_OVER",
        [MBEDTLS_SSL_TLS1_3_NEW_SESSION_TICKET] = "MBEDTLS_SSL_TLS1_3_NEW_SESSION_TICKET",
        [MBEDTLS_SSL_TLS1_3_NEW_SESSION_TICKET_FLUSH] = "MBEDTLS_SSL_TLS1_3_NEW_SESSION_TICKET_FLUSH",
    };

    if( in > ( sizeof( in_to_str )/sizeof( in_to_str[0]) - 1 ) ||
        in_to_str[ in ] == NULL )
    {
        return "UNKNOWN_VALUE";
    }
    return in_to_str[ in ];
}

const char *mbedtls_ssl_protocol_version_str( mbedtls_ssl_protocol_version in )
{
    const char * in_to_str[]=
    {
        [MBEDTLS_SSL_VERSION_UNKNOWN] = "MBEDTLS_SSL_VERSION_UNKNOWN",
        [MBEDTLS_SSL_VERSION_TLS1_2] = "MBEDTLS_SSL_VERSION_TLS1_2",
        [MBEDTLS_SSL_VERSION_TLS1_3] = "MBEDTLS_SSL_VERSION_TLS1_3",
    };

    if( in > ( sizeof( in_to_str )/sizeof( in_to_str[0]) - 1 ) ||
        in_to_str[ in ] == NULL )
    {
        return "UNKNOWN_VALUE";
    }
    return in_to_str[ in ];
}

const char *mbedtls_tls_prf_types_str( mbedtls_tls_prf_types in )
{
    const char * in_to_str[]=
    {
        [MBEDTLS_SSL_TLS_PRF_NONE] = "MBEDTLS_SSL_TLS_PRF_NONE",
        [MBEDTLS_SSL_TLS_PRF_SHA384] = "MBEDTLS_SSL_TLS_PRF_SHA384",
        [MBEDTLS_SSL_TLS_PRF_SHA256] = "MBEDTLS_SSL_TLS_PRF_SHA256",
        [MBEDTLS_SSL_HKDF_EXPAND_SHA384] = "MBEDTLS_SSL_HKDF_EXPAND_SHA384",
        [MBEDTLS_SSL_HKDF_EXPAND_SHA256] = "MBEDTLS_SSL_HKDF_EXPAND_SHA256",
    };

    if( in > ( sizeof( in_to_str )/sizeof( in_to_str[0]) - 1 ) ||
        in_to_str[ in ] == NULL )
    {
        return "UNKNOWN_VALUE";
    }
    return in_to_str[ in ];
}

const char *mbedtls_ssl_key_export_type_str( mbedtls_ssl_key_export_type in )
{
    const char * in_to_str[]=
    {
        [MBEDTLS_SSL_KEY_EXPORT_TLS12_MASTER_SECRET] = "MBEDTLS_SSL_KEY_EXPORT_TLS12_MASTER_SECRET",
#if defined(MBEDTLS_SSL_PROTO_TLS1_3)
        [MBEDTLS_SSL_KEY_EXPORT_TLS1_3_CLIENT_EARLY_SECRET] = "MBEDTLS_SSL_KEY_EXPORT_TLS1_3_CLIENT_EARLY_SECRET",
        [MBEDTLS_SSL_KEY_EXPORT_TLS1_3_EARLY_EXPORTER_SECRET] = "MBEDTLS_SSL_KEY_EXPORT_TLS1_3_EARLY_EXPORTER_SECRET",
        [MBEDTLS_SSL_KEY_EXPORT_TLS1_3_CLIENT_HANDSHAKE_TRAFFIC_SECRET] = "MBEDTLS_SSL_KEY_EXPORT_TLS1_3_CLIENT_HANDSHAKE_TRAFFIC_SECRET",
        [MBEDTLS_SSL_KEY_EXPORT_TLS1_3_SERVER_HANDSHAKE_TRAFFIC_SECRET] = "MBEDTLS_SSL_KEY_EXPORT_TLS1_3_SERVER_HANDSHAKE_TRAFFIC_SECRET",
        [MBEDTLS_SSL_KEY_EXPORT_TLS1_3_CLIENT_APPLICATION_TRAFFIC_SECRET] = "MBEDTLS_SSL_KEY_EXPORT_TLS1_3_CLIENT_APPLICATION_TRAFFIC_SECRET",
        [MBEDTLS_SSL_KEY_EXPORT_TLS1_3_SERVER_APPLICATION_TRAFFIC_SECRET] = "MBEDTLS_SSL_KEY_EXPORT_TLS1_3_SERVER_APPLICATION_TRAFFIC_SECRET",
#endif
    };

    if( in > ( sizeof( in_to_str )/sizeof( in_to_str[0]) - 1 ) ||
        in_to_str[ in ] == NULL )
    {
        return "UNKNOWN_VALUE";
    }
    return in_to_str[ in ];
}



#endif


