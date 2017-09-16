/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:42:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/16 15:25:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static int	check_previous_fd_in_prog_buf(char **prog_buf, char **read_buf)
{
	int 	place_newline;
	char 	*tmp;

	if (*prog_buf == INIT_PROG_BUFF)
	{
		*read_buf = ft_strnew(BUFF_SIZE);
		return (BUFF_SIZE);
	}
	if ((place_newline = ft_strcpos(*prog_buf, '\n')) == -1)
	{
		if (ft_strlen(*prog_buf) < BUFF_SIZE)
			ft_strcpy((*read_buf = ft_strnew(BUFF_SIZE)), *prog_buf);
		else
			*read_buf = *prog_buf;
		*prog_buf = INIT_PROG_BUFF;
		return (MAX(ft_strlen(*read_buf), BUFF_SIZE));
	}
	*read_buf = ft_strnew(place_newline);
	ft_strncpy(*read_buf, *prog_buf, place_newline);
	tmp = ft_strdup((*prog_buf) + place_newline + 1);
	free(*prog_buf);
	*prog_buf = tmp;
	return (-1);
}

static int 	check_and_parse_break_line(char **original, char **prog_buf)
{
	int 	place_newline;
	char	*new_original;
	char 	*new_prog_bug;

	place_newline = ft_strcpos(*original, '\n');
	if (place_newline == -1)
		return (0);
	new_original = ft_strnew(place_newline);
	ft_strncpy(new_original, *original, (unsigned int)place_newline);
	new_prog_bug = ft_strconcat((*prog_buf == INIT_PROG_BUFF) ? "" : *prog_buf, (*original) + place_newline + 1);
	free(*original);
	free(*prog_buf);
	*original = new_original;
	*prog_buf = new_prog_bug;
	return (1);
}

static int	read_extend_if_necessary(const int fd, char **buf, int *size_buff_actu)
{
	char			buf_tmp[BUFF_SIZE + 1];
	char			*tmp;
	int				rt;

	ft_strclr(buf_tmp);
	rt = read((int)fd, buf_tmp, BUFF_SIZE);
	if (rt <= 0)
		return (0);
	buf_tmp[BUFF_SIZE] = 0;
	if (*size_buff_actu - ft_strlen(*buf) <= (unsigned int)rt) /** Not enough places **/
	{
		*size_buff_actu = *size_buff_actu * 2;
		tmp = ft_strnew(*size_buff_actu);
		ft_strcpy(tmp, *buf);
		free(*buf);
		*buf = tmp;
		ft_strcat(*buf, buf_tmp);
	}
	else /** enough places we can write in the buffer **/
	{
		ft_strcat(*buf, buf_tmp);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*prog_buf = INIT_PROG_BUFF;
	int 			ret_read;
	int 			size_buff_actu;

	if ((int)fd < 0 || line == 0)
		return (-1);
	size_buff_actu = check_previous_fd_in_prog_buf(&prog_buf, line);
	if (size_buff_actu == -1)
		return (1);
	ret_read = 0;
	while ((ret_read = read_extend_if_necessary(fd, line, &size_buff_actu)) != 0)
	{
		if (check_and_parse_break_line(line, &prog_buf) != 0)
			return (1);
	}
	if (ret_read == -1)
		return (-1);
	return (0);
}