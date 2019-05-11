#include "irc_udp.h"

void            ps7_send_random_neighbour_tlv(void) {
	size_t nb_nei;
	int pos[2];
	t_neighbour * nei[2];
	t_buffer_tlv_ip * buffer;

	dprintf(ui_getfd_log(), "Step 7 - Send random Neighbour TLV\n");

	nb_nei = lst_size(g_env->li_neighbours);
	if (nb_nei <= 1 || gen_rand() >= PERCENT_SEND_NEI)
		return;

	pos[0] = gen_randint(nb_nei);
	pos[1] = gen_randint(nb_nei - 1);
	if (pos[1] >= pos[0])
		pos[1]++;
	dprintf(ui_getfd_log(), "Sending neighbours\n");
	nei[0] = lst_get(g_env->li_neighbours, pos[0]);
	nei[1] = lst_get(g_env->li_neighbours, pos[1]);
	dprintf(ui_getfd_log(), "nei0 : %p, nei1 : %p\n", nei[0], nei[1]);
	buffer = tlvip_search(g_env->li_buffer_tlv_ip, nei[0]->ip_port);
	dprintf(ui_getfd_log(), "buffer : %p\n", buffer);
	tlvb_add_neighbour(buffer->tlv_builder, nei[1]->ip_port);
}
