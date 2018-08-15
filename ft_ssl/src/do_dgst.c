/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dgst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:38:31 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/15 16:42:54 by jpriou           ###   ########.fr       */
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
	int				fd;
	struct stat		stat_actu;
	int				ret;
	char			*content_file;
	char			*hashed;

	ret = stat(file_path, &stat_actu);
	if (ret == 0)
	{
		fd = open(file_path, O_RDONLY);
		content_file = ft_strnew(stat_actu.st_size);
		read(fd, content_file, stat_actu.st_size);
		hashed = cmd->hash(content_file);
		print_result(cmd, file_path, hashed, TRUE);
		ft_strdel(&content_file);
		ft_strdel(&hashed);
	}
	else
	{
		ft_printf("%s: %s\n", file_path, strerror(errno));
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
	t_slist		*lst;
	char		buf[2];
	char		**tab;
	char		*hashed;
	char		*content;

	lst = ft_slist_new(free);
	ft_slist_add_cpy(lst, MAKE_COPY_PTR(ft_strdup));
	buf[1] = 0;
	while (read(0, buf, 1))
	{
		ft_slist_push_cp(lst, buf);
	}
	ft_slist_rev(lst);
	tab = (char **)ft_slist_tovtab(&lst);
	content = ft_stab_join(tab, "");
	ft_stab_free(&tab);
	hashed = cmd->hash(content);
	if (cmd->stdin)
		ft_putstr(content);
	ft_putendl(hashed);
	ft_strdel(&content);
	ft_strdel(&hashed);
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
