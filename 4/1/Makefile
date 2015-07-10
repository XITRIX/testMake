NAME = 1
REQUEST = -lpthread

all: file1 file2

file1: file1.o
	gcc file1.o $(REQUEST) -o file1.a

file1.o: file1.c bin_sem.h
	gcc file1.c $(REQUEST) -c -o file1.o

file2: file2.o
	gcc file2.o $(REQUEST) -o file2.a

file2.o: file2.c bin_sem.h
	gcc file2.c $(REQUEST) -c -o file2.o