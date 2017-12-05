/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:50:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 09:19:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_env_gnl	*init_next(t_env_gnl *last, int new_fd)
{
	if ((last->next = (t_env_gnl *)malloc(sizeof(t_env_gnl))) == 0)
		return (0);
	last->next->next = 0;
	if ((last->next->buff_prog = (char **)malloc(sizeof(char *))) == 0)
		return (0);
	*(last->next->buff_prog) = ft_strnew(0);
	last->next->fd = new_fd;
	return (last->next);
}

t_env_gnl			*init_env_gnl(void)
{
	t_env_gnl	*res;

	if ((res = (t_env_gnl *)malloc(sizeof(t_env_gnl))) == 0)
		return (0);
	res->next = 0;
	res->buff_prog = 0;
	res->fd = -1;
	return (res);
}

void				free_env_gnl(t_env_gnl *head)
{
	if (head != 0)
	{
		if (head->next != 0)
			free_env_gnl(head->next);
		if (head->buff_prog != 0)
		{
			free(*(head->buff_prog));
			free(head->buff_prog);
		}
		free(head);
	}
}

char				**find_buff_prog(t_env_gnl *head, int searched_fd)
{
	while (1)
	{
		if (head->fd == searched_fd)
		{
			return (head->buff_prog);
		}
		if (head->next == 0)
			break ;
		head = head->next;
	}
	return ((init_next(head, searched_fd))->buff_prog);
}
