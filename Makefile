NAME = GraphTXT
BIN_FOLDER = bin/

MAIN_PATH = "src/Main"
MAIN_PATH_MANIFEST = "src.Main"

MANIFEST = "MANIFEST.MF"
JAR = $(NAME).jar

PATH_FLEX = assets/lex.flex
PATH_FLEX_RENDER = src/lexer_parser/LexerFlex.java

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
