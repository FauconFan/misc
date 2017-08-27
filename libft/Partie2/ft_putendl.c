#include <unistd.h>

void	ft_putendl(char const *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	write(1, str, length);
	write(1, "\n", 1);
}