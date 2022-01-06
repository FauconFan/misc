/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ph_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:40:49 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:16:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_ph_print(t_ph *ph, t_bool hexa)
{
	t_blk	*blk;

	if (ph == NULL)
		return ;
	ft_put_str("PAGE => ");
	ft_put_addr(ph);
	ft_put_str(", LEN = ");
	ft_put_uint(ph->len_page);
	ft_put_str_ln("");
	if (ft_ph_empty(ph))
		ft_put_str_ln("\tEMPTY");
	else
	{
		blk = (t_blk *)(ph + 1);
		ft_blk_print(blk, ph->len_page - sizeof(t_ph), hexa);
	}
	ft_ph_print(ph->next_page, hexa);
}
