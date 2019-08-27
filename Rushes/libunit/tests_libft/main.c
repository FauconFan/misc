/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 09:37:39 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 16:11:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

/*
**	Main de test pour libft
*/

int		main(void)
{
	bzero_launcher();
	strlen_launcher();
	toupper_launcher();
	isalnum_launcher();
	isalpha_launcher();
	isascii_launcher();
	isdigit_launcher();
	isprint_launcher();
	atoi_launcher();
	itoa_launcher();
	memcpy_launcher();
	print_result();
}
