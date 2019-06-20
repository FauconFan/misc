/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:25:50 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 11:41:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
// # include <ar.h>
# include <mach-o/fat.h>
# include <mach-o/arch.h>
# include <sys/utsname.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h> // better includes

# include "std.h"

/*
**	ldf => loader file
*/

# define CORRUPTION_MSG		"The file given is corrupted"
# define ARCHI_MSG			"The architecture cannot be determined"
# define UNKNOWN_FILE		"Unkwnown file type"

typedef struct				s_ldf
{
	char		*filepath;
	void		*content;
	size_t		len;
}							t_ldf;

t_bool						ft_ldf_init(t_ldf *ld, char *path_file);
t_bool						ft_ldf_end(t_ldf *ld);
void						*ft_ldf_jmp(
								t_ldf *ldf,
								size_t offset,
								size_t at_least);
void						*ft_ldf_jmp_str(t_ldf *ldf, size_t offset);

void						ft_otool(t_ldf *lfd);
void						ft_nm(t_ldf *ldf);

/*
**	arch stuff
*/

typedef struct				s_arch_buff
{
	t_bool			set;
	t_bool			fail;
	struct utsname	ust;
}							t_arch_buffer;

char						*get_arch(void);

/*
**	fat stuff
*/

void						fat_cigam(t_ldf *ldf, void (*f)(t_ldf *ldf));

/*
**	nm stuff
*/

void						nm_m64(t_ldf *ldf);

/*
**	otool stuff
*/

void						otool_m64(t_ldf *ldf);

/*
**	utils functions
*/

t_bool						ft_check_str(char *s, size_t remain);

#endif
