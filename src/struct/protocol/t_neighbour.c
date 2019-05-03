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

static t_bool   ip_port_is_eq_nei(t_neighbour * nei, t_ip_port * ip_port) {
	return (ip_port_is_eq(&(nei->ip_port), ip_port));
}

t_neighbour * nei_search_neighbour(t_list * li_neighbours, t_ip_port ip_port) {
	return lst_findp(li_neighbours, (t_bool(*)(void *, void *))ip_port_is_eq_nei, &ip_port);
}

t_bool          nei_is_id(t_neighbour * nei, uint64_t id) {
	return (nei->id == id);
}

static void     parcours_nei(t_neighbour * nei, struct timeval * tv) {
	struct timeval * tmp;

	tmp = timeval_min(tv, &nei->next_hello);
	timeval_assign(tv, tmp);
}

t_bool          nei_get_min_time(t_list * li_neighbours, struct timeval * tv) {
	if (lst_isempty(li_neighbours)) {
		return (FALSE);
	}
	timeval_assign(tv, &(((t_neighbour *) lst_top(li_neighbours))->next_hello));
	lst_iterp(li_neighbours, (void(*)(void *, void *))parcours_nei, tv);
	return (TRUE);
}
