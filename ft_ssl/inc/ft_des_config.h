/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:37:56 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/16 22:56:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DES_CONFIG_H
#define FT_DES_CONFIG_H

typedef struct			s_des_config
{
	char				*cmd;
	t_enc_mode			mode_cipher;
	char				*help_title;
}						t_des_config;

typedef struct			s_des_cmd
{
	t_bool				ascii;
	t_bool				encode_mode;
	t_enc_mode			mode_cipher;
	char				*in;
	char				*out;
	char				*key;
	t_bool				ask_password;
	char				*password;
	char				*salt;
	char				*vector;
	t_bool				no_pad;
}						t_des_cmd;

t_cmd_config_n			*ft_ssl_add_des_cmd(t_cmd_config_n *cmds_tab);

t_des_cmd				*ft_ssl_des_init(t_cmd_parser *parser);
void					ft_ssl_des_free(t_des_cmd **cmd);

t_bool					is_des_cmd(char *cmd);
void					do_des(t_cmd_parser *parser);

#endif
