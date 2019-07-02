/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 02:07:20 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/02 11:30:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libfts.h"

#include <stdio.h>

static void	test_bzero(void)
{
	unsigned char		addr[256];

	for (size_t i = 0; i < 256; ++i)
		addr[i] = i;
	ft_bzero(addr, 0);
	for (size_t i = 0; i < 256; ++i)
		assert(addr[i] == i);
	ft_bzero(addr + 32, 32);
	for (size_t i = 0; i < 256; ++i)
		assert((i >= 32 && i < 64) ? addr[i] == 0 : addr[i] == i);
	ft_bzero(addr, 256);
	for (size_t i = 0; i < 256; ++i)
		assert(addr[i] == 0);
}

static void	test_isalpha(void)
{
	for (int c = 0; c < 256; ++c)
		assert(ft_isalpha(c) == isalpha(c));
}

static void	test_isdigit(void)
{
	for (int c = 0; c < 256; ++c)
		assert(ft_isdigit(c) == isdigit(c));
}

static void	test_isalnum(void)
{
	for (int c = 0; c < 256; ++c)
		assert(ft_isalnum(c) == isalnum(c));
}

static void	test_isascii(void)
{
	for (int c = 0; c < 256; ++c)
		assert(ft_isascii(c) == isascii(c));
}

static void	test_isprint(void)
{
	for (int c = 0; c < 256; ++c)
		assert(ft_isprint(c) == isprint(c));
}

static void	test_toupper(void)
{
	for (int c = 0; c < 256; ++c)
		assert(ft_toupper(c) == toupper(c));
}

static void	test_tolower(void)
{
	for (int c = 0; c < 256; ++c)
		assert(ft_tolower(c) == tolower(c));
}

static void test_strlen(void)
{
	char	*tab[] = {
		"coucou",
		"",
		"abcdefghijklmnopqrstuvwxyz",
	};
	for (size_t i = 0; i < sizeof(tab) / sizeof(*tab); ++i)
		assert(ft_strlen(tab[i]) == strlen(tab[i]));
}

static void	test_tputs(void)
{
	ft_puts("Je suis un premier message");
	ft_puts("Je suis un second message");
	ft_puts("Et finalement un dernier message");
}

static void	test_strcat(void)
{
	char	addr[100];

	addr[0] = 0;
	assert(strcmp(ft_strcat(addr, "42"), "42") == 0);
	assert(strcmp(ft_strcat(addr, ""), "42") == 0);
	assert(strcmp(ft_strcat(addr, "cest une ecole"), "42cest une ecole") == 0);
	assert(strcmp(ft_strcat(addr, " d'informatique"), "42cest une ecole d'informatique") == 0);
	ft_puts(addr);
	ft_strcat(addr, " fantastique");
	ft_puts(addr);
	assert(strcmp(addr, "42cest une ecole d'informatique fantastique") == 0);
	ft_puts(addr);
}

int			main(void)
{
	test_bzero();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	test_strlen();
	test_tputs();
	test_strcat();
}
