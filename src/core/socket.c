#include "irc_udp.h"

int     build_socket(void) {
	int sock;
	struct sockaddr_in6 sin6;
	int rc;
	int one  = 1;
	int zero = 0;

	sock = socket(ENV_FAMILY, ENV_SOCKTYPE, ENV_PROTOCOL);
	if (sock < 0) {
		printf("Error Setup socket %s\n", strerror(errno));
		return (sock);
	}
	rc = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)); // reuse port
	if (rc < 0) {
		printf("setsock opt REUSEADDR fail : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}
	rc = setsockopt(sock, IPPROTO_IPV6, IPV6_V6ONLY, &zero, sizeof(zero)); // polymorph socket
	if (rc < 0) {
		printf("setsock opt IPV6_V6ONLY fail : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}
	rc = setsockopt(sock, IPPROTO_IPV6, IPV6_RECVPKTINFO, &one, sizeof(one)); // receive ancillary message
	if (rc < 0) {
		printf("setsock opt IPV6_RECVPKTINFO fail : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}
	memset(&sin6, 0, sizeof(sin6));
	sin6.sin6_family = ENV_FAMILY;
	sin6.sin6_port   = htons(MY_PORT);
	rc = bind(sock, &sin6, sizeof(sin6));
	if (rc < 0) {
		printf("bind failure : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}
	rc = fcntl(sock, F_GETFL);
	if (rc < 0) {
		printf("echec flags non bloquants 1\n");
		close(sock);
		return (-1);
	}
	rc = fcntl(sock, F_SETFL, rc | O_NONBLOCK);
	if (rc < 0) {
		printf("echec flags non bloquants 2\n");
		close(sock);
		return (-1);
	}

	return (sock);
} /* build_socket */
