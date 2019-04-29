#include "irc_udp.h"

static uint16_t parse_pad1(uint8_t * tlv) {
	(void) tlv;
	dprintf(ui_getfd(), "PAD1\n");
	return (1);
}

static uint16_t parse_padN(uint8_t * tlv) {
	uint16_t len;
	t_bool filled_with_zero;

	dprintf(ui_getfd(), "PADN\n");
	len = tlv[1];
	filled_with_zero = TRUE;
	for (size_t i = 0; i < len; ++i) {
		if (tlv[i + 2] != 0) {
			filled_with_zero = FALSE;
			break;
		}
	}
	if (filled_with_zero == FALSE) {
		dprintf(ui_getfd(), "PADN message but with non zero values...\n");
	}
	return (2 + len);
}

static uint16_t parse_hello(uint8_t * tlv) {
	uint16_t len;
	uint64_t source_id;
	uint64_t dest_id;

	len = tlv[1];
	if (len != 8 && len != 16) {
		dprintf(ui_getfd(), "Inconsistent hello message\n");
		dprintf(ui_getfd(), "Wrong len %d\n", len);
	}
	else if (len == 8) {
		source_id = *(uint64_t *) (tlv + 2);
		dprintf(ui_getfd(), "HELLO SHORT Source-id: %016lx\n", source_id);
	}
	else if (len == 16) {
		source_id = *(uint64_t *) (tlv + 2);
		dest_id   = *(uint64_t *) (tlv + 10);
		dprintf(ui_getfd(), "HELLO LONG Source-id: %016lx, Dest-id: %016lx\n", source_id, dest_id);
	}
	return (len + 2);
}

static uint16_t parse_neighbour(uint8_t * tlv) {
	uint16_t len;
	uint8_t * ip;
	uint16_t port;

	len = tlv[1];
	if (len != 18) {
		dprintf(ui_getfd(), "Inconsistent neighbour message\n");
		dprintf(ui_getfd(), "Wrong len %d\n", len);
	}
	else {
		ip   = tlv + 2;
		port = *(uint16_t *) (tlv + 18);
		dprintf(ui_getfd(), "NEIGHBOUR ");
		dprintf(ui_getfd(), "IP : ");
		for (size_t i = 0; i < 16; ++i) {
			dprintf(ui_getfd(), "%.2x ", ip[i]);
		}
		dprintf(ui_getfd(), "Port : %d\n", ntohs(port));
	}
	return (len + 2);
}

static uint16_t parse_data(uint8_t * tlv) {
	uint16_t len;
	uint64_t sender_id;
	uint32_t nounce;
	uint8_t type;
	uint8_t * msg;

	len = tlv[1];
	if (len < 13) {
		dprintf(ui_getfd(), "Inconsistent data message\n");
		dprintf(ui_getfd(), "len too short : %d\n", len);
	}
	else {
		sender_id = *(uint64_t *) (tlv + 2);
		nounce    = *(uint32_t *) (tlv + 10);
		type      = *(uint8_t *) (tlv + 14);
		msg       = tlv + 15;
		dprintf(ui_getfd(), "DATA ");
		dprintf(ui_getfd(), "sender id : %016lx, nounce : %d, type : %d, msg : ", sender_id, nounce, type);
		if (type != 0)
			dprintf(ui_getfd(), "No printable message\n");
		else
			dprintf(ui_getfd(), "\"%.*s\"", len - 13, msg);
	}
	return (len + 2);
}

static uint16_t parse_ack(uint8_t * tlv) {
	uint8_t len;
	uint64_t sender_id;
	uint32_t nounce;

	len = tlv[1];
	if (len != 12) {
		dprintf(ui_getfd(), "Inconsistent ack message\n");
		dprintf(ui_getfd(), "Wrong len : %d\n", len);
	}
	else {
		sender_id = *(uint64_t *) (tlv + 2);
		nounce    = *(uint32_t *) (tlv + 10);
		dprintf(ui_getfd(), "ACK sender id : %016lx, nounce : %d\n", sender_id, nounce);
	}
	return (len + 2);
}

static uint16_t parse_goaway(uint8_t * tlv) {
	uint8_t len;
	uint8_t code;
	uint8_t * msg;

	len = tlv[1];
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
	}
	return (len + 2);
} /* parse_goaway */

static uint16_t parse_warning(uint8_t * tlv) {
	uint8_t len;
	uint8_t * msg;

	len = tlv[1];
	msg = tlv + 3;
	dprintf(ui_getfd(), "WARNING msg : %.*s\n", len, msg);
	return (len + 2);
}

static uint16_t parse_tlv(uint8_t * tlv) {
	switch (tlv[0]) {
		case PAD1:
			return (parse_pad1(tlv));

		case PADN:
			return (parse_padN(tlv));

		case HELLO:
			return (parse_hello(tlv));

		case NEIGHBOUR:
			return (parse_neighbour(tlv));

		case DATA:
			return (parse_data(tlv));

		case ACK:
			return (parse_ack(tlv));

		case GOAWAY:
			return (parse_goaway(tlv));

		case WARNING:
			return (parse_warning(tlv));

		default:
			dprintf(ui_getfd(), "unrecognised tlv\n");
			// On suppose que la longueur existe.
			return tlv[1];
	}
}

void            parse_datagram(uint8_t * tlv, size_t len) {
	uint16_t len_body;
	uint16_t len_actu;

	if (tlv == NULL) {
		dprintf(ui_getfd(), "TLV is null\n");
		return;
	}
	if (len < 4) {
		dprintf(ui_getfd(), "TLV too short, can't contain header\n");
		return;
	}
	if (tlv[0] != MAGIC_NUMBER) {
		dprintf(ui_getfd(), "Wrong magic number\n");
		return;
	}
	if (tlv[1] != VERSION) {
		dprintf(ui_getfd(), "Wrong version\n");
		return;
	}
	len_body = *(uint16_t *) (tlv + 2);
	len_body = ntohs(len_body);
	if (len_body != len - 4) {
		dprintf(ui_getfd(), "Wrong len body in header tlv\n");
		dprintf(ui_getfd(), "len body : %d\n", len_body);
		dprintf(ui_getfd(), "len received : %lu\n", len);
		return;
	}

	len_actu = 4;
	while (len_actu < len) {
		dprintf(ui_getfd(), "=== ");
		len_actu += parse_tlv(tlv + len_actu);
	}
} /* parse_datagram */
