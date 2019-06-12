/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ph_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:40:26 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 13:21:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_ph	*ft_ph_new(size_t size, size_t mult, t_ph **cache)
{
	t_ph	*res;

	res = ft_env_cache_get(cache, size);
	if (res)
		return (res);
	res = (t_ph *)mmap_good_size(&size, mult);
	if (res == NULL)
		return (NULL);
	res->len_page = size;
	res->next_page = NULL;
	ft_blk_init(res + 1, res->len_page - sizeof(t_ph));
	return (res);
}
