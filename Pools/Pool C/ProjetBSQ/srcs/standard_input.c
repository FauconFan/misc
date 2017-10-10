/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 08:53:13 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/23 19:16:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "functions.h"

#define BUF_LINE 5000

char	*ft_strduphophop(char *buffer, int *size_buffer)
{
	char	*tmp_buffer;

	tmp_buffer = (char *)malloc(sizeof(char) * (2 * *size_buffer) + 1);
	*size_buffer = 2 * *size_buffer + 1;
	if (tmp_buffer == NULL)
		return (0);
	ft_strcpy(tmp_buffer, buffer);
	free(buffer);
	return (tmp_buffer);
}

char	*get_input(int file_descriptor)
{
	char	*true_buffer;
	char	*buffer_read;
	int		size_buffer;
	int		index;
	int		ret;

	true_buffer = (char *)malloc(sizeof(char) * (BUF_LINE + 1));
	size_buffer = BUF_LINE + 1;
	if (true_buffer == NULL)
		return (0);
	index = 0;
	buffer_read = (char *)malloc(sizeof(char) * (BUF_LINE));
	if (buffer_read == NULL)
		return (0);
	while ((ret = read(file_descriptor, buffer_read, BUF_LINE)) > 0)
	{
		buffer_read[ret] = 0;
		index += ret;
		if (index >= size_buffer)
			true_buffer = ft_strduphophop(true_buffer, &size_buffer);
		ft_strcat(true_buffer, buffer_read, index - ret);
	}
	true_buffer[index] = 0;
	free(buffer_read);
	return (true_buffer);
}

char	*echo_issue(char *error, char *name_file)
{
	ft_putstr("./bsq: ");
	ft_putstr(name_file);
	ft_putstr(": ");
	ft_putstr(error);
	ft_putstr("\n");
	return (0);
}

char	*get_file_input(char *name)
{
	int		file_descriptor;
	char	*input;

	if ((file_descriptor = open(name, O_RDONLY)) == -1)
		return (echo_issue("No such file or directory", name));
	input = get_input(file_descriptor);
	if (close(file_descriptor) == -1)
		ft_putstrerr("Cannot close the file properly...\n");
	return (input);
}
