
NAME = sat

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

SRC_FOLDER = src/
LEXER_PARSER_FOLDER = src/lexer_parser/
FLEX_BISON_FOLDER = src/lexer_parser/flex_bison/
PROBLEMS_FOLDER = src/problems/

LIBSAT_DIR = ../libsat/
LIBA = $(LIBSAT_DIR)libsat.a
LIB_FLAGS = -L$(LIBSAT_DIR) -lsat
LIB_INCS = -I $(LIBSAT_DIR)

CXX = clang++
CXX_FLAGS = -g -O2 -Wall -Wextra -Werror \
			-Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align \
			-Wunused -Woverloaded-virtual -pedantic
CXX_STD = -std=c++17 #14
INC_FLAGS = -I ./ $(LIB_INCS) -I $(LEXER_PARSER_FOLDER)
FLAGS = $(CXX_FLAGS) $(CXX_STD) $(INC_FLAGS)

SRC = \
		$(SRC_FOLDER)main.cpp \
		$(LEXER_PARSER_FOLDER)FNC_builder.class.cpp \
		$(LEXER_PARSER_FOLDER)getinput.cpp \
		$(PROBLEMS_FOLDER)queens.cpp \
		$(PROBLEMS_FOLDER)einstein.cpp \
		$(PROBLEMS_FOLDER)pigeon_hole_principle.cpp \

SRC_FLEX = $(FLEX_BISON_FOLDER)dimacs.l
SRC_BISON = $(FLEX_BISON_FOLDER)dimacs.y

OBJ = \
		$(SRC_BISON:%.y=%.parser.o) \
		$(SRC_FLEX:%.l=%.lexer.o) \
		$(SRC:%.cpp=%.o)

.PHONY: all
all: libsat $(NAME)

.PHONY: fast
fast: libsat_fast $(NAME)

$(NAME): $(LIBA) $(OBJ)
	@printf "\\t%sLD%s\\t%s\\n" "$(_PURPLE)" "$(_END)" "$@"
	@$(CXX) $(FLAGS) $(OBJ) -o $(NAME) $(LIB_FLAGS)

.PHONY: libsat
libsat:
	@make -C $(LIBSAT_DIR)

.PHONY: libsat_fast
libsat_fast:
	@make -C $(LIBSAT_DIR) fast

%.a:
	@make -C $(dir $@)

%.o: %.cpp
	@printf "\\t%sCC%s\\t%s\\n" "$(_GREEN)" "$(_END)" "$?"
	@$(CXX) $(FLAGS) -c $? -o $@

$(LEXER_PARSER_FOLDER)%.lexer.o: $(LEXER_PARSER_FOLDER)%.l
	@printf "\\t%sFL%s\\t%s\\n" "$(_YELLOW)" "$(_END)" "$?"
	@flex -o $(@:.o=.cpp) $?
	@printf "\\t%sCC%s\\t%s\\n" "$(_YELLOW)" "$(_END)" "$?"
	@$(CXX) $(INC_FLAGS) $(CXX_STD) -c $(@:.o=.cpp) -o $@
	@rm -f $(@:.o=.cpp)

$(LEXER_PARSER_FOLDER)%.parser.o: $(LEXER_PARSER_FOLDER)%.y
	@printf "\\t%sBS%s\\t%s\\n" "$(_YELLOW)" "$(_END)" "$?"
	@bison -d -o $(@:.o=.cpp) $?
	@printf "\\t%sCC%s\\t%s\\n" "$(_YELLOW)" "$(_END)" "$?"
	@$(CXX) $(INC_FLAGS) $(CXX_STD) -c $(@:.o=.cpp) -o $@
	@rm -f $(@:.o=.cpp)

.PHONY: clean
clean:
	@echo "Objects removed"
	rm -rf $(OBJ) $(SRC_BISON:%.y=%.parser.hpp)
	@make -C $(dir $(LIBA)) clean

.PHONY: fclean
fclean: clean
	@echo "Program $(NAME) removed"
	@rm -rf $(NAME)
	@make -C $(dir $(LIBA)) fclean

.PHONY: re
re: fclean all
