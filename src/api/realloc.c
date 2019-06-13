/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:48:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 15:22:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	copy_buffer(void *ptr, char *next, size_t size, size_t len_in)
{
	if (size > len_in)
		size = len_in;
	ft_memcpy(next, ptr, size);
}

static void	*real_realloc(t_env *env, void *ptr, size_t size)
{
	t_blk		*blk;
	char		*next;
	size_t		len_in;

	if (size == 0)
		size = 16;
	next = NULL;
	if (env != NULL && (len_in = ft_env_find_free(env, ptr)) != 0)
	{
		if (size_ok(size) && (blk = ft_env_alloc(env, size)) != NULL)
		{
			next = (char *)(blk + 1);
			copy_buffer(ptr, next, size, len_in);
		}
		ft_env_clear(env);
	}
	return (next);
}

void		*realloc(void *ptr, size_t size)
{
	void	*res;

	if (ptr == NULL)
		return (malloc(size));
	pthread_mutex_lock(&g_ft_env_mutex);
	res = real_realloc(ft_env_get(), ptr, size);
	pthread_mutex_unlock(&g_ft_env_mutex);
	return (res);
}

void		*ft_malloc_zone_realloc(
				t_malloc_zone *mzone,
				void *ptr,
				size_t size)
{
	void	*res;

	if (ptr == NULL)
		return (ft_malloc_zone_malloc(mzone, size));
	ft_env_mzone_lock(mzone);
	res = real_realloc(mzone, ptr, size);
	ft_env_mzone_unlock(mzone);
	return (res);
}
