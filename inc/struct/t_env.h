#ifndef T_ENV_H
#define T_ENV_H

#include "irc_udp.h"

// Global structure to the program
typedef struct      s_env {
    uint64_t        id;
    int             socket;
    t_list          *li_neighbours;
    t_list          *li_potential_neighbours;
    t_list          *li_messages;
    t_list          *li_acquit;
}                   t_env;

t_env               *env_alloc(void);
void                env_free(t_env * env);

void                env_print(t_env * env);

struct timeval      env_min_time(t_env * env);

#endif
