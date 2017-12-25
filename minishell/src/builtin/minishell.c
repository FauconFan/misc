/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:49:36 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/25 10:02:10 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_minishell(t_ms_env *env_global)
{
	(void)env_global;
	ft_dprintf(2, "minishell is a small interpreter for a simple unix system\n");
	ft_dprintf(2, "\n\tList of all usages :\n");
	display_all_usages();
}
