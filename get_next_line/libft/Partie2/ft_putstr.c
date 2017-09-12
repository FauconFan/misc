#include <unistd.h>

void	ft_putstr(char const *str)
{
	int	length;

	length = 0;
	if (str == 0)
	{
		ft_putstr("(null)");
		return ;
	}
	while (str[length])
		length++;
	write(1, str, length);
}