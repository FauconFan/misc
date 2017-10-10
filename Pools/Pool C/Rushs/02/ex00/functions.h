/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 08:46:54 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 23:10:06 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define NO_RESULTS0 "[colle-00] [0] [?] || [colle-00] [?] [0] || "
# define NO_RESULTS1 "[colle-01] [0] [?] || [colle-01] [?] [0] || "
# define NO_RESULTS2 "[colle-02] [0] [?] || [colle-02] [?] [0] || "
# define NO_RESULTS3 "[colle-03] [0] [?] || [colle-03] [?] [0] || "
# define NO_RESULTS4 "[colle-04] [0] [?] || [colle-04] [?] [0]\n"

void		ft_putstr(char *str);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
char		*ft_strcpy(char *dest, char *src);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *s);
void		reverse_form(char *s);

char		*get_standard_input(void);

int			*id_recognize(char *str);

char		*rush00(int x, int y, char *template);
char		*get_template_with_id(int id);
char		*print_no_results(void);

#endif
