#include "irc_udp.h"

t_env * env_alloc(int port) {
	t_env * res;

	if ((res = (t_env *) malloc(sizeof(t_env))) == NULL)
		return (NULL);

	memset(res, 0, sizeof(t_env));
	if (gettimeofday(&res->now, NULL) == -1) {
		free(res);
		return (NULL);
	}
	res->sock = build_socket(port);
	if (res->sock < 0) {
		free(res);
		return (NULL);
	}
	res->sock_multicast = build_socket_multicast();
	if (res->sock_multicast < 0) {
		close(res->sock);
		free(res);
		return (NULL);
	}
	if ((res->li_neighbours = lst_alloc(FREE_PTR(nei_free), PRINT_PTR(nei_print))) == NULL ||
	  (res->li_potential_neighbours = lst_alloc(FREE_PTR(pot_nei_free), PRINT_PTR(pot_nei_print))) == NULL ||
	  (res->li_messages = lst_alloc(FREE_PTR(message_free), PRINT_PTR(message_print))) == NULL ||
	  (res->li_acquit = lst_alloc(FREE_PTR(acquit_free), PRINT_PTR(acquit_print))) == NULL ||
	  (res->li_buffer_tlv_ip = lst_alloc(FREE_PTR(tlvip_free), PRINT_PTR(tlvip_print))) == NULL)
	{
		if (res->li_neighbours)
			lst_free(res->li_neighbours);
		if (res->li_potential_neighbours)
			lst_free(res->li_potential_neighbours);
		if (res->li_messages)
			lst_free(res->li_messages);
		if (res->li_acquit)
			lst_free(res->li_acquit);
		if (res->li_buffer_tlv_ip)
			lst_free(res->li_buffer_tlv_ip);
		close(res->sock);
		close(res->sock_multicast);
		free(res);
		return (NULL);
	}
	res->id = gen_id();
	res->need_neighbours = TRUE;
	return (res);
} /* env_alloc */

void                env_free(t_env * env) {
	env_go_away_all();
	close(env->sock);
	close(env->sock_multicast);
	lst_free(env->li_neighbours);
	lst_free(env->li_potential_neighbours);
	lst_free(env->li_messages);
	lst_free(env->li_acquit);
	lst_free(env->li_buffer_tlv_ip);
	free(env);
}

void                env_print(t_env * env, int fd) {
	dprintf(fd, "env {\n");
	dprintf(fd, "\tid : %016lx\n", env->id);
	dprintf(fd, "\tsock : %d\n", env->sock);
	dprintf(fd, "\tneed_neighbours : %s\n", STR_OF_BOOL(env->need_neighbours));
	dprintf(fd, "\tli_neighbours : ");
	lst_print(env->li_neighbours, fd);
	dprintf(fd, "\tli_potential_neighbours : ");
	lst_print(env->li_potential_neighbours, fd);
	dprintf(fd, "\tli_messages : ");
	lst_print(env->li_messages, fd);
	dprintf(fd, "\tli_acquit : ");
	lst_print(env->li_acquit, fd);
	dprintf(fd, "\tli_buffer_tlv_ip : ");
	lst_print(env->li_buffer_tlv_ip, fd);
	dprintf(fd, "}\n");
}

void                env_update_time(t_env * env) {
	if (env == NULL)
		return;

	if (gettimeofday(&env->now, NULL) == -1) {
		dprintf(ui_getfd_log(), "Fail update env time : %s\n", strerror(errno));
	}
}
