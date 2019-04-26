#include "irc_udp.h"

t_bool      get_sockaddr_juliusz(
                struct sockaddr ** sock_addr,
                socklen_t * sock_len) {
    return (get_sockaddr(JCH_NODE, JCH_SERVICE, sock_addr, sock_len));
}

t_bool      get_sockaddr(
                const char * node,
                const char * service,
                struct sockaddr ** sock_addr,
                socklen_t * sock_len) {
    struct addrinfo     hints;
    struct addrinfo     *res;
    struct addrinfo     *p;
    int                 rc;
    int                 s;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = ENV_FAMILY;
    hints.ai_socktype = ENV_SOCKTYPE;
    hints.ai_protocol = ENV_PROTOCOL;
    hints.ai_flags = ENV_FLAGS;

    rc = getaddrinfo(node, service, &hints, &res);
    if(rc != 0) {
        fprintf(stderr, "Échec cinglant : %s\n", gai_strerror(rc));
        return (FALSE);
    }

    for (p = res; p != NULL; p = p->ai_next) {
        s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(s < 0) {
            close(s);
            continue;
        }
        close(s);
        break ;
    }

    if (p == NULL) {
        fprintf(stderr, "La connection a échoué.\n");
        freeaddrinfo(res);
        return (FALSE);
    }
    *sock_addr = p->ai_addr;
    *sock_len = p->ai_addrlen;
    freeaddrinfo(res);
    return (TRUE);
}
