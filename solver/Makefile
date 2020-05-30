# Makefile for 'solver' module
#
# May 2020

# variables
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../libcs50/ -I../common/
FCFLAGS = -Wall -pedantic -std=gnull -ggdb -I../libcs50/ -I../common/ 
PROG = solver

# rules
all:
	make solver


solver: solver.o ../common/functions.o ../libcs50/libcs50-given.a
	$(CC) $(CFLAGS) $^ -o $@ 

solver.o: solver.c ../common/functions.h ../libcs50/file.h


# phony targets
.PHONY: clean

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f core