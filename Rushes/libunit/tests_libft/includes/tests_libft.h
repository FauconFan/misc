/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 08:37:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 16:29:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_LIBFT_H
# define TESTS_LIBFT_H

# include "libft.h"
# include "framework.h"
# include "libft_unit_tests.h"

/*
** ---------------------------------- BZERO -----------------------------------
*/

void	bzero_launcher(void);

int		basic_test_bzero01(void);
int		basic_test_bzero02(void);

/*
** ---------------------------------- STRLEN ----------------------------------
*/

void	strlen_launcher(void);

int		strlen_simple_test_01(void);
int		strlen_simple_test_02(void);
int		strlen_empty_test(void);

/*
** ---------------------------------- TOUPPER ---------------------------------
*/

void	toupper_launcher(void);

int		toupper_basic_test1(void);
int		toupper_basic_test2(void);
int		toupper_basic_test3(void);

/*
** ---------------------------------- ISALNUM ---------------------------------
*/

void	isalnum_launcher(void);

int		basic_test_isalnum01(void);
int		basic_test_isalnum02(void);
int		basic_test_isalnum03(void);

/*
** ---------------------------------- ISALPHA ---------------------------------
*/

void	isalpha_launcher(void);

int		basic_test_isalpha01(void);
int		basic_test_isalpha02(void);

/*
** ---------------------------------- ISASCII ---------------------------------
*/

void	isascii_launcher(void);

int		basic_test_isascii01(void);

/*
** ---------------------------------- ISDIGIT ---------------------------------
*/

void	isdigit_launcher(void);

int		basic_test_isdigit01(void);
int		basic_test_isdigit02(void);

/*
** ---------------------------------- ISPRINT ---------------------------------
*/

void	isprint_launcher(void);

int		basic_test_isprint01(void);

/*
** ------------------------------------ ITOA ----------------------------------
*/

void	itoa_launcher(void);

int		basic_test_itoa01(void);
int		basic_test_itoa02(void);
int		basic_test_itoa03(void);
int		basic_test_itoa04(void);
int		basic_test_itoa05(void);

/*
** ------------------------------------ ATOI ----------------------------------
*/

void	atoi_launcher(void);

int		basic_test_atoi01(void);
int		basic_test_atoi02(void);
int		basic_test_atoi03(void);

/*
** ----------------------------------- MEMCPY ---------------------------------
*/

void	memcpy_launcher(void);

int		basic_test_memcpy01(void);
int		basic_test_memcpy02(void);

#endif
