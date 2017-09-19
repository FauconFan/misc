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

static char	**get_previous_fd(t_list **prog_buf, const int fd)
{
	t_list *tmp_list;
	t_elem *tmp_elem;

	tmp_list = *prog_buf;
	while (tmp_list)
	{
		if (((t_elem *)tmp_list->content)->fd == (int)fd)
			return (&(((t_elem *)tmp_list->content)->buf_fd));
		tmp_list = tmp_list->next;
	}
	if ((tmp_elem = (t_elem *)malloc(sizeof(t_elem))) == NULL)
		return (0);
	tmp_elem->fd = (int)fd;
	tmp_elem->buf_fd = INIT_PROG_BUFF;
	tmp_list = ft_lstnew((void const *)tmp_elem, sizeof(tmp_elem));
	ft_lstadd(prog_buf, tmp_list);
	return (&(((t_elem *)tmp_list->content)->buf_fd));
}

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

static int 	check_and_parse_break_line(char **original, char **prog_buf, int ret_read, int size_buff_actu)
{
	int 	place_newline;
	char	*new_original;
	char 	*new_prog_bug;

	ft_putendl("OUI");
	if (ret_read < BUFF_SIZE)
	{
			ft_putendl(*prog_buf);
	ft_putnbrl(((*prog_buf == INIT_PROG_BUFF) ? 0 : ft_strlen(*prog_buf)));
	ft_putendl(*original);
	ft_putnbrl(ret_read);
	ft_putnbrl(size_buff_actu);
		new_original = ft_strnew(BUFF_SIZE);
		ft_strncat(new_original, *original, ret_read);
		*original = new_original;
		return (2);
	}
	ft_putendl("NON");
	place_newline = ft_strcpos(*original, '\n');
	if (place_newline == -1)
		return (0);
	ft_putendl("ahhaha");
	new_original = ft_strnew(place_newline);
	ft_strncpy(new_original, *original, (unsigned int)place_newline);
	new_prog_bug = ft_strconcat((*prog_buf == INIT_PROG_BUFF) ? "" : *prog_buf, (*original) + place_newline + 1);
	ft_putendl(*original);
	free(*original);
	ft_putendl("ahhaha");
	free(*prog_buf);
	*original = new_original;
	*prog_buf = new_prog_bug;
	ft_putendl("coucou");
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
	return (rt);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*prog_buf_list = INIT_PROG_BUFF;
	char 			**prog_buf;
	int 			ret_read;
	int 			size_buff_actu;
	int 			code_check_parse;

	if ((int)fd < 0 || line == 0)
		return (-1);
	prog_buf = get_previous_fd(&prog_buf_list, fd);
	size_buff_actu = check_previous_fd_in_prog_buf(prog_buf, line);
	if (size_buff_actu == -1)
		return (1);
	ret_read = 0;
	while ((ret_read = read_extend_if_necessary(fd, line, &size_buff_actu)) != 0)
	{
		code_check_parse = check_and_parse_break_line(line, prog_buf, ret_read, size_buff_actu);
		if (code_check_parse == 1)
			return (1);
		else if (code_check_parse == 2)
			return (0);
	}
	if (ret_read == -1)
		return (-1);
	return (0);
}