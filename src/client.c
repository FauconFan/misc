#include "irc_udp.h"

#define TIME 25

void    client(
                struct sockaddr *sock_addr,
                socklen_t sock_len,
                const void *buff,
                size_t len_buff,
                void *hello_long,
                size_t len_hello){
    uint8_t         buff_res[1024];
    size_t          N;
    int             rc;
    struct timeval  tv;
    struct timeval  debut;
    struct timeval  current;
    fd_set          readfds;

    /*Send message to server*/
    rc = sendto(g_env->socket, buff, len_buff, 0, sock_addr, sock_len);

    printf("%d\n", rc);

    /*Receive message from server*/
    memset(buff_res, 0, 1024);
    N = recv(g_env->socket, buff_res, 1024, 0);

    for (size_t i = 0; i < N; ++i) {
        printf("%.2d ", buff_res[i]);
    }
    printf("\n");

    parse_datagram(buff_res, N);

    memcpy(hello_long + 14, buff_res + 6, 8);

    rc = fcntl(g_env->socket, F_GETFL);
    if (rc < 0){
        fprintf(stderr, "echec flags non bloquants 1\n");
        exit(1);
    }
    rc = fcntl(g_env->socket, F_SETFL, rc | O_NONBLOCK);
    if (rc < 0) {
        fprintf(stderr, "echec flags non bloquants 2\n" );
    }

    tv.tv_sec = TIME;
    tv.tv_usec = 0;
    gettimeofday(&debut, NULL);


    while (1) {
        FD_ZERO(&readfds);
        FD_SET(g_env->socket, &readfds);
        rc = select(g_env->socket +1, &readfds, NULL, NULL, &tv);

        // timeout
        if (rc == 0) {
            get_sockaddr_juliusz(&sock_addr, &sock_len);
            printf("timeout\n");
            N = sendto(g_env->socket, hello_long, len_hello, 0, sock_addr, sock_len);

            printf("N : %ld\n", (long int)N);
            if (N == (size_t)-1) {
                printf("sendto failed %s\n", strerror(errno));
            }
            else {
                printf(">> ");
                for (size_t i = 0; i < N; i++){
                    printf("%.2d ",((uint8_t *)hello_long)[i]);
                }
                printf("\n");
            }

            gettimeofday(&debut, NULL);
            tv.tv_sec = TIME;
            tv.tv_usec = 0;
        }

        // message de Juliusz
        else if (rc == 1) {
            struct sockaddr_in6     sock6;
            socklen_t               len;

            printf("read\n");
            memset(buff_res, 0, 1024);
            N = recvfrom(g_env->socket, buff_res, 1024, 0, (struct sockaddr *)&sock6, &len);

            printf("From\n");
            printf("Ip : ");

            for (size_t i = 0; i < 16; ++i) {
                printf("%.2x ", sock6.sin6_addr.s6_addr[i]);
            }
            printf("\n");
            printf("Port : %d\n", ntohs(sock6.sin6_port));

            for (size_t i = 0; i < N; ++i) {
                printf("%.2d ", buff_res[i]);
            }
            printf("\n");
            parse_datagram(buff_res, N); // Pretty parser
            gettimeofday(&current, NULL);
            tv.tv_sec = TIME - (current.tv_sec - debut.tv_sec);
            tv.tv_usec = 0;
        }
        else {
            perror("select failed");
            exit(1);
        }
    }
}
