/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_cache_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:50:36 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:52:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t		ft_env_cache_len(t_ph **cache)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (i < BUFF_PAGE_CACHE)
	{
		if (cache[i] != NULL)
			res++;
		i++;
	}
	return (res);
}
