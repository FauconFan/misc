NAME = test.exe
FLAGS = -Wall -Wextra -Werror -I ./includes/
LIB = -L./lib/ -lft -lperso

FILES_O = main.o partie1.o partie2.o tools.o

all: $(NAME)

$(NAME): $(FILES_O)
	gcc $(FLAGS) $^ $(LIB) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $?

clean:
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all