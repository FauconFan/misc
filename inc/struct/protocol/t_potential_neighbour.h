// Le nom est a revoir sans doute, je savais pas comment l'appeler

// je vois pas si on doit rajouter des choses dans la struct
// parce que le tlv 3 ne donne pas plus d'info

#ifndef T_POTENTIAL_NEIGHBOUR_H
#define	T_POTENTIAL_NEIGHBOUR_H

#include "irc_udp.h"

typedef struct      s_potential_neighbour{
	t_ip_port      ip_port;
	struct timeval last_send;
	uint8_t        no_response;
}                   t_potential_neighbour;


t_potential_neighbour * pot_nei_alloc(t_ip_port ip_port);
void                        pot_nei_free(t_potential_neighbour * pot_nei);

void                        pot_nei_print(t_potential_neighbour * pot_nei, int fd);

t_bool                      pot_nei_is_old(t_potential_neighbour * pot_nei);

t_bool                      pot_nei_is(t_potential_neighbour * pot_nei, t_ip_port * ip_port);

#endif // ifndef T_POTENTIAL_NEIGHBOUR_H
