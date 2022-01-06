/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_display_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:40:16 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/25 10:20:56 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_all_usages(void)
{
	display_usage(CST_ENV);
	display_usage(CST_SETENV);
	display_usage(CST_UNSETENV);
	display_usage(CST_CD);
	display_usage(CST_ECHO);
	display_usage(CST_PWD);
	display_usage(CST_HISTORY);
}

void	display_usage(char *option)
{
	if (ft_strcmp(option, CST_ENV) == 0)
		ft_dprintf(2, "usage: %s\n", USAGE_ENV);
	else if (ft_strcmp(option, CST_SETENV) == 0)
		ft_dprintf(2, "usage: %s\n", USAGE_SETENV);
	else if (ft_strcmp(option, CST_UNSETENV) == 0)
		ft_dprintf(2, "usage: %s\n", USAGE_UNSETENV);
	else if (ft_strcmp(option, CST_CD) == 0)
		ft_dprintf(2, "usage: %s\n", USAGE_CD);
	else if (ft_strcmp(option, CST_ECHO) == 0)
		ft_dprintf(2, "usage: %s\n", USAGE_ECHO);
	else if (ft_strcmp(option, CST_PWD) == 0)
		ft_dprintf(2, "usage: %s\n", USAGE_PWD);
	else if (ft_strcmp(option, CST_HISTORY) == 0)
		ft_dprintf(2, "usage: %s\n", USAGE_HISTORY);
}
