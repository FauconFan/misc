/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_octalx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:51:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 20:01:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_OCTALX_H
# define CI_OCTALX_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "struct_treat_data.h"

# define HEXALOWER		"0123456789abcdef"
# define HEXAUPPER		"0123456789ABCDEF"

char	*get_first_rep_ci_octalx(va_list va, t_treat_data *res);
char	*adapt_params_function_ci_octalx
			(char *tmp, va_list va, t_treat_data *data);

#endif
