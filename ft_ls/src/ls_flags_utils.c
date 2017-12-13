/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 08:45:06 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/13 08:50:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		handle_flags_display(t_env_ls *env_ls, char c)
{
	if (c == 'l')
		env_ls->flags += FLAG_L_MIN * ((env_ls->flags & FLAG_L_MIN) == FALSE);
	else if (c == '1')
	{
		env_ls->flags -= FLAG_L_MIN * ((env_ls->flags & FLAG_L_MIN));
		env_ls->flags = env_ls->flags;
	}
	else if (c == 'n')
	{
		env_ls->flags += FLAG_N_MIN * ((env_ls->flags & FLAG_N_MIN) == FALSE);
		env_ls->flags += FLAG_L_MIN * ((env_ls->flags & FLAG_L_MIN) == FALSE);
	}
	else
		return (0);
	return (1);
}

void			handle_flags(t_env_ls *env_ls, char c)
{
	if (handle_flags_display(env_ls, c) == 1)
		return ;
	else if (c == 'R')
		env_ls->flags += FLAG_R_MAJ * ((env_ls->flags & FLAG_R_MAJ) == FALSE);
	else if (c == 'a')
		env_ls->flags += FLAG_A_MIN * ((env_ls->flags & FLAG_A_MIN) == FALSE);
	else if (c == 'r')
		env_ls->flags += FLAG_R_MIN * ((env_ls->flags & FLAG_R_MIN) == FALSE);
	else if (c == 't')
		env_ls->flags += FLAG_T_MIN * ((env_ls->flags & FLAG_T_MIN) == FALSE);
	else if (c == 'd')
		env_ls->flags += FLAG_D_MIN * ((env_ls->flags & FLAG_D_MIN) == FALSE);
	else if (c == 'p')
		env_ls->flags += FLAG_P_MIN * ((env_ls->flags & FLAG_P_MIN) == FALSE);
	else
		ls_display_usage(c, env_ls);
}
