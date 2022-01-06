#include "irc_udp.h"

void parse_ack(uint8_t * tlv, t_neighbour * nei) {
	uint8_t len;
	uint64_t sender_id;
	uint32_t nonce;
	t_id_nonce_acq id_nonce;

	len = tlv[1];
	if (nei == NULL) {
		dprintf(ui_getfd_log(), "ACK reçu d'un non neighbour\n");
		return;
	}
	if (len != 12) {
		dprintf(ui_getfd_log(), "Inconsistent ack message\n");
		dprintf(ui_getfd_log(), "Wrong len : %d\n", len);
	}
	else {
		sender_id = *(uint64_t *) (tlv + 2);
		nonce     = *(uint32_t *) (tlv + 10);
		dprintf(ui_getfd_log(), "ACK sender id : %016lx, nonce : %08x\n", sender_id, nonce);
		id_nonce.sender_id = sender_id;
		id_nonce.nonce     = nonce;
		id_nonce.dest_id   = nei->id;
		env_remove_acquit_by_id_nonce(id_nonce);
	}
}
