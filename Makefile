CFLAGS=-c -g -Wall -Werror
CC=gcc

all: voteDB voteVM

voteDB: voteDB.o
	$(CC) -o voteDB voteDB.o -lm

voteVM: voteVM.o
	$(CC) -o voteVM voteVM.o

clean:
	rm -f *.o voteDB voteVM

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<