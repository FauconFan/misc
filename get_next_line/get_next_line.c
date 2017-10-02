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

static void 	fill_line(char **line, char **buff_prog)
{
	char 	*tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while ((*buff_prog)[++i] != '\n' && (*buff_prog)[i]);
	*line = ft_strsub(*buff_prog, 0, i);
	if (ft_strlen(*buff_prog) > 0)
		tmp = ft_strsub(*buff_prog, i + 1, ft_strlen(*buff_prog) - i);
	free(*buff_prog);
	*buff_prog = tmp;
}

int 			get_next_line(const int fd, char **line)
{
	static char 	*buff_prog[MAX_FD];
	char			*tmp;
	char 			buff[BUFF_SIZE + 1];
	static int 		ret[MAX_FD];

	if (fd < 0 || line == 0)
		return (-1);
	if (buff_prog[fd] == 0)
		buff_prog[fd] = ft_strnew(1);
	while (ft_strchr(buff_prog[fd], '\n') == 0)
	{
		if ((ret[fd] = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (ret[fd] == 0)
			break ;
		buff[ret[fd]] = 0;
		tmp = ft_strjoin(buff_prog[fd], buff);
		free(buff_prog[fd]);
		buff_prog[fd] = tmp;
	}
	fill_line(line, &buff_prog[fd]);
	if (ret[fd] == 0)
		return (0);
	return (1);
}