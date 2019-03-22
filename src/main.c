#include "irc_udp.h"

#define NODE    "jch.irif.fr"
#define SERVICE "1212"

uint8_t     msg[14] = {93, 2, 0, 10, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0};

int main(void)
{
    int             sfd;
    struct sockaddr *sock_addr;
    socklen_t       sock_len;

    getSocketJuliusz(NODE, SERVICE, &sfd, &sock_addr, &sock_len);

    client(sfd, sock_addr, sock_len, msg, sizeof(msg));

    return 0;
}
