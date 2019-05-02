// Le nom est a revoir sans doute, je savais pas comment l'appeler

// je vois pas si on doit rajouter des choses dans la struct
// parce que le tlv 3 ne donne pas plus d'info

#ifndef T_POTENTIAL_NEIGHBOUR_H
#define	T_POTENTIAL_NEIGHBOUR_H

#include "irc_udp.h"

typedef struct      s_potential_neighbour{
	t_ip_port      ip_port;
	struct timeval last_send;
}                   t_potential_neighbour;


t_potential_neighbour * pot_nei_alloc(t_ip_port ip_port);
void                        pot_nei_free(t_potential_neighbour * pot_nei);

void                        pot_nei_print(t_potential_neighbour * pot_nei, int fd);

t_potential_neighbour * pot_nei_get_available(t_list * li_potential_neighbours, struct timeval * now);


#endif // ifndef T_POTENTIAL_NEIGHBOUR_H
