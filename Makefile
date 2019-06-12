# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 12:40:29 by jpriou            #+#    #+#              #
#    Updated: 2019/06/12 13:14:33 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

CC = clang

SRC_FOLDER = src/

CFLAGS = -Wall -Wextra -Werror -Weverything -pedantic -Wno-cast-align -fPIC
SRC_CFLAGS = -fPIC
BIN_CFLAGS = -shared
IFLAGS = -I .
LFLAGS =
SRC_FLAGS = $(SRC_CFLAGS) $(CFLAGS) $(IFLAGS)
BIN_FLAGS = $(BIN_CFLAGS) $(CFLAGS) $(IFLAGS)

SRC_FILES = \
			api/malloc.c \
			api/free.c \
			api/realloc.c \
			api/calloc.c \
			api/show_alloc_mem.c \
			ft_env/ft_env_get.c \
			ft_env/ft_env_print.c \
			ft_env/ft_env_alloc.c \
			ft_env/ft_env_find_free.c \
			ft_env/ft_env_clear.c \
			ft_env/ft_env_cache_len.c \
			ft_env/ft_env_cache_get.c \
			ft_env/ft_env_cache_put.c \
			ft_ph/ft_ph_new.c \
			ft_ph/ft_ph_alloc.c \
			ft_ph/ft_ph_find_free.c \
			ft_ph/ft_ph_print.c \
			ft_ph/ft_ph_empty.c \
			ft_blk/ft_blk_init.c \
			ft_blk/ft_blk_alloc.c \
			ft_blk/ft_blk_find_free.c \
			ft_blk/ft_blk_print.c \
			utils/print/ft_put_addr.c \
			utils/print/ft_put_str.c \
			utils/print/ft_put_uint.c \
			utils/mmap_utils.c \
			utils/size_utils.c \

HEADER_FILES = \
			ft_malloc.h \
			inc/ft_malloc_intern.h \

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

OBJ = $(SRC:%.c=%.o)

#################################### COMPILATION ###############################

.PHONY: all
all: $(NAME_LN)

$(NAME): $(OBJ)
	@printf "\\t%sLD%s\\t" "$(_CYAN)" "$(_END)"
	@$(CC) $(BIN_FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@printf "%s\\n" "$@"

$(NAME_LN): $(NAME)
	@printf "\\t%sLN%s\\t" "$(_CYAN)" "$(_END)"
	@rm -f $(NAME_LN)
	@ln -s $(NAME) $(NAME_LN)
	@printf "%s\\n" "$(NAME_LN)"

%.o: %.c $(HEADER_FILES)
	@printf "\\t%sCC%s\\t" "$(_GREEN)" "$(_END)"
	@$(CC) $(SRC_FLAGS) -c $< -o $@
	@printf "%s\\n" "$<"

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
