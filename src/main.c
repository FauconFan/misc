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

static void start(t_bool with_juliusz) {
	struct sockaddr_in6 sock_juliusz;
	t_ip_port ip_port_juliusz;

	// Setting up env with juliusz by default
	if (with_juliusz) {
		get_sockaddr_juliusz(&sock_juliusz);
		ip_port_assign_sockaddr6(&ip_port_juliusz, sock_juliusz);
		lst_add(g_env->li_potential_neighbours, pot_nei_alloc(ip_port_juliusz));
	}

	// Run
	core_loop();
}

int main(int argc, char ** argv) {
	t_bool with_ncurses;
	t_bool with_logs;
	t_bool with_juliusz;
	int port;
	int rc_main;

	rc_main = 1;
	if (parse_args(argc, argv, &with_ncurses, &with_logs, &with_juliusz, &port) == TRUE &&
	  setup_pseudo() == 0 &&
	  ui_setup(with_ncurses, with_logs) == TRUE &&
	  (g_env = env_alloc(port)) != NULL)
	{
		rc_main = 0;
	}

	if (rc_main == 0) {
		printf("Launching application\n");
		printf("\twith ncurses : %s\n", STR_OF_BOOL(with_ncurses));
		printf("\twith logs : %s\n", STR_OF_BOOL(with_logs));
		printf("\twith juliusz_init : %s\n", STR_OF_BOOL(with_juliusz));
		printf("\twith port : %d\n", port);
		env_print(g_env, ui_getfd_log());
		start(with_juliusz);
	}

	if (g_env)
		env_free(g_env);
	ui_down();
	return (rc_main);
} /* main */
