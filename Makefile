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

CFLAGS = -g -Wall -Wextra -Werror
IFLAGS = -I $(INC_FOLDER)
LFLAGS =
FLAGS = $(CFLAGS) $(IFLAGS)

SRC := ""
include files.mk # On charge la liste des fichiers depuis le fichier files.mk

OBJ = $(SRC:%.c=%.o)

#################################### COMPILATION ###############################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@printf "Program %s... " "$(NAME)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@printf "%scompiled%s\\n" "$(_CYAN)" "$(_END)"

%.o: %.c
	@printf "Compiling %s... " "$?"
	@$(CC) $(FLAGS) -c $? -o $@
	@printf "%scompiled%s\\n" "$(_GREEN)" "$(_END)"

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