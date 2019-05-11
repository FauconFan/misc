#include "irc_udp.h"

static void     build_hello(t_neighbour * nei) {
	t_buffer_tlv_ip * buffer;

	if (timeval_lessthan(nei->next_hello, g_env->now)) {
		dprintf(ui_getfd_log(), "Found neighbour to say long hello : ");
		nei_print(nei, ui_getfd_log());
		dprintf(ui_getfd_log(), "\n");

		buffer = tlvip_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_hello_long(buffer->tlv_builder, g_env->id, nei->id);
		nei->next_hello.tv_sec += TIMEOUT_NEI_TIME;
	}
}

void     ps4_send_long_hello() {
	dprintf(ui_getfd_log(), "Step 4 - Send Long Hellos\n");
	lst_iter(g_env->li_neighbours, (void(*)(void *))build_hello);
}
