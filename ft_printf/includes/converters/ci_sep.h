/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_sep.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:57:53 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 19:53:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_SEP_H
# define CI_SEP_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "struct_treat_data.h"

char	*get_first_rep_ci_sep(va_list va, t_treat_data *res);
char	*adapt_params_function_ci_sep
				(char *tmp, va_list va, t_treat_data *data);

#endif
