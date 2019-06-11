/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:20:14 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/11 12:04:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*malloc(size_t size)
{
	t_env		*env;
	t_blk		*blk;

	if (size == 0)
		return (NULL);
	env = ft_env_get();
	if (env == NULL)
		return (NULL);
	blk = ft_env_find_alloc(env, size);
	if (blk == NULL)
		return (NULL);
	return (blk + 1);
}
