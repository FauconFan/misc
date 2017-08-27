
NAME = libft.exe
GCC = gcc -Wall -Wextra -Werror
PARTIE2_FOLDER = Partie2/
BIN_FOLDER = bin/
PARTIE2 = 	$(PARTIE2_FOLDER)ft_putchar.c \
			$(PARTIE2_FOLDER)ft_putstr.c
FILES_O = 	$(BIN_FOLDER)ft_putchar.o \
			$(BIN_FOLDER)ft_putstr.o \
			

all: bin $(NAME)

$(NAME): $(FILES_O) $(BIN_FOLDER)main.o
	$(GCC) $? -o $(NAME)

$(BIN_FOLDER)%.o: $(PARTIE2_FOLDER)%.c
	$(GCC) -c $? -o $@

$(BIN_FOLDER)main.o: main.c
	$(GCC) -c $? -o $@

bin:
	mkdir -p $(BIN_FOLDER)

clean:
	rm -f $(FILES_O)
	rm -f main.o

fclean: clean
	rm -f $(NAME)

re: fclean all