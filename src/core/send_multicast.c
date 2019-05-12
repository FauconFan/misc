#include "irc_udp.h"

void    send_multicast(void) {
	struct sockaddr_in6 sin6;
	struct msghdr msg;
	ssize_t ret_sendmsg;
	t_tlv_builder * tlvb;

	if (build_sockaddr_multicast(&sin6) == FALSE)
		return;

	dprintf(ui_getfd_log(), " ### random send multicast\n");

	tlvb = tlvb_alloc();
	tlvb_add_hello_short(tlvb, g_env->id);

	if (tlvb_finish(tlvb, GMTU) == FALSE) {
		dprintf(ui_getfd_log(), "something strange happens in send_buffer 1\n");
		return;
	}

	dprintf(ui_getfd_log(), "splitted in %ld messages\n", tlvb->num_splitted);

	for (size_t i = 0; i < tlvb->num_splitted; ++i) {
		t_iovec_builder * final;

		final = tlvb->splitted[i];
		memset(&msg, 0, sizeof(msg));
		msg.msg_name    = &sin6;
		msg.msg_namelen = sizeof(sin6);
		msg.msg_iov     = final->msg_iov;
		msg.msg_iovlen  = final->len_max;
		ret_sendmsg     = sendmsg(g_env->sock, &msg, 0);

		if (ret_sendmsg == -1) {
			dprintf(ui_getfd_log(), "Failed call to sendmsg\n");
			dprintf(ui_getfd_log(), "error code %d error msg %s\n", errno, strerror(errno));
		}
		else {
			dprintf(ui_getfd_log(), "Success call to sendmsg\n");
		}
	}

	tlvb_free(tlvb);
} /* send_multicast */
