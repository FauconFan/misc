/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_munmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 09:19:26 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 09:48:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_env_munmap(t_env *env)
{
	size_t	i;

	if (env == NULL)
		return ;
	ft_ph_munmap(env->tn_header, TRUE);
	ft_ph_munmap(env->sm_header, TRUE);
	ft_ph_munmap(env->lrg_header, TRUE);
	i = 0;
	while (i < BUFF_PAGE_CACHE)
	{
		ft_ph_munmap(env->tn_cache[i], FALSE);
		ft_ph_munmap(env->sm_cache[i], FALSE);
		++i;
	}
	munmap(env, env->len_main);
}
