.PHONY: all

NAME = 99_Ocaml_Problems

DIR_CHALLENGE := challenges
CHALLENGES = $(shell ls -1 $(DIR_CHALLENGE))

all: $(NAME)

$(NAME):
	cp $(DIR_CHALLENGE)/* .
	dune build main.exe
	cp _build/default/main.exe $(NAME)

clean:
	dune clean
	rm -f $(CHALLENGES)
	rm -f $(NAME)

re: clean all
