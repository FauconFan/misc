/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:23:46 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:26:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_buffer.h"
#include "string_buffer_utils.h"

t_string_buffer		*new_string_buffer(void)
{
	t_string_buffer		*res;
	int					index;

	if ((res = (t_string_buffer *)malloc(sizeof(t_string_buffer))) == NULL)
		return (0);
	if ((res->tab = (char **)
		malloc(sizeof(char *) * SIZE_STRING_BUFFER)) == NULL)
		return (0);
	index = 0;
	while (index < SIZE_STRING_BUFFER)
	{
		res->tab[index] = 0;
		index++;
	}
	res->size = SIZE_STRING_BUFFER;
	res->size_actu = 0;
	return (res);
}

t_string_buffer		*sb_append(t_string_buffer *buf, char *str)
{
	char			**tab;
	int				index;

	if (buf->size_actu >= buf->size)
	{
		if ((tab = (char **)
			malloc(sizeof(char *) * (buf->size + SIZE_STRING_BUFFER))) == NULL)
			return (0);
		index = 0;
		while (index < buf->size)
		{
			tab[index] = buf->tab[index];
			index++;
		}
		free(buf->tab);
		buf->tab = tab;
		buf->size = buf->size + SIZE_STRING_BUFFER;
	}
	buf->tab[buf->size_actu] = ft_strdup(str);
	buf->size_actu = buf->size_actu + 1;
	return (buf);
}

char				*sb_to_string_and_free_all(t_string_buffer *buf)
{
	int			i;
	int			size_word;
	int			size_actu;
	char		*str;

	str = ft_strnew(length_tot(buf));
	i = 0;
	size_actu = 0;
	size_word = 0;
	while (i < buf->size_actu)
	{
		size_word = ft_strlen(buf->tab[i]);
		ft_strncat(str + size_actu, buf->tab[i], size_word);
		free(buf->tab[i]);
		size_actu += size_word;
		i++;
	}
	free(buf->tab);
	free(buf);
	return (str);
}

void				sb_print_and_free_all(t_string_buffer *buf)
{
	char		*str;

	str = sb_to_string_and_free_all(buf);
	ft_putstr(str);
	free(str);
}
