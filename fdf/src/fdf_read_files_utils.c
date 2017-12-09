/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_files_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 08:36:04 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/09 08:38:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_col	*build_point(int x, int y, int z)
{
	t_point_col	*res;

	ft_memcheck((res = (t_point_col *)malloc(sizeof(t_point_col))));
	res->x = x;
	res->y = y;
	res->z = z;
	res->x_treated = (double)x;
	res->y_treated = (double)y;
	res->z_treated = (double)z;
	res->color = 0;
	res->is_changeable = 1;
	return (res);
}

t_fdf_line	*build_line(void)
{
	t_fdf_line	*res;

	ft_memcheck((res = (t_fdf_line *)malloc(sizeof(t_fdf_line))));
	res->list = 0;
	res->next = 0;
	return (res);
}

int			get_information_first(char *buff)
{
	int			size;

	size = 0;
	while (*buff)
	{
		if (ft_isblank(*buff))
			buff++;
		else if (ft_isdigit(*buff) ||
					(*buff == '-' && ft_isdigit(*(buff + 1))))
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
