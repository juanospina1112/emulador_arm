CC = gcc
CFLAGS = -O3 -c -Wall

all:	obj
	$(CC) -o main.exe *.o
	rm -f *.o

obj:
	$(CC) $(CFLAGS)	*.c

clean:
	rm -f main.exe
