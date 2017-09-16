/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:25:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/15 18:42:51 by jpriou           ###   ########.fr       */
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
		get_next_line(0, &tmp);
	else
	{
		int fd = open(argv[1], O_RDONLY);
		int index = 0;
		while (index < 25)
		{
			get_next_line(fd, &tmp);
			ft_putendl(tmp);
			index++;
		}
		close(fd);
	}
	return (0);
}