
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

LIBA = ../libsat/libsat.a
LIB_FLAGS = -L../libsat/ -lsat -lfl
LIB_INCS = -I ../libsat/

CXX = clang++
CXX_FLAGS = -g -O2 -Wall -Wextra -Werror \
			-Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align \
			-Wunused -Woverloaded-virtual -pedantic
CXX_STD = -std=c++11
INC_FLAGS = -I ./ $(LIB_INCS) -I $(LEXER_PARSER_FOLDER)
FLAGS = $(CXX_FLAGS) $(CXX_STD) $(INC_FLAGS)

SRC = \
		$(SRC_FOLDER)main.cpp \
		$(SRC_FOLDER)FNC_builder.class.cpp \

SRC_FLEX = $(LEXER_PARSER_FOLDER)dimacs.l
SRC_BISON = $(LEXER_PARSER_FOLDER)dimacs.y

OBJ = \
		$(SRC_BISON:%.y=%.parser.o) \
		$(SRC_FLEX:%.l=%.lexer.o) \
		$(SRC:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(LIBA) $(OBJ)
	@printf "Program %s... " "$(NAME)"
	@$(CXX) $(FLAGS) $(OBJ) -o $(NAME) $(LIB_FLAGS)
	@printf "%scompiled%s\\n" "$(_CYAN)" "$(_END)"

%.a:
	@printf "Compiling %s... " "$?"
	@make -C $(dir $@) $(notdir $@)
	@printf "%scompiled%s\\n" "$(_GREEN)" "$(_END)"

%.o: %.cpp
	@printf "Compiling %s... " "$?"
	@$(CXX) $(FLAGS) -c $? -o $@
	@printf "%scompiled%s\\n" "$(_GREEN)" "$(_END)"

$(LEXER_PARSER_FOLDER)%.lexer.o: $(LEXER_PARSER_FOLDER)%.l
	@printf "Lexer generating %s... " "$?"
	@flex -o $(@:.o=.cpp) $?
	@printf "%sgenerated%s\\n" "$(_YELLOW)" "$(_END)"
	@printf "Lexer compiling %s... " "$?"
	@$(CXX) $(INC_FLAGS) $(CXX_STD) -c $(@:.o=.cpp) -o $@
	@printf "%scompiled%s\\n" "$(_YELLOW)" "$(_END)"
	@rm -f $(@:.o=.cpp)

$(LEXER_PARSER_FOLDER)%.parser.o: $(LEXER_PARSER_FOLDER)%.y
	@printf "Parser generating %s... " "$?"
	@bison -d -o $(@:.o=.cpp) $?
	@printf "%sgenerated%s\\n" "$(_YELLOW)" "$(_END)"
	@printf "Parser compiling %s... " "$?"
	@$(CXX) $(INC_FLAGS) $(CXX_STD) -c $(@:.o=.cpp) -o $@
	@printf "%scompiled%s\\n" "$(_YELLOW)" "$(_END)"
	@rm -f $(@:.o=.cpp)

.PHONY: clean
clean:
	@echo "Objects removed"
	@rm -rf $(OBJ) $(SRC_BISON:%.y=%.parser.hpp)
	@make -C $(dir $(LIBA)) clean

.PHONY: fclean
fclean:
	@echo "Objects removed"
	@rm -rf $(OBJ)
	@echo "Program $(NAME) removed"
	@rm -rf $(NAME)
	@make -C $(dir $(LIBA)) fclean

.PHONY: re
re: fclean all
