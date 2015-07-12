NAME = 
REQUEST = 

all: fifo1 fifo2

fifo1: fifo1.o
	gcc fifo1.o $(REQUEST) -o fifo1.a

fifo1.o: fifo1.c
	gcc fifo1.c $(REQUEST) -c -o fifo1.o

fifo2: fifo2.o
	gcc fifo2.o $(REQUEST) -o fifo2.a

fifo2.o: fifo2.c
	gcc fifo2.c $(REQUEST) -c -o fifo2.o