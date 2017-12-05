/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:15:24 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/05 12:30:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>

/*
**	Includes for ft_printf
*/

# include "string_buffer.h"
# include "string_buffer_utils.h"
# include "treat_data_utils.h"

/*
**	Define Get next line
*/

# define BUFF_SIZE_GNL			25

/*
**	-------------------------- LIBFT_CHAR_FUNCTIONS ---------------------------
*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_isprint(int c);
int				ft_iswhitespace(int c);
int				ft_isspace(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);

int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	--------------------------- LIBFT_STR_FUNCTIONS ---------------------------
*/

char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);

char			*ft_strnew(size_t size);
char			*ft_strsetnew(int len, char c);

size_t			ft_strlen(char const *str);

int				ft_atoi(char const *nptr);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, char *base);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t size);

char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);

char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, char *src, size_t nb);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);

char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
										size_t len);

void			ft_strdel(char **as);
void			ft_strclr(char *s);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

int				ft_strcpos(char *s, int c);
int				ft_strcrpos(char *s, int c);
int				ft_strpos(char *big, char *little);
int				ft_strrpos(char *big, char *little);

int				ft_strparse(char ***res, char *str, char c);
int				ft_strparse_n_free(char ***res, char *str, char c);

int				ft_str_all(char *s, int (*f)(int c));
int				ft_str_any(char *s, int (*f)(int c));

int				ft_str_is_alnum(char *s);
int				ft_str_is_alpha(char *s);
int				ft_str_is_ascii(char *s);
int				ft_str_is_numeric(char *s);
int				ft_str_is_lowercase(char *s);
int				ft_str_is_uppercase(char *s);
int				ft_str_is_printable(char *s);
int				ft_str_is_blank(char *s);

/*
** ------------------------------ LIBFT MEMMORY -------------------------------
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_bzero(void *s, size_t n);
void			ft_memcheck(void *ptr);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**	-------------------------------- LIBFT PUT --------------------------------
*/

void			ft_putchar(char c);

void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int nb);
void			ft_putnbrl(int c);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int nb, int fd);

/*
**	---------------------------- LIBFT LINKED LIST ----------------------------
*/

typedef struct	s_list
{
	void				*content;
	struct s_list		*next;
}				t_list;

t_list			*ft_lstnew(void *content, void *(*cpy)(void *));
void			ft_lstadd(t_list **alst, t_list *new);
int				ft_lstsize(t_list *alst);
void			ft_lstdelone(t_list **alst, void (*del)(void*));
void			ft_lstdel(t_list **alst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *),
						void *(*cpy)(void *));

/*
**	------------------------------- LIBFT MATH --------------------------------
*/

int				ft_min(int a, int b);
int				ft_max(int a, int b);

int				ft_abs(int c);
int				ft_log10(int n);
int				ft_logb(int n, int lengthbase);

/*
**	------------------------------ GET NEXT LINE ------------------------------
*/

typedef struct	s_env_gnl
{
	struct s_env_gnl	*next;
	char				**buff_prog;
	int					fd;
}				t_env_gnl;

int				get_next_line(const int fd, char **line, t_env_gnl *env_gnl);

t_env_gnl		*init_env_gnl(void);
void			free_env_gnl(t_env_gnl *head);
char			**find_buff_prog(t_env_gnl *head, int searched_fd);

/*
**	-------------------------------- FT_PRINTF --------------------------------
*/

int				ft_center_printf(
						const char *restrict format,
						va_list va,
						char **answer,
						int *len_to_print);

int				ft_printf(
						const char *restrict format,
						...);
int				ft_dprintf(
						int fd,
						const char *restrict format,
						...);
int				ft_sprintf(char **str,
						const char *restrict format,
						...);
int				ft_snprintf(
						char **str,
						size_t size,
						const char *restrict format,
						...);

int				ft_vprintf(
						const char *restrict format,
						va_list ap);
int				ft_vdprintf(
						int fd,
						const char *restrict format,
						va_list ap);
int				ft_vsprintf(
						char **str,
						const char *restrict format,
						va_list ap);
int				ft_vsnprintf(char **str,
						size_t size,
						const char *restrict format,
						va_list ap);

#endif
