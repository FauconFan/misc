/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:25:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 12:44:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Utilities for file content sorting
*/

int		ls_sort_by_file_name(void *d1, void *d2)
{
	t_file_content	*t1;
	t_file_content	*t2;

	t1 = (t_file_content *)d1;
	t2 = (t_file_content *)d2;
	return (ft_strcmp(t1->name_file, t2->name_file));
}

int		ls_sort_by_file_name_reverse(void *d1, void *d2)
{
	return(-ls_sort_by_file_name(d1, d2));
}

int		ls_sort_by_last_time_modified(void *d1, void *d2)
{
	int				tmp;
	t_file_content	*t1;
	t_file_content	*t2;

	t1 = (t_file_content *)d1;
	t2 = (t_file_content *)d2;
	tmp = t2->stat_file->st_mtimespec.tv_sec - t1->stat_file->st_mtimespec.tv_sec;
	if (tmp != 0)
		return (tmp);
	return (ft_strcmp(t1->name_file, t2->name_file));
}

int		ls_sort_by_last_time_modified_reverse(void *d1, void *d2)
{
	return(-ls_sort_by_last_time_modified(d1, d2));
}
