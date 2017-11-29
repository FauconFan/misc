/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_data_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 08:59:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/29 14:50:12 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREAT_DATA_UTILS_H
# define TREAT_DATA_UTILS_H

# include <stdarg.h>
# include "ft_printf.h"
# include "struct_treat_data.h"
# include "set_values_treat_data.h"
# include "management.h"
# include "string_buffer.h"
# include "string_buffer_utils.h"

# define SEPERATOR		'%'

# define HASHTAG_FLAG	'#'
# define ZERO_FLAG		'0'
# define MINUS_FLAG		'-'
# define PLUS_FLAG		'+'
# define SPACE_FLAG		' '

# define SEP_PRECISION	'.'

/*
**	Don't change the following
**	The following conerters id are not used finally :
**	S, D, O, U, C
*/

# define LM_HH			1
# define LM_H			2
# define LM_LL			3
# define LM_L			4
# define LM_J			5
# define LM_Z			6

# define CI_SEP			9
# define CI_SMIN		10
# define CI_SMAJ		11
# define CI_P			12
# define CI_DMIN		13
# define CI_DMAJ		14
# define CI_I			15
# define CI_OMIN		16
# define CI_OMAJ		17
# define CI_UMIN		18
# define CI_UMAJ		19
# define CI_XMIN		20
# define CI_XMAJ		21
# define CI_CMIN		22
# define CI_CMAJ		23
# define CI_EMIN		24
# define CI_EMAJ		25
# define CI_FMIN		26
# define CI_FMAJ		27
# define CI_GMIN		28
# define CI_GMAJ		29
# define CI_AMIN		30
# define CI_AMAJ		31
# define CI_N			32

char			*init_and_set_values_treat_data(char *str, t_treat_data **data);
void			treat_data(t_treat_data *data, va_list va, t_string_buffer *sb);
char			*treat_sep(char *str, va_list va, t_string_buffer *sb);
int				process(char *str, va_list va, t_string_buffer *sb,
							char **to_print, int *len_to_print);
void			print_values(t_treat_data *data);

#endif
