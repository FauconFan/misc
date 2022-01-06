/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_array_keys_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:54:29 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/22 14:08:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			size_array_keys(t_array_key **env_local)
{
	int		res;

	res = 0;
	while (env_local[res])
		res++;
	return (res);
}

char		**from_array_keys_to_array_string(t_array_key **env_local)
{
	char	**res;
	int		index;
	int		size;

	index = 0;
	size = size_array_keys(env_local);
	ft_memcheck((res = (char **)malloc(sizeof(char *) * (size + 1))));
	while (index < size)
	{
		ft_sprintf(res + index, "%s=%s",
						env_local[index]->key,
						env_local[index]->value);
		index++;
	}
	res[index] = 0;
	return (res);
}

void		free_array_string(char **list)
{
	int		index;

	index = 0;
	while (list[index])
	{
		free(list[index]);
		index++;
	}
	free(list);
}
