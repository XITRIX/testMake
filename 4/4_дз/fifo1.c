#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fd,i;
	if (mknod("fifo", S_IFIFO | 0666, 0) < 0){
		printf("Can\'t create MY_FIFO\n");
		exit(-1);
	}

	if (fd = open("fifo", 0666) < 0){
		printf("Can't open MY_FIFO for writing\n");
		exit(-1);
	}
	freopen("fifo", "w", stdout);
    i = execl("/bin/ls", "ls", "-l", "/tmp/", NULL);
    if (i==-1) printf("Get out of here");
    close(fd);
    exit(0);
}