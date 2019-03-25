#include "irc_udp.h"

#define NODE    "jch.irif.fr"
#define SERVICE "1212"

// uint8_t     msg[14] = {93, 2, 0, 10, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0};

int main(void)
{
    // int             sfd;
    // struct sockaddr *sock_addr;
    // socklen_t       sock_len;

    // getSocketJuliusz(NODE, SERVICE, &sfd, &sock_addr, &sock_len);

    // client(sfd, sock_addr, sock_len, msg, sizeof(msg));

    // return 0;

    t_msg_hdr_builder   *msg;

    msg = mhb_alloc();
    for (size_t i = 0; i < 12; ++i)
        mbh_add(msg, "coucou", 6);
    mbh_print(msg);
    mbh_free(msg);
}
