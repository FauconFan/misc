#include <unistd.h>

void	my_putstr(char *s)
{
	int		length;

	length = 0;
	while (s[length])
		length++;
	write(1, s, length);
}

void	my_putstrlen(char *s, int len)
{
	write(1, s, len);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_clrsrc(void)
{
	my_putstr("\033[H\033[2J");
}