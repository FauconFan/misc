#include "irc_udp.h"

static void     go_away_for_all(t_neighbour * nei) {
	t_ip_port ip_port;
	t_buffer_tlv_ip * buffer;

	ip_port_assign_brut(&ip_port, nei->ip_port.ip, nei->ip_port.port);
	buffer = tlvip_search(g_env->li_buffer_tlv_ip, ip_port);
	tlvb_add_goaway(buffer->tlv_builder, 1, (uint8_t *) GOOD_BYE, sizeof(GOOD_BYE) - 1);
}

void env_go_away_all() {
	dprintf(ui_getfd_log(), "go away protocol called\n");
	lst_iter(g_env->li_neighbours, (void(*)(void *))go_away_for_all);
	clear_buffer();
	lst_clear(g_env->li_neighbours);
}
