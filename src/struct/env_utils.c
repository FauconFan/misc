#include "irc_udp.h"


t_bool          already_received_msg(t_message * msg, t_id_nonce * id_nonce) {
	return is_message(msg, id_nonce->sender_id, id_nonce->nonce);
}

t_bool           search_ack(t_acquit * ack, t_id_nonce * id_nonce) {
	return (is_acquit(ack, id_nonce->dest_id, id_nonce->sender_id, id_nonce->nonce));
}

static void     go_away_for_all(t_neighbour * nei) {
	t_ip_port ip_port;
	t_buffer_tlv_ip * buffer;

	ip_port_assign_brut(&ip_port, nei->ip_port.ip, nei->ip_port.port);
	buffer = buffer_search(g_env->li_buffer_tlv_ip, ip_port);
	tlvb_add_goaway(buffer->tlv_builder, 1, (uint8_t *) GOOD_BYE, sizeof(GOOD_BYE) - 1);
}

void            go_away() {
	dprintf(ui_getfd_log(), "go away protocol called\n");
	lst_iter(g_env->li_neighbours, (void(*)(void *))go_away_for_all);
	clear_buffer();
}

static t_bool   search_acq_nei(t_acquit * acq, t_neighbour * nei) {
	return (nei->id == acq->dest_id);
}

void            erase_nei(t_neighbour * nei) {
	// remove tous les ack
	lst_removeall_ifp(g_env->li_acquit, (t_bool(*)(void *, void *))search_acq_nei, nei);
	// ajout pot_nei
	t_potential_neighbour * pot_nei = pot_nei_alloc(nei->ip_port);
	lst_add(g_env->li_potential_neighbours, pot_nei);
	// remove nei
	lst_remove_ifp(g_env->li_neighbours, (t_bool(*)(void *, void *))nei_is_id, (void *) nei->id);
}
