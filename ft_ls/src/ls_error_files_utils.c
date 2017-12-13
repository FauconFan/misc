/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error_files_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:48:37 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/13 10:31:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content_error_files	*ls_new_error_file(char *name)
{
	t_content_error_files	*res;

	ft_memcheck((res = (t_content_error_files *)
			malloc(sizeof(t_content_error_files))));
	res->file_name = name;
	res->perror_message = strerror(errno);
	return (res);
}

void					free_error_file(void *content)
{
	free(content);
}

/*
**	Remove this shit
*/

void					display_error(void *elem)
{
	t_content_error_files	*tmp;
	t_bool					is_fts_open;

	tmp = (t_content_error_files *)(elem);
	is_fts_open = ft_strcmp(tmp->file_name, "") == 0;
	ft_dprintf(2, "ft_ls: %s: %s\n",
		is_fts_open ? "fts_open" : tmp->file_name,
		tmp->perror_message);
	if (is_fts_open)
		exit(1);
}

int						cmp_error_files(void *d1, void *d2)
{
	t_content_error_files	*t1;
	t_content_error_files	*t2;

	t1 = (t_content_error_files *)d1;
	t2 = (t_content_error_files *)d2;
	return (ft_strcmp((char *)t1->file_name, (char *)t2->file_name));
}
