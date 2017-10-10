/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 10:48:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 18:04:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		get_nb_spaces_gap_stairs(int level)
{
	int		index;
	int		res;

	if (level == 0)
		return (0);
	if (level == 1)
		return (2);
	if (level % 2 == 0)
	{
		index = 2;
		res = 0;
		while (index <= (2 + ((level / 2) - 1)))
		{
			res += index;
			index++;
		}
		res *= 2;
		return (res);
	}
	return (get_nb_spaces_gap_stairs(level - 1) + (level / 2) + 2);
}

void	print_normal_line(int number_space, int number_inside_sastantua)
{
	int		index;

	index = 0;
	while (index < number_space)
	{
		ft_putchar(' ');
		index++;
	}
	index = 0;
	ft_putchar('/');
	while (index < number_inside_sastantua)
	{
		ft_putchar('*');
		index++;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	doli(int number_space, int ast, int size_door, int index_hand)
{
	int		index;
	int		size_next_to_door;

	index = 0;
	size_next_to_door = (ast / 2) - (size_door / 2);
	while (index++ < number_space)
		ft_putchar(' ');
	index = 0;
	ft_putchar('/');
	while (index++ < size_next_to_door)
		ft_putchar('*');
	index = 0;
	while (index++ < size_door)
		ft_putchar((index == index_hand + 1) ? '$' : '|');
	index = 0;
	while (index++ < size_next_to_door + ((size_door % 2 == 0) ? 1 : 0))
	{
		ft_putchar('*');
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	print_level(int size, int level, int *nb_line, int nb_line_tot)
{
	int		index;
	int		sp;
	int		ast;
	int		liac;
	int		data[2];

	index = 0;
	sp = get_nb_spaces_gap_stairs(size - 1) - get_nb_spaces_gap_stairs(level);
	ast = (*nb_line * 2) - 1 + 2 * get_nb_spaces_gap_stairs(level);
	data[0] = ((size % 2) == 1) ? size : size - 1;
	data[1] = (size <= 4) ? -1 : data[0] - 2;
	while (index < level + 3)
	{
		liac = nb_line_tot - *nb_line;
		if (level == size - 1 && (liac < ((size % 2 == 1) ? size : size - 1)))
			doli(sp + liac, ast, data[0], (liac == level / 2) ? data[1] : -1);
		else
			print_normal_line(sp + liac, ast);
		index++;
		*nb_line = *nb_line + 1;
		ast += 2;
	}
}

void	sastantua(int size)
{
	int		level;
	int		nb_line;
	int		nb_line_tot;
	int		i;

	if (size <= 0)
		return ;
	level = 0;
	nb_line = 1;
	nb_line_tot = 0;
	i = 0;
	while (i < size)
	{
		nb_line_tot += i + 3;
		i++;
	}
	while (level < size)
	{
		print_level(size, level, &nb_line, nb_line_tot);
		level++;
	}
}
