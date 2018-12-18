#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <sys/wait.h>

void *thread(void *vargp)
{
    char str[200];
    pthread_t t = pthread_self();
    sprintf(str,"Thread ID = %ld\n",(long int)t);
    write(1,str,strlen(str));   
}

int main()
{
    struct  timeval start,end;
    pthread_t tid;
    pid_t p;
    double thr,pro;

    gettimeofday(&start,0);
    pthread_create(&tid, NULL, thread, NULL);
    gettimeofday(&end,0);

    thr = ((end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec));
    printf("Time to create a thread: %0.6lfus\n",thr);

    gettimeofday(&start,0);
    p = fork();
    gettimeofday(&end,0); 
    
    if(p>0)
      wait(NULL); 
      
    pro = ((end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec));
    printf("Time to create a process: %0.6lfus\n",pro); 

}

