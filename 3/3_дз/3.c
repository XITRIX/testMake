#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define THREADS_NUM 10

pthread_mutex_t mut;
pthread_mutex_t mut2;
pthread_cond_t Wmut;
int timer=0;

void *thread(void *t)
{
	int i;
	pthread_mutex_lock(&mut);
	i = timer;
	timer++;
	pthread_mutex_unlock(&mut);
	printf("Я, #%d, буду спать %d секунд\n",i,timer);
	sleep(timer);
	printf("#%d проснулся!\n",i);
	
	if (i == THREADS_NUM-1) 
	{ 
		printf("%d, %d\n",i,*((int*)t));
		pthread_cond_broadcast(&Wmut);
	}
	
	printf("#%d жду!\n",i);
	pthread_mutex_lock(&mut);
	pthread_cond_wait(&Wmut,&mut2);
	pthread_mutex_unlock(&mut);
	printf("#%d дроп!\n",i);
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[THREADS_NUM];
	pthread_mutex_init(&mut, NULL);
	pthread_cond_init (&Wmut, NULL);
	int i,rc[THREADS_NUM];
	for (i=0;i<THREADS_NUM;i++){
		printf("Создаю поток #%d\n",i);
		rc[i] = pthread_create(&threads[i], NULL, thread, (void *)&i);
        if (rc[i]) {
            printf("ERROR: %d\n", rc[i]);
            exit(-1);
        }
	}
	for (i=0;i<THREADS_NUM;i++){
		pthread_join(threads[i],NULL);
		printf("Поток #%d завершил работу\n", i);
	}
	pthread_mutex_destroy(&mut);
	pthread_cond_destroy(&Wmut);
}
