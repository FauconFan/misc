NAME = laby3d
BIN_FOLDER = bin/
DOC_FOLDER = doc/
DEP = "deps/gson-2.8.2.jar"
DEPS_FOLDER = ".:"$(DEP)

MAIN_PATH = "src/Main"
MAIN_PATH_MANIFEST = "src.Main"

MANIFEST = "MANIFEST.MF"
JAR = $(NAME).jar

all :
	@mkdir -p $(BIN_FOLDER)
	@javac -cp $(DEPS_FOLDER) -d $(BIN_FOLDER) $(MAIN_PATH).java -Xlint
	@echo "Main-Class: "$(MAIN_PATH_MANIFEST) > $(MANIFEST)
	@echo "Class-Path: "$(DEP) >> $(MANIFEST)
	@jar -cvmf $(MANIFEST) $(JAR) -C $(BIN_FOLDER) ./

testgen :
	@make all MAIN_PATH="src/model/gen/Algo" MAIN_PATH_MANIFEST="src.model.gen.Algo"

testparser :
	@make all MAIN_PATH="src/model/parser/ParserTest" MAIN_PATH_MANIFEST="src.model.parser.ParserTest"

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

dep: 
	curl http://repo1.maven.org/maven2/com/google/code/gson/gson/2.8.2/gson-2.8.2.jar -o deps/gson-2.8.2.jar 

