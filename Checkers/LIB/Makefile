CC = g++
CFLAGS = -c

all:libcheckers.a

checkers.o : checkers.cpp checkers.h
	$(CC) $(CFLAGS) -o $@ $<

source.o : source.cpp source.h
	$(CC) $(CFLAGS) -o $@ $<
	
libcheckers.a : source.o checkers.o
	ar rs $@ $^
clean:
	rm -fr libcheckers.a *.o
