
#include "atpt.h"

t_atpt			*g_atpt = NULL;

int				atpt_init(void)
{
	if ((g_atpt = (t_atpt *)malloc(sizeof(t_atpt))) == NULL)
		return (1);
	printf("%s\n", "oi");
	if (setup_termios())
	{
		free(g_atpt);
		return (1);
	}
	return (0);
}

void			atpt_end(void)
{
	reset_termios();
	free(g_atpt);
}
