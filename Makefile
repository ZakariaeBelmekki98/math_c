CC=gcc
CFLAGS= -Wall -g 
DEPS=LinAlg.h SigProc.h Complex.h
LIBS=-lm
SRCS=Main.c LinAlg.c SigProc.c Complex.c
OBJS=$(SRCS:.c=.o)
MAIN=main

.PHONY: clean

all: $(MAIN)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

clean:
	rm *.o $(MAIN)