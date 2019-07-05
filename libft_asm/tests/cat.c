/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:25:51 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/05 09:29:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "libfts.h"

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_cat(0);
	for (int i = 1; i < argc; ++i)
	{
		int		fd;

		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			dprintf(2, "Fail opening %s : %s\n", argv[i], strerror(errno));
			continue ;
		}
		ft_cat(fd);
		close(fd);
	}
}
