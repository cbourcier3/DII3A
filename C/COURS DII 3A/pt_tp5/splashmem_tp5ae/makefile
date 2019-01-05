
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

CFLAGS= -Wall -g2 
LDFLAGS= # a completer
EXE=splash

all: $(OBJS)
	gcc -v $(OBJS) $(LDFLAGS) -o $(EXE)

clean: 
	rm $(OBJS)
	rm $(EXE)
