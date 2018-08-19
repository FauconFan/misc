/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dgst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:38:31 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 16:04:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void			print_result(
						t_dgst_cmd *cmd,
						char *origin,
						char *hashed,
						t_bool is_file)
{
	if (cmd->quiet)
		ft_putendl(hashed);
	else if (cmd->reverse)
	{
		if (is_file)
			ft_printf("%s %s\n", hashed, origin);
		else
			ft_printf("%s \"%s\"\n", hashed, origin);
	}
	else
	{
		if (is_file)
			ft_printf("%s(%s) = %s\n", cmd->name, origin, hashed);
		else
			ft_printf("%s(\"%s\") = %s\n", cmd->name, origin, hashed);
	}
}

static void			do_file(t_dgst_cmd *cmd, char *file_path)
{
	char			*errno_str;
	char			*content_file;
	char			*hashed;

	content_file = ft_get_content_file(file_path, &errno_str);
	if (errno_str == NULL)
	{
		hashed = cmd->hash(content_file);
		print_result(cmd, file_path, hashed, TRUE);
		ft_strdel(&content_file);
		ft_strdel(&hashed);
	}
	else
	{
		ft_printf("%s: %s\n", file_path, errno_str);
	}
}

static void			do_sample(t_dgst_cmd *cmd, char *sample)
{
	char	*hashed;

	hashed = cmd->hash(sample);
	print_result(cmd, sample, hashed, FALSE);
	ft_strdel(&hashed);
}

static void			do_stdin(t_dgst_cmd *cmd)
{
	char		*errno_str;
	char		*content;
	char		*hashed;

	content = ft_get_content_file_fd_nostat(0, &errno_str);
	if (errno_str == NULL)
	{
		hashed = cmd->hash(content);
		if (cmd->stdin)
			ft_putstr(content);
		ft_putendl(hashed);
		ft_strdel(&content);
		ft_strdel(&hashed);
	}
	else
	{
		ft_printf("(stdin): %s\n", errno_str);
	}
}

void				do_dgst(t_cmd_parser *parser)
{
	t_dgst_cmd	*cmd;
	int			i;

	cmd = ft_ssl_dgst_init(parser);
	if (cmd->stdin || (ft_stab_len(cmd->samples) == 0 && cmd->nb_files == 0))
	{
		do_stdin(cmd);
	}
	i = 0;
	while (cmd->samples[i])
	{
		do_sample(cmd, cmd->samples[i]);
		i++;
	}
	i = 0;
	while (i < cmd->nb_files)
	{
		do_file(cmd, cmd->file_names[i]);
		i++;
	}
	ft_ssl_dgst_free(&cmd);
}
