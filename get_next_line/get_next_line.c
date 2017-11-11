/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:42:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 10:16:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
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

int				get_next_line(const int fd, char **line)
{
	static char		*buff_prog[MAX_FD];
	int				ret;
	char			*tmp;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || line == 0)
		return (-1);
	if (buff_prog[fd] == 0)
		buff_prog[fd] = ft_strnew(1);
	while (ft_strchr(buff_prog[fd], '\n') == 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
			break ;
		buff[ret] = 0;
		tmp = ft_strjoin(buff_prog[fd], buff);
		free(buff_prog[fd]);
		buff_prog[fd] = tmp;
	}
	fill_line(line, &buff_prog[fd]);
	if (ret == 0 && ft_strcmp(*line, "") == 0)
		return (0);
	return (1);
}
