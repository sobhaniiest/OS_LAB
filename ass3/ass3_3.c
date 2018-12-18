#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

void *thread1(void *vargp)
{
    char str[200];
    pthread_t t = pthread_self();
    sprintf(str,"Thread ID = %ld \n",(long int)t);
    write(1,str,strlen(str));
    return NULL;
}

int main()
{
    int d,k;
    char s[200];
    
    pthread_t tid1;
    pthread_create(&tid1, NULL, thread1, NULL);
    getchar();
    d = pthread_detach(tid1);
    sprintf(s,"Pthread_detach status : %d \n",d);
    write(1,s,strlen(s));
    getchar();
    k = pthread_kill(tid1,1);
    char *msg = strerror(k);
    write(1,msg,strlen(msg));
    
    printf("\n");
    exit(0);
}


