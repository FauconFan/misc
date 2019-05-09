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
	// t_tlv_builder * bd;
	// t_ip_port ipp;
	// uint64_t id = gen_id();
	// uint32_t nonce = gen_nonce();

	// for (size_t i = 0; i < 16; ++i)
	// 	ipp.ip[i] = i;
	// ipp.port = 1234;
	// bd = tlvb_alloc();

	// tlvb_add_pad1(bd);
	// tlvb_add_padN(bd, 4);
	// tlvb_add_hello_short(bd, 1);
	// tlvb_add_hello_long(bd, 1, 2);
	// tlvb_add_neighbour(bd, ipp);
	// tlvb_add_data(bd, id, nonce, 0, (uint8_t *)"coucou", 6);
	// tlvb_add_ack(bd, id, nonce);
	// tlvb_add_goaway(bd, 0, (uint8_t *)"t moche", 7);
	// tlvb_add_warning(bd, (uint8_t *)"Warning", 7);
	// tlvb_add_padN(bd, 5);
	// tlvb_add_padN(bd, 6);
	// tlvb_add_padN(bd, 7);

	// iovb_print(bd->builder, 1);

	// printf("%d\n", tlvb_finish(bd, 26));

	// iovb_print(bd->builder, 1);

	// for (size_t i = 0; i < bd->num_splitted; ++i) {
	// 	printf("PRINTING %ld\n", i);
	// 	iovb_print(bd->splitted[i], 1);
	// }

	// tlvb_free(bd);

	t_bool with_ncurses;
	t_bool with_logs;
	int rc_main;

	rc_main = 1;
	if (parse_args(argc, argv, &with_ncurses, &with_logs) == TRUE &&
	  setup_pseudo() == 0 &&
	  ui_setup(with_ncurses, with_logs) == TRUE &&
	  (g_env = env_alloc()) != NULL)
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
} /* main */
