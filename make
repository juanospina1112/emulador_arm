CC=gcc
FLAGS=-o3 -c -Wall
all:	obj
	$(CC)-o main.exe.o
obj:
$(CC) $(FLAGS)	*.c
clean
	rm main.exe
