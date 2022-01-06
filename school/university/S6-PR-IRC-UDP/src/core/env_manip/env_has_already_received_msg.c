#include "irc_udp.h"

static t_bool already_received_msg(t_message * msg, t_id_nonce_msg * id_nonce) {
	return (is_message(msg, id_nonce->sender_id, id_nonce->nonce));
}

t_bool env_has_already_received_msg(t_id_nonce_msg id_nonce) {
	return (lst_findp(g_env->li_messages, (t_bool(*)(void *, void *))already_received_msg, &id_nonce) != NULL);
}
