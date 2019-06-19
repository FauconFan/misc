/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 07:35:13 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/19 07:52:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

char	*get_arch(void)
{
	static t_arch_buffer	buffer = {FALSE, FALSE, {{0}, {0}, {0}, {0}, {0}}};

	if (buffer.fail)
		return (NULL);
	if (buffer.set == FALSE)
	{
		if (uname(&buffer.ust) < 0
			|| ft_check_str(buffer.ust.machine, 256) == FALSE)
		{
			ft_put_str_ln(ARCHI_MSG);
			buffer.fail = TRUE;
			return (NULL);
		}
		buffer.set = TRUE;
	}
	return (buffer.ust.machine);
}
