NAME = libft.exe
GCC = gcc -Wall -Wextra -Werror -I ./

PARTIE1_FOLDER = Partie1/
PARTIE2_FOLDER = Partie2/
BIN_FOLDER = bin/

PARTIE1 = 	$(PARTIE1_FOLDER)ft_memset.c \
			$(PARTIE1_FOLDER)ft_bzero.c \
			$(PARTIE1_FOLDER)ft_memcpy.c \
			$(PARTIE1_FOLDER)ft_memccpy.c \
			$(PARTIE1_FOLDER)ft_memmove.c \
			$(PARTIE1_FOLDER)ft_memchr.c \
			$(PARTIE1_FOLDER)ft_memcmp.c \
			$(PARTIE1_FOLDER)ft_strlen.c \
			$(PARTIE1_FOLDER)ft_strdup.c \
			$(PARTIE1_FOLDER)ft_strcpy.c \
			$(PARTIE1_FOLDER)ft_strncpy.c \
			$(PARTIE1_FOLDER)ft_strcat.c \
			$(PARTIE1_FOLDER)ft_strncat.c \
			$(PARTIE1_FOLDER)ft_strlcat.c \
			$(PARTIE1_FOLDER)ft_strchr.c \
			$(PARTIE1_FOLDER)ft_strrchr.c \
			$(PARTIE1_FOLDER)ft_strstr.c \
			$(PARTIE1_FOLDER)ft_strnstr.c \
			$(PARTIE1_FOLDER)ft_strcmp.c \
			$(PARTIE1_FOLDER)ft_strncmp.c \
			$(PARTIE1_FOLDER)ft_atoi.c \
			$(PARTIE1_FOLDER)ft_isalnum.c \
			$(PARTIE1_FOLDER)ft_isalpha.c \
			$(PARTIE1_FOLDER)ft_isdigit.c \
			$(PARTIE1_FOLDER)ft_isprint.c \
			$(PARTIE1_FOLDER)ft_isascii.c \
			$(PARTIE1_FOLDER)ft_toupper.c \
			$(PARTIE1_FOLDER)ft_tolower.c
PARTIE1_OBJ = 	$(BIN_FOLDER)ft_memset.o \
				$(BIN_FOLDER)ft_bzero.o \
				$(BIN_FOLDER)ft_memcpy.o \
				$(BIN_FOLDER)ft_memccpy.o \
				$(BIN_FOLDER)ft_memmove.o \
				$(BIN_FOLDER)ft_memchr.o \
				$(BIN_FOLDER)ft_memcmp.o \
				$(BIN_FOLDER)ft_strlen.o \
				$(BIN_FOLDER)ft_strdup.o \
				$(BIN_FOLDER)ft_strcpy.o \
				$(BIN_FOLDER)ft_strncpy.o \
				$(BIN_FOLDER)ft_strcat.o \
				$(BIN_FOLDER)ft_strncat.o \
				$(BIN_FOLDER)ft_strlcat.o \
				$(BIN_FOLDER)ft_strchr.o \
				$(BIN_FOLDER)ft_strrchr.o \
				$(BIN_FOLDER)ft_strstr.o \
				$(BIN_FOLDER)ft_strnstr.o \
				$(BIN_FOLDER)ft_strcmp.o \
				$(BIN_FOLDER)ft_strncmp.o \
				$(BIN_FOLDER)ft_atoi.o \
				$(BIN_FOLDER)ft_isalnum.o \
				$(BIN_FOLDER)ft_isdigit.o \
				$(BIN_FOLDER)ft_isalpha.o \
				$(BIN_FOLDER)ft_isprint.o \
				$(BIN_FOLDER)ft_isascii.o \
				$(BIN_FOLDER)ft_toupper.o \
				$(BIN_FOLDER)ft_tolower.o

PARTIE2 = 	$(PARTIE2_FOLDER)ft_memalloc.c \
			$(PARTIE2_FOLDER)ft_memdel.c \
			$(PARTIE2_FOLDER)ft_strnew.c \
			$(PARTIE2_FOLDER)ft_putchar.c \
			$(PARTIE2_FOLDER)ft_putstr.c \
			$(PARTIE2_FOLDER)ft_putendl.c \
			$(PARTIE2_FOLDER)ft_putnbr.c \
			$(PARTIE2_FOLDER)ft_putchar_fd.c \
			$(PARTIE2_FOLDER)ft_putstr_fd.c \
			$(PARTIE2_FOLDER)ft_putendl_fd.c \
			$(PARTIE2_FOLDER)ft_putnbr_fd.c
PARTIE2_OBJ =	$(BIN_FOLDER)ft_memalloc.o \
				$(BIN_FOLDER)ft_memdel.o \
				$(BIN_FOLDER)ft_strnew.o \
				$(BIN_FOLDER)ft_putchar.o \
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