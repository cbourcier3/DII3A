SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
CFLAGS= -Wall -I.. -fPIC
LDFLAGS= 
NAME=example

all: $(OBJS)
	gcc -shared -o $(NAME).so $(OBJS)

clean: 
	rm $(OBJS)
	rm $(NAME).so
