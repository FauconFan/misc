/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:25:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/16 15:42:06 by jpriou           ###   ########.fr       */
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

	if (argc == 1)
	{
		tmp = 0;
		get_next_line(0, &tmp);
		ft_putendl(tmp);
	}
	else
	{
		int fd = open(argv[1], O_RDONLY);
		tmp = 0;
		while (get_next_line(fd, &tmp) != 0)
		{
			ft_putendl(tmp);
		}
		if (tmp != 0)
			ft_putendl(tmp);
		close(fd);
	}
	return (0);
}