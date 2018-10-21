/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:43:39 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/18 11:59:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_COMMAND_H
#define FT_SSL_COMMAND_H

#include <linux/random.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "libft.h"
#include "ft_dgst_config.h"
#include "ft_base_config.h"
#include "ft_des_config.h"

/*
**	Define common to multiple modes (des, base)
*/

#define HELP_OPT_DEC	"decode mode"
#define HELP_OPT_ENC	"encode mode (default)"
#define HELP_OPT_IN		"input file (default:stdin)"
#define HELP_OPT_OUT	"output file (default:stdout)"

#define HELP_ENC_TAG	"encode_tag"
#define HELP_DEC_TAG	"decode_tag"
#define HELP_IN_TAG		"input_file_tag"
#define HELP_OUT_TAG	"output_file_tag"

#define HELP_PROG		"Program tool to crypt, hash or decrypt contents"

void					ft_ssl_add_cmds(t_cmd_builder_parser *bd_parser);

uint64_t				custom_pbkdf2(char *pwd);
int						getrandom(char *buffer, size_t len);

#endif
