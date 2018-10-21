/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_config.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:40:03 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/18 11:59:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE_CONFIG_H
#define FT_BASE_CONFIG_H

#define HELP_BASE64		"Base64 encode or decode."

#define CMD_BASE64		"base64"
#define CMD_BASE64_URL	"base64_url"

t_bool					is_base_cmd(char *cmd);
void					do_base(t_cmd_parser *parser, char *cmd);

void					ft_ssl_add_base_cmd(t_cmd_builder_parser *bd_parser);

#endif
