/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:25:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/15 11:17:27 by jpriou           ###   ########.fr       */
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
	char	*test;

	test = ft_strconcat("coucou", " la famille !");
	ft_putendl(test);
	free(test);

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