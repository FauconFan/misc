#include "irc_udp.h"

int     build_socket(void) {
	int sock;
	int rc;

	sock = socket(ENV_FAMILY, ENV_SOCKTYPE, ENV_PROTOCOL);
	if (sock < 0) {
		dprintf(ui_getfd_screen(), "Error Setup socket %s\n", strerror(errno));
		return (sock);
	}
	rc = fcntl(sock, F_GETFL);
	if (rc < 0) {
		dprintf(ui_getfd_screen(), "echec flags non bloquants 1\n");
		close(sock);
		return (-1);
	}
	rc = fcntl(sock, F_SETFL, rc | O_NONBLOCK);
	if (rc < 0) {
		dprintf(ui_getfd_screen(), "echec flags non bloquants 2\n");
		close(sock);
		return (-1);
	}
	return (sock);
}
