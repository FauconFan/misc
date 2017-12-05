/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:42:32 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 19:21:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft.h"

# define WIDTH_WINDOW			1200
# define HEIGHT_WINDOW			900

# define ESC_KEYCODE			53

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
}					t_env_fdf;

t_env_fdf			*init_env_fdf(void);
void				free_env_fdf(t_env_fdf **env_fdf);

void				ft_mlx_draw_line(int x1, int y1, int x2, int y2, t_env_fdf *env_fdf);
void				draw_pixels(t_env_fdf *env_fdf);

void				ft_init_matrix(t_env_fdf *fdf);

int					key_handle(int keycode, void *param);

void				ft_read_file(t_env_fdf *env_fdf, char *name_file);

#endif
