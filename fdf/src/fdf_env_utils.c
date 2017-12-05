/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:11:24 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 14:15:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env_fdf		*init_env_fdf(void)
{
	t_env_fdf	*res;

	ft_memcheck((res = (t_env_fdf *)malloc(sizeof(t_env_fdf))));
	res->mlx_ptr = 0;
	res->mlx_win = 0;
	return (res);
}

void			free_env_fdf(t_env_fdf **env_fdf)
{
	t_env_fdf	*fdf;

	fdf = *env_fdf;
	mlx_destroy_window(fdf->mlx_ptr, fdf->mlx_win);
	fdf->mlx_win = 0;
	fdf->mlx_ptr = 0;
	*env_fdf = 0;
}
