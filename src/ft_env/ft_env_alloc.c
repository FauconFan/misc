/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:30:15 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 15:51:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_blk	*search(
						t_ph **page_ptr,
						t_len *len,
						size_t mult,
						t_ph **cache)
{
	if (*page_ptr == NULL)
	{
		*page_ptr = ft_ph_new(len->len, mult, cache);
		if (*page_ptr == NULL)
			return (NULL);
	}
	return (ft_ph_alloc(*page_ptr, len, mult, cache));
}

t_blk			*ft_env_alloc(t_env *env, size_t lasked)
{
	t_len	len;

	len.len_asked = lasked;
	len.len = lasked;
	len.len += sizeof(t_blk);
	size_multiple_16(&len.len);
	if (len.len <= TINY_MAX)
		return (search(&env->tn_header, &len, MULT_PAGE_TINY, env->tn_cache));
	if (len.len <= SMALL_MAX)
		return (search(&env->sm_header, &len, MULT_PAGE_SMALL, env->sm_cache));
	size_multiple_page(&len.len);
	len.len -= sizeof(t_ph);
	return (search(&env->lrg_header, &len, MULT_PAGE_LARGE, NULL));
}
