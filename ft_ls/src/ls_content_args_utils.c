/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_content_args_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:17:28 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/11 15:52:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_content_args	*ls_new_content_args(struct stat *stat_file, char *file_name)
{
	t_content_args	*res;

	ft_memcheck((res = (t_content_args *)malloc(sizeof(t_content_args))));
	res->stat_file = stat_file;
	res->file_name = file_name;
	return (res);
}

void			free_new_content_file(void *content)
{
	t_content_args	*tmp;

	tmp = (t_content_args *)content;
	free(tmp->stat_file);
	free(content);
}

void			display_content(void *content, void *param)
{
	t_content_args	*arg;
	struct stat		stat_actu;

	(void)param;
	arg = (t_content_args *)content;
	stat_actu = (struct stat)(*(arg->stat_file));
	ft_printf("%s %d\n", arg->file_name, stat_actu.st_ino);
}

int				cmp_content_args(void *d1, void *d2)
{
	t_content_args	*t1;
	t_content_args	*t2;

	t1 = (t_content_args *)d1;
	t2 = (t_content_args *)d2;
	return (ft_strcmp((char *)(t1->file_name), (char *)(t2->file_name)));
}
