/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:37:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 11:45:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

t_bool		ft_ldf_init(t_ldf *ld, char *path_file)
{
	struct stat		statbuff;
	int				fd;

	ld->filepath = path_file;
	if ((fd = open(path_file, O_RDONLY)) < 0)
	{
		ft_put_str("Failed to open file : ");
		ft_put_str_ln(path_file);
		return (FALSE);
	}
	if (fstat(fd, &statbuff) < 0)
	{
		ft_put_str("Failed to fstat on file : ");
		ft_put_str_ln(path_file);
		close(fd);
		return (FALSE);
	}
	ld->len = (size_t)statbuff.st_size;
	if ((ld->content = mmap(NULL, ld->len, PROT_READ, MAP_PRIVATE, fd, 0))
		== MAP_FAILED)
	{
		ft_put_str("Failed to load file : ");
		ft_put_str_ln(path_file);
		close(fd);
		return (FALSE);
	}
	if (close(fd) < 0)
	{
		ft_put_str("Failed to close the file : ");
		ft_put_str_ln(path_file);
		munmap(ld->content, ld->len);
		return (FALSE);
	}
	return (TRUE);
}
