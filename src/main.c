#include "irc_udp.h"

t_env       * g_env = NULL;

uint8_t     msg[14] = {93, 2, 0, 10, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t     hello_long[22] = {93, 2, 0, 18, 2, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main(void)
{
    g_env = env_alloc();

    memcpy(msg + 6, (char *)&g_env->id, 8);
    memcpy(hello_long + 6, (char *)&g_env->id, 8);


    int             sfd;
    struct sockaddr *sock_addr;
    socklen_t       sock_len;

    getSocketJuliusz(JCH_NODE, JCH_SERVICE, &sfd, &sock_addr, &sock_len);

    client(sfd, sock_addr, sock_len, msg, sizeof(msg), hello_long, sizeof(hello_long));

    env_free(g_env);
    return 0;
}