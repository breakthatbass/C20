  
CC=gcc
CFLAGS=-lm -std=c99 -pedantic
PREFIX=/usr/local
ifndef NAME
    NAME=dice
endif

all: dice

dice: dice.c helpers.c
	$(CC) -o $(NAME) dice.c helpers.c $(CFLAGS)

install: dice
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/$(NAME)

clean:
	rm $(NAME)