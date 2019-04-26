#include "irc_udp.h"

int     build_socket(void) {
    int     sock;

    sock = socket(ENV_FAMILY, ENV_SOCKTYPE, ENV_PROTOCOL);
    if (sock < 0)
        printf("Error Setup socket %s\n", strerror(errno));
    return (sock);
}
