#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	tmp[n];

	ft_memcpy(tmp, src, n);
	ft_memcpy(dest, tmp, n);
	return (dest);
}