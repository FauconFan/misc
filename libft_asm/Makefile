# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 01:43:15 by jpriou            #+#    #+#              #
#    Updated: 2019/07/04 12:19:08 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

MAKEFLAGS += --no-print-directory

AR = ar
AS = nasm
RANLIB = ranlib

AS_FLAG = -g -f macho64
AR_FLAG = -rc

SRC_FOLDER = src/
INC_FOLDER = inc/

INC_FLAGS = $(foreach dir, $(INC_FOLDER), -I $(dir))

_AS_FILES = \
			ft_bzero.s \
			ft_memset.s \
			ft_memcpy.s \
			ft_isalpha.s \
			ft_isdigit.s \
			ft_isalnum.s \
			ft_isascii.s \
			ft_isprint.s \
			ft_toupper.s \
			ft_tolower.s \
			ft_strcat.s \
			ft_strlen.s \
			ft_strdup.s \
			ft_puts.s \

AS_FILES = $(addprefix $(SRC_FOLDER), $(_AS_FILES))

TEST = test

OBJ = $(AS_FILES:%.s=%.o)

#################################### COMPILATION ###############################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@ printf "\\t%sLD%s\\t" "$(_CYAN)" "$(_END)"
	@ $(AR) $(AR_FLAG) $@ $^
	@ $(RANLIB) $@ 
	@ printf "%s\\n" "$@"

%.o: %.s
	@ printf "\\t%sAS%s\\t" "$(_GREEN)" "$(_END)"
	@ $(AS) $(AS_FLAG) $(INC_FLAGS) $< -o $@
	@ printf "%s\\n" "$<"

.PHONY: clean
clean:
	@ rm -rf $(OBJ)
	@ echo "Objects removed"

.PHONY: fclean
fclean: clean
	@ rm -rf $(NAME)
	@ echo "Library $(NAME) removed"
	@ rm -rf $(TEST)
	@ echo "Executable $(TEST) removed"

.PHONY: re
re:
	@ make fclean
	@ make all

##################################### TEST ####################################

.PHONY: $(TEST)
$(TEST): $(NAME)
	@ gcc -g test_main.c -o $@ -L. -lfts -I inc 
	@ ./$@
