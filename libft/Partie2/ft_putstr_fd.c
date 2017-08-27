#include <unistd.h>

void	ft_putstr_fd(char const *str, int fd)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	write(fd, str, length);
}