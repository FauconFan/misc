/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:22:20 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 13:28:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		s_cara
{
	int				is_number;
	int				value;
	char			operation;
}					t_cara;

typedef struct		s_list
{
	struct s_list	*next;
	struct s_cara	*data;
}					t_list;

t_list				*ft_create_elem(char *s);
void				ft_list_clear(t_list *begin);
void				ft_list_push_back(t_list *begin_list, char *data);
int					ft_list_size(t_list *begin_list);
void				ft_remove_next(t_list *actu);
void				ft_remove_nextn(t_list *actu, int n);

t_list				*ft_build_expr(char *str);
void				ft_print_list(t_list *begin);
int					is_nextn_exist(t_list *actu, int n);
int					is_pattern_match(t_list *actu, int *pattern);
void				set_pattern(int mode, int *tab);
void				set_pattern2(int mode, int *tab);
void				check_no_operand_parenthesis(t_list *actu);

void				check_state0(t_list *actu);
void				check_state1(t_list *actu);
void				check_state2(t_list *actu);
void				check_state3(t_list *actu);
void				check_state4(t_list *actu);

#endif
