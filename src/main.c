#include "irc_udp.h"

t_env       * g_env = NULL;

uint8_t     msg[14] = {93, 2, 0, 10, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t     hello_long[22] = {93, 2, 0, 18, 2, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main(void)
{
    ui_setup();

    g_env = env_alloc();
    if (g_env == NULL)
        return (1);

    env_print(g_env, ui_getfd());

    memcpy(msg + 6, (char *)&g_env->id, 8);
    memcpy(hello_long + 6, (char *)&g_env->id, 8);

    struct sockaddr *sock_addr;
    socklen_t       sock_len;

    get_sockaddr_juliusz(&sock_addr, &sock_len);

    client(sock_addr, sock_len, msg, sizeof(msg), hello_long, sizeof(hello_long));

    env_free(g_env);

    ui_down();
    return (0);
}
