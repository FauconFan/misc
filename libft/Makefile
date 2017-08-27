NAME = libft.exe
GCC = gcc -Wall -Wextra -Werror -I ./

PARTIE1_FOLDER = Partie1/
PARTIE2_FOLDER = Partie2/
BIN_FOLDER = bin/

PARTIE1 = 	$(PARTIE1_FOLDER)ft_strlen.c
PARTIE1_OBJ = 	$(BIN_FOLDER)ft_strlen.o

PARTIE2 = 	$(PARTIE2_FOLDER)ft_putchar.c \
			$(PARTIE2_FOLDER)ft_putstr.c \
			$(PARTIE2_FOLDER)ft_putendl.c \
			$(PARTIE2_FOLDER)ft_putnbr.c \
			$(PARTIE2_FOLDER)ft_putchar_fd.c \
			$(PARTIE2_FOLDER)ft_putstr_fd.c \
			$(PARTIE2_FOLDER)ft_putendl_fd.c \
			$(PARTIE2_FOLDER)ft_putnbr_fd.c
PARTIE2_OBJ =	$(BIN_FOLDER)ft_putchar.o \
				$(BIN_FOLDER)ft_putstr.o \
				$(BIN_FOLDER)ft_putendl.o \
				$(BIN_FOLDER)ft_putnbr.o \
				$(BIN_FOLDER)ft_putchar_fd.o \
				$(BIN_FOLDER)ft_putstr_fd.o \
				$(BIN_FOLDER)ft_putendl_fd.o \
				$(BIN_FOLDER)ft_putnbr_fd.o

FILES_O = $(PARTIE1_OBJ) $(PARTIE2_OBJ) $(BIN_FOLDER)main.o

all: bin $(NAME)

$(NAME): $(FILES_O)
	$(GCC) $^ -o $(NAME)

$(BIN_FOLDER)%.o: $(PARTIE1_FOLDER)%.c
	$(GCC) -c $? -o $@

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