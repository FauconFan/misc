/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgst_config.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:37:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/18 09:44:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DGST_CONFIG_H
#define FT_DGST_CONFIG_H

#define HELP_DGT		"Digest messages with %s algorithm."

#define HELP_OPT_P		"STDIN to STDOUT and append the checksum to STDOUT"
#define HELP_OPT_Q		"quiet mode"
#define HELP_OPT_R		"reverse the format of the output"
#define HELP_OPT_S		"print the sum of the given string"

#define HELP_STDIN_TAG	"stdin_tag"
#define HELP_QUIET_TAG	"quiet_tag"
#define HELP_REV_TAG	"reverse_tag"
#define HELP_SAM_TAG	"samples_tag"

#define CMD_MD5			"md5"
#define CMD_MD4			"md4"
#define CMD_SHA1		"sha1"
#define CMD_SHA224		"sha224"
#define CMD_SHA256		"sha256"
#define CMD_SHA384		"sha384"
#define CMD_SHA512		"sha512"
#define CMD_SHA512_256	"sha512_256"
#define CMD_SHA512_224	"sha512_224"

typedef struct			s_dgst_config
{
	char				*help_title;
	char				*cmd;
	char				*(*hash)(uint8_t *, size_t);
	char				*name;
}						t_dgst_config;

typedef struct			s_dgst_cmd
{
	t_bool				stdin;
	t_bool				quiet;
	t_bool				reverse;
	char				**samples;
	char				*(*hash)(uint8_t *, size_t);
	int					nb_files;
	char				**file_names;
	char				*name;
}						t_dgst_cmd;

extern size_t			g_cmds_dgst_size;
extern t_dgst_config	g_cmds_dgst[];

void					ft_ssl_add_dgst_cmd(t_cmd_builder_parser *bd_parser);

t_dgst_cmd				*ft_ssl_dgst_init(t_cmd_parser *parser);
void					ft_ssl_dgst_free(t_dgst_cmd **cmd);

t_bool					is_dgst_cmd(char *cmd);
void					do_dgst(t_cmd_parser *parser);

#endif
