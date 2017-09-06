#include "libperso.h"

void	h1(char *s)
{
	int		size;
	int		index;

	size = 0;
	index = 0;
	while (s[size])
		size++;
	libperso_putstr("\n\t*-");
	while (index++ < size)
		libperso_putchar('-');
	index = 0;
	libperso_putstr("-*\n\t| ");
	libperso_putstr(s);
	libperso_putstr(" |\n\t*-");
	while (index++ < size)
		libperso_putchar('-');
	libperso_putstr("-*\n\n");
}

void	h2(char *s)
{
	libperso_putstr("   ## ");
	libperso_putstr(s);
	libperso_putstr(" ##   \n");
}

void	h3(char *s)
{
	libperso_putstr(" => ");
	libperso_putstr(s);
	libperso_putstr(" <= \n");
}