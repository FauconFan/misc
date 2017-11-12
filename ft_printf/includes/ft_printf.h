/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 08:09:18 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 10:06:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include "string_buffer.h"
# include "string_buffer_utils.h"
# include "treat_data_utils.h"

# define WMALLOC		"WRONG MALLOC"
# define UNEND			"UNEXPECTED END OF STRING"
# define SEPERATOR		'%'

# define HASHTAG_FLAG	'#'
# define ZERO_FLAG		'0'
# define MINUS_FLAG		'-'
# define PLUS_FLAG		'+'
# define SPACE_FLAG		' '

# define SEP_PRECISION	'.'

# define LM_HH			1
# define LM_H			2
# define LM_LL			3
# define LM_L			4
# define LM_J			5
# define LM_Z			6

# define CI_SEP			9
# define CI_s			10
# define CI_S			11
# define CI_p			12
# define CI_d			13
# define CI_D			14
# define CI_i			15
# define CI_o			16
# define CI_O			17
# define CI_u			18
# define CI_U			19
# define CI_x			20
# define CI_X			21
# define CI_c			22
# define CI_C			23
# define CI_e			24
# define CI_E			25
# define CI_f			26
# define CI_F			27
# define CI_g			28
# define CI_G			29
# define CI_a			30
# define CI_A			31
# define CI_n			32

int				ft_printf(char *str, ...);
void			die(char *str);

#endif
