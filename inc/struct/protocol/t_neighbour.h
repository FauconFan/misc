#ifndef T_NEIGHBOUR_H
#define	T_NEIGHBOUR_H

#include "irc_udp.h"

typedef struct       s_neighbour{
	uint64_t       id;
	t_ip_port      ip_port;
	struct timeval last_hello;      // le dernier hello qu'on a reçu
	struct timeval last_hello_long; // le dernier hello long qu'on a reçu
	struct timeval next_hello;
}                   t_neighbour;

t_neighbour * nei_alloc(uint64_t id, t_ip_port ip_port);
void            nei_free(t_neighbour * nei);

void            nei_print(t_neighbour * nei, int fd);

t_neighbour * nei_search_neighbour(t_list * li_neighbours, t_ip_port ip_port);

// prédicat d'égalité
t_bool          nei_is_id(t_neighbour * nei, uint64_t id);

t_bool          nei_get_min_time(t_list * li_neighbours, struct timeval * tv);

#endif // ifndef T_NEIGHBOUR_H
