/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_utils_time_birth.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:08:55 by jpriou            #+#    #+#             */
/*   Updated: 2018/11/08 11:44:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_sort_by_last_time_birth(void *d1, void *d2)
{
	int				tmp;
	t_file_content	*t1;
	t_file_content	*t2;

	t1 = (t_file_content *)d1;
	t2 = (t_file_content *)d2;
	tmp = t2->stat_file->st_btime
		- t1->stat_file->st_btime;
	if (tmp != 0)
		return (tmp);
	return (ft_strcmp(t1->name_file, t2->name_file));
}

int				ls_sort_by_last_time_birth_reverse(void *d1, void *d2)
{
	return (-ls_sort_by_last_time_birth(d1, d2));
}
