CC=gcc
CFLAGS=-W -Wall -pedantic 
LDFLAGS=-lm
EXEC=robot.out

all: $(EXEC)

robot.out: robot.o main.o
	$(CC) -o robot.out robot.o main.o $(LDFLAGS)

robot.o: robot.c
	$(CC) -o robot.o -c robot.c $(CFLAGS)

main.o: main.c robot.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)