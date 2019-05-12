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

MAKEFLAGS += --no-print-directory

CC = gcc
RUN_SH = ./run.sh

SRC_FOLDER = src/

CFLAGS = -Wall -Wextra -Werror -fPIC
IFLAGS = -I .
LFLAGS =
FLAGS = $(CFLAGS) $(IFLAGS)

SRC_FILES = \
			api/malloc.c \
			api/free.c \
			api/realloc.c \
			api/calloc.c \
			api/show_alloc_mem.c \
			mlc_main/mlc_main_get.c \
			mlc_ph/mlc_ph_new.c \
			mlc_block/mlc_block_init.c \
			utils/mmap_utils.c \
			utils/print_utils.c \

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
	@make -C test fclean

.PHONY: re
re: fclean all

#################################### TEST #####################################

.PHONY: test
test: $(NAME_LN)
	make -C test run

SINGLE = test/files/ns02_single
SINGLE_DOWN = files/ns02_single

.PHONY: single
single:
	make -C test $(SINGLE_DOWN)
	$(RUN_SH) $(SINGLE)