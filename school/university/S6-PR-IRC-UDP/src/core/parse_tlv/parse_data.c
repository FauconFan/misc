#include "irc_udp.h"

typedef struct  s_meta_data{
	uint64_t  from_id;
	uint64_t  sender_id;
	uint32_t  nonce;
	uint8_t   type;
	uint16_t  msg_len;
	uint8_t * msg;
}               t_meta_data;

static void forall_nei(t_neighbour * nei, t_meta_data * metadata) {
	t_id_nonce_acq id_nonce_acq;

	id_nonce_acq.dest_id   = nei->id;
	id_nonce_acq.sender_id = metadata->sender_id;
	id_nonce_acq.nonce     = metadata->nonce;
	if (nei->id != metadata->from_id && env_has_acquit_by_id_nonce(id_nonce_acq) == FALSE) {
		lst_add(g_env->li_acquit, acquit_alloc(id_nonce_acq.dest_id, id_nonce_acq.sender_id, id_nonce_acq.nonce));
	}
}

void    parse_data(uint8_t * tlv, t_neighbour * nei, t_ip_port ip_port) {
	uint16_t len;
	t_buffer_tlv_ip * buffer;
	t_meta_data mdt;
	t_id_nonce_acq id_nonce_acq;
	t_id_nonce_msg id_nonce_msg;

	len = tlv[1];
	if (nei == NULL) {
		dprintf(ui_getfd_log(), "DATA reçu d'un non neighbour\n");
		return;
	}
	if (len < 13) {
		dprintf(ui_getfd_log(), "Inconsistent data message\n");
		dprintf(ui_getfd_log(), "len too short : %d\n", len);
	}
	else {
		mdt.from_id   = nei->id;
		mdt.sender_id = *(uint64_t *) (tlv + 2);
		mdt.nonce     = *(uint32_t *) (tlv + 10);
		mdt.type      = *(uint8_t *) (tlv + 14);
		mdt.msg_len   = len - 13;
		mdt.msg       = tlv + 15;

		id_nonce_acq.sender_id = mdt.sender_id;
		id_nonce_acq.nonce     = mdt.nonce;
		id_nonce_acq.dest_id   = mdt.from_id;
		id_nonce_msg.sender_id = mdt.sender_id;
		id_nonce_msg.nonce     = mdt.nonce;

		// on envoie un ack à la personne qui vient de nous envoyer un message
		buffer = tlvip_search(g_env->li_buffer_tlv_ip, ip_port);
		tlvb_add_ack(buffer->tlv_builder, mdt.sender_id, mdt.nonce);

		dprintf(ui_getfd_log(), "DATA ");
		dprintf(
		  ui_getfd_log(), "sender id : %016lx, nonce : %08x, type : %d, msg : ", mdt.sender_id, mdt.nonce, mdt.type);
		if (mdt.type != 0) {
			dprintf(ui_getfd_log(), "No printable message\n");
		}
		else {
			dprintf(ui_getfd_log(), "\"%.*s\"\n", mdt.msg_len, mdt.msg);
		}

		if (env_has_already_received_msg(id_nonce_msg) == FALSE) {
			lst_iterp(g_env->li_neighbours, (void(*)(void *, void *))forall_nei, &mdt);
			lst_add(g_env->li_messages, message_alloc(mdt.sender_id, mdt.nonce, mdt.type, mdt.msg_len, mdt.msg));
			if (mdt.type == 0)
				dprintf(ui_getfd_screen(), "%.*s\n", mdt.msg_len, mdt.msg);
		}
		else {
			env_remove_acquit_by_id_nonce(id_nonce_acq);
			dprintf(ui_getfd_log(), "This message has been already received\n");
		}
	}
} /* parse_data */
