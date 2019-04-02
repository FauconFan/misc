#include "irc_udp.h"

static uint16_t parse_pad1(uint8_t * tlv) {
    (void)tlv;
    printf("RECEIVE PAD1 msg\n");
    return (1);
}

static uint16_t parse_padN(uint8_t * tlv) {
    uint16_t len;
    t_bool   filled_with_zero;

    printf("RECEIVE PADN msg\n");
    len = tlv[1];
    filled_with_zero = TRUE;
    for (size_t i = 0; i < len; ++i) {
        if (tlv[i + 2] != 0) {
            filled_with_zero = FALSE;
            break ;
        }
    }
    if (filled_with_zero == FALSE) {
        printf("PADN message but with non zero values...\n");
    }
    return (2 + len);
}

static uint16_t parse_hello(uint8_t * tlv) {
    uint16_t len;
    uint64_t source_id;
    uint64_t dest_id;

    printf("RECEIVE HELLO msg\n");
    len = tlv[1];
    if (len != 8 && len != 16) {
        printf("Inconsistent hello message\n");
        printf("Wrong len %d\n", len);
    }
    else if (len == 8) {
        printf("Short hello\n");
        source_id = *(uint64_t *)(tlv + 2);
        printf("From %lx\n", source_id);
    }
    else if (len == 16) {
        printf("Long hello\n");
        source_id = *(uint64_t *)(tlv + 2);
        dest_id = *(uint64_t *)(tlv + 10);
        printf("From %lx\n", source_id);
        printf("To   %lx\n", dest_id);
    }
    return (len + 2);
}

static uint16_t parse_neighbor(uint8_t * tlv) {
    uint16_t len;
    uint8_t  *ip;
    uint16_t port;

    printf("RECEIVE NEIGHBOR MSG\n");
    len = tlv[1];
    if (len != 18) {
        printf("Inconsistent neighbor message\n");
        printf("Wrong len %d\n", len);
    }
    else {
        ip = tlv + 2;
        port = *(uint16_t *)(tlv + 18);
        printf("New neighbor\n");
        printf("IP : ");
        for (size_t i = 0; i < 16; ++i) {
            printf("%.2x ", ip[i]);
        }
        printf("\nPort : %d\n", port);
    }
    return (len + 2);
}

static uint16_t parse_data(uint8_t * tlv) {
    uint16_t len;
    uint64_t sender_id;
    uint32_t nounce;
    uint8_t type;
    uint8_t *msg;

    printf("RECEIVE DATA MSG\n");
    len = tlv[1];
    if (len < 13) {
        printf("Inconsistent data message\n");
        printf("len too short : %d\n", len);
    }
    else {
        sender_id = *(uint64_t *)(tlv + 2);
        nounce = *(uint32_t *)(tlv + 10);
        type = *(uint8_t *)(tlv + 14);
        msg = tlv + 15;
        printf("sender id : %lx\n", sender_id);
        printf("nounce : %d\n", nounce);
        printf("type : %d\n", type);
        if (type != 0)
            printf("No printable message\n");
        else
            printf("msg : %.*s", len - 13, msg);
    }
    return (len + 2);
}

static uint16_t parse_ack(uint8_t * tlv) {
    uint8_t len;
    uint64_t sender_id;
    uint32_t nounce;

    printf("RECEIVE ACK MSG\n");
    len = tlv[1];
    if (len != 12) {
        printf("Inconsistent ack message\n");
        printf("Wrong len : %d\n", len);
    }
    else {
        sender_id = *(uint64_t *)(tlv + 2);
        nounce = *(uint32_t *)(tlv + 10);
        printf("sender id : %lx\n", sender_id);
        printf("nounce : %d\n", nounce);
    }
    return (len + 2);
}

static uint16_t parse_goaway(uint8_t * tlv) {
    uint8_t len;
    uint8_t code;
    uint8_t *msg;

    printf("RECEIVE GOAWAY MSG\n");
    len = tlv[1];
    if (len < 1) {
        printf("Inconsistent goaway msg\n");
        printf("len is too short : %d\n", len);
    }
    else {
        code = tlv[2];
        printf("code %d\n", code);
        switch (code) {
            case 0: printf("unknown reason\n"); break;
            case 1: printf("sender quit the system\n"); break;
            case 2: printf("hello message missing for too long\n"); break;
            case 3: printf("sender didn't respect the protocol\n"); break;
            default: printf("unknown code\n"); break;
        }
        msg = tlv + 3;
        printf("msg : %.*s\n", len - 1, msg);
    }
    return (len + 2);
}

static uint16_t parse_warning(uint8_t * tlv) {
    uint8_t len;
    uint8_t * msg;

    printf("RECEIVE Warning MSG\n");
    len = tlv[1];
    msg = tlv + 3;
    printf("msg : %.*s\n", len, msg);
    return (len + 2);
}

static uint16_t parse_tlv(uint8_t * tlv) {
    switch (tlv[0]) {
        case PAD1: return (parse_pad1(tlv));
        case PADN: return (parse_padN(tlv));
        case HELLO: return (parse_hello(tlv));
        case NEIGHBOR: return (parse_neighbor(tlv));
        case DATA: return (parse_data(tlv));
        case ACK: return (parse_ack(tlv));
        case GOAWAY: return (parse_goaway(tlv));
        case WARNING: return (parse_warning(tlv));
        
        default:
            printf("unrecognised tlv\n");
            // On suppose que la longueur existe.
            return tlv[1];
    }
}

void            parse_datagram(uint8_t *tlv, size_t len) {
    uint16_t    len_body;
    uint16_t    len_actu;

    if (tlv == NULL) {
        printf("TLV is null\n");
        return ;
    }
    if (len < 4) {
        printf("TLV too short, can't contain header\n");
        return ;
    }
    if (tlv[0] != MAGIC_NUMBER) {
        printf("Wrong magic number\n");
        return ;
    }
    if (tlv[1] != VERSION) {
        printf("Wrong version\n");
        return ;
    }
    len_body = *(uint16_t *)(tlv + 2);
    len_body = ntohs(len_body);
    if (len_body != len - 4) {
        printf("Wrong len body in header tlv\n");
        printf("len body : %d\n", len_body);
        printf("len received : %lu\n", len);
        return ;
    }

    len_actu = 4;
    while (len_actu < len) {
        printf("====================\n");
        len_actu += parse_tlv(tlv + len_actu);
        printf("====================\n");
    }
    printf("all good\n");
}