# -*- MakeFile -*-

OBJECTS = myBank.o
CC = gcc
AR = ar
CFLAGS = -Wall


main: main.o libmyBank.a
	$(CC) $(CFLAGS) -o main main.o libmyBank.a
	
main.o: main.c myBank.h
	$(CC) $(CFLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c myBank.c

libmyBank.a: $(OBJECTS)
	$(AR) -rcs libmyBank.a $(OBJECTS)

.PHONY: clean all

clean:
	rm -f *.o *.a *.so main