/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:18:07 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/19 15:16:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_NUMBERS_UTILS_H
# define CI_NUMBERS_UTILS_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "struct_treat_data.h"

char						*get_rep_with_prec(va_list va, t_treat_data *res);
char						*get_prefix(char **str, t_treat_data *data);

#endif
