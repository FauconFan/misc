/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:51:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/17 00:33:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static char		*core_ask(int fd)
{
	char	*buff;
	char	*tmp;
	size_t	len;
	size_t	count;
	int		ret;

	len = 128;
	count = 0;
	buff = ft_strnew(len);
	while ((ret = read(fd, buff + count, 1)) > 0 && buff[count] != '\n')
	{
		if (buff[count] == 127)
		{
			if (count > 0)
			{
				buff[count] = 0;
				--count;
			}
		}
		else
		{
			count++;
			if (count == len)
			{
				len *= 2;
				tmp = ft_strndup(buff, len);
				free(buff);
				buff = tmp;
			}
		}
	}
	write(1, "\n", 1);
	return (buff);
}

char			*ft_ask_pass(char *prompt)
{
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
	ft_putstr(prompt);
	res = core_ask(fd);
	tcsetattr(fd, TCSANOW, &t_old);
	if (close(fd) < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
