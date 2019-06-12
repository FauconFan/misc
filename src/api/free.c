/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:18:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 13:53:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	free(void *ptr)
{
	t_env	*env;

	pthread_mutex_lock(&g_ft_env_mutex);
	if (ptr != NULL)
	{
		env = ft_env_get();
		if (env != NULL)
		{
			ft_env_find_free(env, ptr);
			ft_env_clear(env);
		}
	}
	pthread_mutex_unlock(&g_ft_env_mutex);
}
