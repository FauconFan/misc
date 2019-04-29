#include "irc_udp.h"

#define	TIME 25

void    client(
  struct sockaddr * sock_addr,
  socklen_t         sock_len,
  const void *      buff,
  size_t            len_buff,
  void *            hello_long,
  size_t            len_hello) {
	uint8_t buff_res[1024];
	size_t N;
	int rc;
	struct timeval tv;
	struct timeval debut;
	struct timeval current;
	fd_set readfds;

	/*Send message to server*/
	rc = sendto(g_env->socket, buff, len_buff, 0, sock_addr, sock_len);

	dprintf(ui_getfd(), "%d\n", rc);

	/*Receive message from server*/
	memset(buff_res, 0, 1024);
	N = recv(g_env->socket, buff_res, 1024, 0);

	for (size_t i = 0; i < N; ++i) {
		dprintf(ui_getfd(), "%.2d ", buff_res[i]);
	}
	dprintf(ui_getfd(), "\n");

	parse_datagram(buff_res, N);

	memcpy(hello_long + 14, buff_res + 6, 8);

	rc = fcntl(g_env->socket, F_GETFL);
	if (rc < 0) {
		dprintf(ui_getfd(), "echec flags non bloquants 1\n");
		exit(1);
	}
	rc = fcntl(g_env->socket, F_SETFL, rc | O_NONBLOCK);
	if (rc < 0) {
		dprintf(ui_getfd(), "echec flags non bloquants 2\n");
	}

	tv.tv_sec  = TIME;
	tv.tv_usec = 0;
	gettimeofday(&debut, NULL);

	t_bool running = TRUE;

	while (running) {
		int max_fd = g_env->socket;
		FD_ZERO(&readfds);
		FD_SET(g_env->socket, &readfds);
		FD_SET(ui_getcallbackfd(), &readfds);
		if (ui_getcallbackfd() > max_fd)
			max_fd = ui_getcallbackfd();
		rc = select(max_fd + 1, &readfds, NULL, NULL, &tv);


		// timeout
		if (rc == 0) {
			get_sockaddr_juliusz(&sock_addr, &sock_len);
			dprintf(ui_getfd(), "timeout\n");
			N = sendto(g_env->socket, hello_long, len_hello, 0, sock_addr, sock_len);

			dprintf(ui_getfd(), "N : %ld\n", (long int) N);
			if (N == (size_t) -1) {
				dprintf(ui_getfd(), "sendto failed %s\n", strerror(errno));
			}
			else {
				dprintf(ui_getfd(), ">> ");
				for (size_t i = 0; i < N; i++) {
					dprintf(ui_getfd(), "%.2d ", ((uint8_t *) hello_long)[i]);
				}
				dprintf(ui_getfd(), "\n");
			}

			gettimeofday(&debut, NULL);
			tv.tv_sec  = TIME;
			tv.tv_usec = 0;
		}
		// message de Juliusz
		else if (FD_ISSET(g_env->socket, &readfds)) {
			struct sockaddr_in6 sock6;
			socklen_t len;

			dprintf(ui_getfd(), "read\n");
			memset(buff_res, 0, 1024);
			N = recvfrom(g_env->socket, buff_res, 1024, 0, (struct sockaddr *) &sock6, &len);

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
			parse_datagram(buff_res, N); // Pretty parser
			gettimeofday(&current, NULL);
			tv.tv_sec  = TIME - (current.tv_sec - debut.tv_sec);
			tv.tv_usec = 0;
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
	}
} /* client */
