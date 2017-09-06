#include <unistd.h>

void	libperso_putstr(char *s)
{
	int		length;

	length = 0;
	while (s[length])
		length++;
	write(1, s, length);
}

void	libperso_putstrlen(char *s, int len)
{
	write(1, s, len);
}

void	libperso_putchar(char c)
{
	write(1, &c, 1);
}

void	clrsrc(void)
{
	libperso_putstr("\033[H\033[2J");
}