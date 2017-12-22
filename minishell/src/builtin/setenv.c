/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:14:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/22 13:31:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_setenv(t_array_key ***env_actu, char **args)
{
	char	*if_no_value;
	int		number;

	number = 0;
	while (args[number])
		number++;
	if (number > 2 || number == 0)
		ft_dprintf(2, "usage: setenv VAR [VALUE]\n");
	else
	{
		if (number == 1)
			if_no_value = ft_strnew(0);
		else
			if_no_value = ft_strdup(args[1]);
		set_env_local(env_actu, args[0], if_no_value);
		free(if_no_value);
	}
}
