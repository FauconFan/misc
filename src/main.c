#include "irc_udp.h"

t_env       * g_env = NULL;

uint8_t     msg[14] = {93, 2, 0, 10, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t     hello_long[22] = {93, 2, 0, 18, 2, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main(void)
{
    g_env = env_alloc();
    if (g_env == NULL)
        return (1);

    uint8_t ip[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    lst_add(g_env->li_neighbours, nei_alloc(gen_id(), ip, 1234));
    lst_add(g_env->li_neighbours, nei_alloc(gen_id(), ip, 1234));

    lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip, 4321));
    lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip, 4321));

    lst_add(g_env->li_messages, message_alloc(gen_id(), gen_nonce(), 0, 6, (uint8_t *)"coucou"));
    lst_add(g_env->li_messages, message_alloc(gen_id(), gen_nonce(), 0, 6, (uint8_t *)"coucou"));

    lst_add(g_env->li_acquit, acquit_alloc(gen_id(), gen_nonce()));
    lst_add(g_env->li_acquit, acquit_alloc(gen_id(), gen_nonce()));
    lst_add(g_env->li_acquit, acquit_alloc(gen_id(), gen_nonce()));
    lst_add(g_env->li_acquit, acquit_alloc(gen_id(), gen_nonce()));

    env_print(g_env);
    print_time_val(env_min_time(g_env));
    printf("\n");
    // memcpy(msg + 6, (char *)&g_env->id, 8);
    // memcpy(hello_long + 6, (char *)&g_env->id, 8);

    // struct sockaddr *sock_addr;
    // socklen_t       sock_len;

    // get_sockaddr_juliusz(&sock_addr, &sock_len);

    // client(sock_addr, sock_len, msg, sizeof(msg), hello_long, sizeof(hello_long));

    env_free(g_env);
    return (0);
}
