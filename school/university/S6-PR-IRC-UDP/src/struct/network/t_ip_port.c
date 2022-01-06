#include "irc_udp.h"

void        ip_port_assign_brut(t_ip_port * ip_port, uint8_t ip[16], uint16_t port) {
	memcpy(ip_port->ip, ip, 16);
	ip_port->port = port;
}

void        ip_port_assign_sockaddr6(t_ip_port * ip_port, struct sockaddr_in6 in6) {
	ip_port_assign_brut(ip_port, in6.sin6_addr.s6_addr, in6.sin6_port);
}

void        ip_port_assign(t_ip_port * ip_port1, t_ip_port ip_port2) {
	ip_port_assign_brut(ip_port1, ip_port2.ip, ip_port2.port);
}

void        ip_port_print(t_ip_port ip_port, int fd) {
	uint16_t ip32[8];
	uint8_t nprevzeros;

	for (size_t i = 0; i < 8; i++) {
		ip32[i] = (ip_port.ip[2 * i] << 8) | ip_port.ip[2 * i + 1];
	}
	nprevzeros = 0;
	dprintf(fd, "{ ip \"");
	if (ip32[0] != 0)
		dprintf(fd, "%.4x", ip32[0]);
	for (size_t i = 1; i < 8; ++i) {
		if (nprevzeros < 2)
			dprintf(fd, ":");
		if (ip32[i] == 0) {
			nprevzeros++;
		}
		else {
			dprintf(fd, "%.4x", ip32[i]);
			nprevzeros = 0;
		}
	}
	dprintf(fd, "\", port : %d }", ntohs(ip_port.port));
}

t_bool      ip_port_is_eq(t_ip_port ip_port1, t_ip_port ip_port2) {
	return (memcmp(ip_port1.ip, ip_port2.ip, 16) == 0 && ip_port1.port == ip_port2.port);
}
