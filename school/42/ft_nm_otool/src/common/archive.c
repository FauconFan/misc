/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:35:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/01 09:09:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static char	*get_name_from_hdr(
				t_ldf *ldf,
				size_t offset,
				struct ar_hdr *actu,
				size_t *additional_off)
{
	size_t	len_prefix;
	char	*name;
	int		tmp;

	*additional_off = 0;
	len_prefix = ft_strlen(AR_EFMT1);
	if (len_prefix >= sizeof(actu->ar_name))
		return (NULL);
	if (ft_strncmp(actu->ar_name, AR_EFMT1, len_prefix) == 0)
	{
		*additional_off = ft_antou(actu->ar_name + len_prefix,
			sizeof(actu->ar_name) - len_prefix);
		if (*additional_off == 0)
			return (NULL);
		name = ft_ldf_jmp(ldf, actu, offset + sizeof(*actu), *additional_off);
		if (name == NULL)
			return (NULL);
		return (ft_strndup(name, *additional_off));
	}
	if ((tmp = ft_strncpos(actu->ar_name, sizeof(actu->ar_name), ' ')) < 0)
		return (NULL);
	return (ft_strndup(actu->ar_name, (size_t)tmp));
}

static void	archive_parcours(t_ldf *ldf, void (*f)(t_ldf *ldf), size_t loff)
{
	struct ar_hdr	*actu;
	void			*beg;
	size_t			len[3];
	char			*names[2];
	t_ldf			in_file;

	if (loff >= ldf->len)
		return ;
	if ((actu = ft_ldf_jmp(ldf, NULL, loff, sizeof(*actu))) == NULL)
		return ;
	if ((names[0] = get_name_from_hdr(ldf, loff, actu, len + 1)) == NULL)
		return ;
	len[0] = ft_antou(actu->ar_size, sizeof(actu->ar_size));
	len[2] = len[0] - len[1];
	if ((beg = ft_ldf_jmp(ldf, (char *)actu + sizeof(*actu),
		loff + sizeof(*actu) + len[1], len[2])) == NULL)
		return ;
	names[1] = ft_strformat2("%(%)", ldf->name, names[0]);
	free(names[0]);
	ft_ldf_init_custom(&in_file, names[1], beg, len[2]);
	f(&in_file);
	archive_parcours(ldf, f, loff + sizeof(*actu) + len[0]);
	ft_ldf_end(&in_file);
}

void		archive(t_ldf *ldf, void (*f)(t_ldf *ldf))
{
	struct ar_hdr	*hdr;
	size_t			len;

	hdr = ft_ldf_jmp(ldf, NULL, SARMAG, sizeof(*hdr));
	if (hdr == NULL)
		return ;
	len = ft_antou(hdr->ar_size, sizeof(hdr->ar_size));
	archive_parcours(ldf, f, 8 + sizeof(*hdr) + len);
}
