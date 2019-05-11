#include "irc_udp.h"

void     ps2_connect_new_neighbour() {
	t_potential_neighbour * pot_nei;
	t_buffer_tlv_ip * buffer;

	dprintf(ui_getfd_log(), "Step 2 - Connect new Neighbour\n");
	if (lst_size(g_env->li_neighbours) < NB_NEI_MAX) {
		pot_nei = pot_nei_get_available(g_env->li_potential_neighbours);
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
