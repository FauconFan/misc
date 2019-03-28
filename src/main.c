#include "irc_udp.h"

#define NODE    "jch.irif.fr"
#define SERVICE "1212"
#define TIME 25

uint8_t     msg[14] = {93, 2, 0, 10, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t     hello_long[22] = {93, 2, 0, 18, 2, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


int main(void)
{
    int             sfd;
    struct sockaddr *sock_addr;
    socklen_t       sock_len;
    fd_set          readfds;
    int             rc;
    struct timeval  tv;
    struct timeval  debut;
    struct timeval  current;
    uint8_t         buff_res[1024];


    getSocketJuliusz(NODE, SERVICE, &sfd, &sock_addr, &sock_len);

    client(sfd, sock_addr, sock_len, msg, sizeof(msg));
    printf("fin debut\n");



    rc = fcntl(sfd, F_GETFL);
    if (rc < 0){
        fprintf(stderr, "echec flags non bloquants 1\n");
        exit(1);
    }
    rc = fcntl(sfd, F_SETFL, rc|O_NONBLOCK);
    if (rc < 0) {
        fprintf(stderr, "echec flags non bloquants 2\n" );
    }



    FD_ZERO(&readfds);
    FD_SET(sfd, &readfds);
    tv.tv_sec = TIME;
    tv.tv_usec = 0;
    gettimeofday(&debut, NULL);

    while (1) {
        rc = select(sfd +1, &readfds, NULL, NULL, &tv);
        // timeout
        if (rc == 0){
            printf("timeout\n");
            rc = sendto(sfd, hello_long, sizeof(hello_long), 0, sock_addr, sock_len);

            printf(">> ");
            for (int i=0; i < rc; i++){
                printf("%.2d ",hello_long[i]);
            }
            printf("\n");
            // on recommence à compter 25 secondes
            gettimeofday(&debut, NULL);
            tv.tv_sec = TIME;
            tv.tv_usec = 0;
        }

        // message de Juliusz
        else if (rc == 1){
            printf("read\n" );
            memset(buff_res, 0, 1024);
            rc = recv(sfd, buff_res, 1024, 0);

            for (int i = 0; i < rc; ++i) {
                printf("%.2d ", buff_res[i]);
            }
            printf("\n");
            gettimeofday(&current, NULL);
            tv.tv_sec = current.tv_sec - debut.tv_sec;
            tv.tv_usec = current.tv_usec - debut.tv_usec;
        }
        else {
            fprintf(stderr, "select failed\n");
            exit(1);
        }
    }

    return 0;
}
