#include "irc_udp.h"

static t_bool search_acq_nei(t_acquit * acq, t_neighbour * nei) {
	return (nei->id == acq->dest_id);
}

void env_erase_nei(t_neighbour * nei) {
	t_potential_neighbour * pot_nei;

	if (nei == NULL)
		return;

	// remove tous les ack
	lst_removeall_ifp(g_env->li_acquit, (t_bool(*)(void *, void *))search_acq_nei, nei);
	// ajout pot_nei
	pot_nei = pot_nei_alloc(nei->ip_port);
	lst_add(g_env->li_potential_neighbours, pot_nei);
	// remove nei
	lst_remove_ifp(g_env->li_neighbours, (t_bool(*)(void *, void *))nei_is_id, (void *) nei->id);
}
