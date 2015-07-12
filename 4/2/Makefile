NAME = 1
REQUEST = -lpthread

all: client server

client: client.o
	gcc client.o $(REQUEST) -o client.a

client.o: client.c
	gcc client.c $(REQUEST) -c -o client.o

server: server.o
	gcc server.o $(REQUEST) -o server.a

server.o: server.c 
	gcc server.c $(REQUEST) -c -o server.o