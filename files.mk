
SRC_FOLDER = src/

SRC_FILES = \
			main.c \
			readline.c \

SRC = \
		$(addprefix $(SRC_FOLDER), $(SRC_FILES))
