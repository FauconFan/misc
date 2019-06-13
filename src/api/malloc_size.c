/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:46:47 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 14:09:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_blk	*search(t_env *env, const void *ptr)
{
	if (env == NULL)
		return (NULL);
	return (ft_env_find(env, ptr));
}

size_t			malloc_size(const void *ptr)
{
	size_t	res;
	t_blk	*blk;

	pthread_mutex_lock(&g_ft_env_mutex);
	blk = search(ft_env_get(), ptr);
	res = 0;
	if (blk)
		res = blk->len_block - sizeof(t_blk);
	pthread_mutex_unlock(&g_ft_env_mutex);
	return (res);
}

size_t			malloc_asked_size(const void *ptr)
{
	size_t	res;
	t_blk	*blk;

	pthread_mutex_lock(&g_ft_env_mutex);
	blk = search(ft_env_get(), ptr);
	res = 0;
	if (blk)
		res = ft_blk_get_len_asked(blk);
	pthread_mutex_unlock(&g_ft_env_mutex);
	return (res);
}

size_t			ft_malloc_zone_malloc_size(
					t_malloc_zone *mzone,
					const void *ptr)
{
	size_t	res;
	t_blk	*blk;

	ft_env_mzone_lock(mzone);
	blk = search(mzone, ptr);
	res = 0;
	if (blk)
		res = blk->len_block - sizeof(t_blk);
	ft_env_mzone_unlock(mzone);
	return (res);
}

size_t			ft_malloc_zone_malloc_asked_size(
					t_malloc_zone *mzone,
					const void *ptr)
{
	size_t	res;
	t_blk	*blk;

	ft_env_mzone_lock(mzone);
	blk = search(mzone, ptr);
	res = 0;
	if (blk)
		res = ft_blk_get_len_asked(blk);
	ft_env_mzone_unlock(mzone);
	return (res);
}
