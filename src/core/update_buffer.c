#include "irc_udp.h"

// Étape 1

static void     good_num_neighbours(struct timeval * now) {
	t_potential_neighbour * pot_nei;
	t_buffer_tlv_ip * buffer;

	if (lst_size(g_env->li_neighbours) < NB_NEI_MAX) {
		pot_nei = pot_nei_get_available(g_env->li_potential_neighbours, now);
		if (pot_nei != NULL) {
			buffer = buffer_search(g_env->li_buffer_tlv_ip, pot_nei->ip_port);
			tlvb_add_hello_short(buffer->tlv_builder, g_env->id);
			timeval_assign(&pot_nei->last_send, now);
		}
	}
}

// Étapes 2 et 3

static void     build_hello(t_neighbour * nei, struct timeval * now) {
	t_buffer_tlv_ip * buffer;
	struct timeval limite;
	limite.tv_sec = 120;
	limite.tv_usec = 0;
	struct timeval diff = timeval_diff(now, &nei->last_hello);
	if (timeval_min (&limite, &diff) != &limite){
		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		char msg[] = "No hello receivedfor too long";
		tlvb_add_goaway(buffer->tlv_builder, 2, (uint8_t *)msg, sizeof(msg));
	}
	else if (timeval_min(now, &nei->next_hello) != now) {
		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_hello_long(buffer->tlv_builder, g_env->id, nei->id);
		nei->next_hello.tv_sec += TIMEOUT_NEI_TIME;
	}
}

// Étape 4 et 5

static t_bool   search_nei(t_neighbour * nei, t_acquit * acq) {
	return (nei->id == acq->dest_id);
}

static t_bool   search_msg(t_message * msg, t_acquit * acq) {
	return (msg->sender_id == acq->sender_id && msg->nonce == acq->nonce);
}

static void     build_acquit(t_acquit * acq, struct timeval * now) {
	t_neighbour * nei;
	t_message * msg;
	t_buffer_tlv_ip * buffer;

	nei    = lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))search_nei, acq);
	if (acq->no_response >= 5){
		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		char msg[14] = "No ack in time";
		tlvb_add_goaway(buffer->tlv_builder, 2, (uint8_t *) msg, 14);
	}

	if (timeval_min(now, &(acq->next_time)) != now) {
		msg    = lst_findp(g_env->li_messages, (t_bool(*)(void *, void *))search_msg, acq);
		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_data(buffer->tlv_builder, acq->sender_id, acq->nonce, msg->type, msg->text, msg->length);

		acquit_no_response(acq);
	}
}

// Update buffer

void            update_buffer() {
	struct timeval now;

	gettimeofday(&now, NULL);

	dprintf(ui_getfd_log(), "current time : ");
	timeval_print(now, ui_getfd_log());
	dprintf(ui_getfd_log(), "\n");
	// étape 1
	good_num_neighbours(&now);
	// étape 2 et 3
	lst_iterp(g_env->li_neighbours, (void(*)(void *, void *))build_hello, &now);
	// étape 4 et 5
	lst_iterp(g_env->li_acquit, (void(*)(void *, void *))build_acquit, &now);
	// étape 6, ajouter des neighbours aléatoirement
	/* uint8_t piece = gen_pile_face();
	if (piece % 2== 1){
		send_nei();
	}*/
}
