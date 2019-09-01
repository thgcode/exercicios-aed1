CCFLAGS=-Wall -g

all: agenda.exe

agenda.exe: agenda.o
	gcc $(CCFLAGS) -o agenda agenda.o

agenda.o: agenda.c
	gcc $(CCFLAGS) -c agenda.c