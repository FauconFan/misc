/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_set_env_local.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:39:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/23 16:11:54 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char					*get_env_local(t_array_key **list, char *key)
{
	int			index;

	index = 0;
	while (list[index])
	{
		if (ft_strcmp(list[index]->key, key) == 0)
		{
			return (ft_strdup(list[index]->value));
		}
		index++;
	}
	return (0);
}

void					set_env_local(
							t_array_key ***list,
							char *key,
							char *value)
{
	t_array_key		**new_list;
	int				index;

	index = 0;
	while ((*list)[index])
	{
		if (ft_strcmp((*list)[index]->key, key) == 0)
		{
			free((*list)[index]->value);
			(*list)[index]->value = ft_strdup(value);
			return ;
		}
		index++;
	}
	ft_memcheck((new_list = (t_array_key **)
			malloc(sizeof(t_array_key *) * (index + 2))));
	index = -1;
	while ((*list)[++index])
		new_list[index] = (*list)[index];
	ft_memcheck((new_list[index] = (t_array_key *)malloc(sizeof(t_array_key))));
	new_list[index]->key = ft_strdup(key);
	new_list[index]->value = ft_strdup(value);
	new_list[index + 1] = 0;
	free(*list);
	*list = new_list;
}

void					remove_env_local(t_array_key ***list, char *key)
{
	int			size;
	int			index;

	size = 0;
	while ((*list)[size])
	{
		if (ft_strcmp((*list)[size]->key, key) == 0)
		{
			free((*list)[size]->key);
			free((*list)[size]->value);
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
