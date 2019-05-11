#include "irc_udp.h"


t_potential_neighbour * pot_nei_alloc(t_ip_port ip_port) {
	t_potential_neighbour * pot_nei = malloc(sizeof(t_potential_neighbour));

	if (pot_nei == NULL)
		return (NULL);

	ip_port_assign(&pot_nei->ip_port, &ip_port);
	pot_nei->last_send.tv_sec  = 0;
	pot_nei->last_send.tv_usec = 0;
	pot_nei->no_response       = 0;
	return (pot_nei);
}

void                        pot_nei_free(t_potential_neighbour * pot_nei) {
	free(pot_nei);
}

void                        pot_nei_print(t_potential_neighbour * pot_nei, int fd) {
	dprintf(fd, "potential neighbour { ip_port : ");
	ip_port_print(pot_nei->ip_port, fd);
	dprintf(fd, ", no_response : %u", pot_nei->no_response);
	dprintf(fd, ", last send : ");
	timeval_print(pot_nei->last_send, fd);
	dprintf(fd, "}");
}

t_bool                      is_pot_nei_old(t_potential_neighbour * pot_nei) {
	if (pot_nei == NULL)
		return (FALSE);

	return (pot_nei->no_response >= TIMEOUT_POT_NEI_RETRY);
}

t_bool                      pot_nei_is(t_potential_neighbour * pot_nei, t_ip_port * ip_port) {
	return (ip_port_is_eq(&(pot_nei->ip_port), ip_port));
}

static t_bool               is_available(t_potential_neighbour * pot_nei, struct timeval * now) {
	struct timeval diff;

	diff = timeval_diff(&pot_nei->last_send, now);
	return (diff.tv_sec > TIMEOUT_POT_NEI);
}

t_potential_neighbour * pot_nei_get_available(t_list * li_potential_neighbours, struct timeval * now) {
	return (lst_findp(li_potential_neighbours, (t_bool(*)(void *, void *))is_available, now));
}
