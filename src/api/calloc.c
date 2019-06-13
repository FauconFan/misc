/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:18:20 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 09:01:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
	t_env		*env;
	t_blk		*blk;

	if (do_mult_overflow(nmemb, size) || size_ok(nmemb * size) == FALSE)
		return (NULL);
	pthread_mutex_lock(&g_ft_env_mutex);
	blk = NULL;
	env = ft_env_get();
	if (env != NULL)
	{
		blk = ft_env_alloc(env, size * nmemb);
		if (blk != NULL)
		{
			blk++;
			ft_bzero(blk, nmemb * size);
		}
	}
	pthread_mutex_unlock(&g_ft_env_mutex);
	return (blk);
}
