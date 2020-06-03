# Makefile for 'creator' module
#
# May 2020

# variables
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../libcs50/ 
FCFLAGS = -Wall -pedantic -std=gnull -ggdb -I../libcs50/ 
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../libcs50/ -I../common/
FCFLAGS = -Wall -pedantic -std=gnull -ggdb -I../libcs50/ -I../common/ 
PROG = creator

# rules
all:
	make creator


creator: creator.o ../common/functions.o ../libcs50/libcs50-given.a
	$(CC) $(CFLAGS) $^ -o $@ 

creator.o: creator.c ../common/functions.h ../libcs50/file.h


# phony targets
.PHONY: clean

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f core