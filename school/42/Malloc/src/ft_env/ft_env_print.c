/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:45:32 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 08:14:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_env_print(t_env *main, t_bool hexa)
{
	size_t	len_caches[2];

	ft_put_str_ln("TINY:");
	ft_ph_print(main->tn_header, hexa);
	ft_put_str_ln("SMALL:");
	ft_ph_print(main->sm_header, hexa);
	ft_put_str_ln("LARGE:");
	ft_ph_print(main->lrg_header, hexa);
	len_caches[0] = ft_env_cache_len(main->tn_cache);
	len_caches[1] = ft_env_cache_len(main->sm_cache);
	if (len_caches[0])
	{
		ft_put_str("Number tiny pages in cache :  ");
		ft_put_uint16_ln(len_caches[0]);
	}
	if (len_caches[1])
	{
		ft_put_str("Number small pages in cache :  ");
		ft_put_uint16_ln(len_caches[1]);
	}
}
