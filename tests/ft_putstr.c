#include <unistd.h>
#include <string.h>

void	ft_putstr(char *str)
{
	write(1, str, strlen(str));
}
