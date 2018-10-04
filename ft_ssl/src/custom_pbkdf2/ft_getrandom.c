/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrandom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:21:04 by pepe              #+#    #+#             */
/*   Updated: 2018/10/03 18:42:33 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int		fill_buffer(int fd, char *buffer, size_t len)
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

int				getrandom(char *buffer, size_t len)
{
	int		entropy;
	int		fd_random;
	int		ret;

	ret = 0;
	if ((fd_random = open("/dev/urandom", O_RDONLY)) < 0)
		return (1);
	else if (ioctl(fd_random, RNDGETENTCNT, &entropy) == 0)
	{
		if (entropy < (int)(sizeof(int) * 8))
			ret = 2;
		else if (fill_buffer(fd_random, buffer, len))
			ret = 3;
	}
	if (close(fd_random))
		ret = 1;
	return (ret);
}
