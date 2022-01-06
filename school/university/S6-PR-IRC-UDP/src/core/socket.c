#include "irc_udp.h"

int     build_socket(int port) {
	int sock;
	struct sockaddr_in6 sin6;
	int rc;
	static const int one  = 1;
	static const int zero = 0;

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
	if (port != NO_PORT)
		sin6.sin6_port = htons(port);
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

t_bool build_sockaddr_multicast(struct sockaddr_in6 * sin6) {
	struct ifaddrs * ifap;
	char * name_if;
	int rc;

	rc = getifaddrs(&ifap);
	if (rc < 0) {
		printf("getifaddrs failed : %s\n", strerror(errno));
		return (FALSE);
	}

	name_if = NULL;
	for (struct ifaddrs * ifap_i = ifap; ifap_i != NULL; ifap_i = ifap_i->ifa_next) {
		if (ifap_i->ifa_flags & IFF_UP && ifap_i->ifa_flags & IFF_RUNNING && strncmp(ifap_i->ifa_name, "lo", 2) != 0) {
			name_if = strdup(ifap_i->ifa_name);
			break;
		}
	}
	freeifaddrs(ifap);
	if (name_if == NULL)
		return (FALSE);

	memset(sin6, 0, sizeof(*sin6));
	sin6->sin6_family = AF_INET6;
	rc = inet_pton(AF_INET6, MULTICAST_ADDR, &sin6->sin6_addr);
	if (rc < 0) {
		printf("inet_pton fail : %s\n", strerror(errno));
		free(name_if);
		return (FALSE);
	}
	sin6->sin6_port     = htons(MULTICAST_PORT);
	sin6->sin6_scope_id = if_nametoindex(name_if);
	free(name_if);
	return (TRUE);
} /* build_sockaddr_multicast */

int build_socket_multicast(void) {
	int sock;
	int rc;
	struct sockaddr_in6 sin6;
	static const int one  = 1;
	static const int zero = 0;

	if (build_sockaddr_multicast(&sin6) == FALSE)
		return (-1);

	sock = socket(ENV_FAMILY, ENV_SOCKTYPE, ENV_PROTOCOL);

	rc = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
	if (rc < 0) {
		printf("setsock opt SO_REUSEADDR fail : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}
	rc = setsockopt(sock, IPPROTO_IPV6, IPV6_V6ONLY, &one, sizeof(one));
	if (rc < 0) {
		printf("setsock opt IPV6_V6ONLY fail : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}
	rc = setsockopt(sock, IPPROTO_IPV6, IPV6_UNICAST_HOPS, &one, sizeof(one));
	if (rc < 0) {
		printf("setsock opt IPV6_UNICAST_HOPS fail : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}
	rc = setsockopt(sock, IPPROTO_IPV6, IPV6_MULTICAST_HOPS, &one, sizeof(one));
	if (rc < 0) {
		printf("setsock opt IPV6_MULTICAST_HOPS fail : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}
	rc = setsockopt(sock, IPPROTO_IPV6, IPV6_MULTICAST_LOOP, &zero, sizeof(zero));
	if (rc < 0) {
		printf("setsock opt IPV6_MULTICAST_LOOP fail : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}
	rc = bind(sock, &sin6, sizeof(sin6));
	if (rc < 0) {
		printf("bind failure : %s\n", strerror(errno));
		close(sock);
		return (-1);
	}

	struct ipv6_mreq mreq;

	memset(&mreq, 0, sizeof(mreq));
	memcpy(&mreq.ipv6mr_multiaddr, &sin6.sin6_addr, sizeof(sin6.sin6_addr));
	mreq.ipv6mr_interface = sin6.sin6_scope_id;

	rc = setsockopt(sock, IPPROTO_IPV6, IPV6_JOIN_GROUP, &mreq, sizeof(mreq));
	if (rc < 0) {
		printf("setsock opt IPV6_JOIN_GROUP : %s\n", strerror(errno));
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
} /* build_socket_multicast */
