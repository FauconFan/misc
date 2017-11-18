/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_data_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 08:59:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/18 09:32:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREAT_DATA_UTILS_H
# define TREAT_DATA_UTILS_H

# include <stdarg.h>
# include "ft_printf.h"
# include "struct_treat_data.h"
# include "set_values_treat_data.h"
# include "build_str_treat_data.h"

t_treat_data	*init_treat_data(void);
void			free_treat_data(t_treat_data *data);
char			*set_values_treat_data(char *str, t_treat_data *data);
char			*treat_data(t_treat_data *data, va_list va, int *res);
void			print_values(t_treat_data *data);

#endif
