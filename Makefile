NAME = GraphTXT
BIN_FOLDER = bin/

MAIN_PATH = "src/Main"
MAIN_PATH_MANIFEST = "src.Main"

MANIFEST = "MANIFEST.MF"
JAR = $(NAME).jar

PATH_FLEX = assets/lex.flex
PATH_FLEX_RENDER = src/LexerFlex.java
PATH_FLEX_TMP = LexerFlex.java

all : genflex
	@mkdir -p $(BIN_FOLDER)
	@javac -d $(BIN_FOLDER) $(MAIN_PATH).java
	@echo "Main-Class: "$(MAIN_PATH_MANIFEST) > $(MANIFEST)
	@jar -cvmf $(MANIFEST) $(JAR) -C $(BIN_FOLDER) ./

genflex : cleanflex
	@jflex -d . $(PATH_FLEX)
	@printf "package src;\\n\\n" > $(PATH_FLEX_RENDER)
	@cat $(PATH_FLEX_TMP) >> $(PATH_FLEX_RENDER)
	@rm -f $(PATH_FLEX_TMP)

cleanflex :
	@rm -rf src/LexerFlex.java

clean: cleanflex
	@rm -rf $(BIN_FOLDER)
	@rm -rf $(MANIFEST)

fclean: clean
	@rm -rf $(JAR)

re: fclean all
