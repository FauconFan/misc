NAME = test.exe
FLAGS = -Wall -Wextra -Werror -I ./includes/
LIB = -L./lib/ -lft -lperso

FILES_O = main.o

all: $(NAME)

$(NAME): main.o 
	gcc $(FLAGS) $^ $(LIB) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $?

clean:
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all