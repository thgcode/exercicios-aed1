CCFLAGS=-Wall -g

all: agenda.o
	gcc $(CCFLAGS) -o agenda agenda.o
agenda.o:
	gcc $(CCFLAGS) -c agenda.c