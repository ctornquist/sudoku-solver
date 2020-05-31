#VARIABLES
CC = gcc
CFLAGS = -Wall -g -pedantic -std=c11 -ggdb -I libcs50/ -I common/
PROG = sudoku
PROG1 = fuzztest
OBJS = sudoku.o common/functions.o
OBJS1 = fuzztest.o common/functions.o
LLIBS = libcs50/libcs50-given.a
LIBS = -lm
MAKE = make

#RULES
all: fuzztest sudoku

$(PROG): $(OBJS) $(LLIBS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(PROG1): $(OBJS1) $(LLIBS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

functions.o: common/functions.h
sudoku.o: common/functions.h

#PHONY
.PHONY: test clean

test: testing.sh
	./testing.sh
	
#clean:
	#rm -f *~ *.o *.dSYM
	#rm -f $(PROG)
	#rm -f core

############## clean  ##########
clean:
	rm -f *~ *.o *.dSYM
	rm -f TAGS
	$(MAKE) -C libcs50 clean
	$(MAKE) -C common clean
	$(MAKE) -C solver clean
	$(MAKE) -C creator clean
