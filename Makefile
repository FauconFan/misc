NAME = GraphTXT
BIN_FOLDER = bin/

MAIN_PATH = "src/Main"
MAIN_PATH_MANIFEST = "src.Main"

MANIFEST = "MANIFEST.MF"
JAR = $(NAME).jar

all : genflex
	@mkdir -p $(BIN_FOLDER)
	@javac -d $(BIN_FOLDER) $(MAIN_PATH).java
	@echo "Main-Class: "$(MAIN_PATH_MANIFEST) > $(MANIFEST)
	@jar -cvmf $(MANIFEST) $(JAR) -C $(BIN_FOLDER) ./

genflex : cleanflex
	@jflex -d . assets/lex.flex
	@printf "package src;\\n\\n" > src/LexerFlex.java
	@cat LexerFlex.java >> src/LexerFlex.java
	@rm -f LexerFlex.java

cleanflex :
	@rm -rf src/LexerFlex.java

clean: cleanflex
	@rm -rf $(BIN_FOLDER)
	@rm -rf $(MANIFEST)

fclean: clean
	@rm -rf $(JAR)

re: fclean all
