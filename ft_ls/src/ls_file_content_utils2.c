/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file_content_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:08:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 19:27:44 by jpriou           ###   ########.fr       */
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

void			display_total_blocks_if_need(int flags, t_list *dir_content)
{
	t_file_content	*tmp;
	int				size_tot;

	if (flags & FLAG_L_MIN)
	{
		size_tot = 0;
		tmp = (t_file_content *)dir_content->content;
		while (1)
		{
			size_tot += tmp->stat_file->st_blocks;
			if ((dir_content = dir_content->next) == 0)
				break ;
			tmp = (t_file_content *)dir_content->content;
		}
		ft_printf("total %d\n", size_tot);
	}
}
