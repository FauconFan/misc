/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:46:05 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/06 14:06:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point_col	*build_point(int x, int y, int z)
{
	t_point_col	*res;

	ft_memcheck((res = (t_point_col *)malloc(sizeof(t_point_col))));
	res->x = x;
	res->y = y;
	res->z = z;
	res->x_treated = (double)x;
	res->y_treated = (double)y;
	res->z_treated = (double)z;
	res->color = 0x00FFFFFF;
	res->is_changeable = 1;
	return (res);
}

static t_fdf_line	*build_line(void)
{
	t_fdf_line	*res;

	ft_memcheck((res = (t_fdf_line *)malloc(sizeof(t_fdf_line))));
	res->list = 0;
	res->next = 0;
	return (res);
}

int					get_information_first(char *buff)
{
	int			size;

	size = 0;
	while (*buff)
	{
		if (ft_isblank(*buff))
			buff++;
		else if (ft_isdigit(*buff) || (*buff == '-' && ft_isdigit(*(buff + 1))))
		{
			buff++;
			while (ft_isdigit(*buff))
				buff++;
			size++;
		}
		else
			ft_die(FILE_NOT_VALID);
	}
	return (size);
}

void				ft_fill(t_fdf_line *line, char *buff, int size_x, int size_y)
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
			line->list[size_actu] = build_point(size_actu, size_y, ft_atoi(buff));
			buff++;
			while (ft_isdigit(*buff))
				buff++;
			if (ft_strncmp(buff, ",0x", 3) == 0)
			{
				buff += 3;
				line->list[size_actu]->color = ft_atoi_base(buff, "0123456789ABCDEF");
				line->list[size_actu]->is_changeable = 0;
				while (ft_isxdigit(*buff))
					buff++;
			}
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

void				ft_fill_env(t_env_fdf *env_fdf, char *buff, int size_x, int fd)
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
