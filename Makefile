
OCAMLMAKEFILE = OCamlMakefile

RESULT = mondrian

MAIN = src/Main.ml

ML_FILES = \
		src/model/Base.ml \
		src/model/Check.ml \
		src/model/Generation.ml \
		src/view/DUGraphics.ml \
		src/controller/Translate.ml \

MLI_FILES = $(ML_FILES:%.ml=%.mli)

SOURCES = $(MLI_FILES) $(ML_FILES) $(MAIN)

$(RESULT): all

all: nc

exec: $(RESULT)
	./$(RESULT)

fclean: clean-all
	rm -rf doc/

re: fclean all

include $(OCAMLMAKEFILE)
