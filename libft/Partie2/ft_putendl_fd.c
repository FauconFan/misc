#include <unistd.h>

void	ft_putendl_fd(char const *str, int fd)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	write(fd, str, length);
	write(fd, "\n", 1);
}