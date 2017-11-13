/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str_treat_data.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:42:09 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 18:40:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_STR_TREAT_DATA_H
# define BUILD_STR_TREAT_DATA_H

# include <stdarg.h>
# include "ft_printf.h"
# include "struct_treat_data.h"
# include "management.h"

char	*get_first_rep(va_list va, t_treat_data *data);
char	*adapt_flags_gabarit_precision
			(char *res, va_list va, t_treat_data *data);

#endif
