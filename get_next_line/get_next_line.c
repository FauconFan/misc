/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:42:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/15 10:08:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static int	read_extend_if_necessary(const int fd, char **buf)
{
	char			buf_tmp[BUFF_SIZE + 1];
	char			*tmp;
	int				rt;

	ft_strclr(buf_tmp);
	rt = read((int)fd, buf_tmp, BUFF_SIZE);
	if (rt <= 0)
		return (0);
	if (sizeof(*buf) - ft_strlen(*buf) <= (unsigned int)rt) /** Not enough places **/
	{
		tmp = ft_strnew(2 * sizeof(*buf));
		ft_strclr(tmp);
		ft_strcpy(tmp, *buf);
		free(*buf);
		*buf = tmp;
		ft_strcat(*buf, buf_tmp);
	}
	else /** enough places we can write on the buffer **/
	{
		ft_strcat(*buf, buf_tmp);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*prog_buf = INIT_PROG_BUFF;
	char			*read_buf;
	int 			ret_read;

	ret_read = 0;
	(void)prog_buf;
	read_buf = ft_strnew(BUFF_SIZE + 1);
	ft_strclr(read_buf);
	while ((ret_read = read_extend_if_necessary(fd, &read_buf)) != 0)
	{
		
	}
	*line = read_buf;
	return (0);
}