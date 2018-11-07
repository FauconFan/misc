
OCAMLMAKEFILE = OCamlMakefile

RESULT = mondrian

MAIN = src/Main.ml

SOURCES = $(MAIN)

$(RESULT): all

all: nc

exec: $(RESULT)
	./$(RESULT)

fclean: clean-all
	rm -rf doc/

re: fclean all

include $(OCAMLMAKEFILE)
