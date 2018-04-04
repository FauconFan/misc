NAME = HonorPi
BIN_FOLDER = bin/

MAIN_PATH = "src/Main"
MAIN_PATH_MANIFEST = "src.Main"

MANIFEST = "MANIFEST.MF"
JAR = $(NAME).jar

_RED=$(shell tput setaf 1)
_GREEN=$(shell tput setaf 2)
_YELLOW=$(shell tput setaf 3)
_BLUE=$(shell tput setaf 4)
_PURPLE=$(shell tput setaf 5)
_CYAN=$(shell tput setaf 6)
_WHITE=$(shell tput setaf 7)
_END=$(shell tput sgr0)

all :
	@mkdir -p $(BIN_FOLDER)
	@javac -d $(BIN_FOLDER) $(MAIN_PATH).java
	@echo "Main-Class: "$(MAIN_PATH_MANIFEST) > $(MANIFEST)
	@jar -cvmf $(MANIFEST) $(JAR) -C $(BIN_FOLDER) ./

clean:
	@rm -rf $(BIN_FOLDER)
	@rm -rf $(MANIFEST)

fclean: clean
	@rm -rf $(JAR)

re: fclean all