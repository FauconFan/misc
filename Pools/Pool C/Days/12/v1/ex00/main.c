/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:50:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 16:06:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE_BUF	10

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
	}
	else
	{
		do_main(argv[1]);
	}
	return (0);
}

void	do_main(char *name_file)
{
	int		file_descriptor;
	int		ret;
	char	buffer[SIZE_BUF + 1];

	file_descriptor = open(name_file, O_RDONLY);
	if (file_descriptor == -1)
		return ;
	ret = read(file_descriptor, buffer, SIZE_BUF);
	while (ret != 0)
	{
		buffer[ret] = 0;
		ft_putstr(buffer);
		ret = read(file_descriptor, buffer, SIZE_BUF);
	}
	if (close(file_descriptor) == -1)
		return ;
}
