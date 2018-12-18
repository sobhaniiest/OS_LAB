#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

#define size 10

struct Memory
{
  int mutex,r,f,c;
  int data;
};

void semwait(int *n)
{
  while(*n>=9 );
  ( (*n)+1)%size;
}

void semmutwait(int *n)
{
  while(*n<=0);
  (*n)--;
}
void semmutsig(int *n)
{
  (*n)++;
}

void semsig(int *n)
{
  ((*n)+1)%size;
}

void main(int argc, char *argv[])
{
  key_t KEY = 50;
  int ShmID,item;
  struct Memory *PTR;  

  ShmID = shmget(KEY, sizeof(struct Memory), IPC_CREAT | 0666);
  
  printf("%d\n",ShmID);

  PTR = (struct Memory *) shmat(ShmID, NULL, 0);
  
  PTR->mutex = 1;
  PTR->r = 0;
  PTR->f = 0;
  PTR->c = 0;
  
  while(1)
  {
    printf("##\n");
    item = rand()%100;
    semwait(&(PTR->c));
    semmutwait(&(PTR->mutex));
    printf("Produced : %d",item);
    PTR->data = item;
    sleep(1);
    semmutsig(&(PTR->mutex));
    semsig(&(PTR->f));
  }

}