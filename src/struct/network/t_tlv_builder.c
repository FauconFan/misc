#include "irc_udp.h"

#define	HEADER_SIZE 4

t_tlv_builder * tlvb_alloc(void) {
	t_tlv_builder * tlv;

	if ((tlv = (t_tlv_builder *) malloc(sizeof(t_tlv_builder))) == NULL) {
		return (NULL);
	}
	if ((tlv->builder = iovb_alloc()) == NULL) {
		free(tlv);
		return (NULL);
	}
	tlv->finished     = FALSE;
	tlv->splitted     = NULL;
	tlv->num_splitted = 0;
	return (tlv);
}

void        tlvb_free(t_tlv_builder * tlv) {
	if (tlv == NULL)
		return;

	iovb_free(tlv->builder);
	if (tlv->splitted != NULL) {
		for (size_t i = 0; i < tlv->num_splitted; ++i)
			iovb_free(tlv->splitted[i]);
		free(tlv->splitted);
	}
	free(tlv);
}

static void tlvb_finish_single(t_iovec_builder * single, t_iovec_builder * builder, size_t first, size_t last) {
	uint8_t header[4];
	uint16_t len_tot;

	len_tot = 0;
	for (size_t i = first; i < last; ++i) {
		len_tot += builder->msg_iov[i].iov_len;
	}
	header[0] = MAGIC_NUMBER;
	header[1] = VERSION;
	len_tot   = htons(len_tot);
	memcpy(header + 2, &len_tot, 2);
	iovb_push(single, header, 4);
	for (size_t i = first; i < last; ++i) {
		iovb_push(single, builder->msg_iov[i].iov_base, builder->msg_iov[i].iov_len);
	}
}

t_bool      tlvb_finish(t_tlv_builder * tlv, uint32_t mtu) {
	size_t size_actu;
	size_t index_actu;
	size_t first_index;

	if (tlv == NULL || tlv->finished)
		return (FALSE);

	tlv->num_splitted = iovb_rearrange(tlv->builder, mtu - HEADER_SIZE);
	if (tlv->num_splitted == 0)
		return (FALSE);

	if ((tlv->splitted = (t_iovec_builder **) malloc(tlv->num_splitted * sizeof(t_iovec_builder *))) == NULL)
		return (FALSE);

	for (size_t i = 0; i < tlv->num_splitted; ++i) {
		if ((tlv->splitted[i] = iovb_alloc()) == NULL) {
			for (size_t j = 0; j < i; ++j) {
				iovb_free(tlv->splitted[j]);
			}
			free(tlv->splitted);
			return (FALSE);
		}
	}
	size_actu   = 0;
	first_index = 0;
	index_actu  = 0;
	for (size_t i = 0; i < tlv->builder->len_used; ++i) {
		if (tlv->builder->msg_iov[i].iov_len + size_actu > mtu - HEADER_SIZE) {
			tlvb_finish_single(tlv->splitted[index_actu], tlv->builder, first_index, i);
			first_index = i;
			index_actu++;
			size_actu = 0;
		}
		size_actu += tlv->builder->msg_iov[i].iov_len;
	}
	tlvb_finish_single(tlv->splitted[index_actu], tlv->builder, first_index, tlv->builder->len_used);

	tlv->finished = TRUE;
	return (TRUE);
} /* tlvb_finish */

static void     tlvb_prepare(uint8_t * v, t_tlv_type t, size_t l) {
	v[0] = t;
	v[1] = l;
}

t_bool      tlvb_add_pad1(t_tlv_builder * tlv) {
	static const uint8_t pad1[1] = {PAD1};

	if (tlv == NULL || tlv->finished)
		return (FALSE);

	return (iovb_push(tlv->builder, pad1, 1));
}

t_bool      tlvb_add_padN(t_tlv_builder * tlv, size_t l) {
	static uint8_t sbuff[4096] = {0};

	if (tlv == NULL || tlv->finished || l >= GMTU - HEADER_SIZE)
		return (FALSE);

	tlvb_prepare(sbuff, PADN, l);
	return (iovb_push(tlv->builder, sbuff, l + 2));
}

t_bool      tlvb_add_hello_short(t_tlv_builder * tlv, uint64_t id1) {
	if (tlv == NULL || tlv->finished)
		return (FALSE);

	uint8_t msg[10];

	tlvb_prepare(msg, HELLO, 8);
	memcpy(msg + 2, ((uint8_t *) &id1), 8);
	return (iovb_push(tlv->builder, msg, 10));
}

t_bool      tlvb_add_hello_long(t_tlv_builder * tlv, uint64_t id1, uint64_t id2) {
	if (tlv == NULL || tlv->finished)
		return (FALSE);

	uint8_t msg[18];
	tlvb_prepare(msg, HELLO, 16);
	memcpy(msg + 2, ((uint8_t *) &id1), 8);
	memcpy(msg + 10, ((uint8_t *) &id2), 8);
	return (iovb_push(tlv->builder, msg, 18));
}

t_bool      tlvb_add_neighbour(t_tlv_builder * tlv, t_ip_port ip_port) {
	if (tlv == NULL || tlv->finished)
		return (FALSE);

	uint8_t msg[20];
	tlvb_prepare(msg, NEIGHBOUR, 18);
	memcpy(msg + 2, ip_port.ip, 16);
	memcpy(msg + 18, &(ip_port.port), 2);
	return (iovb_push(tlv->builder, msg, 20));
}

t_bool      tlvb_add_data(t_tlv_builder * tlv, uint64_t id, uint32_t nonce, uint8_t type, uint8_t * data,
  size_t taille) {
	if (tlv == NULL || tlv->finished || data == NULL || taille > 256)
		return (FALSE);

	uint8_t * msg = (uint8_t *) malloc((15 + taille));
	tlvb_prepare(msg, DATA, 13 + taille);
	memcpy(msg + 2, ((uint8_t *) &id), 8);
	memcpy(msg + 10, ((uint8_t *) &nonce), 4);
	memcpy(msg + 14, &type, 1);
	memcpy(msg + 15, data, taille);
	t_bool rc = iovb_push(tlv->builder, msg, 15 + taille);
	free(msg);
	return (rc);
}

t_bool      tlvb_add_ack(t_tlv_builder * tlv, uint64_t id, uint32_t nonce) {
	if (tlv == NULL || tlv->finished)
		return (FALSE);

	uint8_t msg[14];
	tlvb_prepare(msg, ACK, 12);
	memcpy(msg + 2, ((uint8_t *) &id), 8);
	memcpy(msg + 10, ((uint8_t *) &nonce), 4);
	return (iovb_push(tlv->builder, msg, 14));
}

t_bool      tlvb_add_goaway(t_tlv_builder * tlv, uint8_t code, uint8_t * message, size_t taille) {
	if (tlv == NULL || tlv->finished || message == NULL || taille > 256)
		return (FALSE);

	uint8_t * msg = (uint8_t *) malloc(taille + 3);
	tlvb_prepare(msg, GOAWAY, taille + 1);
	memcpy(msg + 2, &code, 1);
	memcpy(msg + 3, message, taille);
	t_bool rc = iovb_push(tlv->builder, msg, taille + 3);
	free(msg);
	return (rc);
}

t_bool      tlvb_add_warning(t_tlv_builder * tlv, uint8_t * message, size_t taille) {
	if (tlv == NULL || tlv->finished || message == NULL || taille > 256)
		return (FALSE);

	uint8_t * msg = (uint8_t *) malloc(taille + 2);
	tlvb_prepare(msg, WARNING, taille);
	memcpy(msg + 2, message, taille);
	t_bool rc = iovb_push(tlv->builder, msg, taille + 2);
	free(msg);
	return (rc);
}
