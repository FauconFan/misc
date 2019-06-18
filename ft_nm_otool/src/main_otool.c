/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 07:21:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 10:30:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int			main(int argc, char **argv)
{
	t_ldf	ld;
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (ft_ldf_init(&ld, argv[i]) == FALSE)
			continue ;
		ft_put_str(ld.filepath);
		ft_put_str_ln(":");
		ft_otool(&ld);
		if (ft_ldf_end(&ld) == FALSE)
			continue ;
	}
	return (0);
}
