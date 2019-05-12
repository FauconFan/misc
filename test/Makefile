
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

SRC_FOLDER = src/

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

# With Show
FILES_WS = \
			ws01_test5.c \

FILES_NS_ = $(addprefix files/, $(FILES_NS))
FILES_WS_ = $(addprefix files/, $(FILES_WS))

PROGS_NS = $(FILES_NS_:%.c=%)
PROGS_WS = $(FILES_WS_:%.c=%)

PROGS = $(PROGS_NS) $(PROGS_WS)

#################################### COMPILATION ###############################

.PHONY: all
all: $(PROGS)

files/ns%: files/ns%.c measuring.c
	@printf "\\t%sCC%s\\t" "$(_GREEN)" "$(_END)"
	@$(CC) $(FLAGS) $? -o $@
	@printf "%s\\n" "$<"

files/ws%: files/ws%.c measuring.c
	@printf "\\t%sCC%s\\t" "$(_GREEN)" "$(_END)"
	@$(CC) $(FLAGS) -I .. $? -o $@ -L.. -lft_malloc
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
	@make ..
	@$(foreach prog, $(PROGS_NS), \
		printf "\t===== %s =====\\n" "$(prog)"; \
		printf "\tNormal\\n"; \
		./$(prog); \
		printf "\tFt_malloc\\n"; \
		(cd ..; $(RUN_SH) ./test/$(prog)); \
	)
	@$(foreach prog, $(PROGS_WS), \
		printf "\t===== %s =====\\n" "$(prog)"; \
		printf "\tFt_malloc\\n"; \
		(cd ..; $(RUN_SH) ./test/$(prog)); \
	)

