/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:42:32 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 14:25:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"

# define ESC_KEYCODE		53

typedef struct		s_env_fdf
{
	void	*mlx_ptr;
	void	*mlx_win;
}					t_env_fdf;

t_env_fdf			*init_env_fdf(void);
void				free_env_fdf(t_env_fdf **env_fdf);

int					key_handle(int keycode, void *param);

#endif