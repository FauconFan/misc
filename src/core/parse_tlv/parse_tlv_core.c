#include "irc_udp.h"

static uint16_t parse_tlv(uint8_t * tlv, t_neighbour ** nei, t_ip_port ip_port, size_t remain) {
	if (tlv[0] == PAD1) {
		parse_pad1();
		return (1);
	}
	if (remain < tlv[1]) {
		dprintf(ui_getfd_log(), "the actual tlv is too long, received a non well formatted message\n");
		return (2 + tlv[1]);
	}
	switch (tlv[0]) {
		case PADN:
			parse_padN(tlv);
			break;

		case HELLO:
			parse_hello(tlv, nei, ip_port);
			break;

		case NEIGHBOUR:
			parse_neighbour(tlv, *nei);
			break;

		case DATA:
			parse_data(tlv, *nei, ip_port);
			break;

		case ACK:
			parse_ack(tlv, *nei);
			break;

		case GOAWAY:
			parse_goaway(tlv, *nei);
			break;

		case WARNING:
			parse_warning(tlv, *nei);
			break;

		default:
			dprintf(ui_getfd_log(), "unrecognised tlv\n");
			// On suppose que la longueur existe.
	}
	return (2 + tlv[1]);
} /* parse_tlv */

void            parse_datagram(uint8_t * tlv, size_t len, t_neighbour * nei, t_ip_port ip_port) {
	uint16_t len_body;
	uint16_t len_actu;

	if (tlv == NULL) {
		dprintf(ui_getfd_log(), "TLV is null\n");
		return;
	}
	if (len < 4) {
		dprintf(ui_getfd_log(), "TLV too short, can't contain header\n");
		return;
	}
	if (tlv[0] != MAGIC_NUMBER) {
		dprintf(ui_getfd_log(), "Wrong magic number\n");
		return;
	}
	if (tlv[1] != VERSION) {
		dprintf(ui_getfd_log(), "Wrong version\n");
		return;
	}
	len_body = *(uint16_t *) (tlv + 2);
	len_body = ntohs(len_body);
	if (len_body != len - 4) {
		dprintf(ui_getfd_log(), "Wrong len body in header tlv\n");
		dprintf(ui_getfd_log(), "len body : %d\n", len_body);
		dprintf(ui_getfd_log(), "len received : %lu\n", len);
		return;
	}

	len_actu = 4;
	while (len_actu < len) {
		dprintf(ui_getfd_log(), " === ");
		len_actu += parse_tlv(tlv + len_actu, &nei, ip_port, len - len_actu);
	}
} /* parse_datagram */
