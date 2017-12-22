/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:14:04 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/22 13:31:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_env(t_array_key **env_actu)
{
	int		index;

	index = 0;
	while (env_actu[index])
	{
		ft_printf("%s=%s\n", env_actu[index]->key, env_actu[index]->value);
		index++;
	}
}
