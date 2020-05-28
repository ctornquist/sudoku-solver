#VARIABLES
CC = gcc
CFLAGS = -Wall -g -pedantic -std=c11 -ggdb -I ../libcs50
PROG = sudoku
OBJS = 
LLIBS = ../libcs50/libcs50-given.a ../common/common.a
LIBS = -lm
MAKE = make

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

############## clean  ##########
all clean:
	rm -f *~
	rm -f TAGS
	$(MAKE) -C libcs50 clean
	$(MAKE) -C common clean
	$(MAKE) -C solver clean
	# $(MAKE) -C creator clean
