/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_sys_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:41:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 09:21:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ms_couple		*new_ms_couple(char *index, char *value)
{
	t_ms_couple		*res;

	ft_memcheck((res = (t_ms_couple *)malloc(sizeof(t_ms_couple))));
	res->index = index;
	res->value = value;
	res->next = 0;
	return (res);
}

static void				add_next(t_ms_couple **head, t_ms_couple *list)
{
	t_ms_couple		*tmp;

	if (*head == 0)
	{
		*head = list;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = list;
}

t_ms_couple				*build_cpy_env(char **env)
{
	t_ms_couple		*res;
	int				index;
	int				index_equals;

	index = 0;
	res = 0;
	while (env[index])
	{
		index_equals = ft_strcpos(env[index], '=');
		add_next(&res, new_ms_couple(
						ft_strndup(env[index], index_equals),
						ft_strdup(env[index] + index_equals + 1)));
		index++;
	}
	return (res);
}

void					free_cpy_env(t_ms_couple **head)
{
	t_ms_couple	*list;
	t_ms_couple	*next;

	if (*head)
	{
		list = *head;
		next = list->next;
		while (1)
		{
			free(list->index);
			free(list->value);
			free(list);
			list = next;
			if (list == 0)
				break ;
			next = list->next;
		}
	}
	*head = 0;
}