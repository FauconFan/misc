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
t_bool          tlvb_add_hello(t_tlv_builder *tlv, uint64_t id1, uint64_t id2);
t_bool          tlvb_add_neighbour(t_tlv_builder *tlv, uint8_t ip[16], uint16_t port);
t_bool          tlvb_add_data(t_tlv_builder *tlv, uint64_t id, uint32_t nonce, uint8_t type, uint8_t *data, size_t taille);
t_bool          tlvb_add_ack(t_tlv_builder *tlv, uint64_t id, uint32_t nonce);
t_bool          tlvb_add_goaway(t_tlv_builder *tlv, uint8_t code, uint8_t *message, size_t taille);
t_bool          tlvb_add_warning(t_tlv_builder *tlv, uint8_t *message, size_t taille);
#endif
