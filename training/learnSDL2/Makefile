NAME = t.out

CC ?= gcc

CFLAGS_SDL = $(shell sdl2-config --cflags)
CFLAGS = -Wall -Werror -Wextra $(CFLAGS_SDL)

LDFLAGS_SDL = $(shell sdl2-config --libs)
LDFLAGS = $(LDFLAGS_SDL)

SRC = \
	main.c \

OBJ = $(SRC:%.c=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(NAME)
	rm -rf $(OBJ)
