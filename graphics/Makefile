#VARIABLES
CC = gcc
GRAPHICSFLAGS = -DGRAPHICS
CFLAGS = $(GRAPHICSFLAGS) -Wall -g -pedantic -std=c11 -ggdb -I libcs50/ -I common/
PROG = sudoku
OBJS = sudoku.o common/functions.o
LLIBS = libcs50/libcs50-given.a 
LIBS = -lm
MAKE = make


#RULES
all: sudoku

$(PROG): $(OBJS) $(LLIBS)
	$(CC) $(GRAPHICSFLAGS) $(CFLAGS) $^ $(LIBS) -o $@

functions.o: common/functions.h
sudoku.o: common/functions.h

#PHONY
.PHONY: clean

############## clean  ##########
clean:
	rm -f *~ *.o *.dSYM
	rm -f TAGS
	rm -f graphics
	rm -f graphicsOut
	$(MAKE) -C libcs50 clean
	$(MAKE) -C common clean
