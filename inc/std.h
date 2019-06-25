/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:39:02 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 15:12:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_H
# define STD_H

# include <unistd.h>
# include <stdint.h>

/*
**	General defines
*/

# define TRUE			1
# define FALSE			0

typedef unsigned char	t_bool;

# define BASE_DEC		"0123456789"
# define BASE_HEX_UP	"0123456789ABCDEF"
# define BASE_HEX_LOW	"0123456789abcdef"

/*
**	mem
*/

void					ft_memcpy(
							void *dest,
							const void *src,
							size_t len);
void					ft_memset(void *dest, size_t len, char c);
void					ft_bzero(void *dest, size_t len);

/*
**	int
*/

int32_t					ft_swap_int32(int32_t val);
int64_t					ft_swap_int64(int64_t val);

uint32_t				ft_swap_uint32(uint32_t val);
uint64_t				ft_swap_uint64(uint64_t val);

size_t					ft_antou(const char *str, size_t n);

/*
**	str
*/

char					*ft_strdup(const char *str);
char					*ft_strndup(const char *str, size_t n);
char					*ft_strnew(size_t len);

size_t					ft_strlen(const char *str);
t_bool					ft_strequ(const char *s1, const char *s2);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					ft_strcpy(char *dest, const char *src);
void					ft_strncpy(char *dest, const char *src, size_t n);
int						ft_strcpos(const char *str, char c);
int						ft_strncpos(const char *str, size_t n, char c);
char					ft_toupper(char c);

char					*ft_strformat1(const char *format, const char *string);
char					*ft_strformat2(
							const char *format,
							const char *string1,
							const char *string2);

/*
**	ft_buff
*/

# define BUFF_SIZE		4096

typedef struct			s_buff_str
{
	char				buff[BUFF_SIZE];
	size_t				len;
}						t_buff_str;

void					ft_buff_flush(void);
void					ft_buff_put(const char *str);

void					ft_bput_hex_char(uint8_t val);

void					ft_bput_vm_addr64(uint64_t addr);
void					ft_bput_vm_addr32(uint64_t addr);

void					ft_bput_str(const char *str);
void					ft_bput_str_ln(const char *str);

void					ft_bput_uint(unsigned long int nb);
void					ft_bput_uint16(unsigned long int nb);
void					ft_bput_uint_ln(unsigned long int nb);
void					ft_bput_uint16_ln(unsigned long int nb);

void					ft_bput_uint_base(
							unsigned long int nb,
							const char *base,
							size_t width,
							char width_padded);

#endif
