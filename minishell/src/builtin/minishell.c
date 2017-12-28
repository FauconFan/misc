/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:49:36 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/28 10:13:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_minishell(t_ms_env *env_global)
{
	(void)env_global;
	ft_dprintf(2, "%s\n",
				"minishell is a small interpreter for a simple unix system");
	ft_dprintf(2, "\n\tList of all usages :\n");
	display_all_usages();
}
