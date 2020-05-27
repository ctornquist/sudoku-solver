#VARIABLES
CC = gcc
CFLAGS = -Wall -g -pedantic -std=c11 -ggdb -I ../libcs50
PROG = sudoku
OBJS = 
LLIBS = ../libcs50/libcs50-given.a ../common/common.a
LIBS = -lm

#RULES
$(PROG): $(OBJS) $(LLIBS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@


#PHONY
.PHONY: test clean

test: 
	

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f core
