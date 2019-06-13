/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_mzone_unlock.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:13:37 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 11:00:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_env_mzone_unlock(t_env *env)
{
	pthread_mutex_unlock((pthread_mutex_t *)(env + 1));
}
