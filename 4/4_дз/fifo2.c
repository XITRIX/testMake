#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int ex, fd;
	
	if((fd = open("fifo", O_WRONLY)) < 0) 
	{
	    printf("Ошибка FIFO\n");
	    exit(1);
	}
	
    dup2(fd,1);
	ex = execl("/bin/ls","ls", "-l", "/tmp/", NULL);
	close(fd);
	return(0);
}