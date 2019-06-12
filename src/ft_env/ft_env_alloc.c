/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:30:15 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 13:20:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_blk	*search(
						t_ph **page_ptr,
						size_t len,
						size_t mult,
						t_ph **cache)
{
	if (*page_ptr == NULL)
	{
		*page_ptr = ft_ph_new(len, mult, cache);
		if (*page_ptr == NULL)
			return (NULL);
	}
	return (ft_ph_alloc(*page_ptr, len, mult, cache));
}

t_blk			*ft_env_alloc(t_env *env, size_t l)
{
	l += sizeof(t_blk);
	size_multiple_16(&l);
	if (l <= TINY_MAX)
		return (search(&env->tn_header, l, MULT_PAGE_TINY, env->tn_cache));
	if (l <= SMALL_MAX)
		return (search(&env->sm_header, l, MULT_PAGE_SMALL, env->sm_cache));
	size_multiple_page(&l);
	return (search(&env->lrg_header, l - sizeof(t_ph), MULT_PAGE_LARGE, NULL));
}
