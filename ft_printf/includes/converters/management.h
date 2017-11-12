/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:29:08 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 18:10:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGEMENT_H
# define MANAGEMENT_H

# include "ci_sep.h"

char	*(* get_first_rep_function(int id))(va_list, t_treat_data *);
char	*(* adapt_params_function(int id))(char *, va_list, t_treat_data *);

#endif