#include "libft.h"

int		ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? CODE_ISDIGIT : 0);
}