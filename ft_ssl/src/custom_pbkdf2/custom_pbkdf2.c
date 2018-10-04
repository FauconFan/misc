/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_pbkdf2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:41:24 by pepe              #+#    #+#             */
/*   Updated: 2018/10/04 08:49:35 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		compute_core(char *pwd, size_t len_pwd, char **salt, char *res)
{
	t_hmac		*hmac;
	size_t		i;

	i = 0;
	hmac = ft_hmac_init((uint8_t *)(*salt), ft_strlen(*salt), ft_sha1, 64);
	ft_strdel(salt);
	*salt = ft_hmac_process(hmac, (uint8_t *)pwd, len_pwd);
	while (i < 40)
	{
		res[i] ^= (*salt)[i];
		i++;
	}
	ft_hmac_free(&hmac);
}

static char		*compute_pbkdf2(char *pwd, size_t len_pwd)
{
    char		*res;
	char		*salt;
	size_t		i;

	i = -1;
	res = ft_strnew(40);
	salt = ft_strnew(64);
	if (getrandom(salt, 64) != 0)
	{
		ft_dprintf(2, "No random devices found.\n");
		ft_strdel(&salt);
		return (NULL);
	}
	while (++i < 20)
	{
		compute_core(pwd, len_pwd, &salt, res);
		for (size_t i = 0; i < 40; i++) {
			ft_printf("%02x ", res[i]);
		}
		ft_putchar('\n');
	}
	ft_strdel(&salt);
	return (res);
}

/*
** We will use pbkdf2 with hmac_sha1
*/
char			*custom_pbkdf2(char *pwd)
{
	char	*res;

	res = compute_pbkdf2(pwd, ft_strlen(pwd));
	return (res);
}
