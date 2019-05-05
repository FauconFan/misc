#include "irc_udp.h"

void parse_padN(uint8_t * tlv) {
	uint16_t len;
	t_bool filled_with_zero;

	dprintf(ui_getfd_log(), "PADN\n");
	len = tlv[1];
	filled_with_zero = TRUE;
	for (uint16_t i = 2; i < len + 2; ++i) {
		if (tlv[i] != 0) {
			filled_with_zero = FALSE;
			break;
		}
	}
	if (filled_with_zero == FALSE) {
		dprintf(ui_getfd_log(), "PADN message but with non zero values...\n");
	}
}
