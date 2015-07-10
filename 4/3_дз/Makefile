NAME = 1
REQUEST = 

all: reader writer

reader: reader.o
	gcc reader.o $(REQUEST) -o reader.a

reader.o: reader.c bin_sem.h
	gcc reader.c $(REQUEST) -c -o reader.o

writer: writer.o
	gcc writer.o $(REQUEST) -o writer.a

writer.o: writer.c bin_sem.h
	gcc writer.c $(REQUEST) -c -o writer.o