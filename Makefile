# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 12:40:29 by jpriou            #+#    #+#              #
#    Updated: 2019/07/01 09:03:05 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_OTOOL = ft_otool
NAME_NM = ft_nm

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
COM_FOLDER = common/
NM_FOLDER = nm/
OTOOL_FOLDER = otool/

CFLAGS = -g -Wall -Wextra -Werror -Weverything -pedantic -Wno-cast-align -Wno-sign-conversion
SRC_CFLAGS =
BIN_CFLAGS =
IFLAGS = -I $(INC_FOLDER)
LFLAGS =
SRC_FLAGS = $(SRC_CFLAGS) $(CFLAGS) $(IFLAGS)
BIN_FLAGS = $(BIN_CFLAGS) $(CFLAGS) $(IFLAGS)

include files.makefile

COMMON_OBJ = $(COMMON_FILES:%.c=%.o)
NM_OBJ = $(NM_FILES:%.c=%.o)
NM_MAIN_OBJ = $(NM_MAIN:%.c=%.o)
OTOOL_OBJ = $(OTOOL_FILES:%.c=%.o)
OTOOL_MAIN_OBJ = $(OTOOL_MAIN:%.c=%.o)

OBJ = $(COMMON_OBJ) $(NM_OBJ) $(OTOOL_OBJ) $(NM_MAIN_OBJ) $(OTOOL_MAIN_OBJ)

#################################### COMPILATION ###############################

.PHONY: all
all: $(NAME_NM) $(NAME_OTOOL)

$(NAME_NM): $(COMMON_OBJ) $(NM_OBJ) $(NM_MAIN_OBJ)
	@ printf "\\t%sLD%s\\t" "$(_CYAN)" "$(_END)"
	@ $(CC) $(BIN_FLAGS) $^ -o $@ $(LFLAGS)
	@ printf "%s\\n" "$@"

$(NAME_OTOOL): $(COMMON_OBJ) $(OTOOL_OBJ) $(OTOOL_MAIN_OBJ)
	@ printf "\\t%sLD%s\\t" "$(_CYAN)" "$(_END)"
	@ $(CC) $(BIN_FLAGS) $^ -o $@ $(LFLAGS)
	@ printf "%s\\n" "$@"

%.o: %.c $(HEADER_FILES)
	@ printf "\\t%sCC%s\\t" "$(_GREEN)" "$(_END)"
	@ $(CC) $(SRC_FLAGS) -c $< -o $@
	@ printf "%s\\n" "$<"

.PHONY: clean
clean:
	@ rm -rf $(OBJ)
	@ echo "Objects removed"
	@ make -f test.makefile fclean

.PHONY: fclean
fclean: clean
	@ rm -rf $(NAME)
	@ echo "Executable $(NAME) removed"
	@ rm -rf $(NAME_NM)
	@ echo "Executable $(NAME_NM) removed"
	@ rm -rf $(NAME_OTOOL)
	@ echo "Executable $(NAME_OTOOL) removed"

.PHONY: re
re:
	@ make fclean
	@ make all

##################################### TEST ####################################

.PHONY: test
test:
	@ make -f test.makefile main -j

.PHONY: test_rude
test_rude:
	@ make -f test.makefile rude