#include "irc_udp.h"

static t_bool search_acq_by_id_nonce(t_acquit * ack, t_id_nonce_acq * id_nonce) {
	return (is_acquit(ack, id_nonce->dest_id, id_nonce->sender_id, id_nonce->nonce));
}

void env_remove_acquit_by_id_nonce(t_id_nonce_acq id_nonce) {
	lst_remove_ifp(g_env->li_acquit, (t_bool(*)(void *, void *))search_acq_by_id_nonce, &id_nonce);
}
