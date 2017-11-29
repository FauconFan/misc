/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_treat_data2.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:16:34 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/29 14:50:27 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_VALUES_TREAT_DATA2_H
# define SET_VALUES_TREAT_DATA2_H

# include "ft_printf.h"
# include "struct_treat_data.h"
# include "treat_data_utils.h"

int		set_converter_treat_data2(char cpy);
void	update_uppercase_for_l_lm(char letter, t_treat_data *data);

#endif
