#include "libperso.h"

static void		my_putcolor(char *s)
{
	my_putstr("\033[");
	my_putstr(s);
	my_putchar('m');
}

void			my_putcol(char *color, char *text)
{
	int		index;

	index = 0;
	while (text[index])
		index++;
	if (index >= 1 && text[index - 1] == '\n')
	{
		my_putcolor(color);
		my_putstrlen(text, index - 1);
		my_putcolor("0");
		my_putchar('\n');
	}
	else
	{
		my_putcolor(color);
		my_putstr(text);
		my_putcolor("0");
	}
}