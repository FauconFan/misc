// Le nom est a revoir sans doute, je savais pas comment l'appeler

// je vois pas si on doit rajouter des choses dans la struct
// parce que le tlv 3 ne donne pas plus d'info

#ifndef T_POTENTIAL_NEIGHBOUR_H
#define	T_POTENTIAL_NEIGHBOUR_H

#include "irc_udp.h"

typedef struct      s_potential_neighbour{
	uint8_t  ip[16];
	uint16_t port;
}                   t_potential_neighbour;


t_potential_neighbour * pot_nei_alloc(uint8_t ip[16], uint16_t port);
void                        pot_nei_free(t_potential_neighbour * pot_nei);

void                        pot_nei_print(t_potential_neighbour * pot_nei, int fd);

// prédicat d'égalité
t_bool                      pot_nei_is_id(t_potential_neighbour * pot_nei, uint8_t ip[16], uint16_t port);


#endif // ifndef T_POTENTIAL_NEIGHBOUR_H
