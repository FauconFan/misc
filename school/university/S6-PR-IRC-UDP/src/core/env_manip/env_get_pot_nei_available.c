#include "irc_udp.h"

static t_bool               is_available(t_potential_neighbour * pot_nei) {
	struct timeval diff;

	timeval_diff(&diff, pot_nei->last_send, g_env->now);
	return (diff.tv_sec > TIMEOUT_POT_NEI);
}

t_potential_neighbour * env_get_pot_nei_available(void) {
	return (lst_find(g_env->li_potential_neighbours, (t_bool(*)(void *))is_available));
}
