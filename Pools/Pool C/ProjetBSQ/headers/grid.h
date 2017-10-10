/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 08:25:26 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/23 15:24:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

typedef struct		s_grid
{
	int				height;
	int				length;
	int				**tab;
}					t_grid;

typedef struct		s_sol
{
	int				x;
	int				y;
	int				size;
}					t_sol;

int					check_first_line(char **str);
int					check_cara(char to_test, char *cara);
int					check_lines(char *entry, int nb_line);
t_grid				*entry_test_and_build(char *entry);
t_grid				*entry_build(char *entry, int nb_line);
void				free_grid(t_grid *res);
void				print_grid(t_grid *status, char *entry);

void				ft_solve(t_grid *resultat, t_sol *sol);
t_sol				*init_sol(void);
int					is_in_square(int x, int y, t_sol *sol);
void				check_update_sol(t_sol *sol, int y, int x, int size);
void				print_result(t_sol *sol, t_grid *resultat, char *entry);

#endif
