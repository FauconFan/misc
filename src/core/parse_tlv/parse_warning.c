#include "irc_udp.h"

void parse_warning(uint8_t * tlv, t_neighbour * nei) {
	uint8_t len;
	uint8_t * msg;

	len = tlv[1];
	if (nei == NULL) {
		dprintf(ui_getfd(), "WARNING reçu d'un non neighbour\n");
		return;
	}
	msg = tlv + 3;
	dprintf(ui_getfd(), "WARNING msg : %.*s\n", len, msg);
}
