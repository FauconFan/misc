/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:14:10 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/18 15:40:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "functions.h"

int		main(int argc, char **argv)
{
	if(argc == 1)
		ft_putstr("Need at least one argument.\n");
	else if(argc == 2)
		ft_putstr("Need option -C and filename.\n");
	else
	{
		if (ft_strcmp(argv[1], "-C") != 0)
			ft_putstr("Need option -C.\n");
		else
		{
			argc -= 2;
			argv += 2;
			do_main(argc, argv);
		}
	}
	return (0);
}

void	do_main(int argc, char **argv)
{
	unsigned long	addr;
	int				file_descriptor;
	char			buffer[SIZE_BUF];
	int				ret;

	addr = 0;
	while (argc != 0)
	{
		file_descriptor = open(argv[0], O_RDONLY);
		if (file_descriptor == -1)
			return ;
		ret = read(file_descriptor, buffer, SIZE_BUF);
		while (ret != 0)
		{
			ft_printbuffer(addr, buffer, ret);
			addr += 16;
			ret = read(file_descriptor, buffer, SIZE_BUF);
		}
		if(close(file_descriptor) == -1)
			return ;
		argv++;
		argc--;
	}
}
