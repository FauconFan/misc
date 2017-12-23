/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_sys_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:41:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/23 16:34:24 by fauconfan        ###   ########.fr       */
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

t_array_key					**build_empty_env(void)
{
	t_array_key		**cpy_env;

	ft_memcheck((cpy_env = (t_array_key **)malloc(sizeof(t_array_key *))));
	cpy_env[0] = 0;
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

t_array_key					**cpy_env_from_another(t_array_key **list)
{
	t_array_key		**res;
	int				index;
	int				size;

	size = size_array_keys(list);
	ft_memcheck((res = (t_array_key **)malloc(sizeof(t_array_key *) * (size + 1))));
	index = 0;
	while (list[index])
	{
		ft_memcheck((res[index] = (t_array_key *)malloc(sizeof(t_array_key))));
		res[index]->key = ft_strdup(list[index]->key);
		res[index]->value = ft_strdup(list[index]->value);
		index++;
	}
	res[index] = 0;
	return (res);
}

void						display_env(t_array_key **list)
{
	int		index;

	index = 0;
	while (list[index])
	{
		ft_printf("%s=%s\n", list[index]->key, list[index]->value);
		index++;
	}
}
