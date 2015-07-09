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
	int i=0;
	char *buf;
	char str[100];

	key_t key = ftok("reader.c",1);
	int semid = binary_semaphore_allocation(111, 0666 | IPC_CREAT);
	binary_semaphore_initialize(semid);

	int segment_id;
	char *shared_memory;
	struct shmid_ds shmbuffer;
	const int shared_segment_size = 100;

	segment_id = shmget (KEY, shared_segment_size, IPC_CREAT | 0666);
	if (segment_id < 0) {printf ("ошибка шаред памяти\n"); return -1;}
	shared_memory = (char*) shmat (segment_id, 0, 0);
    printf ("\nСоздал шаред память\n");

	file = fopen("kek", "r");
	if (file == NULL) {printf ("ошибка файла\n"); return -1;}
    printf ("\nОткрыл файл\n");
    binary_semaphore_take(semid);
	while (1)
    {
    	if (semid > 0)
    	{
    		binary_semaphore_take(semid);
    		buf = fgets (str, 100, file);
    		if (buf == NULL)
    		{
    			if ( feof (file) != 0)
    			{  
    				printf ("\nЧтение файла закончено\n");
    				break;
    			}
    			else
    			{
    				printf ("\nОшибка чтения из файла\n");
    				break;
    			}
    		}
    		sprintf (shared_memory, "%s", str);
    		//if (i==1) {binary_semaphore_free(semid);
    		//printf ("\nДошёл до семафора %d\n", semid);}
    		i++;
    	}
    }
    sprintf (shared_memory, "@END!!END@");
    binary_semaphore_take(semid);
    return 0;
}