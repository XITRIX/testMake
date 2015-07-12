MODULES = 1/1 1/2_дз 1/3_дз 2/1 2/2 2/3 2/4_дз 2/5_дз 3/1 3/2 3/3_дз 4/1 4/2 4/3_дз 3/3_дз 5/1 5/2
all:
	for dir in $(MODULES); do \
		(cd $$dir; ${MAKE} all); \
	done
	
ipad:
	gcc './1/1/1.c' -o ./1/1/run.a
	g++ './1/2_дз/2.cpp' -o ./1/2_дз/run.a
	g++ './1/3_дз/3.cpp' -o ./1/3_дз/run.a
	gcc './2/1/1.c' -o ./2/1/run.a
	gcc './2/2/2.c' -o ./2/2/run.a
	gcc './2/3/3.c' -o ./2/3/run.a
	gcc './2/4_дз/4.c' -o ./2/4_дз/run.a
	gcc './3/1/main.c' -o ./3/1/run.a
	gcc './3/2/2.c' -o ./3/2/run.a
	gcc './3/3_дз/3.c' -o ./3/3_дз/run.a
	gcc './4/1/file1.c' './4/1/bin_sem.c' -o ./4/1/file1.a
	gcc './4/1/file2.c' './4/1/bin_sem.c' -o ./4/1/file2.a
	gcc './4/2/client.c' -o ./4/2/client.a
	gcc './4/2/server.c' -o ./4/2/server.a
	gcc './4/3_дз/reader.c' -o ./4/3_дз/reader.a
	gcc './4/3_дз/writer.c' -o ./4/3_дз/writer.a
	gcc './5/1/signal.c' -o ./5/1/signal.a
	gcc './5/2/timer.c' -o ./5/2/timer.a
	
clear:
	for dir in $(MODULES); do \
		(cd $$dir; rm *.a *.o); \
	done