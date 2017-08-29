#include <unistd.h>

void	ft_putendl(char const *str)
{
	int		length;

	length = 0;
	if (str == 0)
	{
		ft_putendl("(null)");
		return ;
	}
	while (str[length])
		length++;
	write(1, str, length);
	write(1, "\n", 1);
}