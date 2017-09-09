NAME = libperso.a
FLAGS = -Wall -Wextra -Werror -I ./

FILES_O = ft_putstr.o ft_putcolor.o ft_puttitle.o ft_uiexchange.o

all: $(NAME)

$(NAME): $(FILES_O)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	gcc -c $(FLAGS) $? -o $@

clean:
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all