/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:18:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/06 15:36:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		directional_buttons(int keycode, t_env_fdf *env)
{
	if (keycode == UP_KEYCODE)
		env->matrix->additional_y -= MOVE_WHEN_PRESSING;
	else if (keycode == DOWN_KEYCODE)
		env->matrix->additional_y += MOVE_WHEN_PRESSING;
	else if (keycode == LEFT_KEYCODE)
		env->matrix->additional_x -= MOVE_WHEN_PRESSING;
	else if (keycode == RIGHT_KEYCODE)
		env->matrix->additional_x += MOVE_WHEN_PRESSING;
	else
		return (0);
	return (1);
}

static int		handle_zoom(int keycode, t_env_fdf *env)
{
	if (keycode == ZOOM_PLUS)
	{
		env->matrix->x1 *= ZOOM_WHEN_PRESSING;
		env->matrix->x2 *= ZOOM_WHEN_PRESSING;
		env->matrix->x3 *= ZOOM_WHEN_PRESSING;
		env->matrix->y1 *= ZOOM_WHEN_PRESSING;
		env->matrix->y2 *= ZOOM_WHEN_PRESSING;
		env->matrix->y3 *= ZOOM_WHEN_PRESSING;
	}
	else if (keycode == ZOOM_MINUS)
	{
		env->matrix->x1 /= ZOOM_WHEN_PRESSING;
		env->matrix->x2 /= ZOOM_WHEN_PRESSING;
		env->matrix->x3 /= ZOOM_WHEN_PRESSING;
		env->matrix->y1 /= ZOOM_WHEN_PRESSING;
		env->matrix->y2 /= ZOOM_WHEN_PRESSING;
		env->matrix->y3 /= ZOOM_WHEN_PRESSING;
	}
	else
		return (0);
	return (1);
}

static int		handle_rotate(int keycode, t_env_fdf *env)
{
	if (keycode == ROTATE_X_KEYCODE)
	{
		env->rotation_y += ROTATE_WHEN_PRESSING;
	}
	else
		return (0);
	return (1);
}

int				key_handle(int keycode, void *param)
{
	t_env_fdf	*env;

	env = (t_env_fdf *)param;
	if (handle_zoom(keycode, env) != 0 ||
		directional_buttons(keycode, env) != 0 ||
		handle_rotate(keycode, env) != 0)
	{
		draw_pixels(env);
		return (0);
	}
	else if (keycode == ESC_KEYCODE)
	{
		free_env_fdf(&env);
		ft_printf("fdf exit normally, no leaks boys\n");
		exit(0);
	}
	else
		ft_printf("keycode : %d\n", keycode);
	return (0);
}
