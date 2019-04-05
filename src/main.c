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
    //printf("%ld\n", id);
    for (size_t i = 0; i < 8; i++) {
        printf("%d ", ((uint8_t *)&id)[i]);
    }
    printf("\n");


    /*int             sfd;
    struct sockaddr *sock_addr;
    socklen_t       sock_len;

    getSocketJuliusz(NODE, SERVICE, &sfd, &sock_addr, &sock_len);

    client(sfd, sock_addr, sock_len, msg, sizeof(msg), hello_long, sizeof(hello_long));
    */


    /* TEST PAD1/ PADN
    t_tlv_builder   * tlvb;

    tlvb = tlvb_alloc();
    //tlvb_add_pad1(tlvb);
    tlvb_add_padN(tlvb, 20);
    tlvb_finish(tlvb);
    iovb_print(tlvb->msg);
    tlvb_free(tlvb);
    */

    /* TEST HELLO COURT/LONG
    t_tlv_builder   *hello;
    uint8_t test[8] = {42, 42, 42, 42, 42, 42, 42, 42};

    hello = tlvb_alloc();
    tlvb_add_hello(hello, id, 0);
    tlvb_finish(hello);
    iovb_print(hello->msg);
    tlvb_free(hello);
    */

    return 0;
}
