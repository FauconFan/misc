#include "irc_udp.h"


t_potential_neighbour * pot_nei_alloc(t_ip_port ip_port) {
	t_potential_neighbour * pot_nei = malloc(sizeof(t_potential_neighbour));

	if (pot_nei == NULL)
		return (NULL);

	memcpy(pot_nei->ip_port.ip, ip_port.ip, 16);
	pot_nei->ip_port.port = ip_port.port;
	return (pot_nei);
}

void                        pot_nei_free(t_potential_neighbour * pot_nei) {
	free(pot_nei);
}

void                        pot_nei_print(t_potential_neighbour * pot_nei, int fd) {
	dprintf(fd, "potential neighbour { ip_port : ");
	ip_port_print(pot_nei->ip_port, fd);
	dprintf(fd, "}");
}

t_bool                      pot_nei_is_id(t_potential_neighbour * pot_nei, t_ip_port ip_port) {
	return (memcmp(pot_nei->ip_port.ip, ip_port.ip, 16) == 0 && pot_nei->ip_port.port == ip_port.port);
}
