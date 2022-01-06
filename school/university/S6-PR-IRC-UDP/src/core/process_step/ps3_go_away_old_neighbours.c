#include "irc_udp.h"

static t_bool       is_out_of_time(t_neighbour * nei) {
	struct timeval limite;
	struct timeval diff;

	limite.tv_sec  = 120;
	limite.tv_usec = 0;
	timeval_diff(&diff, g_env->now, nei->last_hello);
	return (timeval_lessthan(limite, diff));
}

void         ps3_go_away_old_neighbours() {
	t_neighbour * nei;
	t_buffer_tlv_ip * buffer;

	dprintf(ui_getfd_log(), "Step 3 - Go Away old Neighbours\n");
	while ((nei = lst_find(g_env->li_neighbours, (t_bool(*)(void *))is_out_of_time)) != NULL) {
		dprintf(ui_getfd_log(), "Found neighbour to say goobye : ");
		nei_print(nei, ui_getfd_log());
		dprintf(ui_getfd_log(), "\n");

		buffer = tlvip_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_goaway(buffer->tlv_builder, 2, (uint8_t *) NO_HELLO, sizeof(NO_HELLO));
		env_erase_nei(nei);
	}
}
