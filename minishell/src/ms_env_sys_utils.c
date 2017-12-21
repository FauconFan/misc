/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_sys_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:41:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 19:10:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char					**build_cpy_env(char **env)
{
	char	**cpy_env;
	int		index;

	index = 0;
	while(env[index])
		index++;
	ft_memcheck((cpy_env = (char **)malloc(sizeof(char *) * (index + 1))));
	index = 0;
	while (env[index])
	{
		cpy_env[index] = ft_strdup(env[index]);
		index++;
	}
	cpy_env[index] = 0;
	return (cpy_env);
}

void					free_cpy_env(char ***list)
{
	int			index;

	index = 0;
	while ((*list)[index])
	{
		free((*list)[index]);
		index++;
	}
	free((*list));
	*list = 0;
}

char					*get_env_local(char **list, char *key)
{
	int			index;
	int			pos_equals;

	index = 0;
	while (list[index])
	{
		pos_equals = ft_strcpos(list[index], '=');
		if (ft_strncmp(list[index], key, pos_equals) == 0)
		{
			return (ft_strdup(list[index] + pos_equals + 1));
		}
		index++;
	}
	return (0);
}

void					set_env_local(char ***list, char *key, char *value)
{
	int			index;
	int			pos_equals;
	char		**new_list;

	index = 0;
	while ((*list)[index])
	{
		pos_equals = ft_strcpos((*list)[index], '=');
		if (ft_strncmp((*list)[index], key, pos_equals) == 0)
		{
			free((*list)[index]);
			ft_sprintf((*list) + index, "%s=%s", key, value);
			return ;
		}
		index++;
	}
	ft_memcheck((new_list = (char **)malloc(sizeof(char *) * (index + 2))));
	index = -1;
	while ((*list)[++index])
		new_list[index] = (*list)[index];
	ft_sprintf(new_list + index, "%s=%s", key, value);
	new_list[index + 1] = 0;
	free(*list);
	*list = new_list;
}

void					remove_env_local(char ***list, char *key)
{
	int			pos_equals;
	int			size;
	int			index;

	size = 0;
	while ((*list)[size])
	{
		pos_equals = ft_strcpos((*list)[size], '=');
		if (ft_strncmp((*list)[size], key, pos_equals) == 0)
		{
			free((*list)[size]);
			index = size;
			while ((*list)[index + 1])
			{
				(*list)[index] = (*list)[index + 1];
				index++;
			}
			(*list)[index] = 0;
		}
		else
			size++;
	}
}
