#                                  |\    /|
#                               ___| \,,/_/
#                            ---__/ \/    \
#                           __--/     (D)  \
#                           _ -/    (_      \
#                          // /       \_ / ==\
#    __-------------------/           / \_ O o)
#   /                                 /   \==/`
#  /                                 /
# ||          )                   \_/\
# ||         /              _      /  |
# | |      /--------      ___\    /\  :
# | /   __-  - _/   ------    |  |   \ \
#  |   -  -   /                | |     \ )
#  |  |   -  |                 | )     | |
#   | |    | |                 | |    | |
#   | |    < |                 | |   |_/
#   < |    /__\                <  \
#   /__\                       /___\

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

INC_FOLDER = inc/

CFLAGS = -g -Wall -Wextra -Werror -std=c11 $(SDL_FLAGS)
IFLAGS = -I $(INC_FOLDER)
LFLAGS = $(SDL_LIBS)
FLAGS = $(CFLAGS) $(IFLAGS)

SRC := ""
INC := ""
include files.mk # On charge la liste des fichiers depuis le fichier files.mk

ALL_FILES = $(SRC) $(INC)

OBJ = $(SRC:%.c=%.o)
OBJ_NO_MAIN = $(SRC_NO_MAIN:%.c=%.o)
OBJ_TEST = $(TEST_SRC:%.c=%.o)

#################################### COMPILATION ###############################

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
	@rm -rf $(OBJ)
	@echo "Objects removed"

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)
	@echo "Program $(NAME) removed"

.PHONY: ffclean
ffclean: fclean
	@rm -rf \
		$(CIMP_CHECK) \
		gcovr \
		venv \
		infer.tar.xz infer-out \
		images/
	@find . -name "*.o" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.gcno" -delete
	@echo "Projecl all cleaned"

.PHONY: re
re: fclean all

###################################### INSTALL #################################

.PHONY: install
install:
	@test -f $(NAME) || (printf "'make all' before\\n" && false)
	cp $(NAME) /usr/local/bin/$(NAME)

###################################### IMAGES ##################################

BMP_IMAGES_REMOTE = \
			https://neptun.weebly.com/uploads/3/1/3/1/3131773/untitled17.bmp \
			https://neptun.weebly.com/uploads/3/1/3/1/3131773/untitled5.bmp \
			https://neptun.weebly.com/uploads/3/1/3/1/3131773/untitled3.bmp \

images:
	mkdir -p $@
	$(foreach url, $(BMP_IMAGES_REMOTE), curl $(url) -o images/$(shell basename $(url));)

###################################### VENV ####################################

venv:
	python3 -m venv venv
	venv/bin/pip3 install pip --upgrade
	venv/bin/pip3 install cpplint
	venv/bin/pip3 install gcovr


###################################### SUBMODULES ##############################

.PHONY: submodule
submodule:
	git submodule init
	git submodule update

###################################### UTILS ###################################
## This part is for continuous integration, testing, linting, etc...

UNCRUSTIFY = uncrustify/build/uncrustify
CPPLINT = venv/bin/cpplint
CPPCHECK = cppcheck
CLANG_TIDY = clang-tidy-6.0
INFER = /usr/local/bin/infer
GCOVR = venv/bin/gcovr

print-%:
	@echo $($*)

###################################### CHECK ###################################

CIMP_CHECK = cimp_check
GCOV_LIBS = -lcheck -lm -lpthread -lrt -lsubunit -lgcov -coverage

$(CIMP_CHECK): fclean venv recompile_with_profile_args $(OBJ_TEST)
	@$(CC) $(OBJ_NO_MAIN) $(OBJ_TEST) $(GCOV_LIBS) $(LFLAGS) -o $@
	./$@
	mkdir -p gcovr
	$(GCOVR) -r . --html --html-details -o gcovr/index.html

.PHONY: recompile_with_profile_args
recompile_with_profile_args:
	make CFLAGS="$(CFLAGS) -fprofile-arcs -ftest-coverage" $(OBJ_NO_MAIN)

###################################### UNCRUSTIFY ##############################

CONFIG_UNCRUSTIFY = uncrustify_config.txt

$(UNCRUSTIFY): submodule
	mkdir -p uncrustify/build
	(cd uncrustify/build && cmake ..)
	make -C uncrustify/build

.PHONY: uncrustify_apply
uncrustify_apply: $(UNCRUSTIFY)
	$(UNCRUSTIFY) -c $(CONFIG_UNCRUSTIFY) --replace --no-backup --mtime $(ALL_FILES)

.PHONY: uncrustify_check
uncrustify_check: $(UNCRUSTIFY)
	$(UNCRUSTIFY) -c $(CONFIG_UNCRUSTIFY) --check $(ALL_FILES)

###################################### CPPLINT #################################

.PHONY: cpplint_run
cpplint_run: venv
	$(CPPLINT) $(ALL_FILES)

##################################### CPPCHECK #################################

.PHONY: cppcheck_run
cppcheck_run:
	$(CPPCHECK) --error-exitcode=1 --enable=all -I inc $(ALL_FILES)

##################################### CLANG_TIDY ###############################

.PHONY: clang_tidy_run
clang_tidy_run:
	$(CLANG_TIDY) \
		-checks="*,-llvm-header-guard,-google-readability-braces-around-statements,-hicpp-braces-around-statements,-readability-braces-around-statements" \
		-header-filter=".*" \
		-warnings-as-errors="*" \
		$(SRC) -- -I inc \

.PHONY: clang_tidy_fix
clang_tidy_fix:
	$(CLANG_TIDY) \
		-checks="*,-llvm-header-guard,-google-readability-braces-around-statements,-hicpp-braces-around-statements,-readability-braces-around-statements" \
		-header-filter=".*" \
		-fix-errors \
		$(SRC) -- -I inc \

###################################### INFER ##################################

INFER_TAR = infer.tar.xz
VERSION_INFER = 0.15.0
PATH_DL_INFER = https://github.com/facebook/infer/releases/download/v$(VERSION_INFER)/infer-linux64-v$(VERSION_INFER).tar.xz
SHASUM_INFER = f6eb98162927735e8c545528bb5a472312e5defcf0761e43c07c73fe214cb18a

$(INFER):
	test -f $(INFER_TAR) || make $(INFER_TAR)
	tar -C /opt -xJf $(INFER_TAR)
	rm -rf $(INFER_TAR)
	ln -s /opt/infer-linux64-v$(VERSION_INFER)/bin/infer $@

$(INFER_TAR):
	curl -sSL $(PATH_DL_INFER) -o $@
	echo "$(SHASUM_INFER)  $@" | shasum -a 256 -c -

.PHONY: infer_run
infer_run: $(INFER)
	make CC="$(INFER) run --fail-on-issue -- $(CC)" all