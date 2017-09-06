NAME = test.exe
FLAGS = -Wall -Wextra -Werror -I ./includes/
LIB = -L./lib/ -lft -lperso

FOLDER_SRCS = srcs/
FOLDER_BIN = bin/
FOLDER_TOOLS = $(FOLDER_SRCS)tools/
FOLDER_TEST = $(FOLDER_SRCS)test/

MAIN_FILES = 	$(FOLDER_SRCS)main.c \
				$(FOLDER_SRCS)partie1.c \
				$(FOLDER_SRCS)partie2.c
MAIN_OBJ = 	$(FOLDER_BIN)main.o \
			$(FOLDER_BIN)partie1.o \
			$(FOLDER_BIN)partie2.o

TOOLS_FILES =	$(FOLDER_TOOLS)tools.c \
				$(FOLDER_TOOLS)s_answer.c
TOOLS_OBJ =	$(FOLDER_BIN)tools.o \
			$(FOLDER_BIN)s_answer.o

TEST_FILES = 	$(FOLDER_TEST)ft_strlen.c \
				$(FOLDER_TEST)ft_strchr.c \
				$(FOLDER_TEST)ft_strcmp.c \
				$(FOLDER_TEST)ft_teststr1.c \
				$(FOLDER_TEST)ft_teststr2.c \
				$(FOLDER_TEST)ft_atoi.c
TEST_OBJ = 	$(FOLDER_BIN)ft_strlen.o \
			$(FOLDER_BIN)ft_strchr.o \
			$(FOLDER_BIN)ft_strcmp.o \
			$(FOLDER_BIN)ft_teststr1.o \
			$(FOLDER_BIN)ft_teststr2.o \
			$(FOLDER_BIN)ft_atoi.o

FILES_O = $(MAIN_OBJ) $(TOOLS_OBJ) $(TEST_OBJ)

all: bin $(NAME)

$(NAME): $(FILES_O)
	gcc $(FLAGS) $^ $(LIB) -o $(NAME)

$(FOLDER_BIN)%.o: $(FOLDER_SRCS)%.c
	gcc $(FLAGS) -c $? -o $@

$(FOLDER_BIN)%.o: $(FOLDER_TOOLS)%.c
	gcc $(FLAGS) -c $? -o $@

$(FOLDER_BIN)%.o: $(FOLDER_TEST)%.c
	gcc $(FLAGS) -c $? -o $@

clean:
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

bin:
	mkdir -p $(FOLDER_BIN)