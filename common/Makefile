# Makefile for 'common' module
#
# May 2020

# variables
CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I ../common/
PROG = functions

# rules

functions.o: functions.h ../libcs50/file.h


# phony targets
.PHONY: clean


clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f stocks