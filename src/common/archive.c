/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:35:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 14:01:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static char	*get_name_from_hdr(
				t_ldf *ldf,
				size_t offset,
				struct ar_hdr *actu,
				size_t *additional_offset)
{
	size_t	len_prefix;
	char	*name;
	int		tmp;

	*additional_offset = 0;
	len_prefix = ft_strlen(AR_EFMT1);
	if (len_prefix >= sizeof(actu->ar_name))
		return (NULL);
	if (ft_strncmp(actu->ar_name, AR_EFMT1, len_prefix) == 0)
	{
		*additional_offset = ft_antou(actu->ar_name + len_prefix,
			sizeof(actu->ar_name) - len_prefix);
		if (*additional_offset == 0)
			return (NULL);
		name = ft_ldf_jmp(ldf, offset + sizeof(*actu), *additional_offset);
		if (name == NULL)
			return (NULL);
		return (ft_strndup(name, *additional_offset));
	}
	if ((tmp = ft_strncpos(actu->ar_name, sizeof(actu->ar_name), ' ')) < 0)
		return (NULL);
	return (ft_strndup(actu->ar_name, (size_t)tmp));
}

static void	archive_parcours(t_ldf *ldf, void (*f)(t_ldf *ldf), size_t offset)
{
	struct ar_hdr	*actu;
	void			*beg;
	size_t			len[2];
	char			*names[2];
	t_ldf			in_file;

	if (offset >= ldf->len)
		return ;
	if ((actu = ft_ldf_jmp(ldf, offset, sizeof(*actu))) == NULL)
		return ;
	if ((names[0] = get_name_from_hdr(ldf, offset, actu, len + 1)) == NULL)
		return ;
	len[0] = ft_antou(actu->ar_size, sizeof(actu->ar_size));
	if ((beg = ft_ldf_jmp(ldf, offset + sizeof(*actu) + len[1], len[0] - len[1])) == NULL)
		return ;
	names[1] = ft_strformat2("%(%)", ldf->name, names[0]);
	free(names[0]);
	ft_ldf_init_custom(&in_file, names[1], beg, len[0] - len[1]);
	f(&in_file);
	archive_parcours(ldf, f, offset + sizeof(*actu) + len[0]);
}

void		archive(t_ldf *ldf, void (*f)(t_ldf *ldf))
{
	struct ar_hdr	*hdr;
	size_t			len;

	hdr = ft_ldf_jmp(ldf, SARMAG, sizeof(*hdr));
	if (hdr == NULL)
		return ;
	len = ft_antou(hdr->ar_size, sizeof(hdr->ar_size));
	archive_parcours(ldf, f, 8 + sizeof(*hdr) + len);
}
