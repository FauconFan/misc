#include "irc_udp.h"

static t_bool   search_nei_by_acq(t_neighbour * nei, t_acquit * acq) {
	return (nei->id == acq->dest_id);
}

t_neighbour * env_search_nei_by_acq(t_acquit * acq) {
	return (lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))search_nei_by_acq, acq));
}
