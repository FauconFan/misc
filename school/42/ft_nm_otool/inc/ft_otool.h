/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:09:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 13:57:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "ft_nm_otool.h"

typedef struct		s_pprint_help
{
	char		*v;
	uint64_t	vm_addr;
	size_t		len;
	cpu_type_t	cputype;
	t_bool		is64;
	char		pad[3];
}					t_pprint_help;

void				otool_pretty_print(t_pprint_help *pphelp);

#endif
