/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_unit_tests.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:11:36 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 15:59:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UNIT_TESTS_H
# define LIBFT_UNIT_TESTS_H

/*
** --------------------------- Librairies --------------------------------------
*/

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# define BUFF_SIZE	1024

/*
** ----------------- general structure for chained lists -----------------------
*/

# ifndef LIBFT_H

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

# endif

/*
** --------------------------- write functions ---------------------------------
*/

void				my_putchar(char c);
void				my_myputchar(char *string, char c);
void				my_putstr(char const *s);
void				my_myputstr(char const *s1, char const *s2);
void				my_putstr_fd(char const *s, int fd);
void				my_putchar_fd(char c, int fd);
void				my_putnbr(int n);
void				my_putnbrn(long long int n);
void				my_putnbr_base(long long int n, unsigned int base);
void				my_putnbr_fd(int n, int fd);
void				my_putendl_fd(char const *s, int fd);
void				my_putendl(char const *s);
void				my_myputnbr(char *str, int n);
void				my_myputendl(char const *s1, char const *s2);

/*
** --------------------------- cleaning functions ------------------------------
*/

void				my_bzero(void *s, size_t n);
void				*my_memset(void *b, int c, size_t len);
void				my_strdel(char **as);
void				my_strclr(char *s);

/*
** ---------------------------- mem functions ----------------------------------
*/

void				*my_memalloc(size_t size);
void				*my_memcpy(void *dst, const void *src, size_t n);
void				*my_memccpy(void *dst, const void *src, int c, size_t n);
void				*my_memmove(void *s1, const void *s2, size_t n);
void				*my_memchr(const void *s, int c, size_t n);
void				*my_memdup(const void *s, size_t n);
int					my_memcmp(const void *s1, const void *s2, size_t n);
void				my_memdel(void **ap);
void				my_protect_malloc(void);

/*
** -------------------------- string manipulation -----------------------------
*/

size_t				my_strlen(char const *s);
char				*my_strnew(size_t size);
char				*my_strnewset(int c, size_t len);
void				my_striter(char *s, void (*f)(char *));
void				my_striteri(char *s, void (*f)(unsigned int, char *));
char				*my_strsub(char const *s, unsigned int start, size_t len);
char				*my_strjoin(char const *s1, char const *s2);
char				*my_strtrim(char const *s);
int					my_countdigits(int n);
char				*my_strdup(char const *s1);
char				*my_strndup(char const *s1, int n);
char				*my_strdupfree(char *s1, int free_malloc);
char				*my_strrev(char *s);
char				*my_strmemrev(const char *s);
char				*my_strcpy(char *dst, const char *src);
char				*my_strncpy(char *dst, const char *src, size_t len);
char				*my_strcat(char *s1, const char *s2);
char				*my_strncat(char *s1, const char *s2, size_t n);
size_t				my_strlcat(char *dst, const char *src, size_t size);
char				*my_strstr(const char *big, const char *little);
char				*my_strnstr(const char *big, const char *little, size_t n);
int					my_strcmp(const char *s1, const char *s2);
int					my_strncmp(const char *s1, const char *s2, size_t n);
int					get_next_line(const int fd, char **line);

/*
** ------------------------------ string parsing -------------------------------
*/

int					my_isalpha(int c);
int					my_isdigit(int c);
int					my_isalnum(int c);
int					my_isascii(int c);
int					my_isprint(int c);
int					my_iswhitespaces(int c);
char				**my_strsplit(char const *s, char c);
char				*my_strmap(char const *s, char (*f)(char));
char				*my_strmapi(char const *s, char (*f)(unsigned int, char));
int					my_strequ(char const *s1, char const *s2);
int					my_strnequ(char const *s1, char const *s2, size_t n);
char				*my_strchr(const char *s, int c);
char				*my_strrchr(const char *s, int c);

/*
** -------------------------- conversion functions -----------------------------
*/

int					my_atoi(const char *str);
char				*my_itoa(int n);
int					my_toupper(int c);
int					my_tolower(int c);
void				my_swap(int *a, int *b);

/*
** ---------------------- linked lists manipulation ---------------------------
*/

t_list				*my_lstnew(void const *content, size_t content_size);
void				my_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				my_lstdel(t_list **alst, void (*del)(void *, size_t));
void				my_lstadd(t_list **alst, t_list *new);
void				my_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*my_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
