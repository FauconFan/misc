/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strparse_n_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:12:17 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/07 14:51:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_strparse_n_free(char ***res, char *str, char c)
{
	int		nb_words;

	nb_words = ft_strparse(res, str, c);
	free(str);
	return (nb_words);
}
