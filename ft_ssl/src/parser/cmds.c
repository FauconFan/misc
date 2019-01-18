/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:04:56 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 10:46:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_cmd_config			*cmd_config_init(void)
{
	t_cmd_config		*conf;
	t_cmd_config_n		*ptrtmp;

	if ((conf = (t_cmd_config *)malloc(sizeof(t_cmd_config))) == NULL)
		exit(2);
	conf->help = ft_strdup(HELP_PROG);
	conf->nb_cmds = g_cmds_dgst_size + g_cmds_des_size + 2;
	if ((conf->cmds = (t_cmd_config_n *)malloc(
						sizeof(t_cmd_config_n) * (conf->nb_cmds))) == NULL)
		exit(2);
	ptrtmp = conf->cmds;
	ptrtmp = ft_ssl_add_dgst_cmd(ptrtmp);
	ptrtmp = ft_ssl_add_des_cmd(ptrtmp);
	ptrtmp = ft_ssl_add_base_cmd(ptrtmp);
	return (conf);
}

void					cmd_config_end(t_cmd_config *conf)
{
	size_t				i;

	i = -1;
	while (++i < conf->nb_cmds)
	{
		free(conf->cmds[i].cmd);
		free(conf->cmds[i].u.cli_config->help);
		free(conf->cmds[i].u.cli_config);
	}
	free(conf->cmds);
	free(conf->help);
	free(conf);
}
