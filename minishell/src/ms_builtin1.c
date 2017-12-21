/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:59:49 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 18:43:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_env(t_ms_env *ms_env)
{
	int		index;

	index = 0;
	while (ms_env->cpy_env[index])
	{
		ft_printf("%s\n", ms_env->cpy_env[index]);
		index++;
	}
}

void	builtin_setenv(t_ms_env *ms_env, char **args)
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
		set_env_local(&(ms_env->cpy_env), args[0], if_no_value);
		free(if_no_value);
	}
}

void	builtin_unsetenv(t_ms_env *ms_env, char **args)
{
	int		number;

	number = 0;
	while (args[number])
		number++;
	if (number != 1)
		ft_dprintf(2, "usage: unsetenv VAR\n");
	else
	{
		remove_env_local(&(ms_env->cpy_env), args[0]);
	}
}
