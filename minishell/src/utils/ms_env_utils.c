/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 09:02:45 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/25 10:21:29 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ms_env		*new_env(void)
{
	t_ms_env	*res;

	ft_memcheck((res = (t_ms_env *)malloc(sizeof(t_ms_env))));
	ft_memcheck((res->env_local =
						(t_array_key ***)malloc(sizeof(t_array_key **))));
	*(res->env_local) = 0;
	ft_memcheck((res->history_local = (t_history *)malloc(sizeof(t_history))));
	res->history_local->head = 0;
	res->history_local->tail = 0;
	return (res);
}

t_ms_env			*init_ms_env(char **env)
{
	t_ms_env	*res;
	char		*shlvl;
	char		*tmp;

	res = new_env();
	*(res->env_local) = build_cpy_env(env);
	shlvl = get_env_local(*(res->env_local), ENV_CST_SHLVL);
	if (ft_str_is_numeric(shlvl))
	{
		tmp = ft_itoa(ft_atoi(shlvl) + 1);
		set_env_local(res->env_local, ENV_CST_SHLVL, tmp);
		free(tmp);
	}
	free(shlvl);
	return (res);
}

t_ms_env			*cpy_from_another_env(t_ms_env *ms_env)
{
	t_ms_env		*res;

	res = new_env();
	*(res->env_local) = cpy_env_from_another(*(ms_env->env_local));
	return (res);
}

void				free_ms_env(t_ms_env **ms_env)
{
	free_cpy_env((*ms_env)->env_local);
	free((*ms_env)->env_local);
	ft_lstfreeall(&((*ms_env)->history_local->head), free_history);
	free((*ms_env)->history_local);
	free(*ms_env);
	*ms_env = 0;
}
