#include "irc_udp.h"

#define	ARG_NO_NCURSES  "--no-ncurses"
#define	ARG_W_LOG       "--with-logs"
#define	ARG_NO_JULIUSZ  "--no-juliusz-init"
#define	ARG_NO_PORT     "--no-port"
#define	ARG_PORT_ASSIGN "--port"

#define	SHIFT           {argc--; argv++;}

static void print_help(char * argv0) {
	printf("Help:\n");
	printf("%s " ARG_NO_NCURSES " " ARG_W_LOG " " ARG_NO_JULIUSZ " " ARG_NO_PORT " " ARG_PORT_ASSIGN " NUM_PORT " "\n",
	  argv0);
	printf("\n");
	printf("\t" ARG_NO_NCURSES " : launch the application in raw mode\n");
	printf("\t" ARG_W_LOG " : launch the application with logs on the screen\n");
	printf("\t" ARG_NO_JULIUSZ " : launch the application without juliusz connexion\n");
	printf("\t" ARG_NO_PORT " : launch the application with no port specified\n");
	printf("\t" ARG_PORT_ASSIGN " NUM_PORT : launch the application with port NUM_PORT specified\n");
	printf("\n");
	printf("If some contradicory informations are given, the last one is kept\n");
	printf("\n");
}

t_bool    parse_args(int argc, char ** argv, t_bool * with_ncurses, t_bool * with_log, t_bool * juliusz_init,
  int * port) {
	t_bool res;
	char * argv0;

	*with_ncurses = WITH_NCURSES_DEFAULT;
	*with_log     = WITH_LOG_DEFAULT;
	*juliusz_init = WITH_JULIUSZ_INIT;
	*port         = DEFAULT_PORT;
	res = TRUE;
	if (argc < 2)
		return (TRUE);

	argv0 = *argv;
	SHIFT
	while (argc) {
		if (strcmp(*argv, ARG_NO_NCURSES) == 0) {
			*with_ncurses = (WITH_NCURSES_DEFAULT == FALSE);
		}
		else if (strcmp(*argv, ARG_W_LOG) == 0) {
			*with_log = (WITH_LOG_DEFAULT == FALSE);
		}
		else if (strcmp(*argv, ARG_NO_JULIUSZ) == 0) {
			*juliusz_init = (WITH_JULIUSZ_INIT == FALSE);
		}
		else if (strcmp(*argv, ARG_NO_PORT) == 0) {
			*port = NO_PORT;
		}
		else if (strcmp(*argv, ARG_PORT_ASSIGN) == 0) {
			SHIFT
			if (argc == 0) {
				res = FALSE;
				break;
			}
			*port = atoi(*argv);
		}
		else {
			res = FALSE;
		}
		SHIFT
	}
	if (res == FALSE)
		print_help(argv0);
	return (res);
} /* parse_args */
