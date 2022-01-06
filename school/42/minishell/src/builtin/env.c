/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:14:04 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/28 10:42:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	1 <= -i : Remove everything in the environment
**	2 <= -u : Remove a single element
**	3 <= NAME=VALUE : set value of a new environment variable
*/

static void		handle_treatment_args(
					t_array_key ***env_actu,
					char *str1,
					char *str2,
					int option)
{
	if (option == 1)
	{
		free_cpy_env(env_actu);
		*env_actu = build_empty_env();
	}
	else if (option == 2)
	{
		remove_env_local(env_actu, str1);
	}
	else if (option == 3)
	{
		set_env_local(env_actu, str1, str2);
	}
}

static int		handle_simple_arg(
					t_array_key ***env_actu,
					char ***args,
					int *index)
{
	int		subindex;

	subindex = 1;
	while (((*args)[*index][subindex]))
	{
		if ((*args)[*index][subindex] == 'i')
			handle_treatment_args(env_actu, 0, 0, 1);
		else if ((*args)[*index][subindex] == 'u')
		{
			if ((*args)[*index][subindex + 1] != 0 || (*args)[*index + 1] == 0)
				return (1);
			*index = *index + 1;
			handle_treatment_args(env_actu, (*args)[*index], 0, 2);
			return (0);
		}
		else
			return (1);
		subindex++;
	}
	return (0);
}

static int		handle_args(t_array_key ***env_actu, char ***args)
{
	int		index;
	int		posequals;

	index = 0;
	while ((*args)[index])
	{
		if ((*args)[index][0] == '-')
		{
			if (handle_simple_arg(env_actu, args, &index) != 0)
				return (1);
		}
		else if ((posequals = ft_strcpos((*args)[index], '=')) != -1)
		{
			(*args)[index][posequals] = 0;
			handle_treatment_args(env_actu,
					(*args)[index],
					(*args)[index] + posequals + 1, 3);
		}
		else
			break ;
		index++;
	}
	*args = *args + index;
	return (0);
}

void			builtin_env(t_ms_env *env_global, char **args)
{
	t_ms_env		*new_env;

	new_env = cpy_from_another_env(env_global);
	if (handle_args(new_env->env_local, &args) != 0)
	{
		display_usage(CST_ENV);
		return ;
	}
	if (*args == 0)
		display_env(*(new_env->env_local));
	else
		handle_cmd(*args, args + 1, new_env);
	free_ms_env(&new_env);
}
