/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:25:32 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:15:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	show_alloc_mem(void)
{
	t_env		*env;

	pthread_mutex_lock(&g_ft_env_mutex);
	env = ft_env_get();
	if (env == NULL)
		ft_put_str_ln("No env");
	else
		ft_env_print(env, FALSE);
	pthread_mutex_unlock(&g_ft_env_mutex);
}
