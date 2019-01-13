/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 11:34:36 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 11:37:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_dgst_config	g_cmds_dgst[] =
{
	{"md5", CMD_MD5, &ft_md5, "MD5"},
	{"md4", CMD_MD4, &ft_md4, "MD4"},
	{"sha1", CMD_SHA1, &ft_sha1, "SHA1"},
	{"sha224", CMD_SHA224, &ft_sha224, "SHA224"},
	{"sha256", CMD_SHA256, &ft_sha256, "SHA256"},
	{"sha384", CMD_SHA384, &ft_sha384, "SHA384"},
	{"sha512", CMD_SHA512, &ft_sha512, "SHA512"},
	{"sha512/256", CMD_SHA512_256, &ft_sha512_256, "SHA512/256"},
	{"sha512/224", CMD_SHA512_224, &ft_sha512_224, "SHA512/224"},
};

t_des_config	g_cmds_des[] =
{
	{"ecb", CMD_ECB, ECB},
};

size_t			g_cmds_dgst_size = sizeof(g_cmds_dgst) / sizeof(*g_cmds_dgst);
size_t			g_cmds_des_size = sizeof(g_cmds_des) / sizeof(*g_cmds_des);
