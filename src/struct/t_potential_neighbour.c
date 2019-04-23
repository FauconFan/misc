#include "irc_udp.h"


t_potential_neighbour       *pot_nei_alloc(uint8_t ip[16], uint16_t port){
    t_potential_neighbour *pot_nei = malloc(sizeof(t_potential_neighbour));
    if (pot_nei == NULL)
        return NULL;
    memcpy(pot_nei->ip, ip, 16);
    pot_nei->port = port;

    return pot_nei;
}
void                        pot_nie_free(t_potential_neighbour *pot_nei){
    free(pot_nei);
}



t_bool                      pot_nei_is_id(t_potential_neighbour *pot_nei, uint8_t ip[16], uint16_t port){
    return (memcmp(pot_nei->ip, ip, 16)== 0 && pot_nei->port == port);
}
