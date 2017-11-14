/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:17:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/14 22:40:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_NUMBERS_H
# define CI_NUMBERS_H

# include <stdarg.h>
# include <stdint.h>
# include "libft.h"
# include "ft_printf.h"
# include "struct_treat_data.h"
# include "ft_lltoa_n_ulltoa.h"

char						*get_first_rep_ci_numbers(
								va_list va, t_treat_data *res);
char						*adapt_params_function_ci_numbers(
	char *tmp, va_list va, t_treat_data *data);

#endif
