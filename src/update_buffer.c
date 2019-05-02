#include "irc_udp.h"

// Étape 1

static void     good_num_neighbours(struct timeval * now) {
	t_potential_neighbour * pot_nei;

	pot_nei = NULL;
	if (lst_size(g_env->li_neighbours) < NB_NEI_MAX) {
		pot_nei = pot_nei_get_available(g_env->li_potential_neighbours, now);
		if (pot_nei != NULL) {
			t_buffer_tlv_ip * buffer = buffer_search(g_env->li_buffer_tlv_ip, pot_nei->ip_port);
			tlvb_add_hello(buffer->tlv_builder, g_env->id, 0);
		}
	}
}

// Étape 2

static t_bool   search_nei(t_neighbour * nei, t_acquit * acq) {
	return (nei->id == acq->sender_id );
}

static t_bool   search_msg(t_message * msg, t_acquit * acq) {
	return (msg->sender_id == acq->sender_id && msg->nonce == acq->nonce);
}

static void     build_hello(t_neighbour * nei, struct timeval * now) {
	if (timeval_min(*now, nei->next_hello) != now) {
		t_buffer_tlv_ip * buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_hello(buffer->tlv_builder, g_env->id, nei->id);
		nei->next_hello.tv_sec += 30;
	}
}

// Étape 4

static void     build_acquit(t_acquit * acq, struct timeval * now) {
	if (timeval_min(*now, acq->next_time) != now) {
		t_neighbour * nei = lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))search_nei, acq);
		t_message * msg   = lst_findp(g_env->li_messages, (t_bool(*)(void *, void *))search_msg, acq);

		t_buffer_tlv_ip * buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_data(buffer->tlv_builder, acq->sender_id, acq->nonce, msg->type, msg->text, msg->length);

		acquit_no_response(acq);
	}
}

void            update_buffer() {
	struct timeval now;

	gettimeofday(&now, NULL);

	// étape 1
	good_num_neighbours(&now);
	// étape 2
	lst_iterp(g_env->li_neighbours, (void(*)(void *, void *))build_hello, &now);
	// étape 4
	lst_iterp(g_env->li_acquit, (void(*)(void *, void *))build_acquit, &now);
}
