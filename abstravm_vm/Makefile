# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 16:52:43 by jpriou            #+#    #+#              #
#    Updated: 2018/10/20 16:42:54 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

SRC_FOLDER = src/
EXC_FOLDER = src/exceptions/
CORE_FOLDER = src/core/
INS_FOLDER = src/core/instructions/
OPP_FOLDER = src/core/operands/
DOP_FOLDER = src/core/operands/default_op/
LEX_FOLDER = src/lexer_parser/
TOK_FOLDER = src/lexer_parser/tokens/

ALL_FOLDER = $(SRC_FOLDER) $(EXC_FOLDER) $(CORE_FOLDER) $(INS_FOLDER) $(OPP_FOLDER) $(DOP_FOLDER) $(LEX_FOLDER) $(TOK_FOLDER)

FLAGS = -Wall -Wextra -Werror \
			-Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align \
			-Wunused -Woverloaded-virtual -pedantic

CXX_STD = -std=c++11

INCLUDES_DIR = $(foreach d, $(ALL_FOLDER), -I $d)

CXX = clang++ $(FLAGS) $(CXX_STD) $(INCLUDES_DIR)

SRC = \
		$(SRC_FOLDER)main.cpp \
		$(EXC_FOLDER)SuperException.class.cpp \
		$(EXC_FOLDER)OverUnderFlowException.class.cpp \
		$(EXC_FOLDER)ZeroException.class.cpp \
		$(EXC_FOLDER)UnknownTypeException.class.cpp \
		$(EXC_FOLDER)AssertException.class.cpp \
		$(EXC_FOLDER)EndStackException.class.cpp \
		$(EXC_FOLDER)InvalidEntryException.class.cpp \
		$(CORE_FOLDER)ProgEnv.class.cpp \
		$(INS_FOLDER)Instruction.class.cpp \
		$(INS_FOLDER)UnaryInstruction.class.cpp \
		$(OPP_FOLDER)OperandFactory.class.cpp \
		$(LEX_FOLDER)Lexer.class.cpp \
		$(LEX_FOLDER)LexerError.class.cpp \
		$(LEX_FOLDER)Parser.class.cpp \
		$(LEX_FOLDER)ParserError.class.cpp \
		$(TOK_FOLDER)InstructionToken.class.cpp \
		$(TOK_FOLDER)ValueToken.class.cpp \

_RED=$(shell tput setaf 1)
_GREEN=$(shell tput setaf 2)
_YELLOW=$(shell tput setaf 3)
_BLUE=$(shell tput setaf 4)
_PURPLE=$(shell tput setaf 5)
_CYAN=$(shell tput setaf 6)
_WHITE=$(shell tput setaf 7)
_END=$(shell tput sgr0)

OBJ = $(SRC:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@printf "Program %s... " "$(NAME)"
	@$(CXX) $(OBJ) -o $(NAME)
	@printf "%scompiled%s\\n" "$(_CYAN)" "$(_END)"

%.o: %.cpp
	@printf "Compiling %s... " "$?"
	@$(CXX) -c $? -o $@
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
