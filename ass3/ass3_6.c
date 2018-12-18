#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>

void *ret;
void *tret;
pthread_t tid1;
void *thread1(void *vargp)
{
    char str[200];
    (*(int*)vargp)++;
    pthread_t t = pthread_self();
    sprintf(str,"Thread ID = %ld \n",(long int)t);
    write(1,str,strlen(str));
    pthread_exit(vargp);

    
}

int main()
{
    int j=90;
    pthread_create(&tid1, NULL, thread1, &j);
    //getchar();
    printf("Join = %d\n",pthread_join(tid1,&tret));
    
    printf("#%d $%d\n",j,(*(int*)tret));
    //getchar();
}


