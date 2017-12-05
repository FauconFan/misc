/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/05 09:30:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

int		main(void)
{
	t_env_gnl	*head;
	char		*buff;
	int			fd;

	head = init_env_gnl();
	fd = open("src/main.c", O_RDONLY);
	while (get_next_line(fd, &buff, head) != 0)
	{
		ft_putendl(buff);
		free(buff);
	}
	close(fd);
	fd = open("src/get_next_line/env_gnl.c", O_RDONLY);
	while (get_next_line(fd, &buff, head) != 0)
	{
		ft_putendl(buff);
		free(buff);
	}
	close(fd);
	free_env_gnl(head);
}
