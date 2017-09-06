#ifndef LIBPERSO_H
# define LIBPERSO_H

# define BLACK "30"
# define RED "31"
# define GREEN "32"
# define YELLOW "33"
# define BLUE "34"
# define MAGENTA "35"
# define CYAN "36"
# define WHITE "37"

void	libperso_putstr(char *s);
void	libperso_putstrlen(char *s, int len);
void	libperso_putchar(char c);
void	clrsrc(void);

void	libperso_putcol(char *color, char *text);
void	h1(char *s);
void	h2(char *s);
void	h3(char *s);

#endif