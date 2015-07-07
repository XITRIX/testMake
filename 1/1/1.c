#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int a[2];
	pipe(a);
	pid = fork();
	if(pid == -1){
		printf("ERROR");
	}
	else if(pid == 0){
		char ab[4];
		int i;
		close(a[1]);
		i = read(a[0],ab, 4);
		printf("Res=%s\n",ab);
		exit(0);
		
	}
	else{
		int i;
		printf("child PID: %d\n", getpid());
		close(a[0]);
		printf("p1\n");		
		i = write(a[1],"lol",4);
		printf("Parent cnt=%d\n", i);		
		wait(&i);
	}
	return 0;
}
