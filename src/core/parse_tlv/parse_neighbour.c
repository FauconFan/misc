#include "irc_udp.h"

void parse_neighbour(uint8_t * tlv, t_neighbour * nei) {
	uint16_t len;
	uint8_t * ip;
	uint16_t port;

	len = tlv[1];
	if (nei == NULL) {
		dprintf(ui_getfd_log(), "NEIGHBOUR reçu d'un non neighbour\n");
		return;
	}
	if (len != 18) {
		dprintf(ui_getfd_log(), "Inconsistent neighbour message\n");
		dprintf(ui_getfd_log(), "Wrong len %d\n", len);
	}
	else {
		ip   = tlv + 2;
		port = *(uint16_t *) (tlv + 18);
		dprintf(ui_getfd_log(), "NEIGHBOUR ");
		dprintf(ui_getfd_log(), "IP : ");
		for (size_t i = 0; i < 16; ++i) {
			dprintf(ui_getfd_log(), "%.2x ", ip[i]);
		}
		dprintf(ui_getfd_log(), "Port : %d\n", ntohs(port));
		t_ip_port ip_port2;
		ip_port_assign_brut(&ip_port2, ip, port);
		if (lst_findp(g_env->li_potential_neighbours, (t_bool(*)(void *, void *))pot_nei_is, &ip_port2) == NULL &&
		  nei_search_neighbour(g_env->li_neighbours, ip_port2) == NULL)
			lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip_port2));
	}
}
