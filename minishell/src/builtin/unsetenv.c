/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:15:00 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/22 13:31:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_unsetenv(t_array_key **env_actu, char **args)
{
	int		number;

	number = 0;
	while (args[number])
		number++;
	if (number != 1)
		ft_dprintf(2, "usage: unsetenv VAR\n");
	else
	{
		remove_env_local(&env_actu, args[0]);
	}
}
