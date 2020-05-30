# Makefile for 'common' module
#
# May 2020

# variables
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I ../common/
PROG = functionstest

# rules

functions.o: functions.h ../libcs50/file.h


# phony targets
.PHONY: clean

test: ./functions.o ../libcs50/file.o
	$(CC) $(FLAGS) $^ functionstest.c -o $(PROG)
	./$(PROG)

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f stocks
	rm -f core