#include "irc_udp.h"

static uint16_t parse_pad1(uint8_t * tlv) {
    (void)tlv;
    printf("PAD1\n");
    return (1);
}

static uint16_t parse_padN(uint8_t * tlv) {
    uint16_t len;
    t_bool   filled_with_zero;

    printf("PADN\n");
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

    len = tlv[1];
    if (len != 8 && len != 16) {
        printf("Inconsistent hello message\n");
        printf("Wrong len %d\n", len);
    }
    else if (len == 8) {
        source_id = *(uint64_t *)(tlv + 2);
        printf("HELLO SHORT Source-id: %016lx\n", source_id);
    }
    else if (len == 16) {
        source_id = *(uint64_t *)(tlv + 2);
        dest_id = *(uint64_t *)(tlv + 10);
        printf("HELLO LONG Source-id: %016lx, Dest-id: %016lx\n", source_id, dest_id);
    }
    return (len + 2);
}

static uint16_t parse_neighbour(uint8_t * tlv) {
    uint16_t len;
    uint8_t  *ip;
    uint16_t port;

    len = tlv[1];
    if (len != 18) {
        printf("Inconsistent neighbour message\n");
        printf("Wrong len %d\n", len);
    }
    else {
        ip = tlv + 2;
        port = *(uint16_t *)(tlv + 18);
        printf("NEIGHBOUR ");
        printf("IP : ");
        for (size_t i = 0; i < 16; ++i) {
            printf("%.2x ", ip[i]);
        }
        printf("Port : %d\n", ntohs(port));
    }
    return (len + 2);
}

static uint16_t parse_data(uint8_t * tlv) {
    uint16_t len;
    uint64_t sender_id;
    uint32_t nounce;
    uint8_t type;
    uint8_t *msg;

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
        printf("DATA ");
        printf("sender id : %016lx, nounce : %d, type : %d, msg : ", sender_id, nounce, type);
        if (type != 0)
            printf("No printable message\n");
        else
            printf("\"%.*s\"", len - 13, msg);
    }
    return (len + 2);
}

static uint16_t parse_ack(uint8_t * tlv) {
    uint8_t len;
    uint64_t sender_id;
    uint32_t nounce;

    len = tlv[1];
    if (len != 12) {
        printf("Inconsistent ack message\n");
        printf("Wrong len : %d\n", len);
    }
    else {
        sender_id = *(uint64_t *)(tlv + 2);
        nounce = *(uint32_t *)(tlv + 10);
        printf("ACK sender id : %016lx, nounce : %d\n", sender_id, nounce);
    }
    return (len + 2);
}

static uint16_t parse_goaway(uint8_t * tlv) {
    uint8_t len;
    uint8_t code;
    uint8_t *msg;

    len = tlv[1];
    if (len < 1) {
        printf("Inconsistent goaway msg\n");
        printf("len is too short : %d\n", len);
    }
    else {
        code = tlv[2];
        printf("GOAWAY code %d, meaning : ", code);
        switch (code) {
            case 0: printf("unknown reason"); break;
            case 1: printf("sender quit the system"); break;
            case 2: printf("hello message missing for too long"); break;
            case 3: printf("sender didn't respect the protocol"); break;
            case 4: printf("sender has too many neighbours"); break;
            default: printf("unknown code"); break;
        }
        msg = tlv + 3;
        printf(", msg : %.*s\n", len - 1, msg);
    }
    return (len + 2);
}

static uint16_t parse_warning(uint8_t * tlv) {
    uint8_t len;
    uint8_t * msg;

    len = tlv[1];
    msg = tlv + 3;
    printf("WARNING msg : %.*s\n", len, msg);
    return (len + 2);
}

static uint16_t parse_tlv(uint8_t * tlv) {
    switch (tlv[0]) {
        case PAD1: return (parse_pad1(tlv));
        case PADN: return (parse_padN(tlv));
        case HELLO: return (parse_hello(tlv));
        case NEIGHBOUR: return (parse_neighbour(tlv));
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
        printf("=== ");
        len_actu += parse_tlv(tlv + len_actu);
    }
}
