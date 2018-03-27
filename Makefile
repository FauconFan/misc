NAME = GraphTXT
BIN_FOLDER = bin/

MAIN_PATH = "src/Main"
MAIN_PATH_MANIFEST = "src.Main"

MANIFEST = "MANIFEST.MF"
JAR = $(NAME).jar

PATH_FLEX = flex/lex.flex
PATH_FLEX_RENDER = src/lexer_parser/LexerFlex.java

TESTING_SCRIPT = "tests/testing_script.sh"

_RED=$(shell tput setaf 1)
_GREEN=$(shell tput setaf 2)
_YELLOW=$(shell tput setaf 3)
_BLUE=$(shell tput setaf 4)
_PURPLE=$(shell tput setaf 5)
_CYAN=$(shell tput setaf 6)
_WHITE=$(shell tput setaf 7)
_END=$(shell tput sgr0)

all : genflex
	@mkdir -p $(BIN_FOLDER)
	@javac -d $(BIN_FOLDER) $(MAIN_PATH).java
	@echo "Main-Class: "$(MAIN_PATH_MANIFEST) > $(MANIFEST)
	@jar -cvmf $(MANIFEST) $(JAR) -C $(BIN_FOLDER) ./

genflex : cleanflex
	@jflex -d src/lexer_parser $(PATH_FLEX)

cleanflex :
	@rm -rf $(PATH_FLEX_RENDER)

clean: cleanflex
	@rm -rf $(BIN_FOLDER)
	@rm -rf $(MANIFEST)

fclean: clean
	@rm -rf $(JAR)

re: fclean all

test:
	@sh ${TESTING_SCRIPT}

basic_test:
	@sh ${TESTING_SCRIPT} basic

sys_test:
	@sh ${TESTING_SCRIPT} sys
