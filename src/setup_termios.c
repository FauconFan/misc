#include "atpt.h"

static int		check_conditions(void)
{
	char	*env_term;

	env_term = getenv("TERM");
	if (env_term == NULL)
		return (1);
	if (isatty(STDOUT_FILENO) == 0)
		return (1);
	if (tgetent(0, env_term) < 1)
		return (1);
	return (0);
}

int				setup_termios(void)
{
	if (check_conditions())
		return (1);
	tcgetattr(STDOUT_FILENO, &g_atpt->ios_old);
	tcgetattr(STDOUT_FILENO, &g_atpt->ios_actu);
	g_atpt->ios_actu.c_lflag &= ~ICANON;
	g_atpt->ios_actu.c_cc[VMIN] = 1;
	g_atpt->ios_actu.c_cc[VTIME] = 0;
	tcsetattr(STDOUT_FILENO, TCSANOW, &g_atpt->ios_actu);
	tputs(tgetstr("ti", NULL), 1, putchar);
	tputs(tgetstr("vi", NULL), 1, putchar);
	return (0);
}

void			reset_termios(void)
{
	tcsetattr(STDOUT_FILENO, TCSANOW, &g_atpt->ios_old);
	tputs(tgetstr("ve", NULL), 1, putchar);
	tputs(tgetstr("te", NULL), 1, putchar);
}
