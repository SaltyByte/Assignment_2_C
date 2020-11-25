# -*- MakeFile -*-

OBJECTS = myBank.o
CC = gcc
AR = ar
CFLAGS = -Wall


mybanks: libmyBank.a
mybankd: libmyBank.so
all: mains maind mybankd mybanks


mains: main.o libmyBank.a
	$(CC) $(CFLAGS) -o mains main.o libmyBank.a
	
maind: main.o libmyBank.so
	$(CC) $(CFLAGS) -o maind main.o ./libmyBank.so

main.o: main.c myBank.h
	$(CC) $(CFLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c myBank.c

libmyBank.a: $(OBJECTS)
	$(AR) -rcs libmyBank.a $(OBJECTS)

libmyBank.so: $(OBJECTS)
	$(CC) -fPIC -shared -o libmyBank.so $(OBJECTS)

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maind