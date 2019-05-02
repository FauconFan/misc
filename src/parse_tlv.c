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

static uint16_t parse_hello(uint8_t * tlv, t_neighbour * nei, t_ip_port ip_port) {
	uint16_t len;
	uint64_t source_id;
	uint64_t dest_id;
	struct timeval now;

	gettimeofday(&now, NULL);

	len = tlv[1];
	if (len != 8 && len != 16) {
		dprintf(ui_getfd(), "Inconsistent hello message\n");
		dprintf(ui_getfd(), "Wrong len %d\n", len);
	}
	else if (len == 8) {
		source_id = *(uint64_t *) (tlv + 2);
		dprintf(ui_getfd(), "HELLO SHORT Source-id: %016lx\n", source_id);
		if (nei != NULL) {
			nei->last_hello = now;
		}
		else {
			if (lst_size(g_env->li_neighbours) <= NB_NEI_MAX) {
				nei = nei_alloc(source_id, ip_port);
			}
			else {
				lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip_port));
			}
		}
	}
	else if (len == 16) {
		source_id = *(uint64_t *) (tlv + 2);
		dest_id   = *(uint64_t *) (tlv + 10);
		dprintf(ui_getfd(), "HELLO LONG Source-id: %016lx, Dest-id: %016lx\n", source_id, dest_id);
		if (nei != NULL) {
			nei->last_hello      = now;
			nei->last_hello_long = now;
		}
		else {
			nei = nei_alloc(source_id, ip_port);
			lst_remove_ifp(g_env->li_potential_neighbours, (t_bool(*)(void *, void *))pot_nei_is, &ip_port);
		}
	}
	return (len + 2);
} /* parse_hello */

static uint16_t parse_neighbour(uint8_t * tlv, t_neighbour * nei, t_ip_port ip_port) {
	uint16_t len;
	uint8_t * ip;
	uint16_t port;

	len = tlv[1];
	if (nei == NULL) {
		dprintf(ui_getfd(), "neighbour reçu d'un non neighbour");
		return (len + 2);
	}
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
		lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip_port));
	}
	return (len + 2);
}

typedef struct      s_id_nonce{
	uint64_t sender_id;
	uint32_t nonce;
	// je sais que c'est moche mais voila quoi
	uint64_t dest_id;
}                   t_id_nonce;

static t_bool search_msg(t_message * msg, t_id_nonce * id_nonce) {
	return is_message(msg, id_nonce->sender_id, id_nonce->nonce);
}

static void forall_nei(t_neighbour * nei, uint8_t * tlv) {
	t_buffer_tlv_ip * buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
	uint16_t len       = tlv[1];
	uint64_t sender_id = *(uint64_t *) (tlv + 2);
	uint32_t nonce     = *(uint32_t *) (tlv + 10);
	uint8_t type       = *(uint8_t *) (tlv + 14);
	uint8_t * msg      = tlv + 15;

	tlvb_add_data(buffer->tlv_builder, sender_id, nonce, type, msg, len);
}

static uint16_t parse_data(uint8_t * tlv, t_neighbour * nei, t_ip_port ip_port) {
	uint16_t len;
	uint64_t sender_id;
	uint32_t nonce;
	uint8_t type;
	uint8_t * msg;

	len = tlv[1];
	if (nei == NULL) {
		dprintf(ui_getfd(), "data reçu d'un non neighbour");
		return (len + 2);
	}
	if (len < 13) {
		dprintf(ui_getfd(), "Inconsistent data message\n");
		dprintf(ui_getfd(), "len too short : %d\n", len);
	}
	else {
		sender_id = *(uint64_t *) (tlv + 2);
		nonce     = *(uint32_t *) (tlv + 10);
		type      = *(uint8_t *) (tlv + 14);
		msg       = tlv + 15;

		t_id_nonce id_nonce;
		id_nonce.sender_id = sender_id;
		id_nonce.nonce     = nonce;

		if (lst_findp(g_env->li_messages, (t_bool(*)(void *, void *))search_msg, &id_nonce) == NULL) {
			dprintf(ui_getfd(), "DATA ");
			dprintf(ui_getfd(), "sender id : %016lx, nonce : %d, type : %d, msg : ", sender_id, nonce, type);
			if (type != 0)
				dprintf(ui_getfd(), "No printable message\n");
			else
				dprintf(ui_getfd(), "\"%.*s\"", len - 13, msg);
			t_buffer_tlv_ip * buffer = buffer_search(g_env->li_buffer_tlv_ip, ip_port);
			tlvb_add_ack(buffer->tlv_builder, sender_id, nonce);

			lst_iterp(g_env->li_neighbours, (void(*)(void *, void *))forall_nei, tlv);
		}
	}
	return (len + 2);
} /* parse_data */

static t_bool   search_ack(t_acquit * ack, t_id_nonce id_nonce) {
	return is_acquit(ack, id_nonce.dest_id, id_nonce.sender_id, id_nonce.nonce);
}

static uint16_t parse_ack(uint8_t * tlv, t_neighbour * nei) {
	uint8_t len;
	uint64_t sender_id;
	uint32_t nonce;

	len = tlv[1];
	if (nei != NULL) {
		dprintf(ui_getfd(), "ack reçu d'un non neighbour");
		return (len + 2);
	}
	if (len != 12) {
		dprintf(ui_getfd(), "Inconsistent ack message\n");
		dprintf(ui_getfd(), "Wrong len : %d\n", len);
	}
	else {
		sender_id = *(uint64_t *) (tlv + 2);
		nonce     = *(uint32_t *) (tlv + 10);
		dprintf(ui_getfd(), "ACK sender id : %016lx, nonce : %d\n", sender_id, nonce);
		t_id_nonce id_nonce;
		id_nonce.sender_id = sender_id;
		id_nonce.nonce     = nonce;
		id_nonce.dest_id   = nei->id;
		lst_remove_ifp(g_env->li_acquit, (t_bool(*)(void *, void *))search_ack, &id_nonce);
	}
	return (len + 2);
}

static uint16_t parse_goaway(uint8_t * tlv, t_neighbour * nei) {
	uint8_t len;
	uint8_t code;
	uint8_t * msg;

	len = tlv[1];
	if (nei == NULL) {
		dprintf(ui_getfd(), "GoAway reçu d'un non neighbour");
		return (len + 2);
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
				lst_remove_ifp(g_env->li_neighbours, (t_bool(*)(void *, void *))nei_is_id, (void *) (nei->id));
		}
		msg = tlv + 3;
		dprintf(ui_getfd(), ", msg : %.*s\n", len - 1, msg);
	}
	return (len + 2);
} /* parse_goaway */

static uint16_t parse_warning(uint8_t * tlv, t_neighbour * nei) {
	uint8_t len;
	uint8_t * msg;

	len = tlv[1];
	if (nei == NULL) {
		dprintf(ui_getfd(), "warning reçu d'un non neighbour");
		return (len + 2);
	}
	msg = tlv + 3;
	dprintf(ui_getfd(), "WARNING msg : %.*s\n", len, msg);
	return (len + 2);
}

static uint16_t parse_tlv(uint8_t * tlv, t_neighbour * nei, t_ip_port ip_port) {
	switch (tlv[0]) {
		case PAD1:
			return (parse_pad1(tlv));

		case PADN:
			return (parse_padN(tlv));

		case HELLO:
			return (parse_hello(tlv, nei, ip_port));

		case NEIGHBOUR:
			return (parse_neighbour(tlv, nei, ip_port));

		case DATA:
			return (parse_data(tlv, nei, ip_port));

		case ACK:
			return (parse_ack(tlv, nei));

		case GOAWAY:
			return (parse_goaway(tlv, nei));

		case WARNING:
			return (parse_warning(tlv, nei));

		default:
			dprintf(ui_getfd(), "unrecognised tlv\n");
			// On suppose que la longueur existe.
			return tlv[1];
	}
}

void            parse_datagram(uint8_t * tlv, size_t len, t_neighbour * nei, t_ip_port ip_port) {
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
		len_actu += parse_tlv(tlv + len_actu, nei, ip_port);
	}
} /* parse_datagram */
