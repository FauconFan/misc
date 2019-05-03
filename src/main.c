#include "irc_udp.h"

t_env * g_env   = NULL;
char * g_pseudo = NULL;

static int setup_pseudo() {
	write(1, "Enter your pseudonyme: ", 23);
	if ((g_pseudo = ui_read_pseudo()) == NULL) {
		printf("\nError reading pseudo\n");
		return (1);
	}
	return (0);
}

int main(void) {
	struct sockaddr * in;
	socklen_t lsock;
	t_ip_port ip_port_juliusz;

	if (setup_pseudo())
		return (1);

	ui_setup();
	if ((g_env = env_alloc()) == NULL)
		return (1);

	// Setting up env with juliusz by default
	get_sockaddr_juliusz(&in, &lsock);
	ip_port_assign_sockaddr6(&ip_port_juliusz, *(struct sockaddr_in6 *) in);
	lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip_port_juliusz));

	// Run
	core_loop();

	env_free(g_env);
	ui_down();
	free(g_pseudo);
	return (0);
}
