#include "irc_udp.h"

static t_bool is_acquit_from_sender(t_acquit * acquit, uint64_t dest_id) {
	return (acquit->dest_id == dest_id);
}

void parse_goaway(uint8_t * tlv, t_neighbour * nei) {
	uint8_t len;
	uint8_t code;
	uint8_t * msg;

	len = tlv[1];
	if (nei == NULL) {
		dprintf(ui_getfd(), "GOAWAY reçu d'un non neighbour\n");
		return;
	}
	if (len < 1) {
		dprintf(ui_getfd(), "Inconsistent goaway msg\n");
		dprintf(ui_getfd(), "len is too short : %d\n", len);
	}
	else {
		code = tlv[2];
		dprintf(ui_getfd(), "GOAWAY code %d, meaning : ", code);
		switch (code) {
			case 0:
				dprintf(ui_getfd(), "unknown reason");
				break;
			case 1:
				dprintf(ui_getfd(), "sender quit the system");
				break;
			case 2:
				dprintf(ui_getfd(), "hello message missing for too long");
				break;
			case 3:
				dprintf(ui_getfd(), "sender didn't respect the protocol");
				break;
			case 4:
				dprintf(ui_getfd(), "sender has too many neighbours");
				break;
			default:
				dprintf(ui_getfd(), "unknown code");
				break;
		}
		msg = tlv + 3;
		dprintf(ui_getfd(), ", msg : %.*s\n", len - 1, msg);
		lst_add(g_env->li_potential_neighbours, pot_nei_alloc(nei->ip_port));
		lst_removeall_ifp(g_env->li_acquit, (t_bool(*)(void *, void *))is_acquit_from_sender, (void *) nei->id);
		lst_remove_ifp(g_env->li_neighbours, (t_bool(*)(void *, void *))nei_is_id, (void *) nei->id);
	}
} /* parse_goaway */
