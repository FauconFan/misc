#include "irc_udp.h"

t_bool      get_sockaddr_juliusz(
  struct sockaddr_in6 * sock_addr) {
	return (get_sockaddr(JCH_NODE, JCH_SERVICE, sock_addr));
}

t_bool      get_sockaddr(
  const char *          node,
  const char *          service,
  struct sockaddr_in6 * sock_addr) {
	struct addrinfo hints;
	struct addrinfo * res;
	struct addrinfo * p;
	int rc;
	int s;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family   = ENV_FAMILY;
	hints.ai_socktype = ENV_SOCKTYPE;
	hints.ai_protocol = ENV_PROTOCOL;
	hints.ai_flags    = ENV_FLAGS;

	rc = getaddrinfo(node, service, &hints, &res);
	if (rc != 0) {
		dprintf(ui_getfd_screen(), "Échec cinglant : %s\n", gai_strerror(rc));
		return (FALSE);
	}

	for (p = res; p != NULL; p = p->ai_next) {
		s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (s < 0) {
			close(s);
			continue;
		}
		close(s);
		break;
	}

	if (p == NULL) {
		dprintf(ui_getfd_screen(), "La connection a échoué.\n");
		freeaddrinfo(res);
		return (FALSE);
	}
	memcpy(sock_addr, p->ai_addr, sizeof(*sock_addr));
	freeaddrinfo(res);
	return (TRUE);
} /* get_sockaddr */
