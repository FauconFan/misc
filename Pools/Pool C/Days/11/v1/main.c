/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 08:55:01 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 13:35:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>

void	my_putstr(char *str);
void	my_putnbr(int nb);
void	my_putnbrpos(int nb);
void	change(void *str);
void	print_list(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
t_list	*ft_list_push_params(int ac, char **av);
void	ft_list_clear(t_list **begin_list);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_foreach(t_list *begin_last, void (*f)(void *));
void	ft_list_reverse_fun(t_list *begin_last);

int		main(int argc, char **argv)
{
	t_list	*list;

	list = 0;
	print_list(list);
	my_putnbr(ft_list_size(list));
	my_putstr("\n");
	list = ft_create_elem((void *)"coucou");
	print_list(list);
	my_putnbr(ft_list_size(list));
	my_putstr("\n");
	ft_list_push_back(&list, (void *)"allez");
	ft_list_push_back(&list, (void *)"allezzzz");
	print_list(list);
	my_putnbr(ft_list_size(list));
	my_putstr("\n");
	ft_list_push_front(&list, (void *)"ALED");
	print_list(list);
	my_putnbr(ft_list_size(list));
	my_putstr("\n");
	my_putstr((char *)ft_list_last(list)->data);
	my_putstr("\n");
	print_list(ft_list_push_params(argc, argv));
	//ft_list_clear(&list);
	my_putstr("  AVANT\n");
	print_list(list);
	my_putstr("  APRES\n");
	t_list *last = ft_list_last(list);
	ft_list_reverse_fun(list);
	print_list(last);
}

void	my_putstr(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	write(1, str, length);
}

void	my_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		my_putnbrpos(nb);
	}
}

void	my_putnbrpos(int nb)
{
	char c;

	if (nb == 0)
		return ;
	my_putnbrpos(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	print_list(t_list *begin_list)
{
	if (begin_list == 0)
		return ;
	my_putstr((char *)begin_list->data);
	write(1, "\n", 1);
	print_list(begin_list->next);
}

void	change(void *str)
{
	my_putstr("COOL\n");
}
