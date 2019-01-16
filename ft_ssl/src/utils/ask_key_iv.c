/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_key_iv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:00:15 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/16 23:39:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static char		*getpassphrase()
{
	char	*in[2];

	in[0] = ft_ask_pass(ASK_PWD);
	if (in[0] == NULL)
		return (NULL);
	in[1] = ft_ask_pass(ASK_VERIFYING_PWD);
	if (in[1] == NULL)
	{
		free(in[0]);
		return (NULL);
	}
	if (ft_strcmp(in[0], in[1]) == 0)
	{
		free(in[1]);
		return (in[0]);
	}
	free(in[0]);
	free(in[1]);
	ft_dprintf(2, ASK_PWD_FAILURE "\n");
	return (NULL);
}

static int 		get_salt(t_des_cmd *cmd)
{
	char	rnd[8];
	size_t	l;

	if (cmd->salt)
	{
		if (ft_strlen(cmd->salt) > 16 || ft_str_is_xdigit(cmd->salt) == FALSE)
		{
			ft_dprintf(2, MSG_VALID_SALT "\n");
			return (1);
		}
		return (0);
	}
	l = -1;
	cmd->salt = ft_strnew(16);
	if (ft_getrandom(rnd, 8))
		return (1);
	while (++l < 8)
	{
		cmd->salt[2 * l] = ft_gethexvalue((rnd[l] >> 4) & 0x0f);
		cmd->salt[2 * l + 1] = ft_gethexvalue(rnd[l] & 0x0f);
	}
	return (0);
}

static void		put_in_w_sum(char **str, char *md5_sum, size_t pad)
{
	if (*str == NULL)
	{
		*str = ft_strnew(16);
		ft_strncpy(*str, md5_sum + pad, 16);
	}
}

int				ask_key_iv(t_des_cmd *cmd)
{
	char	*pwd;
	char	*md5_sum;
	int		ret;

	ret = 0;
	if (cmd->key && (cmd->vector || ft_need_iv(cmd->mode_cipher) == FALSE))
		return (1);
	pwd = NULL;
	if (cmd->password)
		pwd = ft_strdup(cmd->password);
	if (pwd == NULL)
		pwd = getpassphrase();
	if (pwd == NULL)
		ret = 1;
	else
	{
		if (get_salt(cmd))
			ret = 1;
		md5_sum = ft_poor_pbkdf2(pwd, cmd->salt);
		put_in_w_sum(&cmd->key, md5_sum, 0);
		put_in_w_sum(&cmd->vector, md5_sum, 16);
		free(md5_sum);
	}
	free(pwd);
	return (ret);
}
