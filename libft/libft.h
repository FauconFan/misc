#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

/*** PARTIE 1 ***/

size_t	ft_strlen(char const *str);
int 	ft_strcmp(char *s1, char *s2);
int 	ft_strncmp(char *s1, char *s2, size_t size);
int 	ft_atoi(char *nptr);
int 	ft_isalnum(int c);
int 	ft_isdigit(int c);
int 	ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*** PARTIE 2 ***/

void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putendl(char const *str);
void	ft_putnbr(int nb);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putendl_fd(char const *str, int fd);
void	ft_putnbr_fd(int nb, int fd);

#endif