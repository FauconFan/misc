/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_main_find_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:30:32 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:30:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t	mlc_main_find_free(t_mlc_main *main, void *ptr)
{
	size_t	res;

	res = mlc_ph_find_free(main->tn_header, ptr);
	if (res != 0)
		return (res);
	res = mlc_ph_find_free(main->sm_header, ptr);
	if (res != 0)
		return (res);
	return (mlc_ph_find_free(main->lrg_header, ptr));
}
