/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:36:50 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 13:36:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_blk	*ft_env_find(t_env *main, const void *ptr)
{
	t_blk	*res;

	res = ft_ph_find(main->tn_header, ptr);
	if (res != NULL)
		return (res);
	res = ft_ph_find(main->sm_header, ptr);
	if (res != NULL)
		return (res);
	return (ft_ph_find(main->lrg_header, ptr));
}
