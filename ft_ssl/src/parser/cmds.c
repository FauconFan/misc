/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:04:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/18 09:33:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void					ft_ssl_add_cmds(t_cmd_builder_parser *bd_parser)
{
	ft_ssl_add_base_cmd(bd_parser);
	ft_ssl_add_dgst_cmd(bd_parser);
	ft_ssl_add_des_cmd(bd_parser);
}
