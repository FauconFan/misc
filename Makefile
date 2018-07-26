.PHONY: all

NAME = 99_Ocaml_Problems

DIR_CHALLENGE := challenges
DIR_CORE := core
CHALLENGES = $(shell ls -1 $(DIR_CHALLENGE))
CORE = $(shell ls -1 $(DIR_CORE))

all: $(NAME)

$(NAME): $(CHALLENGES)
	cp $(addprefix $(DIR_CORE)/, $(CORE)) .
	dune build main.exe
	cp _build/default/main.exe $(NAME)

%.ml: $(DIR_CHALLENGE)/%.ml
	cp $? $@
	@echo "val test : unit -> unit" > $(@:.ml=.mli)

clean:
	dune clean
	rm -f $(CHALLENGES) $(CHALLENGES:.ml=.mli) $(CORE)

fclean: clean
	rm -f $(NAME)

re: fclean all
