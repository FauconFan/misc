
NAME = libft.exe
GCC = gcc -Wall -Wextra -Werror
PARTIE2_FOLDER = Partie2/
PARTIE2 = $(PARTIE2_FOLDER)ft_putchar.c
FILES_O = ft_putchar.o

all: $(NAME)

$(NAME): $(FILES_O) main.o
	$(GCC) $? -o $(NAME)

$(FILES_O): $(PARTIE2)
	$(GCC) -c $?

main.o: main.c
	$(GCC) -c $?

clean:
	rm -f $(FILES_O)
	rm -f main.o

fclean: clean
	rm -f $(NAME)

re: fclean all