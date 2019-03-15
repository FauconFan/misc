#include "irc_udp.h"

int    getSocketJuliusz(void) {
    struct addrinfo     hints;
    struct addrinfo     *res;
    struct addrinfo     *p;
    int                 rc;
    int                 s;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = 0;
    hints.ai_flags = 0;

    rc = getaddrinfo("jch.irif.fr", "1212", &hints, &res);
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

    if(p == NULL) {
        fprintf(stderr, "La connection a échoué.\n");
        exit(1);
    }
    
    freeaddrinfo(res);
    return (s);
}