CC = gcc
all: main

main: main.o lab2.o lab2.h
	$(CC) main.o lab2.o -o main

main.o: main.c lab2.h
	$(CC) -c main.c

lab2.o: lab2.c lab2.h
	$(CC) -c lab2.c

run: main
	./main

clean:
	rm -rf *.o main

