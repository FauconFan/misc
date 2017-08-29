#include <unistd.h>

void	ft_putstr_fd(char const *str, int fd)
{
	int	length;

	length = 0;
	if (str == 0)
	{
		ft_putstr_fd("(null)", fd);
		return ;
	}
	while (str[length])
		length++;
	write(fd, str, length);
}