/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:51:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/15 17:17:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		core_ask(t_sb *sb, int fd)
{
	char	buff[2048 + 1];
	int		ret;
	int		count;

	count = 0;
	while ((ret = read(fd, buff + count, 1)) > 0 && buff[count] != '\n')
	{
		count++;
		if (count == 2048)
		{
			buff[count] = 0;
			ft_sb_append(sb, buff);
			count = 0;
		}
	}
	if (ret > 0)
	{
		buff[count] = '\0';
		ft_sb_append(sb, buff);
	}
	write(1, "\n", 1);
}

char			*ft_ask_pass(char *prompt)
{
	t_sb			*sb;
	char			*res;
	struct termios	t_old;
	struct termios	t_new;
	int				fd;

	if ((fd = open("/dev/tty", O_RDONLY)) < 0)
		return (NULL);
	tcgetattr(fd, &t_old);
	tcgetattr(fd, &t_new);
	t_new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(fd, TCSANOW, &t_new);
	sb = ft_sb_new();
	ft_putstr(prompt);
	core_ask(sb, fd);
	tcsetattr(fd, TCSANOW, &t_old);
	res = ft_sb_tostring(sb);
	ft_sb_free(&sb);
	if (close(fd) < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
