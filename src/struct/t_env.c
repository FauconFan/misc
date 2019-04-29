#include "irc_udp.h"

t_env               *env_alloc(void) {
    t_env   *res;

    if ((res = (t_env *)malloc(sizeof(t_env))) == NULL)
        return (NULL);
    memset(res, 0, sizeof(t_env));
    res->socket = build_socket();
    if (res->socket < 0) {
        free(res);
        return (NULL);
    }
    if ((res->li_neighbours = lst_alloc(FREE_PTR(nei_free), PRINT_PTR(nei_print))) == NULL
        || (res->li_potential_neighbours = lst_alloc(FREE_PTR(pot_nei_free), PRINT_PTR(pot_nei_print))) == NULL
        || (res->li_messages = lst_alloc(FREE_PTR(message_free), PRINT_PTR(message_print))) == NULL
        || (res->li_acquit = lst_alloc(FREE_PTR(acquit_free), PRINT_PTR(acquit_print))) == NULL
        || (res->li_buffer_tlv_ip = lst_alloc(FREE_PTR(buffer_free), PRINT_PTR(buffer_print))) == NULL) {

        if (res->li_neighbours)
            lst_free(res->li_neighbours);
        if (res->li_potential_neighbours)
            lst_free(res->li_potential_neighbours);
        if (res->li_messages)
            lst_free(res->li_messages);
        if (res->li_acquit)
            lst_free(res->li_acquit);
        if (res->li_buffer_tlv_ip)
            lst_free(res->li_buffer_tlv_ip);
        free(res);
        return (NULL);
    }
    res->id = gen_id();
    return (res);
}

void                env_free(t_env * env) {
    lst_free(env->li_neighbours);
    lst_free(env->li_potential_neighbours);
    lst_free(env->li_messages);
    lst_free(env->li_acquit);
    lst_free(env->li_buffer_tlv_ip);
    free(env);
}

void                env_print(t_env * env) {
    printf("env {\n");
    printf("\tid : %016lx\n", env->id);
    printf("\tsocket : %d\n", env->socket);
    printf("\tli_neighbours : ");
    lst_print(env->li_neighbours);
    printf("\tli_potential_neighbours : ");
    lst_print(env->li_potential_neighbours);
    printf("\tli_messages : ");
    lst_print(env->li_messages);
    printf("\tli_acquit : ");
    lst_print(env->li_acquit);
    printf("\tli_buffer_tlv_ip : " );
    lst_print(env->li_buffer_tlv_ip);
    printf("}\n");
}


struct timeval      env_min_time(t_env * env){
    struct timeval min_hello = nei_get_min_time(env->li_neighbours);
    struct timeval min_acquit = acquit_get_min_time(env->li_acquit);

    struct timeval *next = min_time(min_hello, min_acquit);
    return *next;
}
