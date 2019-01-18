/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_config.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:40:03 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 10:34:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE_CONFIG_H
# define FT_BASE_CONFIG_H

t_bool					is_base_cmd(char *cmd);
void					do_base(t_cmd_parser *parser, char *cmd);

t_cmd_config_n			*ft_ssl_add_base_cmd(t_cmd_config_n *cmds_tab);

#endif
