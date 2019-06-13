/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_cache_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:52:10 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:52:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_bool	ft_env_cache_put(t_ph **cache, t_ph *ph)
{
	size_t	i;

	if (cache == NULL)
		return (0);
	i = 0;
	while (i < BUFF_PAGE_CACHE)
	{
		if (cache[i] == NULL)
		{
			cache[i] = ph;
			return (TRUE);
		}
		++i;
	}
	return (FALSE);
}
