# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 12:40:29 by jpriou            #+#    #+#              #
#    Updated: 2019/06/17 08:59:36 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

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
INC_FOLDER = inc/

CFLAGS = -Wall -Wextra -Werror -Weverything -pedantic -Wno-cast-align
SRC_CFLAGS =
BIN_CFLAGS =
IFLAGS = -I $(INC_FOLDER)
LFLAGS =
SRC_FLAGS = $(SRC_CFLAGS) $(CFLAGS) $(IFLAGS)
BIN_FLAGS = $(BIN_CFLAGS) $(CFLAGS) $(IFLAGS)

SRC_FILES = \
			main.c \
			ft_nm.c \
			ft_otool.c \
			t_ldf/ft_ldf_init.c \
			t_ldf/ft_ldf_end.c \
			std/ft_strequ.c \
			std/ft_put_vm_addr.c \
			std/ft_put_hex_char.c \
			std/ft_put_str.c \
			std/ft_put_uint.c \
			std/ft_put_uint_base.c \

HEADER_FILES = \
			$(INC_FOLDER)ft_nm_otool.h \

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

OBJ = $(SRC:%.c=%.o)

#################################### COMPILATION ###############################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@printf "\\t%sLD%s\\t" "$(_CYAN)" "$(_END)"
	@$(CC) $(BIN_FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@printf "%s\\n" "$@"

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

.PHONY: re
re:
	@make fclean
	@make all