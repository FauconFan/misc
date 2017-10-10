/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 09:31:04 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/13 13:49:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define ERROR_STRING "Error\n"

void	print_digit(int digit);
void	print_str(char *str);
void	print_tab(int **tab);

int		ft_just_chiffre(char **argv);
int		ft_verf_ligne(char **argv);
int		ft_verf_col(char **argv);
int		ft_verf_carre_complement(char **argv, int x, int y);
int		ft_verf_carre(char **argv);

int		is_on_column(int value, int j, int **tab);
int		is_on_row(int value, int i, int **tab);
int		is_on_square_treatment(int value, int a, int c, int **tab);
int		is_on_square(int value, int k, int **tab);
int		is_move_valid(int value, int i, int j, int **tab);

void	do_main(int **tab);
int		backtracking_sudoku(int **tab, int rank, int start);

int		**build_tab(char **argv);
int		**cpy_tab(int **tab);
int		cmp_tab(int **tab1, int **tab2);

#endif
