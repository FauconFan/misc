#include "libperso.h"

static void		libperso_putcolor(char *s)
{
	libperso_putstr("\033[");
	libperso_putstr(s);
	libperso_putchar('m');
}

void			libperso_putcol(char *color, char *text)
{
	int		index;

	index = 0;
	while (text[index])
		index++;
	if (index >= 1 && text[index - 1] == '\n')
	{
		libperso_putcolor(color);
		libperso_putstrlen(text, index - 1);
		libperso_putcolor("0");
		libperso_putchar('\n');
	}
	else
	{
		libperso_putcolor(color);
		libperso_putstr(text);
		libperso_putcolor("0");
	}
}