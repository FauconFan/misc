/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_find_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:46:23 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 11:59:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t	ft_env_find_free(t_env *main, void *ptr)
{
	size_t	res;

	res = ft_ph_find_free(main->tn_header, ptr);
	if (res != 0)
		return (res);
	res = ft_ph_find_free(main->sm_header, ptr);
	if (res != 0)
		return (res);
	return (ft_ph_find_free(main->lrg_header, ptr));
}
