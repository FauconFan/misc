/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:18:20 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 17:59:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
	t_env		*env;
	t_blk		*blk;
	char		*v;
	size_t		i;

	pthread_mutex_lock(&g_ft_env_mutex);
	blk = NULL;
	env = ft_env_get();
	if (env != NULL)
	{
		blk = ft_env_alloc(env, size * nmemb);
		if (blk != NULL)
		{
			blk++;
			v = (char *)blk;
			i = 0;
			while (i < nmemb * size)
			{
				v[i] = 0;
				++i;
			}
		}
	}
	pthread_mutex_unlock(&g_ft_env_mutex);
	return (blk);
}
