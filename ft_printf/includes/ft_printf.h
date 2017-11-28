/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 08:09:18 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 14:29:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include "treat_data_utils.h"
# include "string_buffer.h"
# include "string_buffer_utils.h"

# define WMALLOC		"WRONG MALLOC"
# define UNEND			"UNEXPECTED END OF STRING"
# define SNA			"Should never happen exception"
# define LM_UPPERCASE	"Wrong Length Modifiere exception"
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

int				ft_printf(const char *restrict format, ...);
int				ft_dprintf(int fd, const char *restrict format, ...);

#endif
