/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_file_sys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:31:32 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/25 09:32:56 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_abs_path_from_getcwd(void)
{
	char	*res;

	res = ft_strnew(2048);
	getcwd(res, 2048);
	return (res);
}
