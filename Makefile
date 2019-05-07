#                       (
#                         )     (
#                  ___...(-------)-....___
#              .-""       )    (          ""-.
#        .-'``'|-._             )         _.-|
#       /  .--.|   `""---...........---""`   |
#      /  /    |                             |
#      |  |    |                             |
#       \  \   |                             |
#        `\ `\ |                             |
#          `\ `|                             |
#          _/ /\                             /
#         (__/  \                           /
#      _..---""` \                         /`""---.._
#   .-'           \                       /          '-.
#  :               `-.__             __.-'              :
#  :                  ) ""---...---"" (                 :
#   '._               `"--...___...--"`              _.'
#     \""--..__                              __..--""/
#      '._     """----.....______.....----"""     _.'
#         `""--..,,_____            _____,,..--""`
#                       `"""----"""`

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
NAME_LN = libft_malloc.so

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

CC = gcc

SRC_FOLDER = src/
INC_FOLDER = inc/

CFLAGS = -Wall -Wextra -Werror -fPIC
IFLAGS = -I $(INC_FOLDER)
LFLAGS =
FLAGS = $(CFLAGS) $(IFLAGS)

SRC_FILES = \
			malloc.c \

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

OBJ = $(SRC:%.c=%.o)

#################################### COMPILATION ###############################

.PHONY: all
all: $(NAME_LN)

$(NAME): $(OBJ)
	@printf "\\t%sLD%s\\t" "$(_CYAN)" "$(_END)"
	@$(CC) -shared -Wl,-soname,$(NAME) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@printf "%s\\n" "$@"

$(NAME_LN): $(NAME)
	@printf "\\t%sLN%s\\t" "$(_CYAN)" "$(_END)"
	@rm -f $(NAME_LN)
	@ln -s $(NAME) $(NAME_LN)
	@printf "%s\\n" "$(NAME_LN)"

%.o: %.c
	@printf "\\t%sCC%s\\t" "$(_GREEN)" "$(_END)"
	@$(CC) $(FLAGS) -c $? -o $@
	@printf "%s\\n" "$?"

.PHONY: clean
clean:
	@rm -rf $(OBJ)
	@echo "Objects removed"

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)
	@echo "Library $(NAME) removed"
	@rm -rf $(NAME_LN)
	@echo "Symbolic link $(NAME_LN) removed"

.PHONY: re
re: fclean all

#################################### TEST #####################################

.PHONY: test
test: $(NAME_LN)
	make -C test run