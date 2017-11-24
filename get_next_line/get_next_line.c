/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:42:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/24 09:32:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		fill_line(char **line, char **buff_prog)
{
	char	*tmp;
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

static int		loop(const int fd, char *buff_prog[MAX_FD], int ret, int new_buff_size)
{
	char	*tmp;
	char	*buff;

	if ((buff = (char *)malloc(sizeof(char) * (new_buff_size + 1))) == 0)
		return (-1);
	while (ft_strchr(buff_prog[fd], '\n') == 0)
	{
		ft_bzero(buff, new_buff_size + 1);
		if ((ret = read(fd, buff, new_buff_size)) == -1)
			break ;
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		tmp = ft_strjoin(buff_prog[fd], buff);
		free(buff_prog[fd]);
		buff_prog[fd] = tmp;
		if (ft_strlen(buff) < new_buff_size)
			break ;
	}
	free(buff);
	return ((ret == -1) ? -1 : 0);
}

static int		actualize_buff_size()
{
	if (BUFF_SIZE < 1)
		return (1);
	return (BUFF_SIZE);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buff_prog[MAX_FD];
	int				ret;

	if (fd < 0 || line == 0 || fd > 4000 || read(fd, buff_prog[1], 0) < 0)
		return (-1);
	if (buff_prog[fd] == 0)
		buff_prog[fd] = ft_strnew(1);
	if (loop(fd, buff_prog, ret, actualize_buff_size()) == -1)
		return (-1);
	if (ft_strcmp(buff_prog[fd], "") == 0)
		return (0);
	fill_line(line, &buff_prog[fd]);
	return (1);
}
