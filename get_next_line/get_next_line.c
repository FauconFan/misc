/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:42:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/16 13:53:13 by jpriou           ###   ########.fr       */
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
	// *read_buf = ft_strnew(BUFF_SIZE);
	// return (BUFF_SIZE);
	if ((place_newline = ft_strcpos(*prog_buf, '\n')) == -1)
	{
		if (ft_strlen(*prog_buf) < BUFF_SIZE)
		{
			*read_buf = ft_strnew(BUFF_SIZE);
			ft_strcpy(*read_buf, *prog_buf);
			*prog_buf = INIT_PROG_BUFF;
			return (BUFF_SIZE);
		}
		*read_buf = *prog_buf;
		*prog_buf = INIT_PROG_BUFF;
		return (ft_strlen(*read_buf));
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
	// ft_putendl("coucou");
	if (place_newline == -1)
		return (0);
	// ft_putendl("Place");
	// ft_putnbrl(place_newline);
	new_original = ft_strnew(place_newline);
	// ft_putendl("Type");
	ft_strncpy(new_original, *original, (unsigned int)place_newline);
	new_prog_bug = ft_strconcat((*prog_buf == INIT_PROG_BUFF) ? "" : *prog_buf, (*original) + place_newline + 1);
	free(*original);
	free(*prog_buf);
	// ft_putendl("COUCOU");
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
	// ft_putstr("size_buff_actu :");
	// ft_putnbrl(*size_buff_actu);
	// ft_putstr("buf size :");
	// ft_putnbrl(ft_strlen(*buf));
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
	// ft_putstr("size_buff_actu :");
	// ft_putnbrl(*size_buff_actu);
	// ft_putstr("buf size :");
	// ft_putnbrl(ft_strlen(*buf));
	// ft_putendl("-----------------------");
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*prog_buf = INIT_PROG_BUFF;
	char			*read_buf;
	int 			ret_read;
	int 			size_buff_actu;

	size_buff_actu = check_previous_fd_in_prog_buf(&prog_buf, &read_buf);
	if (size_buff_actu == -1)
	{
		*line = read_buf;
		return (1);
	}
	// ft_putstr("Size buff actu :");
	// ft_putnbrl(size_buff_actu);
	// ft_putstr("Content prog_buff :");
	// ft_putendl((prog_buf == INIT_PROG_BUFF) ? "RIEN" : prog_buf);
	// ft_putstr("Size prog_buff :");
	// ft_putnbrl((prog_buf == INIT_PROG_BUFF) ? 0 : ft_strlen(prog_buf));
	// ft_putstr("strlen read_buf :");
	// ft_putnbrl(ft_strlen(read_buf));
	ret_read = 0;
	while ((ret_read = read_extend_if_necessary(fd, &read_buf, &size_buff_actu)) != 0)
	{
		if (check_and_parse_break_line(&read_buf, &prog_buf) != 0)
		{
			*line = read_buf;
			return (1);
		}
	}
	if (ret_read == -1)
		return (-1);
	*line = read_buf;
	return (0);
}