#include "irc_udp.h"

static t_bool lst_acquit_get_min_time(t_list * li_acquit, struct timeval * tv);
static t_bool lst_nei_get_min_time(t_list * li_neighbours, struct timeval * tv);

void      env_build_min_time(struct timeval * res) {
	t_bool ok[2];
	struct timeval min_hello;
	struct timeval min_acquit;
	struct timeval min;

	ok[0] = lst_nei_get_min_time(g_env->li_neighbours, &min_hello);
	ok[1] = lst_acquit_get_min_time(g_env->li_acquit, &min_acquit);

	if (ok[0] == FALSE && ok[1] == FALSE) {
		// On attend 5 sec si on a rien à attendre
		res->tv_sec  = 5;
		res->tv_usec = 0;
		return;
	}
	else if (ok[0] == FALSE) {
		min = min_acquit;
	}
	else if (ok[1] == FALSE) {
		min = min_hello;
	}
	else {
		min = *timeval_min(&min_hello, &min_acquit);
	}
	return (timeval_diff(res, g_env->now, min));
}

static void parcours_acq(t_acquit * acq, struct timeval * tv) {
	timeval_assign(tv, *timeval_min(tv, &acq->next_time));
}

static t_bool lst_acquit_get_min_time(t_list * li_acquit, struct timeval * tv) {
	if (lst_isempty(li_acquit))
		return (FALSE);

	timeval_assign(tv, (((t_acquit *) lst_top(li_acquit))->next_time));
	lst_iterp(li_acquit, (void(*)(void *, void *))parcours_acq, tv);
	return (TRUE);
}

static void parcours_nei(t_neighbour * nei, struct timeval * tv) {
	timeval_assign(tv, *timeval_min(tv, &nei->next_hello));
}

static t_bool lst_nei_get_min_time(t_list * li_neighbours, struct timeval * tv) {
	if (lst_isempty(li_neighbours)) {
		return (FALSE);
	}
	timeval_assign(tv, (((t_neighbour *) lst_top(li_neighbours))->next_hello));
	lst_iterp(li_neighbours, (void(*)(void *, void *))parcours_nei, tv);
	return (TRUE);
}
