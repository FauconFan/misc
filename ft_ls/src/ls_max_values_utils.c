/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_max_values_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 08:26:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/12 17:40:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_max_values_long_format		*init_max_values(void)
{
	t_max_values_long_format	*res;

	ft_memcheck((res = (t_max_values_long_format *)
			malloc(sizeof(t_max_values_long_format))));
	res->max_st_nlink = 0;
	res->max_st_size = 0;
	res->max_len_user_id = 0;
	res->max_len_group_id = 0;
	return (res);
}

void							free_max_values(t_max_values_long_format **max)
{
	if (max == 0)
		return ;
	free(*max);
	*max = 0;
}

void							update_max_values(
					t_max_values_long_format *max,
					struct stat stats,
					int flags)
{
	char	*s1;
	char	*s2;

	s1 = get_real_pw_name(stats, flags);
	s2 = get_real_gr_name(stats, flags);
	max->max_st_nlink = ft_max(max->max_st_nlink,
					ft_log10(stats.st_nlink));
	max->max_st_size = ft_max(max->max_st_size,
					ft_log10(stats.st_size));
	max->max_len_user_id = ft_max(max->max_len_user_id,
					ft_strlen(s1));
	max->max_len_group_id = ft_max(max->max_len_group_id,
					ft_strlen(s2));
	free(s1);
	free(s2);
}
