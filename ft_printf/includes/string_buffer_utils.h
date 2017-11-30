/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:41:42 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/30 17:36:44 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_BUFFER_UTILS_H
# define STRING_BUFFER_UTILS_H

# include <stdlib.h>
# include "string_buffer.h"

void		free_string_buffer(
		t_string_buffer *res);

#endif
