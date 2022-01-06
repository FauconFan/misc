/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrandom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:21:04 by pepe              #+#    #+#             */
/*   Updated: 2019/01/18 08:35:24 by jpriou           ###   ########.fr       */
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

int				ft_getrandom(char *buffer, size_t len)
{
	int		fd_random;
	int		ret;

	ret = 0;
	if ((fd_random = open("/dev/urandom", O_RDONLY)) < 0)
		return (1);
	if (fill_buffer(fd_random, buffer, len))
		ret = 2;
	if (close(fd_random))
		ret = 1;
	return (ret);
}
