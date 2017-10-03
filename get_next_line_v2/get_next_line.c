/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:42:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/19 08:07:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static void		init_prog(t_buff_prog ***prog)
{
	int 	index;

	if ((*prog = (t_buff_prog **)malloc(sizeof(t_buff_prog *) * MAX_FD)) == NULL)
		return ;
	index = 0;
	while (index < MAX_FD)
	{
		if (((*prog)[index] = (t_buff_prog *)malloc(sizeof(t_buff_prog))) == NULL)
			return ;
		(*prog)[index]->buff = ft_strnew(1);
		(*prog)[index]->ret = 0;
		index++;
	}
}

static void 	fill_line(char **line, char **buff_prog)
{
	char 	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while ((*buff_prog)[i] != '\n' && (*buff_prog)[i])
		i++;
	*line = ft_strsub(*buff_prog, 0, i);
	if (ft_strlen(*buff_prog) > 0)
		tmp = ft_strsub(*buff_prog, i + 1, ft_strlen(*buff_prog) - i);
	free(*buff_prog);
	*buff_prog = tmp;
}

int 			get_next_line(const int fd, char **line)
{
	static t_buff_prog	**buff_prog = NULL;
	char				*tmp;
	char 				buff[BUFF_SIZE + 1];

	if (fd < 0 || line == 0)
		return (-1);
	if (buff_prog == NULL)
		init_prog(&buff_prog);
	while (ft_strchr(buff_prog[fd]->buff, '\n') == 0)
	{
		if ((buff_prog[fd]->ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (buff_prog[fd]->ret == 0)
			break ;
		buff[buff_prog[fd]->ret] = 0;
		tmp = ft_strjoin(buff_prog[fd]->buff, buff);
		free(buff_prog[fd]->buff);
		buff_prog[fd]->buff = tmp;
	}
	fill_line(line, &(buff_prog[fd]->buff));
	if (buff_prog[fd]->ret == 0)
		return (0);
	return (1);
}