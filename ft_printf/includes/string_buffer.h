/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:24:08 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/12 22:01:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_BUFFER_H
# define STRING_BUFFER_H

typedef struct  				s_string_buffer
{
	char 						**tab;
	int 						size_actu;
	int							size;
}								t_string_buffer;

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define SIZE_STRING_BUFFER 	3

t_string_buffer					*new_string_buffer();
t_string_buffer					*sb_append(t_string_buffer *buf, char *str);
char 							*sb_to_string_and_free_all(t_string_buffer *buf);
void 							sb_print_and_free_all(t_string_buffer *buf);

#endif