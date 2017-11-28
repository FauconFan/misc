/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:41:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/28 20:03:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_buffer_utils.h"

/*
**	free_string_buffer, assez explicit.
*/

void		free_string_buffer(
		t_string_buffer *res)
{
	if (res)
	{
		if (res->next)
			free_string_buffer(res->next);
		free(res->str);
		free(res);
	}
}
