#include "irc_udp.h"

#define	BUFF_SIZE 4096 + 1

static void display_in_message(
  struct sockaddr_in6 * sock6,
  uint8_t               buff_res[BUFF_SIZE],
  size_t                N) {
	dprintf(ui_getfd_log(), "\nRECEIVE msg on the network from\n");
	dprintf(ui_getfd_log(), "Ip : ");

	for (size_t i = 0; i < 16; ++i) {
		dprintf(ui_getfd_log(), "%.2x ", sock6->sin6_addr.s6_addr[i]);
	}
	dprintf(ui_getfd_log(), "\n");
	dprintf(ui_getfd_log(), "Port : %d\n", ntohs(sock6->sin6_port));

	for (size_t i = 0; i < N; ++i) {
		dprintf(ui_getfd_log(), "%.2d ", buff_res[i]);
	}
	dprintf(ui_getfd_log(), "\n\n");
}

static void receive_in_message() {
	struct sockaddr_in6 sin6;
	struct msghdr msg;
	struct iovec iov[1];

	union {
		struct cmsghdr hdr;
		unsigned char  cmsgbuf[CMSG_SPACE(sizeof(struct in6_pktinfo))];
	} u;
	t_ip_port ip_port;
	uint8_t buff_res[BUFF_SIZE];
	int N;

	memset(buff_res, 0, BUFF_SIZE);
	memset(&msg, 0, sizeof(msg));
	iov[0].iov_base    = buff_res;
	iov[0].iov_len     = BUFF_SIZE;
	msg.msg_name       = &sin6;
	msg.msg_namelen    = sizeof(sin6);
	msg.msg_iov        = iov;
	msg.msg_iovlen     = 1;
	msg.msg_control    = u.cmsgbuf;
	msg.msg_controllen = sizeof(u);
	N = recvmsg(g_env->socket, &msg, 0);

	if (N < 0) {
		dprintf(ui_getfd_log(), "recvmsg failed : %s\n", strerror(errno));
		return;
	}

	uint8_t my_ip[16];
	struct cmsghdr * cmsg;
	struct in6_pktinfo * info = NULL;

	cmsg = CMSG_FIRSTHDR(&msg);
	while (cmsg != NULL) {
		if ((cmsg->cmsg_level == IPPROTO_IPV6) &&
		  (cmsg->cmsg_type == IPV6_PKTINFO))
		{
			info = (struct in6_pktinfo *) CMSG_DATA(cmsg);
			break;
		}
		cmsg = CMSG_NXTHDR(&msg, cmsg);
	}

	if (info == NULL) {/* ce cas ne devrait pas arriver */
		dprintf(ui_getfd_log(), "IPV6_PKTINFO non trouvé\n");
	}
	else {
		memcpy(my_ip, info->ipi6_addr.s6_addr, 16);

		dprintf(ui_getfd_log(), "my theoric ip interface : ");
		for (size_t i = 0; i < 16; ++i) {
			dprintf(ui_getfd_log(), "%d ", my_ip[i]);
		}
		dprintf(ui_getfd_log(), "\n");
	}

	display_in_message(&sin6, buff_res, N);
	ip_port_assign_sockaddr6(&ip_port, sin6);
	parse_datagram(buff_res, N, nei_search_neighbour(g_env->li_neighbours, ip_port), ip_port);
} /* receive_in_message */

typedef struct  s_rec_metadata{
	uint32_t nonce;
	char *   message;
}               t_rec_metadata;

static void sendall_msg(t_neighbour * nei, t_rec_metadata * rec_mdt) {
	t_buffer_tlv_ip * buffer;

	buffer = buffer_search(g_env->li_buffer_tlv_ip, nei->ip_port);
	tlvb_add_data(buffer->tlv_builder, g_env->id, rec_mdt->nonce, 0, (uint8_t *) rec_mdt->message,
	  strlen(rec_mdt->message));
	lst_add(g_env->li_acquit, acquit_alloc(nei->id, g_env->id, rec_mdt->nonce));
}

static void receive_user_message(t_bool * running) {
	t_ui_in in;
	char last_message[254];
	t_rec_metadata rec_mdt;

	ui_receive(&in);
	switch (in.type) {
		case UI_OK:
			break;
		case UI_STOP:
			*running = FALSE;
			break;
		case UI_MESSAGE:
			memset(last_message, 0, 254);
			snprintf(last_message, 253, "%s: %s", g_pseudo, in.u.message);
			dprintf(ui_getfd_screen(), "%s\n", last_message);
			rec_mdt.nonce   = gen_nonce();
			rec_mdt.message = last_message;
			lst_add(g_env->li_messages,
			  message_alloc(g_env->id, rec_mdt.nonce, 0, strlen(last_message), (uint8_t *) last_message));
			lst_iterp(g_env->li_neighbours, (void(*)(void *, void *))sendall_msg, &rec_mdt);
			free(in.u.message);
			break;
	}
}

t_bool   select_treat_input() {
	fd_set readfds;
	int max_fd;
	int rc_select;
	struct timeval tv;
	t_bool running;

	running = TRUE;
	FD_ZERO(&readfds);
	FD_SET(g_env->socket, &readfds);
	FD_SET(ui_getfd_callback(), &readfds);
	max_fd = g_env->socket;
	if (ui_getfd_callback() > max_fd)
		max_fd = ui_getfd_callback();

	// Calculer le minimum time to wait pour tv
	tv = env_min_time(g_env);

	dprintf(ui_getfd_log(), "waiting for at least : ");
	timeval_print(tv, ui_getfd_log());
	dprintf(ui_getfd_log(), "\n");

	rc_select = select(max_fd + 1, &readfds, NULL, NULL, &tv);

	if (rc_select < 0) {
		dprintf(ui_getfd_log(), "select failed : %s\n", strerror(errno));
		return (FALSE);
	}

	// on a reçu un message
	if (FD_ISSET(g_env->socket, &readfds))
		receive_in_message();
	if (FD_ISSET(ui_getfd_callback(), &readfds))
		receive_user_message(&running);
	return (running);
} /* select_treat_input */
