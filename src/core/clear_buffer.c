#include "irc_udp.h"

static void     print_msg_to_ui(t_ip_port ip_port, t_iovec_builder * iovec_builder) {
	dprintf(ui_getfd_log(), "\nSend message : ");
	ip_port_print(ip_port, ui_getfd_log());
	dprintf(ui_getfd_log(), "\n");
	iovb_print(iovec_builder, ui_getfd_log());
	dprintf(ui_getfd_log(), "\n");
}

static void     build_sock_addr6(struct sockaddr_in6 * sin6, uint8_t ip[16], uint16_t port) {
	memset(sin6, 0, sizeof(*sin6));
	sin6->sin6_family = AF_INET6;
	sin6->sin6_port   = port;
	for (size_t i = 0; i < 16; ++i) {
		sin6->sin6_addr.s6_addr[i] = ip[i];
	}
}

static void     send_buffer(t_buffer_tlv_ip * tlvip) {
	struct sockaddr_in6 sin6;
	struct msghdr msg;
	ssize_t ret_sendmsg;

	dprintf(ui_getfd_log(), "send buffer called\n");

	dprintf(ui_getfd_log(), "all buffer\n");
	print_msg_to_ui(tlvip->ip_port, tlvip->tlv_builder->builder);

	if (tlvb_finish(tlvip->tlv_builder, GMTU) == FALSE) {
		dprintf(ui_getfd_log(), "something strange happens in send_buffer 1\n");
		return;
	}

	dprintf(ui_getfd_log(), "splitted in %ld messages\n", tlvip->tlv_builder->num_splitted);

	for (size_t i = 0; i < tlvip->tlv_builder->num_splitted; ++i) {
		t_iovec_builder * final;

		final = tlvip->tlv_builder->splitted[i];
		print_msg_to_ui(tlvip->ip_port, final);
		memset(&msg, 0, sizeof(msg));
		build_sock_addr6(&sin6, tlvip->ip_port.ip, tlvip->ip_port.port);
		msg.msg_name    = &sin6;
		msg.msg_namelen = sizeof(sin6);
		msg.msg_iov     = final->msg_iov;
		msg.msg_iovlen  = final->len_max;
		ret_sendmsg     = sendmsg(g_env->socket, &msg, 0);

		if (ret_sendmsg == -1) {
			dprintf(ui_getfd_log(), "Failed call to sendmsg\n");
			dprintf(ui_getfd_log(), "error code %d error msg %s\n", errno, strerror(errno));
		}
		else {
			dprintf(ui_getfd_log(), "Success call to sendmsg\n");
		}
	}
} /* send_buffer */

void    clear_buffer(void) {
	dprintf(ui_getfd_log(), "Clearing buffer\n");
	if (lst_isempty(g_env->li_buffer_tlv_ip))
		dprintf(ui_getfd_log(), "Nothing to send\n");
	lst_iter(g_env->li_buffer_tlv_ip, (void(*)(void *))send_buffer);
	lst_clear(g_env->li_buffer_tlv_ip);
}
