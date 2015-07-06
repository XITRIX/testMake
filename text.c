#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	pid = fork();
	int a[2];
	pipe(a);
	if(pid == -1){
		printf("ERROR");
	}
	else if(pid == 0){
		int i;
		printf("child PID: %d\n", getpid());
		close(a[0]);
		write(a[1],"lol",4);
		wait(&i);
	}
	else{
		char *ab;
		close(a[1]);
		read(a[0],ab, 4);
		printf("%s\n",ab);
		exit(0);
	}
	return 0;
}
