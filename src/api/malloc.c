/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:20:14 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 13:52:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*malloc(size_t size)
{
	t_env		*env;
	t_blk		*blk;

	pthread_mutex_lock(&g_ft_env_mutex);
	blk = NULL;
	env = ft_env_get();
	if (env != NULL)
	{
		blk = ft_env_alloc(env, size);
		if (blk != NULL)
			blk++;
	}
	pthread_mutex_unlock(&g_ft_env_mutex);
	return (blk);
}
