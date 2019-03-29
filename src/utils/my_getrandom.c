#include "irc_udp.h"

static int		fill_buffer(int fd, uint8_t *buffer, size_t len)
{
	size_t		len_read;
	int			ret_read;

	len_read = 0;
	while (len_read < len)
	{
		if ((ret_read = read(fd, buffer + len_read, len - len_read)) < 0)
			return (1);
		len_read += ret_read;
	}
	return (0);
}

static int		my_getrandom(void *buffer, size_t len)
{
	int		fd_random;
	int		ret;

	ret = 0;
	if ((fd_random = open("/dev/urandom", O_RDONLY)) < 0)
		return (1);
	if (fill_buffer(fd_random, (uint8_t *)buffer, len))
		ret = 2;
	if (close(fd_random))
		ret = 1;
	return (ret);
}