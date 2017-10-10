/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 08:24:26 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/23 21:31:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "grid.h"

int		check_first_line(char **str)
{
	char	*real_entry;
	char	*cpy;
	int		nb_line;

	real_entry = *str;
	cpy = *str;
	while (*real_entry != 0 && *real_entry != '\n')
		real_entry++;
	if (*real_entry == 0 || ft_strlen(cpy) <= 3)
		return (-1);
	real_entry -= 3;
	nb_line = 0;
	while (cpy != real_entry)
	{
		if (*cpy < '0' || *cpy > '9')
			return (-1);
		nb_line = nb_line * 10 + *cpy - '0';
		cpy++;
	}
	if (nb_line == 0 || *real_entry == *(real_entry + 1) ||
			*real_entry == *(real_entry + 2))
		return (-1);
	*str = real_entry;
	return (nb_line);
}

int		check_cara(char to_test, char *cara)
{
	if (to_test == cara[0] || to_test == cara[1])
		return (1);
	return (-1);
}

int		check_line_fixed(int *is_line_fixed, int *nb_cara_line_actu,
		int *nb_cara_line)
{
	if (*is_line_fixed == 1)
		return (1);
	*nb_cara_line = *nb_cara_line_actu;
	return (0);
}

void	set_to_zero(int *n1, int *n2, int *n3)
{
	*n1 = 0;
	*n2 = 0;
	*n3 = 0;
}

int		check_lines(char *entry, int nb_line)
{
	char	*save_param;
	int		nb_real_line;
	int		cara_line;
	int		cara_actu;
	int		is_line_fixed;

	save_param = entry;
	entry += 4;
	set_to_zero(&cara_actu, &nb_real_line, &is_line_fixed);
	while (*entry)
	{
		if (*entry == '\n' && (nb_real_line++ || 1))
		{
			if (check_line_fixed(&is_line_fixed, &cara_actu, &cara_line) == 1)
				if (cara_actu != cara_line)
					return (-1);
		}
		else
		{
			if (check_cara(*entry, save_param) == -1)
				return (-1);
		}
		cara_actu = (*(entry++) == '\n') ? 0 : cara_actu + 1;
	}
	return ((nb_line != nb_real_line) ? -1 : 1);
}
