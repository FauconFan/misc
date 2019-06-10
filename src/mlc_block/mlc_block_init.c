/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_block_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:28:38 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:28:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		mlc_block_init(void *v, size_t remain_tot)
{
	t_mlc_block		*head_block;

	head_block = (t_mlc_block *)v;
	head_block->len_block = remain_tot;
	head_block->is_free = TRUE;
}
