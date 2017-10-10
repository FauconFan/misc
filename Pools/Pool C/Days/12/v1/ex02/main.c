/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 08:56:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/19 13:07:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE_BUF	10
#define MIN(x) ((x < SIZE_BUF) ? x : SIZE_BUF)
#include <stdio.h>

int				main(int argc, char **argv)
{
	int		mode_tail_or_head;
	int		value_of_c;

	if (argc <= 3)
	{
		ft_putstr("Tail needs arguments !\n");
		return (0);
	}
	if (ft_strcmp(argv[1], "-c") != 0)
	{
		ft_putstr("Tail needs option -c to work...\n");
		return (0);
	}
	mode_tail_or_head = (argv[2][0] == '+') ? MODE_FROM_HEAD : MODE_FROM_BOTTOM;
	value_of_c = ABS(ft_atoi(argv[2]));
	argc -= 3;
	argv += 3;
	return (do_main(argc, argv, mode_tail_or_head, value_of_c));
}

int				do_main(int argc, char **argv,
		int mode_tail_or_head, int value_of_c)
{
	int		index;

	if (argc == 1)
	{
		display_main_file(argv[0], value_of_c, mode_tail_or_head);
	}
	else
	{
		index = 0;
		while (index < argc)
		{
			ft_putstr("==> ");
			ft_putstr(argv[index]);
			ft_putstr(" <==\n");
			display_main_file(argv[index], value_of_c, mode_tail_or_head);
			if (index != argc - 1)
				ft_putstr("\n");
			index++;
		}
	}
	return (0);
}

void			display_main_file(char *name_file, int to_ignore, int mode)
{
	int		file_descriptor;
	int		ret;
	char	buffer[SIZE_BUF + 1];
	int		real_ignore;

	real_ignore = (mode == MODE_FROM_HEAD) ? to_ignore :
		get_size_file(name_file) - to_ignore;
	if ((file_descriptor = open(name_file, O_RDONLY)) == -1)
		return ;
	ret = read(file_descriptor, buffer, MIN(real_ignore));
	if (ret == -1)
		return ;
	while (ret != 0)
	{
		real_ignore -= ret;
		ret = read(file_descriptor, buffer, MIN(real_ignore));
	}
	ret = read(file_descriptor, buffer, SIZE_BUF);
	while (ret != 0)
	{
		buffer[ret] = 0;
		ft_putstr(buffer);
		ret = read(file_descriptor, buffer, SIZE_BUF);
	}
	close(file_descriptor);
}

unsigned int	get_size_file(char *name_file)
{
	int		file_descriptor;
	int		ret;
	int		res;
	char	buffer[SIZE_BUF + 1];

	file_descriptor = open(name_file, O_RDONLY);
	if (file_descriptor == -1)
	{
		echo_issue("No such file or directory", name_file);
		return (0);
	}
	res = 0;
	ret = read(file_descriptor, buffer, SIZE_BUF);
	if (ret == -1)
		return (0);
	while (ret != 0)
	{
		res += ret;
		ret = read(file_descriptor, buffer, SIZE_BUF);
	}
	if (close(file_descriptor) == -1)
		return (0);
	return (res);
}

void			echo_issue(char *error, char *name_file)
{
	ft_putstr("ft_tail: ");
	ft_putstr(name_file);
	ft_putstr(": ");
	ft_putstr(error);
	ft_putstr("\n");
}
