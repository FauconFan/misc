
NAME = libsat.a

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

SRC_FOLDER       = src/
MODEL_FOLDER     = src/model/
CORE_FOLDER      = src/model/core/
MODEL_BD_FOLDER  = src/model/model_builder/
COUPURE_FOLDER   = src/coupure/
DPLL_FOLDER      = src/dpll/
BRUTE_FOLDER     = src/bruteforcing/
UTILS_FOLDER     = src/utils/

AR = ar
CXX = clang++
CXX_FLAGS = -g -O2 -Wall -Wextra -Werror \
			-Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align \
			-Wunused -Woverloaded-virtual -pedantic
CXX_STD = -std=c++14
INC_FLAGS = -I ./
FLAGS = $(CXX_FLAGS) $(CXX_STD) $(INC_FLAGS)

SRC = \
	$(CORE_FOLDER)Clause.class.cpp \
	$(CORE_FOLDER)Fnc.class.cpp \
	$(CORE_FOLDER)Occ_list.class.cpp \
	$(CORE_FOLDER)Distrib.class.cpp \
	$(MODEL_BD_FOLDER)modelbuilder.ns.cpp \
	$(UTILS_FOLDER)Pair.class.cpp \
	$(UTILS_FOLDER)Logger.class.cpp \
	$(UTILS_FOLDER)cnull.cpp \
	$(UTILS_FOLDER)combinatorics.ns.cpp \
	$(COUPURE_FOLDER)Coupure.cpp \
	$(DPLL_FOLDER)DPLL.cpp \
	$(BRUTE_FOLDER)bruteforcing.cpp \
	

OBJ = $(SRC:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@printf "Library %s... " "$(NAME)"
	@$(AR) rc $(NAME) $(OBJ)
	@printf "%scompiled%s\\n" "$(_CYAN)" "$(_END)"

%.o: %.cpp
	@printf "Compiling %s... " "$?"
	@$(CXX) $(FLAGS) -c $? -o $@
	@printf "%scompiled%s\\n" "$(_GREEN)" "$(_END)"

.PHONY: clean
clean:
	@echo "Objects removed"
	@rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	@echo "Program $(NAME) removed"
	@rm -rf $(NAME)
	@rm -rf test

.PHONY: re
re: fclean all

