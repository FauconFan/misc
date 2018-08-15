/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:43:39 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/15 12:43:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_COMMAND_H
#define FT_SSL_COMMAND_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "libft.h"

#define HELP_OPT_P		"STDIN to STDOUT and append the checksum to STDOUT"
#define HELP_OPT_Q		"quiet mode"
#define HELP_OPT_R		"reverse the format of the output"
#define HELP_OPT_S		"print the sum of the given string"

#define HELP_STDIN_TAG	"stdin_tag"
#define HELP_QUIET_TAG	"quiet_tag"
#define HELP_REV_TAG	"reverse_tag"
#define HELP_SAM_TAG	"samples_tag"

#define HELP_DGT		"Digest messages with %s algorithm."

#define HELP_PROG		"Program tool to crypt, hash or decrypt contents"

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
	char				*(*hash)(char *);
	char				*name;
}						t_dgst_config;

typedef struct			s_dgst_cmd
{
	t_bool				stdin;
	t_bool				quiet;
	t_bool				reverse;
	char				**samples;
	char				*(*hash)(char *);
	int					nb_files;
	char				**file_names;
	char				*name;
}						t_dgst_cmd;

extern size_t			g_cmds_dgst_size;
extern t_dgst_config	g_cmds_dgst[];

void					ft_ssl_add_cmds(t_cmd_builder_parser *bd_parser);

t_dgst_cmd				*ft_ssl_dgst_init(t_cmd_parser *parser);
void					ft_ssl_dgst_free(t_dgst_cmd **cmd);

#endif
