/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 09:02:45 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/24 10:58:56 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ms_env	*init_ms_env(char **env)
{
	t_ms_env	*res;
	char		*shlvl;
	char		*tmp;

	ft_memcheck((res = (t_ms_env *)malloc(sizeof(t_ms_env))));
	res->env_local = build_cpy_env(env);
	shlvl = get_env_local(res->env_local, ENV_CST_SHLVL);
	if (ft_str_is_numeric(shlvl))
	{
		tmp = ft_itoa(ft_atoi(shlvl) + 1);
		set_env_local(&(res->env_local), ENV_CST_SHLVL, tmp);
		free(tmp);
	}
	free(shlvl);
	return (res);
}

void		free_ms_env(t_ms_env **ms_env)
{
	free_cpy_env(&((*ms_env)->env_local));
	free(*ms_env);
	*ms_env = 0;
}
