/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:18:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 15:23:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	real_free(t_env *env, void *ptr)
{
	if (ptr != NULL && env != NULL)
	{
		ft_env_find_free(env, ptr);
		ft_env_clear(env);
	}
}

void		free(void *ptr)
{
	pthread_mutex_lock(&g_ft_env_mutex);
	real_free(ft_env_get(), ptr);
	pthread_mutex_unlock(&g_ft_env_mutex);
}

void		ft_malloc_zone_free(
				t_malloc_zone *mzone,
				void *ptr)
{
	ft_env_mzone_lock(mzone);
	real_free(mzone, ptr);
	ft_env_mzone_unlock(mzone);
}
