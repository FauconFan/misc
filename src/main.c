
#include "atpt.h"

int				main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	if (atpt_init(argv[1], argv[2]))
		return (1);
	init_signal_handlers();
	core();
	atpt_end();
	return (0);
}
