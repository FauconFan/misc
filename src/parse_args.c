#include "irc_udp.h"

#define	ARG_NCURSES    "--ncurses"
#define	ARG_NO_NCURSES "--no-ncurses"

#define	SHIFT          {argc--; argv++;}

static void print_help(char * argv0) {
	printf("Help:\n");
	printf("%s " ARG_NCURSES " " ARG_NO_NCURSES "\n", argv0);
	printf("\n");
	printf("\t" ARG_NCURSES " : launch the application in ncurses mode\n");
	printf("\t" ARG_NO_NCURSES " : launch the application in raw mode\n");
	printf("\n\n");
	printf("if contracictory arguments are given, the last one is remembered\n");
}

t_bool    parse_args(int argc, char ** argv, t_bool * with_ncurses) {
	t_bool res;
	char * argv0;

	*with_ncurses = WITH_NCURSES_DEFAULT;
	res = TRUE;
	if (argc < 2)
		return (TRUE);

	argv0 = *argv;
	SHIFT
	while (argc) {
		if (strcmp(*argv, ARG_NCURSES) == 0)
			*with_ncurses = TRUE;
		else if (strcmp(*argv, ARG_NO_NCURSES) == 0)
			*with_ncurses = FALSE;
		else
			res = FALSE;
		SHIFT
	}
	if (res == FALSE)
		print_help(argv0);
	return (res);
}
