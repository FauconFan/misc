#include "irc_udp.h"

t_env * g_env = NULL;

int main(void) {
	ui_setup();

	g_env = env_alloc();
	if (g_env == NULL)
		return (1);

	struct sockaddr * in;
	socklen_t lsock;
	t_ip_port ip_port_juliusz;

	get_sockaddr_juliusz(&in, &lsock);
	ip_port_assign_sockaddr6(&ip_port_juliusz, *(struct sockaddr_in6 *) in);

	lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip_port_juliusz));

	client();

	env_free(g_env);

	ui_down();
	return (0);
}
