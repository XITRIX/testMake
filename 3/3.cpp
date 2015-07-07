#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

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
        int i;
        //char ab[10];
        dup2(a[1],1);
        i = execl("/bin/ls", "ls", "-l", "/tmp/", NULL);
        if (i==-1) cout << "Get out of here" << endl;
        exit(0);
    }
    else{
        char *buf;
        char ab[1000];
        char *cur[1000][1000];
        char *ch[1000][1000];
        int i=0,j=0,x,c,miss=0,v;
        close(a[1]);
        read(a[0],ab, 1000);

            buf = strtok(ab, " \n");
            while (buf != NULL)
                {
                    //cout << buf;
                    miss++;
                    if (miss > 2){
                        ch[j][i]=buf; i++;
                        if (i==9) {j++;i=0;}
                    }
                    buf=strtok(NULL," \n");
                }
            /*/Сортировка по алфавиту
            for(x=0;x<j-1;x++)
                    for(c=x+1;c<j;c++)
                        if(strcmp(ch[x][8],ch[c][8])>0)
                        {
                            for (v=0;v<9;v++){
                                strcpy(cur[1][v],ch[x][v]);
                                strcpy(ch[x][v],ch[c][v]);
                                strcpy(ch[c][v],cur[1][v]);
                                cout << cur[1][v];
                            }
                        }
            /*/

        for (x=0;x<j;x++){
            for (c=0;c<9;c++)
                cout  << ch[x][c] << " ";
            cout << endl;
        }
        //for (c=0;c<8;c++)
        //strcpy(cur[1][3],ch[1][3]);
        if(strcmp(ch[x][8],ch[c][8])>0)
        cout << endl << endl << "kek" << " ";
        wait(0);
    }
    return 0;
}

