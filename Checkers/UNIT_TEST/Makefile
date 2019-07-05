CC = g++
CFLAGS = -c

all:test

test.o : test.cpp
	$(CC) $(CFLAGS) -I../LIB/ -o $@ $<

test : test.o
	$(CC) -o $@ $^ ../LIB/libcheckers.a

clean:
	rm -fr *.o test
