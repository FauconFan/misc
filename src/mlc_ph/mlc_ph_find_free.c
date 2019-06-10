/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_ph_find_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:39:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:39:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t	mlc_ph_find_free(t_mlc_ph *ph, void *ptr)
{
	t_mlc_block	*block;
	size_t		remain;
	size_t		res;

	if (ph == NULL || ptr == NULL)
		return (0);
	block = (t_mlc_block *)(ph + 1);
	remain = ph->len_page - sizeof(t_mlc_ph);
	res = mlc_block_find_free(block, remain, ptr);
	if (res != 0)
		return (res);
	return (mlc_ph_find_free(ph->next_page, ptr));
}
