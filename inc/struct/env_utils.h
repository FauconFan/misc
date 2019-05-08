#ifndef ENV_UTILS_H
#define ENV_UTILS_H


typedef struct  s_id_nonce{
	uint64_t sender_id;
	uint32_t nonce;
	uint64_t dest_id;
}               t_id_nonce;

t_bool          search_ack(t_acquit * ack, t_id_nonce * id_nonce);
t_bool          already_received_msg(t_message * msg, t_id_nonce * id_nonce);


// Pour envoyer un go_away à nos voisins quand on quitte le réseau
void            go_away();

void 			erase_nei(t_neighbour *nei);

#endif
