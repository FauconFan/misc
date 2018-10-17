
OCAMLMAKEFILE = OCamlMakefile

RESULT = stream

SOURCES = \
			streams.ml \
			examples/fibonacciStream.ml \
			examples/primeStream.ml \
			examples/oddStream.ml \
			examples/rotcharStream.ml \
			examples/stringStream.ml \

all: clean_links
	make -C . nc
	mv $(RESULT) $(RESULT).opt
	make -C . bc
	mv $(RESULT) $(RESULT).byt
	ln -s $(RESULT).opt $(RESULT)

fclean: cleanup clean_links

clean_links:
	rm -f $(RESULT).opt $(RESULT).byt
	rm -f $(RESULT)

re: fclean all

include $(OCAMLMAKEFILE)
