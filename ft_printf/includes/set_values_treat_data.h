/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_treat_data.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:07:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/30 16:14:47 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_VALUES_TREAT_DATA_H
# define SET_VALUES_TREAT_DATA_H

# include <stdarg.h>
# include "struct_treat_data.h"
# include "treat_data_utils.h"
# include "set_values_treat_data2.h"

char	*set_flags_treat_data(char *str, t_treat_data *data);
char	*set_gabarit_treat_data(char *str, t_treat_data *data, va_list va);
char	*set_precision_treat_data(char *str, t_treat_data *data, va_list va);
char	*set_length_modifer(char *str, t_treat_data *data);
char	*set_converter_treat_data(char *str, t_treat_data *data);

#endif
