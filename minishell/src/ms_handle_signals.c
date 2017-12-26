/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:27:42 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/26 14:50:19 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		handle_sigint(int signal)
{
	if (g_child_pid != 0)
	{
		kill(g_child_pid, signal);
		ft_putstr("\n");
	}
	else
	{
		if (g_cmd_actu != 0)
		{
			free(g_cmd_actu);
			g_cmd_size_actu = 0;
			g_cmd_actu = ft_strnew(0);
			ft_putstr("\n$> ");
		}
	}
}
