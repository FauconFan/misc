
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

LIBA = ../libsat/libsat.a
LIB_FLAGS = -L../libsat/ -lsat
LIB_INCS = -I ../libsat/

CXX = clang++
CXX_FLAGS = -g -O2 -Wall -Wextra -Werror \
			-Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align \
			-Wunused -Woverloaded-virtual -pedantic
CXX_STD = -std=c++11
INC_FLAGS = -I ./ $(LIB_INCS)
FLAGS = $(CXX_FLAGS) $(CXX_STD) $(INC_FLAGS)

SRC = \
		$(SRC_FOLDER)main.cpp \

OBJ = $(SRC:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(LIBA) $(OBJ)
	@printf "Program %s... " "$(NAME)"
	@$(CXX) $(FLAGS) $(OBJ) -o $(NAME) $(LIB_FLAGS)
	@printf "%scompiled%s\\n" "$(_CYAN)" "$(_END)"

%.o: %.cpp
	@printf "Compiling %s... " "$?"
	@$(CXX) $(FLAGS) -c $? -o $@
	@printf "%scompiled%s\\n" "$(_GREEN)" "$(_END)"

%.a:
	@printf "Compiling %s... " "$?"
	@make -C $(dir $@) $(notdir $@)
	@printf "%scompiled%s\\n" "$(_GREEN)" "$(_END)"

.PHONY: clean
clean:
	@echo "Objects removed"
	@rm -rf $(OBJ)
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
