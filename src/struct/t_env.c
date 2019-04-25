#include "irc_udp.h"

t_env               *env_alloc(void) {
    t_env   *res;

    if ((res = (t_env *)malloc(sizeof(t_env))) == NULL)
        return (NULL);
    memset(res, 0, sizeof(t_env));
    if ((res->li_neighbours = lst_alloc(FREE_PTR(nei_free))) == NULL
        || (res->li_potential_neighbours = lst_alloc(FREE_PTR(pot_nie_free))) == NULL
        || (res->li_received_messages = lst_alloc(FREE_PTR(message_free))) == NULL
        || (res->li_acquit_messages = lst_alloc(FREE_PTR(a_message_free))) == NULL) {
        
        if (res->li_neighbours)
            lst_free(res->li_neighbours);
        if (res->li_potential_neighbours)
            lst_free(res->li_potential_neighbours);
        if (res->li_received_messages)
            lst_free(res->li_received_messages);
        if (res->li_acquit_messages)
            lst_free(res->li_acquit_messages);
        free(res);
        return (NULL);
    }
    res->id = gen_id();
    return (res);
}

void                env_free(t_env * env) {
    lst_free(env->li_neighbours);
    lst_free(env->li_potential_neighbours);
    lst_free(env->li_received_messages);
    lst_free(env->li_acquit_messages);
    free(env);
}