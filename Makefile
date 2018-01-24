NAME = laby3d
BIN_FOLDER = bin/

MAIN_PATH = "src/Main"
MANIFEST = "MANIFEST.MF"
JAR = $(NAME).jar

all :
	@mkdir -p $(BIN_FOLDER)
	@javac -d $(BIN_FOLDER) $(MAIN_PATH).java
	@echo "Main-Class: "$(MAIN_PATH) > $(MANIFEST)
	@jar -cvmf $(MANIFEST) $(JAR) -C $(BIN_FOLDER) ./

run:
	@java -jar $(JAR)

clean:
	@rm -rf $(BIN_FOLDER) $(JAR) $(MANIFEST)

re: clean all
