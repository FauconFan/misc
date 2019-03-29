#include "irc_udp.h"

#define TIME 25

void    client(
                int sfd,
                struct sockaddr *sock_addr,
                socklen_t sock_len,
                const void *buff,
                size_t len_buff,
                const void *hello_long,
                size_t len_hello){
    uint8_t         buff_res[1024];
    size_t          N;
    int             rc;
    struct timeval  tv;
    struct timeval  debut;
    struct timeval  current;
    fd_set          readfds;

    /*Send message to server*/
    rc = sendto(sfd, buff, len_buff, 0, sock_addr, sock_len);

    printf("%d\n", rc);

    /*Receive message from server*/
    memset(buff_res, 0, 1024);
    N = recv(sfd, buff_res, 1024, 0);

    for (size_t i = 0; i < N; ++i) {
        printf("%.2d ", buff_res[i]);
    }
    printf("\n");



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
            N = sendto(sfd, hello_long, len_hello, 0, sock_addr, sock_len);

            printf(">> ");
            for (size_t i=0; i < N; i++){
                printf("%.2d ",((uint8_t *)hello_long)[i]);
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
            N = recv(sfd, buff_res, 1024, 0);

            for (size_t i = 0; i < N; ++i) {
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






}
