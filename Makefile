CC = gcc
FLAGS = -Wall


all: frequency
	
frequency : trie.o main.o
	$(CC) $(FLAGS) -o frequency main.o trie.o

main.o : main.c 
	$(CC) $(FLAGS) -c main.c
	
trie.o : trie.c trie.h
	$(CC) $(FLAGS) -c trie.c

.PHONY: clean all 

clean: 
	rm -f *.o  frequency
