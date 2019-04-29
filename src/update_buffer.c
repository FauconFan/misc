#include "irc_udp.h"

static t_bool   search_nei(t_neighbour * nei, t_acquit * acq) {
	return (nei->id == acq->sender_id );
}

static t_bool   search_msg(t_message * msg, t_acquit * acq) {
	return (msg->sender_id == acq->sender_id && msg->nonce == acq->nonce);
}

static void     build_hello(t_neighbour * nei, struct timeval * now) {
	if (min_time(*now, nei->next_hello) != now) {
		t_buffer_tlv_ip * buffer = buffer_search(nei->ip, nei->port);
		tlvb_add_hello(buffer->tlv_builder, g_env->id, nei->id);
		nei->next_hello.tv_sec += 30;
	}
}

static void     build_acquit(t_acquit * acq, struct timeval * now) {
	if (min_time(*now, acq->next_time) != now) {
		t_neighbour * nei = lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))search_nei, acq);
		t_message * msg   = lst_findp(g_env->li_messages, (t_bool(*)(void *, void *))search_msg, acq);

		t_buffer_tlv_ip * buffer = buffer_search(nei->ip, nei->port);
		tlvb_add_data(buffer->tlv_builder, acq->sender_id, acq->nonce, msg->type, msg->text, msg->length);

		acquit_no_response(acq);
	}
}

void            update_buffer() {
	struct timeval now;

	gettimeofday(&now, NULL);
	// iter dans li_neighbours
	lst_iterp(g_env->li_neighbours, (void(*)(void *, void *))build_hello, &now);
	// iter dans li_acquit
	lst_iterp(g_env->li_acquit, (void(*)(void *, void *))build_acquit, &now);
}
