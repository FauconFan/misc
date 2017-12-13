/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_utils_time_change_status.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:15:39 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/13 09:29:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_sort_by_last_time_change_status(void *d1, void *d2)
{
	int				tmp;
	t_file_content	*t1;
	t_file_content	*t2;

	t1 = (t_file_content *)d1;
	t2 = (t_file_content *)d2;
	tmp = t2->stat_file->st_ctimespec.tv_sec
		- t1->stat_file->st_ctimespec.tv_sec;
	if (tmp != 0)
		return (tmp);
	return (ft_strcmp(t1->name_file, t2->name_file));
}

int				ls_sort_by_last_time_change_status_reverse(void *d1, void *d2)
{
	return (-ls_sort_by_last_time_change_status(d1, d2));
}
