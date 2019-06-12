/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ph_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:37:43 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 12:40:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

t_bool		ft_ph_empty(t_ph *ph)
{
	t_blk	*blk;

	if (ph == NULL)
		return (FALSE);
	blk = (t_blk *)(ph + 1);
	return ((ph->len_page - sizeof(t_ph) == blk->len_block)
			&& blk->is_free == TRUE);
}
