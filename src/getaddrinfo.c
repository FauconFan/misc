#include "irc_udp.h"

void    getSocketJuliusz(
                const char * node,
                const char * service,
                int * sfd,
                struct sockaddr ** sock_addr,
                socklen_t * sock_len) {
    struct addrinfo     hints;
    struct addrinfo     *res;
    struct addrinfo     *p;
    int                 rc;
    int                 s;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = 0;
    hints.ai_flags = (AI_V4MAPPED | AI_ALL);

    rc = getaddrinfo(node, service, &hints, &res);
    if(rc != 0) {
        fprintf(stderr, "Échec cinglant : %s\n", gai_strerror(rc));
        exit(1);
    }

    for (p = res; p != NULL; p = p->ai_next) {
        s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(s < 0) {
            close(s);
            continue;
        }
        break ;
    }

    if (p == NULL) {
        fprintf(stderr, "La connection a échoué.\n");
        exit(1);
    }
    *sfd = s;
    *sock_addr = p->ai_addr;
    *sock_len = p->ai_addrlen;
    freeaddrinfo(res);

}