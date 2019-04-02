#include "irc_udp.h"

t_tlv_scanner   *tlvs_alloc(uint8_t * tlv, size_t l) {
    t_tlv_scanner   *scanner;

    if (tlv == NULL)
        return (NULL);
    if ((scanner = (t_tlv_scanner *)malloc(sizeof(t_tlv_scanner))) == NULL) {
        return (NULL);        
    }
    if ((scanner->tlv = (uint8_t *)malloc(sizeof(uint8_t) * l)) == NULL) {
        free(scanner);
        return (NULL);
    }
    memcpy(scanner->tlv, tlv, l);
    scanner->len = l;
    scanner->ok = TRUE;
    return (scanner);
}

void            tlvs_free(t_tlv_scanner * tlvs) {
    if (tlvs == NULL)
        return ;
    free(tlvs->tlv);
    free(tlvs);
}
