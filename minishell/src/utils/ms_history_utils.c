/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_history_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 10:09:04 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/26 11:27:42 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		free_history(void *content)
{
	free(content);
}

void		add_in_history(t_ms_env *ms_env, char *cmd)
{
	t_list	*tmp;

	tmp = ft_lstnew_nocpy(ft_strdup(cmd));
	if (ms_env->history_local->tail == 0)
	{
		ms_env->history_local->head = tmp;
		ms_env->history_local->tail = tmp;
	}
	else
	{
		ms_env->history_local->tail->next = tmp;
		ms_env->history_local->tail = tmp;
	}
}

void		display_history(t_ms_env *ms_env)
{
	t_list	*tmp;
	int		index;

	tmp = ms_env->history_local->head;
	index = 1;
	while (tmp)
	{
		ft_printf("%-10d%s\n", index, (char *)tmp->content);
		tmp = tmp->next;
		index++;
	}
}
