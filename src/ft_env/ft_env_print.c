/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:45:32 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 11:59:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_env_print(t_env *main)
{
	ft_put_str_ln("TINY:");
	ft_ph_print(main->tn_header);
	ft_put_str_ln("SMALL:");
	ft_ph_print(main->sm_header);
	ft_put_str_ln("LARGE:");
	ft_ph_print(main->lrg_header);
}
