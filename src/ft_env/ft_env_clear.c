/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:56:23 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 13:17:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

static void	clear_next(t_ph *prev, t_ph **cache)
{
	t_ph	*tmp;

	if (prev->next_page == NULL)
		return ;
	if (ft_ph_empty(prev->next_page))
	{
		tmp = prev->next_page;
		prev->next_page = prev->next_page->next_page;
		tmp->next_page = NULL;
		if (cache == NULL || ft_env_cache_put(cache, tmp) == FALSE)
			munmap(tmp, tmp->len_page);
		clear_next(prev, cache);
		return ;
	}
	clear_next(prev->next_page, cache);
}

static void	clear(t_ph **head, t_ph **cache)
{
	t_ph	*tmp;

	if (ft_ph_empty(*head) && cache == NULL)
	{
		tmp = (*head)->next_page;
		munmap((*head), (*head)->len_page);
		*head = tmp;
	}
	if (*head == NULL)
		return ;
	clear_next(*head, cache);
}

void		ft_env_clear(t_env *env)
{
	clear(&env->tn_header, env->tn_cache);
	clear(&env->sm_header, env->sm_cache);
	clear(&env->lrg_header, NULL);
}
