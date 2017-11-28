/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_unicode.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:32:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 19:38:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_STRINGS_UNICODE_H
# define CI_STRINGS_UNICODE_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "struct_treat_data.h"
# include "string_buffer.h"

# define MIN_ONE_BYTE			0b00000000
# define MAX_ONE_BYTE			0b01111111
# define MIN_TWO_BYTE			0b1100000010100000
# define MAX_TWO_BYTE			0b1101111110111111
# define MIN_THREE_BYTE_ONE		0b111000001010000010000000
# define MAX_THREE_BYTE_ONE		0b111011011001111110111111
# define MIN_THREE_BYTE_TWO		0b111011101000000010000000
# define MAX_THREE_BYTE_TWO		0b111011111011111110111111
# define MIN_FOUR_BYTE_ONE		0b11110000100100001000000010000000
# define MAX_FOUR_BYTE_ONE		0b11110011101111111011111110111111
# define MIN_FOUR_BYTE_TWO		0b11110100100000001000000010000000
# define MAX_FOUR_BYTE_TWO		0b11110100100011111011111110111111

void	process_special_char(va_list va, t_treat_data *data, t_string_buffer *sb);

#endif
