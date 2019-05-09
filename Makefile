#                    (                           )
#              ) )( (                           ( ) )( (
#           ( ( ( )  ) )                     ( (   (  ) )(
#          ) )     ,,\\\                     ///,,       ) (
#       (  ((    (\\\\//                     \\////)      )
#        ) )    (-(__//                       \\__)-)     (
#       (((   ((-(__||                         ||__)-))    ) )
#      ) )   ((-(-(_||           ```\__        ||_)-)-))   ((
#      ((   ((-(-(/(/\\        ''; 9.- `      //\)\)-)-))    )
#       )   (-(-(/(/(/\\      '';;;;-\~      //\)\)\)-)-)   (   )
#    (  (   ((-(-(/(/(/\======,:;:;:;:,======/\)\)\)-)-))   )
#        )  '(((-(/(/(/(//////:%%%%%%%:\\\\\\)\)\)\)-)))`  ( (
#       ((   '((-(/(/(/('uuuu:WWWWWWWWW:uuuu`)\)\)\)-))`    )
#         ))  '((-(/(/(/('|||:wwwwwwwww:|||')\)\)\)-))`    ((
#      (   ((   '((((/(/('uuu:WWWWWWWWW:uuu`)\)\))))`     ))
#            ))   '':::UUUUUU:wwwwwwwww:UUUUUU:::``     ((   )
#              ((      '''''''\uuuuuuuu/``````         ))
#               ))            `JJJJJJJJJ`           ((
#                 ((            LLLLLLLLLLL         ))
#                   ))         ///|||||||\\\       ((
#                     ))      (/(/(/(^)\)\)\)       ((
#                      ((                           ))
#                        ((                       ((
#                          ( )( ))( ( ( ) )( ) (()

NAME = irc_udp

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

CC = gcc

INC_FOLDER = inc/

CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror
IFLAGS = -I $(INC_FOLDER)
LFLAGS = -lncurses -lm
FLAGS = $(CFLAGS) $(IFLAGS)

SRC := ""
include files.mk # On charge la liste des fichiers depuis le fichier files.mk

OBJ = $(SRC:%.c=%.o)

#################################### COMPILATION ###############################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@printf "\\t%sLD%s\\t" "$(_CYAN)" "$(_END)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@printf "%s\\n" "$@"

%.o: %.c
	@printf "\\t%sCC%s\\t" "$(_GREEN)" "$(_END)"
	@$(CC) $(FLAGS) -c $? -o $@
	@printf "%s\\n" "$?"

.PHONY: clean
clean:
	@rm -rf $(OBJ)
	@echo "Objects removed"

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME)
	@echo "Program $(NAME) removed"

.PHONY: re
re: fclean all

################################### SUBMODULE #################################

.PHONY: submodule
submodule:
	git submodule init
	git submodule update


################################### UNCRUSTIFY ################################

UNCRUSTIFY = uncrustify/build/uncrustify
CONFIG_UNCRUSTIFY = .UNCRUSTIFY.cfg

$(UNCRUSTIFY): submodule
	mkdir -p uncrustify/build
	(cd uncrustify/build && cmake ..)
	make -C uncrustify/build -j8

.PHONY: uncrustify_apply
uncrustify_apply: $(UNCRUSTIFY)
	$(UNCRUSTIFY) -c $(CONFIG_UNCRUSTIFY) --replace --no-backup --mtime $(ALL_FILES)

.PHONY: uncrustify_check
uncrustify_check: $(UNCRUSTIFY)
	$(UNCRUSTIFY) -c $(CONFIG_UNCRUSTIFY) --check $(ALL_FILES)
