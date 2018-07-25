.PHONY: all

NAME = 99_Ocaml_Problems

DIR_CHALLENGE := challenges
CHALLENGES = $(shell ls -1 $(DIR_CHALLENGE))

all: $(NAME)

$(NAME): $(CHALLENGES)
	dune build main.exe
	cp _build/default/main.exe $(NAME)

%.ml: $(DIR_CHALLENGE)/%.ml
	cp $? $@
	@echo "val test : unit -> unit" > $(@:.ml=.mli)

clean:
	dune clean
	rm -f $(CHALLENGES) $(CHALLENGES:.ml=.mli)

fclean: clean
	rm -f $(NAME)

re: fclean all
