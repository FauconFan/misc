# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 16:34:15 by jpriou            #+#    #+#              #
#    Updated: 2019/06/13 12:04:34 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

CC = gcc
RUN_SH = ./run.sh
RUN_PATH = $(shell pwd)/..
MALLOC_PATH = $(shell pwd)/..

SRC_FOLDER = src/
BIN_FOLDER = bin/

CFLAGS =
IFLAGS = -I .
LFLAGS =
FLAGS = $(CFLAGS) $(IFLAGS)

# No Show
FILES_NS = \
			ns01_empty.c \
			ns02_single.c \
			ns03_test0.c \
			ns04_test1.c \
			ns05_test2.c \
			ns06_test3.c \
			ns07_test3bis.c \
			ns08_test4.c \
			ns09_custom.c \
			ns10_overflow.c \

# With Show
FILES_WS = \
			ws01_test5.c \
			ws02_more.c \
			ws03_free.c \
			ws04_realloc.c \
			ws05_test2.c \
			ws06_empty.c \
			ws07_custom.c \
			ws08_realloc_custom.c \
			ws09_mem_alloc.c \
			ws10_malloc_zone.c \

FILES_NS_ = $(addprefix $(BIN_FOLDER), $(FILES_NS))
FILES_WS_ = $(addprefix $(BIN_FOLDER), $(FILES_WS))

PROGS_NS = $(FILES_NS_:%.c=%)
PROGS_WS = $(FILES_WS_:%.c=%)

PROGS = $(PROGS_NS) $(PROGS_WS)

#################################### COMPILATION ###############################

.PHONY: all
all: $(PROGS)

$(BIN_FOLDER)ns%: files/ns%.c
	@mkdir -p $(BIN_FOLDER)
	@printf "\\t%sCC%s\\t" "$(_GREEN)" "$(_END)"
	@$(CC) $(FLAGS) $? measuring.c -o $@
	@printf "%s\\n" "$<"

$(BIN_FOLDER)ws%: files/ws%.c
	@mkdir -p $(BIN_FOLDER)
	@printf "\\t%sCC%s\\t" "$(_GREEN)" "$(_END)"
	@$(CC) $(FLAGS) -I $(MALLOC_PATH) $? measuring.c -o $@ -L$(MALLOC_PATH) -lft_malloc
	@printf "%s\\n" "$<"

.PHONY: clean
clean:
	@rm -rf $(PROGS)
	@echo "Progs removed"

.PHONY: fclean
fclean: clean

.PHONY: re
re: fclean all

.PHONY: run
run: all
	@make $(MALLOC_PATH)
	@$(foreach prog, $(PROGS_NS), \
		printf "\t===== %s =====\\n" "$(prog)"; \
		printf "\tNormal\\n"; \
		./$(prog); \
		printf "\tFt_malloc\\n"; \
		(cd $(RUN_PATH); $(RUN_SH) ./test/$(prog)); \
	)
	@$(foreach prog, $(PROGS_WS), \
		printf "\t===== %s =====\\n" "$(prog)"; \
		printf "\tFt_malloc\\n"; \
		(cd $(RUN_PATH); $(RUN_SH) ./test/$(prog)); \
	)

