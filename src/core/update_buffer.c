#include "irc_udp.h"

// Étape 1
static void     delete_old_pot_neighbours(void) {
	lst_removeall_if(g_env->li_potential_neighbours, (t_bool(*)(void *))is_pot_nei_old);
}

// Étape 2
static void     connect_new_neighbour() {
	t_potential_neighbour * pot_nei;
	t_buffer_tlv_ip * buffer;

	if (lst_size(g_env->li_neighbours) < NB_NEI_MAX) {
		pot_nei = pot_nei_get_available(g_env->li_potential_neighbours);
		if (pot_nei != NULL) {
			dprintf(ui_getfd_log(), "Try adding new neighbour : ");
			ip_port_print(pot_nei->ip_port, ui_getfd_log());
			dprintf(ui_getfd_log(), "\n");

			pot_nei->no_response++;
			buffer = buffer_search(g_env->li_buffer_tlv_ip, pot_nei->ip_port);
			tlvb_add_hello_short(buffer->tlv_builder, g_env->id);
			timeval_assign(&pot_nei->last_send, g_env->now);
		}
	}
}

// Étape 3
static t_bool       is_out_of_time(t_neighbour * nei) {
	struct timeval limite;
	struct timeval diff;

	limite.tv_sec  = 120;
	limite.tv_usec = 0;
	timeval_diff(&diff, g_env->now, nei->last_hello);
	return (timeval_lessthan(limite, diff));
}

static void         go_away_old_neighbours() {
	t_neighbour * nei;
	t_buffer_tlv_ip * buffer;

	while ((nei = lst_find(g_env->li_neighbours, (t_bool(*)(void *))is_out_of_time)) != NULL) {
		dprintf(ui_getfd_log(), "Found neighbour to say goobye : ");
		nei_print(nei, ui_getfd_log());
		dprintf(ui_getfd_log(), "\n");

		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_goaway(buffer->tlv_builder, 2, (uint8_t *) NO_HELLO, sizeof(NO_HELLO));
		erase_nei(nei);
	}
}

// Étape 4
static void     build_hello(t_neighbour * nei) {
	t_buffer_tlv_ip * buffer;

	if (timeval_lessthan(nei->next_hello, g_env->now)) {
		dprintf(ui_getfd_log(), "Found neighbour to say long hello : ");
		nei_print(nei, ui_getfd_log());
		dprintf(ui_getfd_log(), "\n");

		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_hello_long(buffer->tlv_builder, g_env->id, nei->id);
		nei->next_hello.tv_sec += TIMEOUT_NEI_TIME;
	}
}

static t_bool   search_nei(t_neighbour * nei, t_acquit * acq) {
	return (nei->id == acq->dest_id);
}

static t_bool   search_msg(t_message * msg, t_acquit * acq) {
	return (msg->sender_id == acq->sender_id && msg->nonce == acq->nonce);
}

static void     send_long_hello() {
	lst_iter(g_env->li_neighbours, (void(*)(void *))build_hello);
}

// Étape 5
static t_bool   is_out_of_wait(t_acquit * acq) {
	return (acq->no_response >= 5);
}

static void     go_away_ack_missing(void) {
	t_acquit * acq;

	while ((acq = lst_find(g_env->li_acquit, (t_bool(*)(void *))is_out_of_wait)) != NULL) {
		t_neighbour * nei;
		t_buffer_tlv_ip * buffer;

		dprintf(ui_getfd_log(), "Found old acquit : ");
		acquit_print(acq, ui_getfd_log());
		dprintf(ui_getfd_log(), "\n");

		nei    = lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))search_nei, acq);
		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_goaway(buffer->tlv_builder, 2, (uint8_t *) NO_ACK, sizeof(NO_ACK));
		erase_nei(nei);
	}
}

// Étape 6
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
		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_data(buffer->tlv_builder, acq->sender_id, acq->nonce, msg->type, msg->text, msg->length);
		acquit_no_response(acq);
	}
}

static void     resend_messages_non_acquitted() {
	lst_iter(g_env->li_acquit, (void(*)(void *))build_acquit);
}

// Étape 7
void            ajout_alea_neighbours(void) {
	size_t nb_nei;
	int pos[2];
	t_neighbour * nei[2];
	t_buffer_tlv_ip * buffer;

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
	buffer = buffer_search(g_env->li_buffer_tlv_ip, nei[0]->ip_port);
	dprintf(ui_getfd_log(), "buffer : %p\n", buffer);
	tlvb_add_neighbour(buffer->tlv_builder, nei[1]->ip_port);
}

static t_bool   search_acq(t_acquit * acq, uint64_t sender_id) {
	return (acq->sender_id == sender_id);
}

static t_bool   check_message(t_message * msg) {
	if (timeval_lessthan(g_env->now, msg->check_timeout)) {
		return (FALSE);
	}
	if (lst_findp(g_env->li_acquit, (t_bool(*)(void *, void *))search_acq, (void *) msg->sender_id) == NULL) {
		dprintf(ui_getfd_log(), "Found message to delete : ");
		message_print(msg, ui_getfd_log());
		dprintf(ui_getfd_log(), "\n");
		return (TRUE);
	}
	msg->check_timeout.tv_sec += TIMEOUT_CHECK_MSG;
	return (FALSE);
}

// Étape 8
void            delete_messages_if_too_late() {
	lst_removeall_if(g_env->li_messages, (t_bool(*)(void *))check_message);
}

// Update buffer

void            update_buffer(void) {
	dprintf(ui_getfd_log(), "current time : ");
	timeval_print(g_env->now, ui_getfd_log());
	dprintf(ui_getfd_log(), "\n");

	// étape 1
	dprintf(ui_getfd_log(), "Step 1 - Delete Old Pot Neighbours\n");
	delete_old_pot_neighbours();
	// étape 2
	dprintf(ui_getfd_log(), "Step 2 - Connect new Neighbour\n");
	connect_new_neighbour();
	// étape 3
	dprintf(ui_getfd_log(), "Step 3 - Go Away old Neighbours\n");
	go_away_old_neighbours();
	// étape 4
	dprintf(ui_getfd_log(), "Step 4 - Send Long Hellos\n");
	send_long_hello();
	// étape 5
	dprintf(ui_getfd_log(), "Step 5 - Go Away Ack missing\n");
	go_away_ack_missing();
	// étape 6
	dprintf(ui_getfd_log(), "Step 6 - Resend messages non acquitted\n");
	resend_messages_non_acquitted();
	// étape 7
	dprintf(ui_getfd_log(), "Step 7 - Send random Neighbour TLV\n");
	ajout_alea_neighbours();
	// étape 8
	dprintf(ui_getfd_log(), "Step 8 - Delete old messages to free space\n");
	delete_messages_if_too_late();
} /* update_buffer */
