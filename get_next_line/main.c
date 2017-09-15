/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:25:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/15 11:02:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*tmp;

	ft_putnbrl(ft_strrpos("coucou", "o"));

	if (argc == 1)
		get_next_line(0, &tmp);
	else
	{
		int fd = open(argv[1], O_RDONLY);
		get_next_line(fd, &tmp);
		close(fd);
	}
	ft_putstr(tmp);
	return (0);
}