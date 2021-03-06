#include "irc_udp.h"

void     ps2_connect_new_neighbour() {
	t_potential_neighbour * pot_nei;
	t_buffer_tlv_ip * buffer;

	dprintf(ui_getfd_log(), "Step 2 - Connect new Neighbour\n");
	if (g_env->need_neighbours) {
		pot_nei = env_get_pot_nei_available();
		if (pot_nei != NULL) {
			dprintf(ui_getfd_log(), "Try adding new neighbour : ");
			ip_port_print(pot_nei->ip_port, ui_getfd_log());
			dprintf(ui_getfd_log(), "\n");

			pot_nei->no_response++;
			buffer = tlvip_search(g_env->li_buffer_tlv_ip, pot_nei->ip_port);
			tlvb_add_hello_short(buffer->tlv_builder, g_env->id);
			timeval_assign(&pot_nei->last_send, g_env->now);
		}
	}
}
