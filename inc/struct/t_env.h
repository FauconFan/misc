#ifndef T_ENV_H
#define T_ENV_H

#include "irc_udp.h"

// Global structure to the program
typedef struct      s_env {
    uint64_t        id;
    t_list          *li_neighbours;
    t_list          *li_potential_neighbours;
    t_list          *li_received_messages;
    t_list          *li_acquit_messages;
}                   t_env;

t_env               *env_alloc(void);
void                env_free(t_env * env);

#endif