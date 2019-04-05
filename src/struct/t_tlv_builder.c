#include "irc_udp.h"

t_tlv_builder   *tlvb_alloc(void) {
    t_tlv_builder   *tlv;
    const uint8_t  header[2] = { MAGIC_NUMBER, VERSION };

    if ((tlv = (t_tlv_builder *)malloc(sizeof(t_tlv_builder))) == NULL) {
        return (NULL);
    }
    if ((tlv->msg = iovb_alloc()) == NULL) {
        free(tlv);
        return (NULL);
    }
    if (iovb_push(tlv->msg, header, 2) == FALSE) {
        iovb_free(tlv->msg);
        free(tlv);
        return (NULL);
    }
    tlv->len_body = 0;
    tlv->index_len_body = iovb_get_index(tlv->msg);
    tlv->ready = FALSE;
    iovb_skip(tlv->msg);
    return (tlv);
}

t_bool      tlvb_finish(t_tlv_builder *tlv) {
    if (tlv == NULL || tlv->ready)
        return (FALSE);

    uint16_t    len = htons(tlv->len_body);
    iovb_set(tlv->msg, tlv->index_len_body, &len, 2);
    tlv->ready = TRUE;
    return (TRUE);
}

void        tlvb_free(t_tlv_builder *tlv) {
    if (tlv == NULL)
        return ;
    iovb_free(tlv->msg);
    free(tlv);
}

static t_bool   tlvb_add_type(t_tlv_builder *tlv, t_tlv_type t) {
    uint8_t   type[1] = { t };

    tlv->len_body++;
    return (iovb_push(tlv->msg, type, 1));
}

static t_bool   tlvb_add_value(t_tlv_builder *tlv, const void *v, size_t l) {
    uint8_t   length[1] = { l };

    if (iovb_push(tlv->msg, length, 1) == FALSE)
        return (FALSE);
    tlv->len_body += l + 1;
    return (iovb_push(tlv->msg, v, l));
}

t_bool      tlvb_add_pad1(t_tlv_builder *tlv) {
    if (tlv == NULL || tlv->ready)
        return (FALSE);
    if (tlvb_add_type(tlv, PAD1) == FALSE)
        return (FALSE);
    return (TRUE);
}

t_bool      tlvb_add_padN(t_tlv_builder *tlv, size_t l) {
    const uint8_t zeros[4096] = { 0 };

    if (tlv == NULL || tlv->ready || l >= 4096)
        return (FALSE);
    if (tlvb_add_type(tlv, PADN) == FALSE)
        return (FALSE);
    return (tlvb_add_value(tlv, zeros, l));
}


t_bool      tlvb_add_hello(t_tlv_builder *tlv, uint64_t id1, uint64_t id2) {
    if (tlv== NULL || tlv->ready)
        return (FALSE);
    if (tlvb_add_type(tlv, HELLO) == FALSE)
        return (FALSE);

    uint8_t id[16];
    size_t taille = 8;
    memcpy(id, ((uint8_t *)&id1), 8);

    if (id2 != 0){
        taille = 16;
        memcpy(id +8, ((uint8_t *)&id2), 8);
    }

    return (tlvb_add_value(tlv, id, taille));
}

t_bool      tlvb_add_neighbour(t_tlv_builder *tlv, uint8_t ip[16], uint16_t port) {
    if (tlv == NULL || tlv->ready || ip == NULL)
        return (FALSE);
    if (tlvb_add_type(tlv, NEIGHBOUR) == FALSE)
        return (FALSE);
    uint8_t msg[18];
    memcpy(msg, ip, 16);
    memcpy(msg+16, (uint8_t *)&port), 2);
    return (tlvb_add_value(tlv, msg, 18));
}
