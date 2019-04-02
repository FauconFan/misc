#ifndef T_TLV_H
#define T_TLV_H

#include "irc_udp.h"

#define MAGIC_NUMBER    93
#define VERSION         2

typedef enum    e_tlv_type {
    PAD1 = 0,
    PADN,
}               t_tlv_type;

typedef struct  s_tlv {
    t_iovec_builder     *msg;
    uint16_t            len_body;
    size_t              index_len_body;
    t_bool              ready;
}               t_tlv;

t_tlv   *tlv_alloc(void);
t_bool  tlv_finish(t_tlv *tlv);
void    tlv_free(t_tlv *tlv);

t_bool  tlv_add_pad1(t_tlv * tlv);
t_bool  tlv_add_padN(t_tlv * tlv, size_t l);

#endif