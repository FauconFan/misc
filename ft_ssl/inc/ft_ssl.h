/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:43:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 11:36:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_COMMAND_H
# define FT_SSL_COMMAND_H

// #include <linux/random.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include "libft.h"
# include "ft_dgst_config.h"
# include "ft_base_config.h"
# include "ft_des_config.h"
# include "ssl_defines.h"

extern t_dgst_config	g_cmds_dgst[];
extern t_des_config		g_cmds_des[];
extern size_t			g_cmds_dgst_size;
extern size_t			g_cmds_des_size;

void					ft_ssl_add_cmds(t_cmd_builder_parser *bd_parser);

t_cmd_config			*cmd_config_init();
void					cmd_config_end(t_cmd_config *conf);

char					*get_in(char *input_file, size_t *len_in);
char					*get_in_ascii(
							char *input_file,
							size_t *len_in,
							t_bool ascii_mode);

void					set_out(
							char *output_file,
							char *o,
							size_t len_out,
							t_bool nl);

void					prepare_out_ascii(
							uint8_t **out,
							size_t *len,
							t_bool ascii_mode);

// uint64_t				custom_pbkdf2(char *pwd);
// int						getrandom(char *buffer, size_t len);

#endif
