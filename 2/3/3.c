#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 2

int test;

void *one(void *num)
{
	long t_num;
	int i;
	t_num = (long) num;
	printf("Hello, I am thread num: %ld\n", pthread_self());
	for(i=0;i<10;i++){	
		printf("Int = %d\n", test);
		test++;
		printf("Now int = %d\n", test);
		sleep(1);
	}
}

void *two(void *num)
{
	long t_num;
	int i;
	t_num = (long) num;
	printf("Hello, I am thread num: %ld\n", pthread_self());
	for(i=0;i<10;i++){
		printf("Int = %d\n", test);
		test--;
		printf("Now int = %d\n", test);
		sleep(1);
	}
}

int main(int argc, char*argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc1,rc2;
	long t;
	test = 5;
	printf("In main: creating thread 0");
	rc1=pthread_create(&threads[0],NULL, one, (void *)0);
	if(rc1){
		printf("ERROR: %d\n",rc1);
		exit(-1);
	} 
	printf("In main: creating thread 1");
	rc2=pthread_create(&threads[1],NULL, two, (void *)1);
	if(rc2){
		printf("ERROR: %d\n",rc2);
		exit(-1);
	} 
	
	for (t=0;t<NUM_THREADS;t++){
		pthread_join(threads[t],NULL);
		printf("Thread #%ld finished\n",t);
	}
	return 0;
}
