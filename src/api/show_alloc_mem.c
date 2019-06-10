/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:25:32 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/10 14:25:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	show_alloc_mem(void)
{
	t_mlc_main		*env;

	env = mlc_main_get();
	if (env == NULL)
		ft_put_str_ln("No env");
	else
		mlc_main_print(env);
}
