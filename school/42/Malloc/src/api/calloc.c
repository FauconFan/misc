/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:18:20 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 12:07:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	*real_calloc(t_env *env, size_t nmemb, size_t size)
{
	t_blk		*blk;

	if (do_mult_overflow(nmemb, size) || size_ok(nmemb * size) == FALSE)
		return (NULL);
	blk = NULL;
	if (env != NULL)
	{
		blk = ft_env_alloc(env, size * nmemb);
		if (blk != NULL)
		{
			blk++;
			ft_bzero(blk, nmemb * size);
		}
	}
	return (blk);
}

void		*calloc(size_t nmemb, size_t size)
{
	void	*res;

	pthread_mutex_lock(&g_ft_env_mutex);
	res = real_calloc(ft_env_get(), nmemb, size);
	pthread_mutex_unlock(&g_ft_env_mutex);
	return (res);
}

void		*ft_malloc_zone_calloc(
				t_malloc_zone *mzone,
				size_t nmemb,
				size_t size)
{
	void	*res;

	ft_env_mzone_lock(mzone);
	res = real_calloc(mzone, nmemb, size);
	ft_env_mzone_unlock(mzone);
	return (res);
}
