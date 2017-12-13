/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:25:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/13 09:58:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ptr_cmp		get_sort_function(int flags)
{
	if (flags & FLAG_S_MAJ)
		return ((flags & FLAG_R_MIN) ? ls_sort_by_size_reverse :
								ls_sort_by_size);
	if (flags & FLAG_T_MIN)
	{
		if (flags & FLAG_R_MIN)
		{
			if (flags & FLAG_U_MAJ)
				return (ls_sort_by_last_time_birth_reverse);
			if (flags & FLAG_C_MIN)
				return (ls_sort_by_last_time_change_status_reverse);
			if (flags & FLAG_U_MIN)
				return (ls_sort_by_last_time_accessed_reverse);
			return (ls_sort_by_last_time_modified_reverse);
		}
		if (flags & FLAG_U_MAJ)
			return (ls_sort_by_last_time_birth);
		if (flags & FLAG_C_MIN)
			return (ls_sort_by_last_time_change_status);
		if (flags & FLAG_U_MIN)
			return (ls_sort_by_last_time_accessed);
		return (ls_sort_by_last_time_modified);
	}
	else if (flags & FLAG_R_MIN)
		return (ls_sort_by_file_name_reverse);
	return (ls_sort_by_file_name);
}

/*
**	Utilities for file content sorting
*/

int				ls_sort_by_file_name(void *d1, void *d2)
{
	t_file_content	*t1;
	t_file_content	*t2;

	t1 = (t_file_content *)d1;
	t2 = (t_file_content *)d2;
	return (ft_strcmp(t1->name_file, t2->name_file));
}

int				ls_sort_by_file_name_reverse(void *d1, void *d2)
{
	return (-ls_sort_by_file_name(d1, d2));
}
