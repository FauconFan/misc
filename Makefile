NAME = laby3d
BIN_FOLDER = bin/
DOC_FOLDER = doc/

MAIN_PATH = "src/Main"
MAIN_PATH_MANIFEST = "src.Main"
MANIFEST = "MANIFEST.MF"
JAR = $(NAME).jar

all :
	@mkdir -p $(BIN_FOLDER)
	@javac -d $(BIN_FOLDER) $(MAIN_PATH).java
	@echo "Main-Class: "$(MAIN_PATH_MANIFEST) > $(MANIFEST)
	@jar -cvmf $(MANIFEST) $(JAR) -C $(BIN_FOLDER) ./

run:
	@java -jar $(JAR)

clean:
	@rm -rf $(BIN_FOLDER)
	@rm -rf $(DOC_FOLDER)
	@rm -rf $(MANIFEST)

fclean: clean
	@rm -rf $(JAR)

norm:
	sh scripts/uncrustify.sh

doc:
	javadoc -subpackages src -charset utf-8 -d $(DOC_FOLDER)

re: fclean all
