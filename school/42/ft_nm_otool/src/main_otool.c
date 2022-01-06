/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 07:21:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 11:17:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	do_main(char *argv)
{
	t_ldf	ld;

	if (ft_ldf_init_mmap(&ld, argv, ft_strdup(argv), TRUE) == FALSE)
		return ;
	ft_otool(&ld);
	if (ft_ldf_end(&ld) == FALSE)
		return ;
}

int			main(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		do_main(argv[i]);
		ft_buff_flush();
		ft_buff_reset();
	}
	return (0);
}
