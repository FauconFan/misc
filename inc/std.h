/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:39:02 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 12:03:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_H
# define STD_H

# include <unistd.h>
# include <stdint.h>

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
**	mem
*/

void						ft_memcpy(
								void *dest,
								const void *src,
								size_t len);

/*
**	int
*/

int32_t						ft_swap_int32(int32_t val);
int64_t						ft_swap_int64(int64_t val);

uint32_t					ft_swap_uint32(uint32_t val);
uint64_t					ft_swap_uint64(uint64_t val);

/*
**	str
*/

size_t						ft_strlen(const char *str);
t_bool						ft_strequ(const char *s1, const char *s2);
int							ft_strcmp(const char *s1, const char *s2);
char						ft_toupper(char c);

/*
**	ft_buff
*/

# define BUFF_SIZE			4096

typedef struct				s_buff_str
{
	char					buff[BUFF_SIZE];
	size_t					len;
}							t_buff_str;

void						ft_buff_flush(void);
void						ft_buff_put(const char *str);

void						ft_bput_hex_char(uint8_t val);

void						ft_bput_vm_addr(uint64_t addr);

void						ft_bput_str(const char *str);
void						ft_bput_str_ln(const char *str);

void						ft_bput_uint(unsigned long int nb);
void						ft_bput_uint16(unsigned long int nb);
void						ft_bput_uint_ln(unsigned long int nb);
void						ft_bput_uint16_ln(unsigned long int nb);

void						ft_bput_uint_base(
								unsigned long int nb,
								const char *base,
								size_t width,
								char width_padded);

#endif
