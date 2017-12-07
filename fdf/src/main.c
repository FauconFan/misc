/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:42:18 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/06 12:27:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_window(t_env_fdf *env_fdf)
{
	if ((env_fdf->mlx_ptr = mlx_init()) == 0)
		ft_die(STRANGE_OCCURED);
	if ((env_fdf->mlx_win = mlx_new_window(env_fdf->mlx_ptr, WIDTH_WINDOW, HEIGHT_WINDOW, "FdF")) == 0)
		ft_die(STRANGE_OCCURED);
	mlx_key_hook(env_fdf->mlx_win, key_handle, env_fdf);
	mlx_mouse_hook(env_fdf->mlx_win, mouse_handle, env_fdf);
	draw_pixels(env_fdf);
	mlx_loop(env_fdf->mlx_ptr);
}

void	do_main(char *name_file)
{
	t_env_fdf		*env_fdf;

	env_fdf = init_env_fdf();
	ft_read_file(env_fdf, name_file);
	ft_init_matrix(env_fdf);
	fdf_list_iter(env_fdf, adapt_each_point);
	display_window(env_fdf);
	free_env_fdf(&env_fdf);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		do_main(argv[1]);
	}
	else
		ft_die(ONE_UNIQUE_FILE);
	return (0);
}
