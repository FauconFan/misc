#include <unistd.h>

void	ft_putendl_fd(char const *str, int fd)
{
	int		length;

	length = 0;
	if (str == 0)
	{
		ft_putendl_fd("(null)", fd);
		return ;
	}
	while (str[length])
		length++;
	write(fd, str, length);
	write(fd, "\n", 1);
}