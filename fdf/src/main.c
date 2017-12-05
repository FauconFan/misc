/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:42:18 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 14:27:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_window(t_env_fdf *env_fdf)
{
	env_fdf->mlx_ptr = mlx_init();
	env_fdf->mlx_win = mlx_new_window(env_fdf->mlx_ptr, 400, 400, "test 42");
	mlx_key_hook (env_fdf->mlx_win, key_handle, env_fdf);
	mlx_loop(env_fdf->mlx_ptr);
}

int		main(void)
{
	t_env_fdf		*env_fdf;

	env_fdf = init_env_fdf();
	display_window(env_fdf);
	free_env_fdf(&env_fdf);
	return (0);
}
