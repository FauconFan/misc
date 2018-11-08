/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_utils_time_modified.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 08:56:58 by jpriou            #+#    #+#             */
/*   Updated: 2018/11/08 11:44:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_sort_by_last_time_modified(void *d1, void *d2)
{
	int				tmp;
	t_file_content	*t1;
	t_file_content	*t2;

	t1 = (t_file_content *)d1;
	t2 = (t_file_content *)d2;
	tmp = t2->stat_file->st_mtime
		- t1->stat_file->st_mtime;
	if (tmp != 0)
		return (tmp);
	return (ft_strcmp(t1->name_file, t2->name_file));
}

int				ls_sort_by_last_time_modified_reverse(void *d1, void *d2)
{
	return (-ls_sort_by_last_time_modified(d1, d2));
}
