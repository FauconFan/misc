/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:42:32 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/09 08:37:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"

# define WIDTH_WINDOW			1200
# define HEIGHT_WINDOW			900

# define MOVE_WHEN_PRESSING		10
# define ZOOM_WHEN_PRESSING		1.05
# define ROTATE_WHEN_PRESSING	M_PI / 8.0
# define FACTOR_ELEVATION		1.1

# define MIN_COLOR_DEFAULT		0x00FFFFFF
# define MAX_COLOR_DEFAULT		0x0000FFFF

# define ESC_KEYCODE			53
# define UP_KEYCODE				126
# define DOWN_KEYCODE			125
# define LEFT_KEYCODE			123
# define RIGHT_KEYCODE			124

# define ZOOM_PLUS				69
# define ZOOM_MINUS				78

# define A_KEYCODE				12
# define Z_KEYCODE				13

# define ROTATE_PLUS_X_KEYCODE	17
# define ROTATE_MOINS_X_KEYCODE	16

# define ROTATE_PLUS_Y_KEYCODE	5
# define ROTATE_MOINS_Y_KEYCODE	4

# define ROTATE_PLUS_Z_KEYCODE	11
# define ROTATE_MOINS_Z_KEYCODE	45

# define RESET_KEYCODE			15

/*
**	define ESC_KEYCODE			65307
**	define UP_KEYCODE				65362
**	define DOWN_KEYCODE			65364
**	define LEFT_KEYCODE			65361
**	define RIGHT_KEYCODE			65363
**
**	define ZOOM_PLUS				112
**	define ZOOM_MINUS				109
**
**	define A_KEYCODE				97
**	define Z_KEYCODE				122
**
**	define ROTATE_PLUS_X_KEYCODE	116
**	define ROTATE_MOINS_X_KEYCODE	121
**	define ROTATE_PLUS_Y_KEYCODE	103
**	define ROTATE_MOINS_Y_KEYCODE	104
**	define ROTATE_PLUS_Z_KEYCODE	98
**	define ROTATE_MOINS_Z_KEYCODE	110
**
**	define RESET_KEYCODE			114
*/

# define BASE_HEXA				"0123456789ABCDEF"

# define FILE_NOT_VALID			"This file is not well formatted"
# define STRANGE_OCCURED		"Something occured"
# define NAME_FILE_NOT_VALID	"This file name is not valid"
# define ONE_UNIQUE_FILE		"You must specify one unique file"

typedef struct		s_matrix_base
{
	double			x1;
	double			x2;
	double			x3;
	double			y1;
	double			y2;
	double			y3;
	double			additional_x;
	double			additional_y;
}					t_matrix_base;

typedef struct		s_point_col
{
	double				x;
	double				y;
	double				z;
	double				x_treated;
	double				y_treated;
	double				z_treated;
	unsigned int		color;
	short				is_changeable;
}					t_point_col;

typedef struct		s_fdf_line
{
	t_point_col			**list;
	struct s_fdf_line	*next;
}					t_fdf_line;

typedef struct		s_env_fdf
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_env_gnl		*env_gnl;
	t_fdf_line		*fdf_first_line;
	t_matrix_base	*matrix;
	int				size_x;
	int				size_y;
	double			rotation_x;
	double			rotation_y;
	double			rotation_z;
	double			actual_rotation[6];
	int				min_color;
	int				max_color;
}					t_env_fdf;

t_env_fdf			*init_env_fdf(int color_values[2], int is_iso);
void				free_env_fdf(t_env_fdf **env_fdf);
void				setup_env_actu_rotation(t_env_fdf *res);

void				treat_points_for_display_well(t_env_fdf *env);
void				fdf_list_iter(t_env_fdf *env,
						void (*f)(t_env_fdf *env, t_point_col *po));

int					build_color(int color[6], double ecart, int dx);
void				draw_pixels(t_env_fdf *env_fdf);
void				build_rep(int color1, int color2, int *rep);

void				ft_init_matrix(t_env_fdf *fdf);

void				adapt_each_point(t_env_fdf *env, t_point_col *col);
int					key_handle(int keycode, void *param);
int					mouse_handle(int button, int x, int y, void *fdf_env);

void				ft_read_file(t_env_fdf *env_fdf, char *name_file);

t_point_col			*build_point(int x, int y, int z);
t_fdf_line			*build_line(void);
int					get_information_first(char *buff);


#endif
