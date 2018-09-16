.PHONY: all

NAME = 99_Ocaml_Problems

DIR_CHALLENGE := challenges
DIR_CHALLENGE_1 := $(DIR_CHALLENGE)/1_Working_with_lists
DIR_CHALLENGE_2 := $(DIR_CHALLENGE)/2_Arithmetic
DIR_CHALLENGE_3 := $(DIR_CHALLENGE)/3_Logic_and_codes
DIR_CORE := core
CHALLENGES = $(shell find $(DIR_CHALLENGE) -type f -name "*.ml" -exec basename {} \; | sort)
CORE = $(shell ls -1 $(DIR_CORE))

all: $(NAME)

$(NAME): $(CHALLENGES)
	cp $(addprefix $(DIR_CORE)/, $(CORE)) .
	dune build main.exe
	cp _build/default/main.exe $(NAME)

%.ml: $(DIR_CHALLENGE_1)/%.ml
	cp $? $@
	@echo "val test : unit -> unit" > $(@:.ml=.mli)

%.ml: $(DIR_CHALLENGE_2)/%.ml
	cp $? $@
	@echo "val test : unit -> unit" > $(@:.ml=.mli)

%.ml: $(DIR_CHALLENGE_3)/%.ml
	cp $? $@
	@echo "val test : unit -> unit" > $(@:.ml=.mli)

clean:
	dune clean
	rm -f $(CHALLENGES) $(CHALLENGES:.ml=.mli) $(CORE)

fclean: clean
	rm -f $(NAME)

re: fclean all
