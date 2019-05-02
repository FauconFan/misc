#include "irc_udp.h"

static void        ip_port_assign_brut(t_ip_port * ip_port, uint8_t ip[16], uint16_t port) {
	memcpy(ip_port->ip, ip, 16);
	ip_port->port = port;
}

void        ip_port_assign_sockaddr6(t_ip_port * ip_port, struct sockaddr_in6 in6) {
	ip_port_assign_brut(ip_port, in6.sin6_addr.s6_addr, in6.sin6_port);
}

void        ip_port_assign(t_ip_port * ip_port1, t_ip_port * ip_port2) {
	ip_port_assign_brut(ip_port1, ip_port2->ip, ip_port2->port);
}

void        ip_port_print(t_ip_port ip_port, int fd) {
	dprintf(fd, "{ ip : ");
	for (size_t i = 0; i < 16; ++i) {
		if (i != 0)
			dprintf(fd, " ");
		dprintf(fd, "%.2x", ip_port.ip[i]);
	}
	dprintf(fd, ", port : %d }", ip_port.port);
}

t_bool      ip_port_is_eq(t_ip_port * ip_port1, t_ip_port * ip_port2) {
	return (memcmp(ip_port1->ip, ip_port2->ip, 16) == 0 && ip_port1->port == ip_port2->port);
}
