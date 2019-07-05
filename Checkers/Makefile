CC = g++
CFLAGS = -c

all:start

start.o : start.cpp
	$(CC) $(CFLAGS) -ILIB/ -o $@ $<

start : start.o
	$(CC) -o $@ $^ LIB/libcheckers.a

clean:
	rm -fr *.o start
