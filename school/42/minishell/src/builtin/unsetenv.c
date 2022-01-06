/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:15:00 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/25 09:45:39 by fauconfan        ###   ########.fr       */
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
		display_usage(CST_UNSETENV);
	else
	{
		remove_env_local(&env_actu, args[0]);
	}
}
