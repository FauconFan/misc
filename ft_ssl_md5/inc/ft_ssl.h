/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:43:39 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/12 15:40:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_COMMAND_H
#define FT_SSL_COMMAND_H

#include "libft.h"

#define HELP_OPT_P	"STDIN to STDOUT and append the checksum to STDOUT"
#define HELP_OPT_Q	"quiet mode"
#define HELP_OPT_R	"reverse the format of the output"
#define HELP_OPT_S	"print the sum of the given string"

#define HELP_MD5	"Digest messages with md5 algorithm."

#define HELP_PROG	"Program tool to crypt, hash or decrypt contents"

t_cmd_builder_parser_n			*build_md5_cmd();

#endif
