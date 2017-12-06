/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:42:32 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/06 15:34:53 by jpriou           ###   ########.fr       */
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
# define ROTATE_WHEN_PRESSING	M_PI / 180.0

# define ESC_KEYCODE			53
# define UP_KEYCODE				126
# define DOWN_KEYCODE			125
# define LEFT_KEYCODE			123
# define RIGHT_KEYCODE			124

# define ZOOM_PLUS				69
# define ZOOM_MINUS				78

# define ROTATE_X_KEYCODE		31

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
	int					x;
	int					y;
	int					z;
	double				x_treated;
	double				y_treated;
	double				z_treated;
	unsigned int		color;
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
	t_fdf_line		*fdf_first_line;
	t_matrix_base	*matrix;
	int				size_x;
	int				size_y;
	double			rotation_x;
	double			rotation_y;
	double			rotation_z;
	double			actual_rotation[6];
}					t_env_fdf;

t_env_fdf			*init_env_fdf(void);
void				free_env_fdf(t_env_fdf **env_fdf);

void				draw_pixels(t_env_fdf *env_fdf);

void				ft_init_matrix(t_env_fdf *fdf);

int					key_handle(int keycode, void *param);

void				ft_read_file(t_env_fdf *env_fdf, char *name_file);

#endif
