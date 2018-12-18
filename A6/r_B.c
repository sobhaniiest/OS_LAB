#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <pthread.h> 

void *th_funcBB(void * arg); 
void *th_funcAB(void * arg); 

    int fdBB;
    int fdAB; 
  
    char * myfifoBB = "/tmp/myfifoBB"; 
    char * myfifoAB = "/tmp/myfifoAB"; 
    char str[80]; 

  
int main() 
{ 
  
    // Creating the named file(FIFO) - mkfifo(<pathname>, <permission>) 
    mkfifo(myfifoBB, 0666); 
    mkfifo(myfifoAB, 0666);   

  pthread_t thread[2];
  pthread_create(&thread[0],NULL,th_funcBB,NULL); 
  pthread_create(&thread[1],NULL,th_funcAB,NULL);
  pthread_join(thread[0],NULL);   
  pthread_join(thread[1],NULL);   
  return 0;
}

void *th_funcBB(void * arg)
{  
	while(1)
	{
	fdBB = open(myfifoBB,O_RDONLY); 
        read(fdBB, str, 80); 
        printf("me:> %s", str); 
        close(fdBB); 

	}
}

void *th_funcAB(void * arg)
{  
    while (1) 
    { 
      fdAB = open(myfifoAB,O_RDONLY); 
        read(fdAB, str, 80); 
        printf("A:> %s", str); 
        close(fdAB); 
    } 

}