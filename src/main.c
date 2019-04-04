#include "irc_udp.h"

#define NODE    "jch.irif.fr"
#define SERVICE "1212"

uint64_t    id = 0;

// uint8_t     msg[14] = {93, 2, 0, 10, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0};

uint8_t     msg[14] = {93, 2, 0, 10, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t     hello_long[22] = {93, 2, 0, 18, 2, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main(void)
{
    id = gen_id();
    printf("%lx\n", id);

    int             sfd;
    struct sockaddr *sock_addr;
    socklen_t       sock_len;

    getSocketJuliusz(NODE, SERVICE, &sfd, &sock_addr, &sock_len);

    client(sfd, sock_addr, sock_len, msg, sizeof(msg), hello_long, sizeof(hello_long));

    // t_tlv_builder   * tlvb;

    // tlvb = tlvb_alloc();
    // tlvb_add_pad1(tlvb);
    // tlvb_add_padN(tlvb, 20);
    // tlvb_finish(tlvb);
    // iovb_print(tlvb->msg);
    // tlvb_free(tlvb);

    return 0;
}
