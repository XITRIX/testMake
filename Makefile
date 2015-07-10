all:
	make -f './1/1/Makefile'
	make -f './1/2_дз/Makefile'
	make -f './1/3_дз/Makefile'
	make -f './2/1/Makefile'
	make -f './2/2/Makefile'
	make -f './2/3/Makefile'
	make -f './2/4_дз/Makefile'
	make -f './3/1/Makefile'
	make -f './3/2/Makefile'
	make -f './3/3_дз/Makefile'
	make -f './4/1/Makefile'
	make -f './4/2/Makefile'
	make -f './4/3_дз/Makefile'
	make -f './5/1/Makefile'
	make -f './5/2/Makefile'
	
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