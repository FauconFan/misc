/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgst_config.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:37:56 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 10:34:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DGST_CONFIG_H
# define FT_DGST_CONFIG_H

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

t_cmd_config_n			*ft_ssl_add_dgst_cmd(t_cmd_config_n *cmds_tab);

t_dgst_cmd				*ft_ssl_dgst_init(t_cmd_parser *parser);
void					ft_ssl_dgst_free(t_dgst_cmd **cmd);

t_bool					is_dgst_cmd(char *cmd);
void					do_dgst(t_cmd_parser *parser);

#endif
