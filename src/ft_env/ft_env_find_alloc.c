/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_find_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:30:15 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 11:59:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_blk	*alloc_page_then_search(
						t_ph **page_ptr,
						size_t len,
						size_t mult)
{
	if (*page_ptr == NULL)
	{
		*page_ptr = ft_ph_new(len, mult);
		if (*page_ptr == NULL)
			return (NULL);
	}
	return (ft_ph_find_alloc(*page_ptr, len, mult));
}

t_blk			*ft_env_find_alloc(t_env *main, size_t len)
{
	len += sizeof(t_blk);
	size_multiple_16(&len);
	if (len <= TINY_MAX)
		return (alloc_page_then_search(&main->tn_header, len, MULT_PAGE_TINY));
	if (len <= SMALL_MAX)
		return (alloc_page_then_search(&main->sm_header, len, MULT_PAGE_SMALL));
	size_multiple_page(&len);
	return (alloc_page_then_search(
				&main->lrg_header,
				len - sizeof(t_ph),
				MULT_PAGE_LARGE));
}
