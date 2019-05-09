#include "irc_udp.h"

t_env * g_env = NULL;
char g_pseudo[SIZE_PSEUDO + 1] = {0};

static int setup_pseudo() {
	char * tmp;
	size_t min;

	memset(g_pseudo, 0, SIZE_PSEUDO + 1);
	write(1, "Enter your pseudonyme: ", 23);
	if ((tmp = ui_read_pseudo()) == NULL) {
		printf("\nError reading pseudo\n");
		return (1);
	}
	min = strlen(tmp);
	if (min > SIZE_PSEUDO)
		min = SIZE_PSEUDO;
	memcpy(g_pseudo, tmp, min);
	free(tmp);
	return (0);
}

static void start(void) {
	struct sockaddr * in;
	socklen_t lsock;
	t_ip_port ip_port_juliusz;

	// Setting up env with juliusz by default
	get_sockaddr_juliusz(&in, &lsock);
	ip_port_assign_sockaddr6(&ip_port_juliusz, *(struct sockaddr_in6 *) in);
	lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip_port_juliusz));

	// Run
	core_loop();
}

int main(int argc, char ** argv) {
	t_bool with_ncurses;
	t_bool with_logs;
	int rc_main;

	rc_main = 1;
	if (parse_args(argc, argv, &with_ncurses, &with_logs) == TRUE &&
	  setup_pseudo() == 0 &&
	  (g_env = env_alloc()) != NULL &&
	  ui_setup(with_ncurses, with_logs) == TRUE)
	{
		rc_main = 0;
	}

	if (rc_main == 0) {
		start();
	}

	if (g_env)
		env_free(g_env);
	ui_down();
	return (rc_main);
}
