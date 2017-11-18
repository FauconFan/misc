/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_character.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:27:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/18 09:47:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_CHARACTER_H
# define CI_CHARACTER_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "struct_treat_data.h"

void	print_special_char(va_list va, t_treat_data *res, int *return_func);

#endif
