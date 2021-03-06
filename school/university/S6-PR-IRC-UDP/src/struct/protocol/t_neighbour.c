#include "irc_udp.h"

t_neighbour * nei_alloc(uint64_t id, t_ip_port ip_port) {
	t_neighbour * nei = malloc(sizeof(t_neighbour));

	if (nei == NULL)
		return (NULL);

	nei->id = id;

	memcpy(nei->ip_port.ip, ip_port.ip, 16);
	nei->ip_port.port = ip_port.port;

	struct timeval now;
	gettimeofday(&now, NULL);
	nei->last_hello         = now;
	nei->last_hello_long    = now;
	nei->next_hello         = now;
	nei->next_hello.tv_sec += 30;

	return (nei);
}

void            nei_free(t_neighbour * nei) {
	free(nei);
}

void            nei_print(t_neighbour * nei, int fd) {
	dprintf(fd, "neighbour { id : %016lx, ip_port : ", nei->id);
	ip_port_print(nei->ip_port, fd);
	dprintf(fd, ", last hello ");
	timeval_print(nei->last_hello, fd);
	dprintf(fd, ", last hello long ");
	timeval_print(nei->last_hello_long, fd);
	dprintf(fd, ", our next hello ");
	timeval_print(nei->next_hello, fd);
	dprintf(fd, "}");
}

t_bool          nei_is_id(t_neighbour * nei, uint64_t id) {
	return (nei->id == id);
}
