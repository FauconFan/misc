/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_strings_unicode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:11:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 15:50:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_strings_unicode.h"
#define MIN_ONE_BYTE			0b00000000
#define MAX_ONE_BYTE			0b01111111
#define MIN_TWO_BYTE			0b1100000010100000
#define MAX_TWO_BYTE			0b1101111110111111
#define MIN_THREE_BYTE_ONE		0b111000001010000010000000
#define MAX_THREE_BYTE_ONE		0b111011011001111110111111
#define MIN_THREE_BYTE_TWO		0b111011101000000010000000
#define MAX_THREE_BYTE_TWO		0b111011111011111110111111
#define MIN_FOUR_BYTE_ONE		0b11110000100100001000000010000000
#define MAX_FOUR_BYTE_ONE		0b11110011101111111011111110111111
#define MIN_FOUR_BYTE_TWO		0b11110100100000001000000010000000
#define MAX_FOUR_BYTE_TWO		0b11110100100011111011111110111111

int		ft_wcharlen(unsigned int c)
{
	if (c >= MIN_ONE_BYTE && c <= MAX_ONE_BYTE)
		return (1);
	else if (c >= MIN_TWO_BYTE && c <= MAX_TWO_BYTE)
		return (2);
	else if ((c >= MIN_THREE_BYTE_ONE && c <= MAX_THREE_BYTE_ONE) ||
			(c >= MIN_THREE_BYTE_TWO && c <= MAX_THREE_BYTE_TWO))
		return (3);
	else if ((c >= MIN_FOUR_BYTE_ONE && c <= MAX_FOUR_BYTE_ONE) ||
			(c >= MIN_FOUR_BYTE_TWO && c <= MAX_FOUR_BYTE_TWO))
}