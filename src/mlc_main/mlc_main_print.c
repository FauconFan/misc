/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_main_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:38:44 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:38:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	mlc_main_print(t_mlc_main *main)
{
	ft_put_str_ln("TINY:");
	mlc_ph_print(main->tn_header);
	ft_put_str_ln("SMALL:");
	mlc_ph_print(main->sm_header);
	ft_put_str_ln("LARGE:");
	mlc_ph_print(main->lrg_header);
}
