# Makefile for 'solver' module
#
# May 2020

# variables
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../libcs50/ 
FCFLAGS = -Wall -pedantic -std=gnull -ggdb -I../libcs50/ 
PROG = solver

# rules
all:
	make solver


solver: solver.o ../libcs50/libcs50-given.a
	$(CC) $(CFLAGS) $^ -o $@ 

solver.o: solver.c ../libcs50/hashtable.h ../libcs50/file.h


# phony targets
.PHONY: clean

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f core