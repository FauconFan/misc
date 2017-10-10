/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:50:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/18 15:54:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE_BUF	10

int		main(int argc, char **argv)
{
	int		index;
	int		res;

	res = 0;
	if (argc == 1)
	{
		do_main_standard_file();
	}
	else
	{
		index = 1;
		while (index < argc)
		{
			if (do_main_file(argv[index]) == 1)
				res = 1;
			index++;
		}
	}
	return (res);
}

int		do_main_file(char *name_file)
{
	int		file_descriptor;
	int		ret;
	char	buffer[SIZE_BUF + 1];

	file_descriptor = open(name_file, O_RDONLY);
	if (file_descriptor == -1)
	{
		echo_issue("No such file or directory", name_file);
		return (1);
	}
	ret = read(file_descriptor, buffer, SIZE_BUF);
	if (ret == -1)
	{
		return (1);
	}
	while (ret != 0)
	{
		buffer[ret] = 0;
		ft_putstr(buffer);
		ret = read(file_descriptor, buffer, SIZE_BUF);
	}
	if (close(file_descriptor) == -1)
		return (1);
	return (0);
}

void	echo_issue(char *error, char *name_file)
{
	ft_putstr("ft_cat: ");
	ft_putstr(name_file);
	ft_putstr(": ");
	ft_putstr(error);
	ft_putstr("\n");
}

void	do_main_standard_file(void)
{
	int		ret;
	char	buffer[SIZE_BUF + 1];

	ret = read(0, buffer, SIZE_BUF);
	while (ret != 0)
	{
		buffer[ret] = 0;
		ft_putstr(buffer);
		ret = read(0, buffer, SIZE_BUF);
	}
}
