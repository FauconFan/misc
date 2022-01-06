/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:20:14 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/23 11:26:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void		*real_malloc(t_env *env, size_t size)
{
	t_blk		*blk;

	if (size_ok(size) == FALSE)
		return (NULL);
	blk = NULL;
	if (env != NULL)
	{
		blk = ft_env_alloc(env, size);
		if (blk != NULL)
			blk++;
	}
	return (blk);
}

void			*malloc(size_t size)
{
	void		*res;

	pthread_mutex_lock(&g_ft_env_mutex);
	res = real_malloc(ft_env_get(), size);
	pthread_mutex_unlock(&g_ft_env_mutex);
	return (res);
}

void			*ft_malloc_zone_malloc(
					t_malloc_zone *mzone,
					size_t size)
{
	void	*res;

	ft_env_mzone_lock(mzone);
	res = real_malloc(mzone, size);
	ft_env_mzone_unlock(mzone);
	return (res);
}
