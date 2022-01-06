/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:46:05 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/09 08:38:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char			*ft_fill_one(
		t_point_col **po,
		int size_actu,
		int size_y,
		char *buff)
{
	*po = build_point(size_actu, size_y, ft_atoi(buff));
	buff++;
	while (ft_isdigit(*buff))
		buff++;
	if (ft_strncmp(buff, ",0x", 3) == 0)
	{
		buff += 3;
		(*po)->color = ft_atoi_base(buff, BASE_HEXA);
		(*po)->is_changeable = 0;
		while (ft_isxdigit(*buff))
			buff++;
	}
	return (buff);
}

void				ft_fill(
		t_fdf_line *line,
		char *buff,
		int size_x,
		int size_y)
{
	int		size_actu;

	ft_memcheck((line->list =
		(t_point_col **)malloc(sizeof(t_point_col *) * (size_x + 1))));
	line->list[size_x] = 0;
	size_actu = 0;
	while (*buff)
	{
		if (ft_isblank(*buff))
			buff++;
		else if (ft_isdigit(*buff) || (*buff == '-' && ft_isdigit(*(buff + 1))))
		{
			buff = ft_fill_one(line->list + size_actu, size_actu, size_y, buff);
			size_actu++;
			if (size_actu > size_x)
				ft_die(FILE_NOT_VALID);
		}
		else
			ft_die(FILE_NOT_VALID);
	}
	if (size_actu < size_x)
		ft_die(FILE_NOT_VALID);
}

void				ft_fill_env(
		t_env_fdf *env_fdf,
		char *buff,
		int size_x,
		int fd)
{
	int			size_y;
	t_fdf_line	*line;

	size_y = 0;
	env_fdf->fdf_first_line = build_line();
	line = env_fdf->fdf_first_line;
	while (1)
	{
		ft_fill(line, buff, size_x, size_y);
		free(buff);
		if (get_next_line(fd, &buff, env_fdf->env_gnl) == 0)
			break ;
		line->next = build_line();
		line = line->next;
		size_y++;
	}
	env_fdf->size_x = size_x;
	env_fdf->size_y = size_y;
}

void				ft_read_file(t_env_fdf *env_fdf, char *name_file)
{
	int			fd;
	char		*buff;
	int			size_x;

	buff = 0;
	env_fdf->env_gnl = init_env_gnl();
	if ((fd = open(name_file, O_RDONLY)) == -1)
		ft_die(NAME_FILE_NOT_VALID);
	if (get_next_line(fd, &buff, env_fdf->env_gnl) < 0)
		ft_die(STRANGE_OCCURED);
	size_x = get_information_first(buff);
	ft_fill_env(env_fdf, buff, size_x, fd);
	if (close(fd) == -1)
		ft_die(STRANGE_OCCURED);
}
