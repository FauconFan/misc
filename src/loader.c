
#include "atpt.h"

t_atpt			*g_atpt = NULL;

int				atpt_init(char *file, char *cmd)
{
	if ((g_atpt = (t_atpt *)malloc(sizeof(t_atpt))) == NULL)
		return (1);
	if ((g_atpt->file = strdup(file)) == NULL ||
		(g_atpt->cmd = strdup(cmd)) == NULL)
	{
		free(g_atpt);
		return (1);
	}
	if (setup_termios())
	{
		free(g_atpt->file);
		free(g_atpt->cmd);
		free(g_atpt);
		return (1);
	}
	atexit(atpt_end);
	return (0);
}

void			atpt_end(void)
{
	if (g_atpt)
	{
		reset_termios();
		free(g_atpt->file);
		free(g_atpt->cmd);
		free(g_atpt);
		g_atpt = NULL;
	}
}
