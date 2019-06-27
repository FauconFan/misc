/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_print_recu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:03:57 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 10:04:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_buff_print_recu(t_buff_inner *inner)
{
	if (inner)
	{
		write(1, inner->buff, inner->len_actu);
		ft_buff_print_recu(inner->next);
	}
}
