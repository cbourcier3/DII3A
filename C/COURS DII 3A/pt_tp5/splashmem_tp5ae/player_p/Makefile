SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
CFLAGS= -Wall -I.. -fPIC
LDFLAGS= 
NAME=example3

all: $(OBJS)
	gcc -v -shared -o p1.so player1.o
	
clean: 
	rm $(OBJS)
	rm $(NAME).so
