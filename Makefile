CC=g++
CFLAGS=-Wall -Wextra -std=c++20 -pedantic -ggdb
LIBS=-lraylib

all: main.cc ui.cc button.cc canvas.cc
	$(CC) $(CFLAGS) $(LIBS) $^ -o out
	./out
