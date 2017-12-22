/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_sys_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:41:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/22 14:09:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_array_key					**build_cpy_env(char **env)
{
	t_array_key		**cpy_env;
	int				index;
	int				pos_equals;

	index = 0;
	while (env[index])
		index++;
	ft_memcheck((cpy_env = (t_array_key **)
				malloc(sizeof(t_array_key *) * (index + 1))));
	index = 0;
	while (env[index])
	{
		ft_memcheck((cpy_env[index] = (t_array_key *)
				malloc(sizeof(t_array_key))));
		pos_equals = ft_strcpos(env[index], '=');
		cpy_env[index]->key = ft_strndup(env[index], pos_equals);
		cpy_env[index]->value = ft_strdup(env[index] + pos_equals + 1);
		index++;
	}
	cpy_env[index] = 0;
	return (cpy_env);
}

void						free_cpy_env(t_array_key ***list)
{
	int			index;

	index = 0;
	while ((*list)[index])
	{
		free((*list)[index]->key);
		free((*list)[index]->value);
		free((*list)[index]);
		index++;
	}
	free((*list));
	*list = 0;
}
