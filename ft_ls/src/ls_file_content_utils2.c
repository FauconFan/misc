/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file_content_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:08:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 19:26:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_simple_ptr	flag_manager(int flags)
{
	if (flags & FLAG_L_MIN)
		return (display_l_option);
	return (display_name_simply);
}

void			display_name_simply(void *content)
{
	t_file_content	*tmp;

	tmp = (t_file_content *)content;
	ft_printf("%s\n", tmp->name_file);
}
