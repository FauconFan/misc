/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:37:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/18 12:41:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DES_CONFIG_H
#define FT_DES_CONFIG_H

#define HELP_DES		"Encrypt (DES) using %s cipher mode algorithm"

#define HELP_ASC_OUTPUT	"process (input/output) with base64 algorithm"
#define HELP_KEY_HEX	"key in hexadecimal form"
#define HELP_PWD		"password in ascii is the next argument"
#define HELP_SALT_HEX	"salt in hexadecimal form"
#define HELP_VEC_HEX	"initialization vector in hexadecimal form"

#define HELP_ASC_TAG	"ascii_tag"
#define HELP_KEY_TAG	"key_tag"
#define HELP_PWD_TAG	"password_tag"
#define HELP_SALT_TAG	"salt_tag"
#define HELP_VEC_TAG	"vector_tag"

#define CMD_ECB			"des-ecb"

typedef struct			s_des_config
{
	char				*help_title;
	char				*cmd;
	t_enc_mode			mode_cipher;
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
	char				*salt;
	char				*vector;
}						t_des_cmd;

extern size_t			g_cmds_des_size;
extern t_des_config		g_cmds_des[];

void					ft_ssl_add_des_cmd(t_cmd_builder_parser *bd_parser);

t_des_cmd				*ft_ssl_des_init(t_cmd_parser *parser);
void					ft_ssl_des_free(t_des_cmd **cmd);

t_bool					is_des_cmd(char *cmd);
void					do_des(t_cmd_parser *parser);

#endif
