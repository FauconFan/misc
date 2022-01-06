#include "irc_udp.h"

static t_bool   search_nei(t_neighbour * nei, t_acquit * acq) {
	return (nei->id == acq->dest_id);
}

static t_bool   search_msg(t_message * msg, t_acquit * acq) {
	return (msg->sender_id == acq->sender_id && msg->nonce == acq->nonce);
}

static void     build_acquit(t_acquit * acq) {
	t_neighbour * nei;
	t_message * msg;
	t_buffer_tlv_ip * buffer;

	if (timeval_lessthan(acq->next_time, g_env->now)) {
		dprintf(ui_getfd_log(), "build acquit ");
		acquit_print(acq, ui_getfd_log());
		dprintf(ui_getfd_log(), "\n");

		nei    = lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))search_nei, acq);
		msg    = lst_findp(g_env->li_messages, (t_bool(*)(void *, void *))search_msg, acq);
		buffer = tlvip_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_data(buffer->tlv_builder, acq->sender_id, acq->nonce, msg->type, msg->text, msg->length);
		acquit_no_response(acq);
	}
}

void     ps6_resend_messages_non_acquitted() {
	dprintf(ui_getfd_log(), "Step 6 - Resend messages non acquitted\n");
	lst_iter(g_env->li_acquit, (void(*)(void *))build_acquit);
}
