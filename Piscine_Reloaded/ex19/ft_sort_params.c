/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 14:40:54 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 14:53:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		my_strcmp(char *s1, char *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index])
	{
		if (s1[index] == '\0')
			return (0);
		index++;
	}
	return (s1[index] - s2[index]);
}

void	sort_params(char **params, int argc)
{
	int		index;
	char	*min;
	int		min_rank;

	if (argc == 0)
		return ;
	index = 0;
	min_rank = 0;
	min = params[0];
	while (index < argc)
	{
		if (my_strcmp(params[index], min) < 0)
		{
			min_rank = index;
			min = params[index];
		}
		index++;
	}
	params[min_rank] = params[0];
	params[0] = min;
	sort_params(params + 1, argc - 1);
}

int		main(int argc, char **argv)
{
	int		index;
	int		letter;

	index = 1;
	sort_params(argv + 1, argc - 1);
	while (index < argc)
	{
		letter = 0;
		while (argv[index][letter])
		{
			ft_putchar(argv[index][letter++]);
		}
		ft_putchar('\n');
		index++;
	}
	return (0);
}
