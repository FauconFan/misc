/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:25:50 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/14 16:34:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>

/*
**	General defines
*/

# define TRUE				1
# define FALSE				0

typedef unsigned char		t_bool;

/*
**	ldf => loader file
*/

typedef struct				s_ldf
{
	char		*filepath;
	void		*content;
	size_t		len;
	int			fd;
	char		pad[4];
}							t_ldf;

t_bool						ft_ldf_init(t_ldf *ld, char *path_file);
t_bool						ft_ldf_end(t_ldf *ld);

/*
**	std utils functions
*/

void						ft_put_addr(const void *v);
void						ft_put_addr_ln(const void *v);

void						ft_put_str(const char *str);
void						ft_put_str_ln(const char *str);

void						ft_put_uint(unsigned long int nb);
void						ft_put_uint16(unsigned long int nb);
void						ft_put_uint_ln(unsigned long int nb);
void						ft_put_uint16_ln(unsigned long int nb);

#endif
