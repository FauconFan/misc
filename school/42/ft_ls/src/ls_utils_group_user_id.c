/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_group_user_id.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:25:35 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/12 17:51:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_real_pw_name(struct stat mystat, int flags)
{
	struct passwd	*ret_getpwuid;

	if (flags & FLAG_N_MIN || ((ret_getpwuid = getpwuid(mystat.st_uid))) == 0)
	{
		return (ft_itoa(mystat.st_uid));
	}
	return (ft_strdup(ret_getpwuid->pw_name));
}

char		*get_real_gr_name(struct stat mystat, int flags)
{
	struct group	*ret_groupid;

	if (flags & FLAG_N_MIN || ((ret_groupid = getgrgid(mystat.st_gid))) == 0)
	{
		return (ft_itoa(mystat.st_gid));
	}
	return (ft_strdup(ret_groupid->gr_name));
}
