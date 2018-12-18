#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct Memory 
{
  int status;
  char data[100];
};

void main(void)
{

  key_t KEY1 = 300, KEY2 = 700;
  int ShmID1,ShmID2;
  struct Memory *PTR1,*PTR2;

  ShmID1 = shmget(KEY1, sizeof(struct Memory), IPC_CREAT | 0666);
  ShmID2 = shmget(KEY2, sizeof(struct Memory), IPC_CREAT | 0666);

  printf("%d %d\n",ShmID1,ShmID2);
  
  PTR1 = (struct Memory *) shmat(ShmID1, NULL, 0);
  PTR2 = (struct Memory *) shmat(ShmID2, NULL, 0);

  while(1)
  {

    while(PTR1->status == 0);
    printf("B : %s\n", PTR1->data);
    while(PTR2->status == 1);
    printf("B >>");
    scanf("%s",PTR2->data);
    PTR1->status = 0;
    PTR2->status = 1;
  }
 
}