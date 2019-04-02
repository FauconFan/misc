#ifndef T_TLV_SCANNER_H
#define T_TLV_SCANNER_H

#include "irc_udp.h"

typedef struct  s_tlv_scanner {
    uint8_t     *tlv;
    size_t      len;
    t_bool      ok;
}               t_tlv_scanner;

t_tlv_scanner   *tlvs_alloc(uint8_t * tlv, size_t l);

#endif