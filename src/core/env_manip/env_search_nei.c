#include "irc_udp.h"

static t_bool   ip_port_is_eq_nei(t_neighbour * nei, t_ip_port * ip_port) {
	return (ip_port_is_eq((nei->ip_port), *ip_port));
}

t_neighbour * env_search_nei(t_ip_port ipp) {
	return (lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))ip_port_is_eq_nei, &ipp));
}
