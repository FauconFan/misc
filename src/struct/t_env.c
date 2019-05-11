#include "irc_udp.h"

t_env * env_alloc(void) {
	t_env * res;

	if ((res = (t_env *) malloc(sizeof(t_env))) == NULL)
		return (NULL);

	memset(res, 0, sizeof(t_env));
	res->socket = build_socket();
	if (res->socket < 0) {
		free(res);
		return (NULL);
	}
	if ((res->li_neighbours = lst_alloc(FREE_PTR(nei_free), PRINT_PTR(nei_print))) == NULL ||
	  (res->li_potential_neighbours = lst_alloc(FREE_PTR(pot_nei_free), PRINT_PTR(pot_nei_print))) == NULL ||
	  (res->li_messages = lst_alloc(FREE_PTR(message_free), PRINT_PTR(message_print))) == NULL ||
	  (res->li_acquit = lst_alloc(FREE_PTR(acquit_free), PRINT_PTR(acquit_print))) == NULL ||
	  (res->li_buffer_tlv_ip = lst_alloc(FREE_PTR(buffer_free), PRINT_PTR(buffer_print))) == NULL)
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
		free(res);
		return (NULL);
	}
	res->id = gen_id();
	return (res);
} /* env_alloc */

void                env_free(t_env * env) {
	// go_away();
	close(env->socket);
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
	dprintf(fd, "\tsocket : %d\n", env->socket);
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

struct timeval      env_min_time(t_env * env) {
	t_bool ok[2];
	struct timeval min_hello;
	struct timeval min_acquit;
	struct timeval min;
	struct timeval res;
	struct timeval current_time;

	ok[0] = nei_get_min_time(env->li_neighbours, &min_hello);
	ok[1] = acquit_get_min_time(env->li_acquit, &min_acquit);
	gettimeofday(&current_time, NULL);

	if (ok[0] == FALSE && ok[1] == FALSE) {
		res         = current_time;
		res.tv_sec  = 5;
		res.tv_usec = 0; // On attend 5 sec si on a rien à attendre
		return (res);
	}
	else if (ok[0] == FALSE) {
		min = min_acquit;
	}
	else if (ok[1] == FALSE) {
		min = min_hello;
	}
	else {
		min = *timeval_min(&min_hello, &min_acquit);
	}
	return (timeval_diff(&current_time, &min));
}
