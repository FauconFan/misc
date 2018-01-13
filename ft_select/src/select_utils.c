/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:22:11 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 17:37:30 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_arg		*init_arg(char *value)
{
	t_arg		*res;

	ft_memcheck((res = (t_arg *)malloc(sizeof(t_arg))));
	res->value = ft_strdup(value);
	res->is_selected = FALSE;
	return (res);
}

void				display_selected(t_select *env)
{
	t_bool		is_first;
	int			index;

	is_first = TRUE;
	index = -1;
	while (env->args[++index])
	{
		if (env->args[index]->is_selected)
		{
			if (is_first)
				is_first = FALSE;
			else
				ft_putstr_fd(" ", STDOUT_FILENO);
			ft_putstr_fd(env->args[index]->value, STDOUT_FILENO);
		}
	}
}

t_select			*init_select(int size, char **argv)
{
	t_select	*res;
	int			index;

	ft_memcheck((res = (t_select *)malloc(sizeof(t_select))));
	ft_memcheck((res->args = (t_arg **)malloc(sizeof(t_arg *) * (size + 1))));
	res->tot_args = size;
	res->index_selected = 0;
	index = 0;
	while (index < size)
	{
		res->args[index] = init_arg(argv[index]);
		index++;
	}
	res->args[index] = 0;
	return (res);
}

void				free_select(t_select **sel)
{
	int		index;

	index = 0;
	while (index < (*sel)->tot_args)
	{
		free((*sel)->args[index]->value);
		free((*sel)->args[index]);
		index++;
	}
	free((*sel)->args);
	free((*sel));
	*sel = NULL;
}
