// ps -o pid,psr,comm -p (pid)
// top -H -p (pid)
// f - select T

#define _GNU_SOURCE
#include <sched.h>   
#include <pthread.h> 
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void *thread1(void *vargp)
{
    char str[200];
    pthread_t t = pthread_self();
    sprintf(str,"Thread ID = %ld\n",(long int)t);
    write(1,str,strlen(str));
    
    cpu_set_t cpuset; 
    int cpu = 1;
    CPU_ZERO(&cpuset);       //clears the cpuset
    CPU_SET( cpu , &cpuset); 
  
    sched_setaffinity(getpid(), sizeof(cpuset), &cpuset);

    while (1);
    return 0;   
}

void *thread2(void *vargp)
{
    char str[200];
    pthread_t t = pthread_self();
    sprintf(str,"Thread ID = %ld\n",(long int)t);
    write(1,str,strlen(str));
    
    cpu_set_t cpuset; 
    int cpu = 3;
    CPU_ZERO(&cpuset);       //clears the cpuset
    CPU_SET( cpu , &cpuset); 
  
    sched_setaffinity(getpid(), sizeof(cpuset), &cpuset);

    while (1); 
    return 0;   
}

int main(void) 
{
  pthread_t tid1,tid2;
  pthread_create(&tid1,NULL,thread1,NULL); 
  pthread_create(&tid2,NULL,thread2,NULL);

  pthread_join(tid1,NULL);   
  pthread_join(tid2,NULL);   
  return 0;
}
