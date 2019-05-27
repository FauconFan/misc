
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
ALGO_FOLDER      = src/algos/
UTILS_FOLDER     = src/utils/

AR = ar
CXX = clang++
CXX_FLAGS = -g -O2 -Wall -Wextra -Werror \
			-Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align \
			-Wunused -Woverloaded-virtual -pedantic
CXX_ADDITIONAL_FLAGS =
CXX_STD = -std=c++17
INC_FLAGS = -I ./
FLAGS = $(CXX_FLAGS) $(CXX_ADDITIONAL_FLAGS) $(CXX_STD) $(INC_FLAGS)

SRC = \
	$(CORE_FOLDER)Clause.class.cpp \
	$(CORE_FOLDER)Fnc.class.cpp \
	$(CORE_FOLDER)Decision.class.cpp \
	$(CORE_FOLDER)Occ_list.class.cpp \
	$(CORE_FOLDER)Distrib.class.cpp \
	$(MODEL_BD_FOLDER)modelbuilder.ns.cpp \
	$(UTILS_FOLDER)IPair.class.cpp \
	$(UTILS_FOLDER)Logger.class.cpp \
	$(UTILS_FOLDER)cnull.cpp \
	$(UTILS_FOLDER)combinatorics.ns.cpp \
	$(ALGO_FOLDER)RSat.struct.cpp \
	$(ALGO_FOLDER)CDCL.cpp \
	$(ALGO_FOLDER)DPLL.cpp \
	$(ALGO_FOLDER)bruteforcing.cpp \
	$(ALGO_FOLDER)2Sat.cpp \

OBJ = $(SRC:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@printf "\\t%sLD%s\\t%s\\n" "$(_PURPLE)" "$(_END)" "$@"
	@$(AR) rc $(NAME) $(OBJ)

.PHONY: fast
fast:
	make all CXX_ADDITIONAL_FLAGS="-DFAST"

%.o: %.cpp
	@printf "\\t%sCC%s\\t%s\\n" "$(_GREEN)" "$(_END)" "$?"
	@$(CXX) $(FLAGS) -c $? -o $@

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

