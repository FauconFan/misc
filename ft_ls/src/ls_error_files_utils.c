/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error_files_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:48:37 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/10 15:48:49 by fauconfan        ###   ########.fr       */
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
	(void)content;
}

void					display_error(t_list *elem)
{
	t_content_error_files	*tmp;

	tmp = (t_content_error_files *)elem->content;
	ft_printf("ft_ls: cannot access '%s': %s\n",
		tmp->file_name,
		tmp->perror_message);
}

int						cmp_error_files(void *d1, void *d2)
{
	t_content_error_files	*t1;
	t_content_error_files	*t2;

	t1 = (t_content_error_files *)d1;
	t2 = (t_content_error_files *)d2;
	return (ft_strcmp((char *)t1->file_name, (char *)t2->file_name));
}
