/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:18:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:19:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	free(void *ptr)
{
	t_mlc_main	*env;

	if (ptr == NULL)
		return ;
	env = mlc_main_get();
	if (env == NULL)
		return ;
	mlc_main_find_free(env, ptr);
}
