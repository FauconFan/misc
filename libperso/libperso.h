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

void	my_putstr(char *s);
void	my_putstrlen(char *s, int len);
void	my_putchar(char c);
void	my_clrsrc(void);

void	my_putcol(char *color, char *text);

#endif