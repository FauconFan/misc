/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:42:18 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/09 13:32:32 by jpriou           ###   ########.fr       */
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

static char		*display_usage(void)
{
	ft_printf("****** FdF ******\n\n");
	ft_printf("usage ./fdf file_name\n\n");
	ft_printf("how to launch it :\n\n");
	ft_printf("you can specify two colors starting with the prefix \"0x\"\n");
	ft_printf("how to use it :\n\n");
	ft_printf("\t Q => Increase elevation\n");
	ft_printf("\t W => Decrease elevation\n\n");
	ft_printf("\t T => ROTATE X +\n\t Y => ROTATE X -\n");
	ft_printf("\t G => ROTATE Y +\n\t H => ROTATE Y -\n");
	ft_printf("\t B => ROTATE Z +\n\t N => ROTATE Z -\n\n");
	ft_printf("\t + => ZOOM +\n\t - => ZOOM -\n\n");
	ft_printf("\t UP => TRANSLATE UP\n\t DOWN => TRANSLATE DOWN\n");
	ft_printf("\t LEFT => TRANSLATE LEFT\n\t RIGHT => TRANSLATE RIGHT\n\n");
	ft_printf("\t MOUSE CLICK => orient the shape in the dir. of the mouse\n");
	exit(1);
	return (0);
}

static void		do_main(char *name_file, int color_values[2], int is_iso)
{
	t_env_fdf		*env_fdf;

	if (name_file == 0)
		display_usage();
	env_fdf = init_env_fdf(color_values, is_iso);
	ft_read_file(env_fdf, name_file);
	ft_init_matrix(env_fdf);
	treat_points_for_display_well(env_fdf);
	display_window(env_fdf);
	free_env_fdf(&env_fdf);
}

static void		treat_args(int argc, char **argv)
{
	char	*name_file;
	int		color_values[2];
	int		is_iso;
	int		index;

	index = -1;
	is_iso = 0;
	name_file = 0;
	color_values[0] = MIN_COLOR_DEFAULT;
	color_values[1] = MAX_COLOR_DEFAULT;
	while (++index < argc)
	{
		if (ft_strncmp(argv[index], "0x", 2) == 0 &&
			index != argc - 1 && ft_strncmp(argv[index + 1], "0x", 2) == 0)
		{
			color_values[0] = ft_atoi_base(argv[index++] + 2, BASE_HEXA);
			color_values[1] = ft_atoi_base(argv[index] + 2, BASE_HEXA);
		}
		else if (ft_strcmp(argv[index], "-iso") == 0)
			is_iso = 1;
		else
			name_file = (name_file == 0) ? argv[index] : display_usage();
	}
	do_main(name_file, color_values, is_iso);
}

int				main(int argc, char **argv)
{
	if (argc >= 2)
	{
		treat_args(argc - 1, ++argv);
	}
	else
		display_usage();
	return (0);
}
