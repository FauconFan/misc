NAME = cimp

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

CC = gcc

SDL_FLAGS = $(shell sdl2-config --cflags)
SDL_LIBS = $(shell sdl2-config --libs)

CFLAGS = -Wall -Wextra -Werror $(SDL_FLAGS)
IFLAGS = -I ./inc/
LFLAGS = $(SDL_LIBS)
FLAGS = $(CFLAGS) $(IFLAGS)

SRC := ""
include files.mk # On charge la liste des fichiers depuis le fichier files.mk

OBJ = $(SRC:%.c=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@printf "Program %s... " "$(NAME)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@printf "%scompiled%s\\n" "$(_CYAN)" "$(_END)"

%.o: %.c
	@printf "Compiling %s... " "$?"
	@$(CC) $(FLAGS) -c $? -o $@
	@printf "%scompiled%s\\n" "$(_GREEN)" "$(_END)"

.PHONY: clean
clean:
	@echo "Objects removed"
	@rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	@echo "Program $(NAME) removed"
	@rm -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: install
install:
	@test -f $(NAME) || (printf "'make all' before\\n" && false)
	cp $(NAME) /usr/local/bin/$(NAME)
