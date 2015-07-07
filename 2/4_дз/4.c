#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_THREADS 2
#define PassWord "12345qwerty"

int test;
char Pass[30];
char PassTrue[30];

void *in(void *num)
{
	long t_num;
	int i;
	t_num = (long) num;
	printf("Введите пароль: ");
	scanf("%s",Pass);
}

void *out(void *num)
{
	long t_num;
	int i;
	t_num = (long) num;
	while(strcmp(Pass,"")==0)
		sleep(0,5);
	if (strcmp(Pass,PassTrue)==0)
		printf("Пароль верен\n");
	else printf("Пароль НЕверен\n");

}

int main(int argc, char*argv[])
{
	strcpy(PassTrue,PassWord);
	strcpy(Pass,"");
	pthread_t threads[NUM_THREADS];
	int rc1,rc2;
	long t;
	test = 5;
	rc1=pthread_create(&threads[0],NULL, in, (void *)0);
	if(rc1){
		printf("ERROR: %d\n",rc1);
		exit(-1);
	} 
	rc2=pthread_create(&threads[1],NULL, out, (void *)1);
	if(rc2){
		printf("ERROR: %d\n",rc2);
		exit(-1);
	} 
	
	for (t=0;t<NUM_THREADS;t++){
		pthread_join(threads[t],NULL);
	}
	return 0;
}
