# Makefile for 'creator' module
#
# May 2020

# variables
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../libcs50/ 
FCFLAGS = -Wall -pedantic -std=gnull -ggdb -I../libcs50/ 
PROG = creator

# rules
all:
	make creator


solver: creator.o ../libcs50/libcs50-given.a
	$(CC) $(CFLAGS) $^ -o $@ 

# creator.o: creator.c ../libcs50/hashtable.h


# phony targets
.PHONY: clean

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f core