/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_init_mmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:37:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 11:52:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static t_bool	init_verif(char *path_file, int *fd, struct stat *statbuff)
{
	if ((*fd = open(path_file, O_RDONLY)) < 0)
	{
		ft_bput_str("Failed to open file : ");
		ft_bput_str_ln(path_file);
		return (FALSE);
	}
	if (fstat(*fd, statbuff) < 0)
	{
		ft_bput_str("Failed to fstat on file : ");
		ft_bput_str_ln(path_file);
		close(*fd);
		return (FALSE);
	}
	if (statbuff->st_size < 4)
	{
		ft_bput_str("The file is too small : ");
		ft_bput_str_ln(path_file);
		close(*fd);
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	mmap_file(
					t_ldf *ld,
					char *path_file,
					int fd,
					struct stat *statbuff)
{
	ld->len = (size_t)statbuff->st_size;
	if ((ld->content = mmap(NULL, ld->len, PROT_READ, MAP_PRIVATE, fd, 0))
		== MAP_FAILED)
	{
		ft_bput_str("Failed to load file : ");
		ft_bput_str_ln(path_file);
		close(fd);
		return (FALSE);
	}
	if (close(fd) < 0)
	{
		ft_bput_str("Failed to close the file : ");
		ft_bput_str_ln(path_file);
		munmap(ld->content, ld->len);
		return (FALSE);
	}
	return (TRUE);
}

t_bool			ft_ldf_init_mmap(
					t_ldf *ld,
					char *path_file,
					char *name,
					t_bool print_name)
{
	struct stat		statbuff;
	int				fd;

	ft_bzero(ld, sizeof(*ld));
	ld->is_mmap = TRUE;
	ld->print_name = print_name;
	ld->name = name;
	if (init_verif(path_file, &fd, &statbuff) == FALSE)
		return (FALSE);
	return (mmap_file(ld, path_file, fd, &statbuff));
}
