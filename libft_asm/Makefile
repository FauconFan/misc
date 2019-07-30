# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 01:43:15 by jpriou            #+#    #+#              #
#    Updated: 2019/07/30 16:57:47 by jpriou           ###   ########.fr        #
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

ifeq ($(shell uname -s), Darwin)
	AS_FLAG = -f macho64 --prefix _
else
	AS_FLAG = -f elf64
endif

AR_FLAG = -rc

SRC_FOLDER = src/
INC_FOLDER = inc/

INC_FLAGS = $(foreach dir, $(INC_FOLDER), -I $(dir))

_AS_FILES = \
			ctype/ft_isalnum.s \
			ctype/ft_isalpha.s \
			ctype/ft_isascii.s \
			ctype/ft_isdigit.s \
			ctype/ft_islower.s \
			ctype/ft_isprint.s \
			ctype/ft_isupper.s \
			ctype/ft_tolower.s \
			ctype/ft_toupper.s \
			mem/ft_bzero.s \
			mem/ft_memchr.s \
			mem/ft_memcpy.s \
			mem/ft_memset.s \
			mem/ft_memcmp.s \
			str/ft_strcat.s \
			str/ft_strdup.s \
			str/ft_strlen.s \
			str/ft_strcmp.s \
			str/ft_strncmp.s \
			str/ft_strequ.s \
			other/ft_getrandom.s \
			other/ft_cat.s \
			other/ft_puts.s \
			other/ft_abs.s \
			other/ft_rc5.s \

AS_FILES = $(addprefix $(SRC_FOLDER), $(_AS_FILES))

TEST = test
CAT = ft_cat
RC5 = ft_rc5

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
	@ rm -rf $(CAT)
	@ echo "Executable $(CAT) removed"
	@ rm -rf $(RC5)
	@ echo "Executable $(RC5) removed"

.PHONY: re
re:
	@ make fclean
	@ make all

##################################### TEST ####################################

.PHONY: $(TEST)
$(TEST): $(NAME)
	@ printf "\\tProgram %s%s%s compiled\\n" "$(_PURPLE)" "$@" "$(_END)"
	@ gcc tests/main.c -o $@ -L. -lfts -I inc

##################################### CAT #####################################

.PHONY: cat
cat: $(CAT)

.PHONY: $(CAT)
$(CAT): $(NAME)
	@ printf "\\tProgram %s%s%s compiled\\n" "$(_PURPLE)" "$@" "$(_END)"
	@ gcc tests/cat.c -o $@ -L. -lfts -I inc

##################################### RC5 #####################################

.PHONY: $(RC5)
$(RC5): $(NAME)
	@ printf "\\tProgram %s%s%s compiled\\n" "$(_PURPLE)" "$@" "$(_END)"
	@ gcc tests/rc5.c -o $@ -L. -lfts -I inc

#################################### MMEISSON #################################

MMEISSON_REMOTE = https://github.com/mmeisson/tests_libasm

.PHONY: mmeisson
mmeisson: $(NAME)
	@ test -d $@ || git clone https://github.com/mmeisson/tests_libasm $@
	@ make -C $@
