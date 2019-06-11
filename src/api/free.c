/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:18:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 11:59:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	free(void *ptr)
{
	t_env	*env;

	if (ptr == NULL)
		return ;
	env = ft_env_get();
	if (env == NULL)
		return ;
	ft_env_find_free(env, ptr);
}
