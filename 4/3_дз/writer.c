#include "bin_sem.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>

#define KEY ((key_t)(1235))

FILE *file;

int main()
{
	int i;
	char *buf;
	char str[100];
	int ok=0;

	key_t key = ftok("reader.c",1);
	int semid = binary_semaphore_allocation(111, 0666 | IPC_CREAT);
	binary_semaphore_initialize(semid);

	int segment_id;
	char *shared_memory;
	struct shmid_ds shmbuffer;
	const int shared_segment_size = 100;

	segment_id = shmget (KEY, shared_segment_size, 0);
	if (segment_id < 0) {printf ("ошибка шаред памяти\n"); return -1;}
	shared_memory = (char*) shmat (segment_id, 0, 0);
    printf ("\nСоздал шаред память\n");

	file = fopen("100mb_file_Second", "w+");
	if (file == NULL) {printf ("ошибка файла\n"); return -1;}
    printf ("\nОткрыл файл\n");
	while (1)
    {
    	if (semid > 0)
    	{ 
    		//if(ok==1){binary_semaphore_take(semid);}
    		binary_semaphore_free(semid);
    		ok = 1;
    		if (strcmp(shared_memory, "@END!!END@") == 0) break;
    		fputs (shared_memory, file);
    		printf ("\nДошёл до семафора %d\n", semid);
    		printf ("\nПерешёл до семафора %d\n", semid);
    	}
    }
    shmdt (shared_memory);
    return 0;
}