/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_n_ulltoa.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:07:34 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/14 19:36:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LLTOA_N_ULLTOA_H
# define FT_LLTOA_N_ULLTOA_H

# include "libft.h"

char		*ft_lltoa_base(long long n, char *base);
char		*ft_ulltoa_base(unsigned long long n, char *base);

#endif
