/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:43:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 10:37:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termios.h>
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

void					core(t_des_cmd *cmd, uint64_t key, uint64_t iv);
char					*ft_poor_pbkdf2(char *password, char *salt);

/*
**	Utils
*/

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

int						ask_key_iv(t_des_cmd *cmd);
char					*ft_ask_pass(char *prompt);

t_bool					ft_str_to_uint64_ssl(uint64_t *key, char *str);

int						ft_getrandom(char *buffer, size_t len);

#endif
