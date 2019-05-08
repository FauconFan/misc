#include "irc_udp.h"



t_bool          already_received_msg(t_message * msg, t_id_nonce * id_nonce) {
	return is_message(msg, id_nonce->sender_id, id_nonce->nonce);
}

t_bool           search_ack(t_acquit * ack, t_id_nonce * id_nonce) {
	return (is_acquit(ack, id_nonce->dest_id, id_nonce->sender_id, id_nonce->nonce));
}



static void     go_away_for_all(t_neighbour *nei){
    t_ip_port ip_port;
    t_buffer_tlv_ip *buffer;
    ip_port_assign_brut(&ip_port, nei->ip_port.ip, nei->ip_port.port);
    buffer = buffer_search(g_env->li_neighbours, ip_port);
    char msg[11] = "Au revoir";
    tlvb_add_goaway(buffer->tlv_builder, 1, (uint8_t *) msg, 11);
}



void            go_away(){
    lst_iter(g_env->li_neighbours, (void (*)(void *))go_away_for_all);
    clear_buffer();
}
