OBJS=main.o cards.o
CFLAGS=-Wall
EXE=cards
CC=gcc

all: ${OBJS}
	${CC} ${OBJS} -o ${EXE}

clean:
	rm ${OBJS}

mrproper: clean
	rm ${EXE}