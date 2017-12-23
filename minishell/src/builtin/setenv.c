/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:14:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/23 16:02:56 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_exception_n_run(t_array_key ***env_actu, char *key, char *value)
{
	if (ft_strlen(key) == 0)
		ft_dprintf(2, "setenv: %s\n", ERROR_SETENV_EMPTY);
	else if (ft_isalpha(*key) == FALSE)
		ft_dprintf(2, "setenv: %s\n", ERROR_SETENV_BEGIN);
	else if (ft_str_is_alnum(key) == FALSE)
		ft_dprintf(2, "setenv: %s\n", ERROR_SETENV_ALNUM);
	else
		set_env_local(env_actu, key, value);
}

void	builtin_setenv(t_array_key ***env_actu, char **args)
{
	char	*new_value;
	int		number;

	number = 0;
	while (args[number])
		number++;
	if (number > 2 || number == 0)
		ft_dprintf(2, "usage: setenv VAR [VALUE]\n");
	else
	{
		if (number == 1)
			new_value = ft_strnew(0);
		else
			new_value = ft_strdup(args[1]);
		handle_exception_n_run(env_actu, args[0], new_value);
		free(new_value);
	}
}
