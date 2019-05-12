#include "irc_udp.h"

static t_bool   is_out_of_wait(t_acquit * acq) {
	return (acq->no_response >= 5);
}

void     ps5_go_away_ack_missing(void) {
	t_acquit * acq;

	dprintf(ui_getfd_log(), "Step 5 - Go Away Ack missing\n");
	while ((acq = lst_find(g_env->li_acquit, (t_bool(*)(void *))is_out_of_wait)) != NULL) {
		t_neighbour * nei;
		t_buffer_tlv_ip * buffer;

		dprintf(ui_getfd_log(), "Found old acquit : ");
		acquit_print(acq, ui_getfd_log());
		dprintf(ui_getfd_log(), "\n");

		nei    = env_search_nei_by_acq(acq);
		buffer = tlvip_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_goaway(buffer->tlv_builder, 2, (uint8_t *) NO_ACK, sizeof(NO_ACK));
		env_erase_nei(nei);
	}
}
