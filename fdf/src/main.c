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

static void		display_window(t_env_fdf *env_fdf)
{
	if ((env_fdf->mlx_ptr = mlx_init()) == 0)
		ft_die(STRANGE_OCCURED);
	if ((env_fdf->mlx_win = mlx_new_window(
			env_fdf->mlx_ptr, WIDTH_WINDOW, HEIGHT_WINDOW, "FdF")) == 0)
		ft_die(STRANGE_OCCURED);
	mlx_key_hook(env_fdf->mlx_win, key_handle, env_fdf);
	mlx_mouse_hook(env_fdf->mlx_win, mouse_handle, env_fdf);
	draw_pixels(env_fdf);
	mlx_loop(env_fdf->mlx_ptr);
}

static void		do_main(char *name_file)
{
	t_env_fdf		*env_fdf;

	env_fdf = init_env_fdf();
	ft_read_file(env_fdf, name_file);
	ft_init_matrix(env_fdf);
	treat_points_for_display_well(env_fdf);
	display_window(env_fdf);
	free_env_fdf(&env_fdf);
}

static void		display_usgae(void)
{
	ft_printf("****** FdF ******\n\n");
	ft_printf("usage ./fdf file_name\n");
	exit(1);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
	{
		do_main(argv[1]);
	}
	else
		display_usgae();
	return (0);
}
