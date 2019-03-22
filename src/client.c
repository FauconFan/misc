#include "irc_udp.h"

void    client(
                int sfd,
                struct sockaddr *sock_addr,
                socklen_t sock_len,
                const void * buff,
                size_t len_buff) {
    uint8_t    buff_res[1024];
    size_t      N;

    /*Send message to server*/
    int rc = sendto(sfd, buff, len_buff, 0, sock_addr, sock_len);

    printf("%d\n", rc);

    /*Receive message from server*/
    memset(buff_res, 0, 1024);
    N = recv(sfd, buff_res, 1024, 0);

    for (size_t i = 0; i < N; ++i) {
        printf("%.2d ", buff_res[i]);
    }
    printf("\n");
}