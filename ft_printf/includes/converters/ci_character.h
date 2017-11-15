/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_character.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:27:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/15 13:28:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_CHARACTER_H
# define CI_CHARACTER_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "struct_treat_data.h"

char	*get_first_rep_ci_char(va_list va, t_treat_data *res);
char	*adapt_params_function_ci_char
				(char *tmp, va_list va, t_treat_data *data);

#endif