/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:25:32 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 12:00:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	show_alloc_mem(void)
{
	t_env		*env;

	pthread_mutex_lock(&g_ft_env_mutex);
	env = ft_env_get();
	if (env != NULL)
		ft_env_print(env, FALSE);
	pthread_mutex_unlock(&g_ft_env_mutex);
}

void	ft_malloc_zone_show_alloc_mem(t_malloc_zone *mzone)
{
	if (mzone != NULL)
	{
		ft_env_mzone_lock(mzone);
		ft_env_print(mzone, FALSE);
		ft_env_mzone_unlock(mzone);
	}
}
