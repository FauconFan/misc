/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 02:07:20 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/04 16:28:17 by jpriou           ###   ########.fr       */
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

static void	test_memset(void)
{
	unsigned char		addr[256];

	for (size_t i = 0; i < 256; ++i)
		addr[i] = i;
	ft_memset(addr, 42, 0);
	for (size_t i = 0; i < 256; ++i)
		assert(addr[i] == i);
	ft_memset(addr + 32, 16, 32);
	for (size_t i = 0; i < 256; ++i)
		assert((i >= 32 && i < 64) ? addr[i] == 16 : addr[i] == i);
	ft_memset(addr, 42, 256);
	for (size_t i = 0; i < 256; ++i)
		assert(addr[i] == 42);
}

static void	test_memcpy(void)
{
	unsigned char		addr[256];
	unsigned char		temoin[256];

	for (size_t i = 0; i < 256; ++i)
	{
		addr[i] = i;
		temoin[i] = 255 - i;
	}
	ft_memcpy(addr + 16, temoin, 32);
	for (size_t i = 0; i < 256; ++i)
	{
		assert((i >= 16 && i < 48) ? addr[i] == temoin[i - 16] : addr[i] == i);
	}
	ft_memcpy(addr, temoin, 256);
	for (size_t i = 0; i < 256; ++i)
	{
		assert(addr[i] == temoin[i]);
	}
}

#define	TEST_CHAR_FUNC(name) \
	static void test_ ## name (void) { \
		for (int c = 0; c < 256; ++c) \
			assert(ft_ ## name (c) == name (c));\
	} \

TEST_CHAR_FUNC(isalpha)
TEST_CHAR_FUNC(isdigit)
TEST_CHAR_FUNC(isalnum)
TEST_CHAR_FUNC(isascii)
TEST_CHAR_FUNC(isprint)
TEST_CHAR_FUNC(toupper)
TEST_CHAR_FUNC(tolower)

#define ___a	"coucou je mappelle jean"
#define __a		___a ___a ___a ___a ___a ___a ___a ___a ___a ___a ___a ___a
#define _a		__a __a __a __a __a __a __a __a __a __a __a __a __a __a __a
#define a		_a _a _a _a _a _a _a _a _a _a _a _a _a _a _a _a _a _a _a _a

static void test_strlen(void)
{
	char	*tab[] = {
		"coucou",
		"",
		"a",
		"\n",
		"abcdefghijklmnopqrstuvwxyz",
		"abc",
		a,
	};
	for (size_t i = 0; i < sizeof(tab) / sizeof(*tab); ++i)
		assert(ft_strlen(tab[i]) == strlen(tab[i]));
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

#define TEST_STRDUP(name) { \
	char *str = ft_strdup(# name); \
	assert(strcmp(str, # name) == 0); \
	free(str); \
}

static void test_strdup(void)
{
	TEST_STRDUP("coucou");
	TEST_STRDUP("");
	TEST_STRDUP("je");
	TEST_STRDUP(a);
	TEST_STRDUP("\n");
	TEST_STRDUP("abcdefghijklmnopqrstuvwxyz");
}

static void	test_tputs(void)
{
	ft_puts("Je suis un premier message");
	ft_puts("Je suis un second message");
	ft_puts("Et finalement un dernier message");
}

#define DO_TEST(s)	ft_puts("==== TEST " # s ); test_ ## s ();

int			main(void)
{
	DO_TEST(bzero);
	DO_TEST(memset);
	DO_TEST(memcpy);
	DO_TEST(isalpha);
	DO_TEST(isdigit);
	DO_TEST(isalnum);
	DO_TEST(isascii);
	DO_TEST(isprint);
	DO_TEST(toupper);
	DO_TEST(tolower);
	DO_TEST(strlen);
	DO_TEST(strcat);
	DO_TEST(strdup);
	DO_TEST(tputs);
}
