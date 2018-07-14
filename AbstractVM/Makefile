# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 16:52:43 by jpriou            #+#    #+#              #
#    Updated: 2018/07/14 09:53:24 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = avm

FLAGS = -g -Wall -Wextra -Werror \
			-Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align \
			-Wunused -Woverloaded-virtual -pedantic

INCLUDES_DIR = -I src/ \
				-I src/exceptions \
				-I src/prog/ \
				-I src/prog/instructions/ \
				-I src/prog/operands/ \
				-I src/prog/operands/default_op/ \
				-I src/lexer_parser \
				-I src/lexer_parser/tokens

CXX = clang++ $(FLAGS) $(INCLUDES_DIR)

SRC = src/main.cpp \
		src/exceptions/SuperException.class.cpp \
		src/exceptions/OverUnderFlowException.class.cpp \
		src/exceptions/ZeroException.class.cpp \
		src/exceptions/UnknownTypeException.class.cpp \
		src/prog/ProgEnv.class.cpp \
		src/prog/instructions/Instruction.class.cpp \
		src/prog/operands/OperandFactory.class.cpp \
		src/lexer_parser/Lexer.class.cpp \
		src/lexer_parser/Parser.class.cpp \
		src/lexer_parser/tokens/InstructionToken.class.cpp \
		src/lexer_parser/tokens/ValueToken.class.cpp

# _RED=$(shell tput setaf 1)
_GREEN=$(shell tput setaf 2)
# _YELLOW=$(shell tput setaf 3)
# _BLUE=$(shell tput setaf 4)
# _PURPLE=$(shell tput setaf 5)
_CYAN=$(shell tput setaf 6)
# _WHITE=$(shell tput setaf 7)
_END=$(shell tput sgr0)

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@printf "Program %s... " "$(NAME)"
	@$(CXX) $(OBJ) -o $(NAME)
	@printf "%scompiled%s\\n" "$(_CYAN)" "$(_END)"

%.o: %.cpp
	@printf "Compiling %s... " "$?"
	@$(CXX) -c $? -o $@
	@printf "%scompiled%s\\n" "$(_GREEN)" "$(_END)"

clean:
	@echo "Objects removed"
	@rm -rf $(OBJ)

fclean: clean
	@echo "Program $(NAME) removed"
	@rm -rf $(NAME)

re: fclean all
