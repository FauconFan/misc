/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_cache_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:53:29 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 13:28:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

t_ph	*ft_env_cache_get(t_ph **cache, size_t len)
{
	size_t	i;
	t_ph	*res;

	if (cache == NULL)
		return (NULL);
	i = 0;
	while (i < BUFF_PAGE_CACHE)
	{
		if (cache[i] != NULL
			&& cache[i]->len_page >= sizeof(t_ph) + sizeof(t_blk) + len)
		{
			res = cache[i];
			cache[i] = NULL;
			return (res);
		}
		++i;
	}
	return (NULL);
}
