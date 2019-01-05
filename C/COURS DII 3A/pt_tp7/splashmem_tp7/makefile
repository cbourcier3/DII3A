
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
CFLAGS= -Wall -g2 -fPIC -DDEBUG
LDFLAGS= -ldl -lSDL2
EXE=splash

all: $(OBJS)
	gcc -v $(OBJS) $(LDFLAGS) -o $(EXE)

liba: $(OBJS)
	ar crs libsplash.a actions.o main.o player.o world.o

libso: $(OBJS)
	gcc -v -shared -o libsplash.so actions.o main.o player.o world.o

clean: 
	rm -f $(OBJS)
	rm $(EXE)
