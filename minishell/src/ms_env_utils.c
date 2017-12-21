/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 09:02:45 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 09:43:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ms_env	*init_ms_env(char **env)
{
	t_ms_env	*res;

	ft_memcheck((res = (t_ms_env *)malloc(sizeof(t_ms_env))));
	res->cpy_env = build_cpy_env(env);
	return (res);
}

void		free_ms_env(t_ms_env **ms_env)
{
	free_cpy_env(&((*ms_env)->cpy_env));
}
