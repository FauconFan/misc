/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:25:50 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 13:54:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h> // better includes

/*
**	General defines
*/

# define TRUE				1
# define FALSE				0

typedef unsigned char		t_bool;

# define BASE_DEC			"0123456789"
# define BASE_HEX_UP		"0123456789ABCDEF"
# define BASE_HEX_LOW		"0123456789abcdef"

/*
**	ldf => loader file
*/

# define CORRUPTION_MSG		"The file given is corrupted"

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
**	nm stuff
*/

void						nm_m64(t_ldf *ldf);

/*
**	otool stuff
*/

void						otool_m64(t_ldf *ldf);

/*
**	std utils functions
*/

void						ft_put_hex_char(uint8_t val);

void						ft_put_vm_addr(uint64_t addr);

void						ft_put_str(const char *str);
void						ft_put_str_ln(const char *str);

void						ft_put_uint(unsigned long int nb);
void						ft_put_uint16(unsigned long int nb);
void						ft_put_uint_ln(unsigned long int nb);
void						ft_put_uint16_ln(unsigned long int nb);

void						ft_put_uint_base(
								unsigned long int nb,
								const char *base,
								size_t width,
								char width_padded);

t_bool						ft_strequ(const char *s1, const char *s2);
int							ft_strcmp(const char *s1, const char *s2);

void						ft_memcpy(
								void *dest,
								const void *src,
								size_t len);
char						ft_toupper(char c);

#endif
