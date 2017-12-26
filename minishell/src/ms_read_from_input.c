/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_read_from_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:23:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/26 14:45:54 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		read_from_input(void)
{
	char	*tamp;
	char	c;

	g_cmd_size_actu = 0;
	g_cmd_actu = ft_strnew(g_cmd_size_actu);
	tamp = 0;
	while (1)
	{
		if (read(0, &c, 1) == -1)
			ft_die("read aborted");
		if (c == '\n')
			break ;
		if (c == '\t' || (c == ' ' && (g_cmd_size_actu == 0 ||
									g_cmd_actu[g_cmd_size_actu - 1] == ' ')))
			continue ;
		tamp = ft_strnew(g_cmd_size_actu + 1);
		ft_strncpy(tamp, g_cmd_actu, g_cmd_size_actu);
		tamp[g_cmd_size_actu] = c;
		g_cmd_size_actu++;
		free(g_cmd_actu);
		g_cmd_actu = tamp;
	}
}
