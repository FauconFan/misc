#include "irc_udp.h"

static void     print_msg_to_ui(t_ip_port ip_port, t_iovec_builder * iovec_builder) {
	dprintf(ui_getfd(), "\nSend message : ");
	ip_port_print(ip_port, ui_getfd());
	dprintf(ui_getfd(), "\n");
	iovb_print(iovec_builder, ui_getfd());
	dprintf(ui_getfd(), "\n");
}

static void     build_sock_addr6(struct sockaddr_in6 * in6, uint8_t ip[16], uint16_t port) {
	memset(in6, 0, sizeof(*in6));
	in6->sin6_family = AF_INET6;
	in6->sin6_port   = port;
	for (size_t i = 0; i < 16; ++i) {
		in6->sin6_addr.s6_addr[i] = ip[i];
	}
}

static void     send_buffer(t_buffer_tlv_ip * tlvip) {
	struct sockaddr_in6 in6;
	struct msghdr msg;

	memset(&msg, 0, sizeof(msg));
	if (tlvb_finish(tlvip->tlv_builder) == FALSE) {
		dprintf(ui_getfd(), "something strange happens in send_buffer 1\n");
		return;
	}
	if (iovb_get_iovec(tlvip->tlv_builder->msg, &msg.msg_iov, &msg.msg_iovlen) == FALSE) {
		dprintf(ui_getfd(), "something strange happens in send_buffer 2\n");
		return;
	}
	build_sock_addr6(&in6, tlvip->ip_port.ip, tlvip->ip_port.port);
	msg.msg_name    = &in6;
	msg.msg_namelen = sizeof(in6);
	print_msg_to_ui(tlvip->ip_port, tlvip->tlv_builder->msg);
	sendmsg(g_env->socket, &msg, 0);
}

void    clear_buffer(void) {
	lst_iter(g_env->li_buffer_tlv_ip, (void(*)(void *))send_buffer);
	lst_clear(g_env->li_buffer_tlv_ip);
}
