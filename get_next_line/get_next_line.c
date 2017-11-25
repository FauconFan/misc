/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:42:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/25 08:53:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		fill_line(char **line, char **buff_prog)
{
	char	*tmp;
	int		i;
	int		size;

	i = 0;
	tmp = 0;
	while ((*buff_prog)[i] != '\n' && (*buff_prog)[i])
		i++;
	*line = ft_strsub(*buff_prog, 0, i);
	size = 0;
	while ((*buff_prog)[i + size] != 0)
		size++;
	tmp = ft_strsub(*buff_prog, i + 1, size);
	free(*buff_prog);
	*buff_prog = tmp;
}

static int		loop(const int fd, char *buff_prog[MAX_FD])
{
	char	*tmp;
	char	*buff;
	int		ret;

	buff = 0;
	ret = 0;
	if (ft_strchr(buff_prog[fd], '\n') == 0)
		buff = ft_strnew(BUFF_SIZE + 1);
	while (ft_strchr(buff_prog[fd], '\n') == 0)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			break ;
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		tmp = ft_strjoin(buff_prog[fd], buff);
		free(buff_prog[fd]);
		buff_prog[fd] = tmp;
		if (ft_strlen(buff) < BUFF_SIZE)
			break ;
	}
	if (buff != 0)
		free(buff);
	return ((ret == -1) ? -1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buff_prog[MAX_FD];

	if (line == 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (buff_prog[fd] == 0)
		buff_prog[fd] = ft_strnew(1);
	if (loop(fd, buff_prog) == -1)
		return (-1);
	if (*(buff_prog[fd]) == 0)
		return (0);
	fill_line(line, &buff_prog[fd]);
	return (1);
}
