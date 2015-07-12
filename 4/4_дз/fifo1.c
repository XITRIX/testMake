#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd;
    char ab[800];
    if ((mknod("fifo", S_IFIFO|0666, 0)) < 0) 
    {
       	printf("Ошибка FIFO\n");
      	exit(1);
    }

    fd = open("fifo", O_RDONLY);
	read(fd, &ab, sizeof(ab));
    printf("%s", ab);
    close(fd);

    system("rm fifo");

    return(0);
}

            