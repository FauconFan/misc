#ifndef T_NEIGHBOUR_H
#define T_NEIGHBOUR_H

#include "irc_udp.h"

typedef struct       s_neighbour {
    uint64_t        id;
    uint16_t        port;
    uint8_t         ip[16];
    struct timeval  last_hello; // le dernier hello qu'on a reçu
    struct timeval  last_hello_long; // le dernier hello long qu'on a reçu
    // revoir ce nom, parce qu'il est pas terrible
    struct timeval  our_last_hello;
}                   t_neighbour;


t_neighbour     *nei_alloc(uint64_t id, uint16_t port, uint8_t ip[16]);
void            nei_free(t_neighbour *nei);

// prédicat d'égalité
t_bool          nei_is_id(t_neighbour *nei, uint64_t id);





#endif
