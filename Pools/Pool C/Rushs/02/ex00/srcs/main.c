/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 08:30:43 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/23 16:08:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "functions.h"

void	print_results(int *id)
{
	int		index;
	int		is_first_result;

	index = 0;
	is_first_result = 0;
	while (index < 5)
	{
		if (id[index] == 1)
		{
			if (is_first_result == 0)
				is_first_result = 1;
			else
				ft_putstr(" || ");
			ft_putstr("[colle-0");
			ft_putchar(index + '0');
			ft_putstr("] [");
			ft_putnbr(id[5]);
			ft_putstr("] [");
			ft_putnbr(id[6]);
			ft_putchar(']');
		}
		index++;
	}
	ft_putstr((is_first_result == 0) ? "aucune\n" : "\n");
}

char	*check_standard_input(void)
{
	char	*standard_input;

	if ((standard_input = get_standard_input()) == NULL)
		return (0);
	if (ft_strcmp(standard_input, "") == 0)
		return (print_no_results());
	return (standard_input);
}

int		main(void)
{
	char	*standard_input;
	char	*rush_actu;
	int		*id;
	int		index;

	if ((standard_input = check_standard_input()) == 0)
		return (0);
	if ((id = id_recognize(standard_input)) == NULL)
		return (0);
	index = -1;
	while (++index < 5)
		if (id[index] == 1)
		{
			rush_actu = rush00(id[5], id[6], get_template_with_id(index + 1));
			if (rush_actu == NULL)
				return (0);
			ft_putstr(rush_actu);
			if (ft_strcmp(standard_input, rush_actu) != 0)
				id[index] = 0;
			free(rush_actu);
		}
	print_results(id);
	free(standard_input);
	free(id);
	return (0);
}

char	*print_no_results(void)
{
	ft_putstr(NO_RESULTS0);
	ft_putstr(NO_RESULTS1);
	ft_putstr(NO_RESULTS2);
	ft_putstr(NO_RESULTS3);
	ft_putstr(NO_RESULTS4);
	return (0);
}
