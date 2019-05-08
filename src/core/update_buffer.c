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

// Étapes 2
static t_bool		is_out_of_time(t_neighbour *nei, struct timeval *now){
	struct timeval limite;
	limite.tv_sec = 120;
	limite.tv_usec = 0;
	struct timeval diff = timeval_diff(now, &nei->last_hello);
	return (timeval_min (&limite, &diff) != &limite);

}
static void			build_go_away(t_neighbour *nei){
	t_buffer_tlv_ip * buffer;
	buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
	tlvb_add_goaway(buffer->tlv_builder, 2,(uint8_t *) NO_HELLO, sizeof(NO_HELLO));
}

// Étape 3
static void     build_hello(t_neighbour * nei, struct timeval * now) {
	t_buffer_tlv_ip * buffer;

	if (timeval_min(now, &nei->next_hello) != now) {
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

// Étape 4
static t_bool 	is_out_of_wait(t_acquit *acq){
	return (acq->no_response >=5);
}
static void 	build_au_revoir(t_acquit * acq){
		t_neighbour * nei;
		t_buffer_tlv_ip * buffer;

		nei    = lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))search_nei, acq);
		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_goaway(buffer->tlv_builder, 2, (uint8_t *) NO_ACK, sizeof(NO_ACK));

}

// Étape 5
static void     build_acquit(t_acquit * acq, struct timeval * now) {
	t_neighbour * nei;
	t_message * msg;
	t_buffer_tlv_ip * buffer;

	if (timeval_min(now, &(acq->next_time)) != now) {
		nei    = lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))search_nei, acq);
		msg    = lst_findp(g_env->li_messages, (t_bool(*)(void *, void *))search_msg, acq);
		buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
		tlvb_add_data(buffer->tlv_builder, acq->sender_id, acq->nonce, msg->type, msg->text, msg->length);

		acquit_no_response(acq);
	}
}

// Étape 6
void			ajout_alea_neighbours() {
	size_t		nb_nei;
	int			pos[2];
	t_neighbour	*nei[2];
	t_buffer_tlv_ip * buffer;

	nb_nei = lst_size(g_env->li_neighbours);
	if (nb_nei <= 1 || gen_rand() >= PERCENT_SEND_NEI)
		return ;
	pos[0] = gen_randint(nb_nei);
	pos[1] = gen_randint(nb_nei - 1);
	if (pos[1] >= pos[0])
		pos[1]++;
	nei[0] = lst_get(g_env->li_neighbours, pos[0]);
	nei[1] = lst_get(g_env->li_neighbours, pos[1]);
	buffer = buffer_search(g_env->li_buffer_tlv_ip, nei[0]->ip_port);
	tlvb_add_neighbour(buffer->tlv_builder, nei[1]->ip_port);
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
	// étape 2

	t_neighbour *nei;
	while ((nei = lst_findp(g_env->li_neighbours, (t_bool(*)(void *, void *))is_out_of_time, &now)) != NULL) {
		build_go_away(nei);
		erase_nei(nei);
	}

	// étape 3
	lst_iterp(g_env->li_neighbours, (void(*)(void *, void *))build_hello, &now);
	// étape 4

	t_acquit *acq;
	while((acq = lst_find(g_env->li_acquit, (t_bool(*)(void *))is_out_of_wait)) != NULL) {
		build_au_revoir(acq);
		erase_nei(nei);
	}



	// étape 5
	lst_iterp(g_env->li_acquit, (void(*)(void *, void *))build_acquit, &now);
	// étape 6
	ajout_alea_neighbours();
}
