#include "irc_udp.h"


t_potential_neighbour * pot_nei_alloc(t_ip_port ip_port) {
	t_potential_neighbour * pot_nei = malloc(sizeof(t_potential_neighbour));

	if (pot_nei == NULL)
		return (NULL);

	ip_port_assign(&pot_nei->ip_port, &ip_port);
	pot_nei->last_send.tv_sec  = 0;
	pot_nei->last_send.tv_usec = 0;
	return (pot_nei);
}

void                        pot_nei_free(t_potential_neighbour * pot_nei) {
	free(pot_nei);
}

void                        pot_nei_print(t_potential_neighbour * pot_nei, int fd) {
	dprintf(fd, "potential neighbour { ip_port : ");
	ip_port_print(pot_nei->ip_port, fd);
	dprintf(fd, ", last send : ");
	timeval_print(pot_nei->last_send, fd);
	dprintf(fd, "}");
}

static t_bool               is_available(t_potential_neighbour * pot_nei, struct timeval * now) {
	struct timeval diff;

	diff = timeval_diff(&pot_nei->last_send, now);
	return (diff.tv_sec > TIMEOUT_POT_NEI);
}

t_potential_neighbour * pot_nei_get_available(t_list * li_potential_neighbours, struct timeval * now) {
	return (lst_findp(li_potential_neighbours, (t_bool(*)(void *, void *))is_available, now));
}
