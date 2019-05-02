#include "irc_udp.h"

#define	TIME      30
#define	BUFF_SIZE 4096 + 1

// static void		build_sock_addr6(struct sockaddr_in6 *in6, uint8_t ip[16], uint16_t port) {
// 	memset(in6, 0, sizeof(*in6));
// 	in6->sin6_family = AF_INET6;
// 	in6->sin6_port = port;
// 	for (size_t i = 0; i < 16; ++i) {
// 		in6->sin6_addr.s6_addr[i] = ip[i];
// 	}
// }

static t_bool   select_treat_input() {
	fd_set readfds;
	int max_fd;
	int rc_select;
	struct timeval tv;
	t_bool running;
	uint8_t buff_res[BUFF_SIZE];
	size_t N;

	running = TRUE;
	FD_ZERO(&readfds);
	FD_SET(g_env->socket, &readfds);
	FD_SET(ui_getcallbackfd(), &readfds);
	max_fd = g_env->socket;
	if (ui_getcallbackfd() > max_fd)
		max_fd = ui_getcallbackfd();

	// Calculer le minimum time to wait pour tv
	tv        = env_min_time(g_env);
	rc_select = select(max_fd + 1, &readfds, NULL, NULL, &tv);

	if (rc_select < 0) {
		dprintf(ui_getfd(), "select failed : %s\n", strerror(errno));
		running = FALSE;
	}
	// on a reçu un message
	else if (FD_ISSET(g_env->socket, &readfds)) {
		struct sockaddr_in6 sock6;
		socklen_t len;

		memset(buff_res, 0, BUFF_SIZE);
		N = recvfrom(g_env->socket, buff_res, BUFF_SIZE, 0, (struct sockaddr *) &sock6, &len);

		dprintf(ui_getfd(), "message from\n");
		dprintf(ui_getfd(), "From\n");
		dprintf(ui_getfd(), "Ip : ");

		for (size_t i = 0; i < 16; ++i) {
			dprintf(ui_getfd(), "%.2x ", sock6.sin6_addr.s6_addr[i]);
		}
		dprintf(ui_getfd(), "\n");
		dprintf(ui_getfd(), "Port : %d\n", ntohs(sock6.sin6_port));

		for (size_t i = 0; i < N; ++i) {
			dprintf(ui_getfd(), "%.2d ", buff_res[i]);
		}
		dprintf(ui_getfd(), "\n");
		t_ip_port ip_port;
		ip_port_assign_sockaddr6(&ip_port, sock6);
		parse_datagram(buff_res, N, nei_search_neighbour(g_env->li_neighbours, ip_port), ip_port);
		// Pretty parser
	}
	else if (FD_ISSET(ui_getcallbackfd(), &readfds)) {
		t_ui_in in;

		ui_receive(&in);
		switch (in.type) {
			case UI_OK:
				break;
			case UI_STOP:
				running = FALSE;
				break;
			case UI_MESSAGE:
				dprintf(ui_getfd(), "Me: %s\n", in.u.message);
				free(in.u.message);
				break;
		}
	}
	return (running);
} /* select_treat_input */

void    client() {
	t_bool running = TRUE;

	while (running) {
		running = select_treat_input();
	}
} /* client */
