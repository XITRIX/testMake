#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    char *buf;
    char ab[1000];
    char *cur[100][100];
    char *ch[100][100];
    int i=0,j=0,x,c,miss=0,v;
	int fd,a;

	

	while(1){
	if(fd = open("fifo", O_RDONLY) < 0){
		printf("Can't open MY_FIFO for writing\n");
		exit(-1);
	}
		a = read(fd,&ab, 800);
		if (a==-1) {printf("LOH"); exit(1);}
	    printf("%s",ab);
	    close(fd);
	}
}

            /*buf = strtok(ab, " \n");
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
            /Сортировка по алфавиту
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
            /

        for (x=0;x<j;x++){
            for (c=0;c<9;c++)
                printf("%s ",ch[x][c]);
            printf("\n");
        }*/
        //for (c=0;c<8;c++)
        //strcpy(cur[1][3],ch[1][3]);
        //cout << endl << endl << cur[1][3] << " ";
