/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:18:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 14:29:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_handle(int keycode, void *param)
{
	t_env_fdf	*env;

	env = (t_env_fdf *)param;
	if (keycode == ESC_KEYCODE)
	{
		free_env_fdf(&env);
		ft_printf("fdf exit normally, no leaks boys\n");
		exit(0);
	}
	else
		ft_printf("keycode : %d\n", keycode);
	return (0);
}
