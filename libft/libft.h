/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:40:35 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/19 16:55:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/*
** PARTIE 1
*/

void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memccpy(void *dest, const void *src,
									int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);

size_t					ft_strlen(char const *str);
char					*ft_strdup(const char *s);

char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);

char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
size_t					ft_strlcat(char *dest, char *src, size_t nb);

char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);

char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack,
									const char *needle, size_t len);

int						ft_strcmp(char const *s1, char const *s2);
int						ft_strncmp(char const *s1, char const *s2, size_t size);

int						ft_atoi(char const *nptr);

int						ft_isalnum(int c);
int						ft_isdigit(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);

int						ft_toupper(int c);
int						ft_tolower(int c);

/*
** PARTIE 2
*/

void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);

void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
									char (*f)(unsigned int, char));

int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s,
									unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);

void					ft_putchar(char c);
void					ft_putstr(char const *str);
void					ft_putendl(char const *str);
void					ft_putnbr(int nb);

void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *str, int fd);
void					ft_putendl_fd(char const *str, int fd);
void					ft_putnbr_fd(int nb, int fd);

/*
** BONUS
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** MyBONUS
*/

char					*ft_strsetnew(int len, char c);

int						ft_strpos(char *big, char *little);
int						ft_strrpos(char *big, char *little);
int						ft_strcpos(char *s, int c);
int						ft_strcrpos(char *s, int c);

int						ft_str_any(char *s, int (*f)(int c));
int						ft_str_all(char *s, int (*f)(int c));

int						ft_strparse(char ***res, char *str, char c);
int						ft_strparse_n_free(char ***res, char *str, char c);

int						ft_iswhitespace(int c);
int						ft_isspace(int c);
int						ft_islower(int c);
int						ft_isupper(int c);
int						ft_isblank(int c);
int						ft_isxdigit(int c);

int						ft_str_is_alnum(char *s);
int						ft_str_is_alpha(char *s);
int						ft_str_is_ascii(char *s);
int						ft_str_is_numeric(char *s);
int						ft_str_is_lowercase(char *s);
int						ft_str_is_uppercase(char *s);
int						ft_str_is_printable(char *s);
int						ft_str_is_blank(char *s);

void					ft_putnbrl(int c);
char					*ft_strndup(const char *s, size_t n);

int						ft_min(int a, int b);
int						ft_max(int a, int b);

int						ft_abs(int c);
int						ft_log10(int n);
int						ft_logb(int n, int lengthbase);

int						ft_atoi_base(char *str, char *base);
char					*ft_itoa_base(int n, char *base);
char					*ft_convert_base
							(char *nbr, char *base_from, char *base_to);

int						ft_lstsize(t_list *alst);

#endif
