#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	pid_t pid;
	int a[2];
	pipe(a);
	pid = fork();
	if(pid == -1){
		cout << "ERROR" << endl;
	}
	else if(pid == 0){
		char ab[10];
		int i;
		close(a[1]);
		i = read(a[0],ab, 10);
		cout << "Res=" << ab << endl;
		exit(0);
		
	}
	else{
		int i;
		char ab[10];
		cout << "child PID: " << getpid() << endl;
		close(a[0]);
		cout << "Введите 10и символьный текст:" << endl;	
		cin >> ab;
		i = write(a[1],ab,10);
		cout << "Parent cnt=" << i << endl;		
		wait(&i);
	}
	return 0;
}
