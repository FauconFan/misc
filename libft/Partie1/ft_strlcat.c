#include <string.h>
#define POSONLY(x) ((x < 0) ? 0 : x)

static size_t	str_len(char *s)
{
	size_t		index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

size_t			ft_strlcat(char *dest, char *src, size_t nb)
{
	int					beg_i_d;
	int					index;
	size_t				length[2];
	size_t				res;

	length[0] = str_len(dest);
	length[1] = str_len(src);
	res = (nb < length[0]) ? length[1] + nb : length[1] + length[0];
	beg_i_d = nb - length[0];
	beg_i_d = (beg_i_d < 0) ? 0 : beg_i_d;
	index = 0;
	while (beg_i_d >= 0 && index < beg_i_d - 1 && src[index])
	{
		dest[length[0] + index] = src[index];
		index++;
	}
	dest[length[0] + index] = '\0';
	return (res);
}