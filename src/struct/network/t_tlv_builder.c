#include "irc_udp.h"

t_tlv_builder * tlvb_alloc(void) {
	t_tlv_builder * tlv;
	const uint8_t header[2] = {MAGIC_NUMBER, VERSION};

	if ((tlv = (t_tlv_builder *) malloc(sizeof(t_tlv_builder))) == NULL) {
		return (NULL);
	}
	if ((tlv->msg = iovb_alloc()) == NULL) {
		free(tlv);
		return (NULL);
	}
	if (iovb_push(tlv->msg, header, 2) == FALSE) {
		iovb_free(tlv->msg);
		free(tlv);
		return (NULL);
	}
	tlv->len_body       = 0;
	tlv->index_len_body = iovb_get_index(tlv->msg);
	tlv->ready = FALSE;
	iovb_skip(tlv->msg);
	return (tlv);
}

t_bool      tlvb_finish(t_tlv_builder * tlv) {
	if (tlv == NULL || tlv->ready)
		return (FALSE);

	uint16_t len = htons(tlv->len_body);
	iovb_set(tlv->msg, tlv->index_len_body, &len, 2);
	tlv->ready = TRUE;
	return (TRUE);
}

void        tlvb_free(t_tlv_builder * tlv) {
	if (tlv == NULL)
		return;

	iovb_free(tlv->msg);
	free(tlv);
}

static t_bool   tlvb_add_type(t_tlv_builder * tlv, t_tlv_type t) {
	uint8_t type[1] = {t};

	tlv->len_body++;
	return (iovb_push(tlv->msg, type, 1));
}

static t_bool   tlvb_add_value(t_tlv_builder * tlv, const void * v, size_t l) {
	uint8_t length[1] = {l};

	if (iovb_push(tlv->msg, length, 1) == FALSE)
		return (FALSE);

	tlv->len_body += l + 1;
	return (iovb_push(tlv->msg, v, l));
}

t_bool      tlvb_add_pad1(t_tlv_builder * tlv) {
	if (tlv == NULL || tlv->ready)
		return (FALSE);

	if (tlvb_add_type(tlv, PAD1) == FALSE)
		return (FALSE);

	return (TRUE);
}

t_bool      tlvb_add_padN(t_tlv_builder * tlv, size_t l) {
	const uint8_t zeros[4096] = {0};

	if (tlv == NULL || tlv->ready || l >= 4096)
		return (FALSE);

	if (tlvb_add_type(tlv, PADN) == FALSE)
		return (FALSE);

	return (tlvb_add_value(tlv, zeros, l));
}

t_bool      tlvb_add_hello(t_tlv_builder * tlv, uint64_t id1, uint64_t id2) {
	if (tlv == NULL || tlv->ready)
		return (FALSE);

	if (tlvb_add_type(tlv, HELLO) == FALSE)
		return (FALSE);

	uint8_t id[16];
	size_t taille = 8;
	memcpy(id, ((uint8_t *) &id1), 8);

	if (id2 != 0) {
		taille = 16;
		memcpy(id + 8, ((uint8_t *) &id2), 8);
	}

	return (tlvb_add_value(tlv, id, taille));
}

t_bool      tlvb_add_neighbour(t_tlv_builder * tlv, uint8_t ip[16], uint16_t port) {
	if (tlv == NULL || tlv->ready || ip == NULL)
		return (FALSE);

	if (tlvb_add_type(tlv, NEIGHBOUR) == FALSE)
		return (FALSE);

	uint8_t msg[18];
	memcpy(msg, ip, 16);
	memcpy(msg + 16, ((uint8_t *) &port), 2);
	return (tlvb_add_value(tlv, msg, 18));
}

t_bool      tlvb_add_data(t_tlv_builder * tlv, uint64_t id, uint32_t nonce, uint8_t type, uint8_t * data,
  size_t taille) {
	if (tlv == NULL || tlv->ready || data == NULL)
		return (FALSE);

	if (tlvb_add_type(tlv, DATA) == FALSE)
		return (FALSE);

	uint8_t * msg = (uint8_t *) malloc((13 + taille));
	memcpy(msg, ((uint8_t *) &id), 8);
	memcpy(msg + 8, ((uint8_t *) &nonce), 4);
	memcpy(msg + 12, &type, 1);
	memcpy(msg + 13, data, taille);
	t_bool rc = tlvb_add_value(tlv, msg, 13 + taille);
	free(msg);
	return rc;
}

t_bool      tlvb_add_ack(t_tlv_builder * tlv, uint64_t id, uint32_t nonce) {
	if (tlv == NULL || tlv->ready)
		return (FALSE);

	if (tlvb_add_type(tlv, ACK) == FALSE)
		return (FALSE);

	uint8_t msg[12];
	memcpy(msg, ((uint8_t *) &id), 8);
	memcpy(msg, ((uint8_t *) &nonce), 4);
	return (tlvb_add_value(tlv, msg, 12));
}

t_bool      tlvb_add_goaway(t_tlv_builder * tlv, uint8_t code, uint8_t * message, size_t taille) {
	if (tlv == NULL || tlv->ready || message == NULL)
		return (FALSE);

	if (tlvb_add_type(tlv, GOAWAY) == FALSE)
		return (FALSE);

	uint8_t * msg = (uint8_t *) malloc(taille);
	memcpy(msg, &code, 1);
	memcpy(msg + 1, message, taille);
	t_bool rc = tlvb_add_value(tlv, msg, taille + 1);
	free(msg);
	return rc;
}

t_bool      tlvb_add_warning(t_tlv_builder * tlv, uint8_t * message, size_t taille) {
	if (tlv == NULL || tlv->ready || message == NULL)
		return (FALSE);

	if (tlvb_add_type(tlv, WARNING) == FALSE)
		return (FALSE);

	return (tlvb_add_value(tlv, message, taille));
}
