/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:42:18 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/06 12:27:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_handle(int button, int x, int y, void *fdf_env)
{
	t_env_fdf	*env;

	env = (t_env_fdf *)fdf_env;
	if (button == 1)
	{
		env->rotation_x = ((double)y - HEIGHT_WINDOW / 2) / (HEIGHT_WINDOW / 2);
		env->rotation_y = (-(double)x + WIDTH_WINDOW / 2) / (WIDTH_WINDOW / 2);
		draw_pixels(env);
	}
	return (0);
}
