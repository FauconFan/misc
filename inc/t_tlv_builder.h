#ifndef T_TLV_H
#define T_TLV_H

#include "irc_udp.h"

typedef struct  s_tlv_builder {
    t_iovec_builder     *msg;
    uint16_t            len_body;
    size_t              index_len_body;
    t_bool              ready;
}               t_tlv_builder;

t_tlv_builder   *tlvb_alloc(void);
t_bool          tlvb_finish(t_tlv_builder *tlv);
void            tlvb_free(t_tlv_builder *tlv);

t_bool          tlvb_add_pad1(t_tlv_builder * tlv);
t_bool          tlvb_add_padN(t_tlv_builder * tlv, size_t l);

#endif