#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <stdio.h> 
#include <string.h> 

void *th_funcAA(void * arg); 
void *th_funcBA(void * arg); 

// global 
    int fdAA;
    int fdBA; 
  
    char * myfifoAA = "/tmp/myfifoAA"; 
    char * myfifoBA = "/tmp/myfifoBA"; 
    char str[80]; 

  
int main() 
{ 
  
    // Creating the named file(FIFO) - mkfifo(<pathname>, <permission>) 
    mkfifo(myfifoAA, 0666); 
    mkfifo(myfifoBA, 0666);   

  pthread_t thread[2];
  pthread_create(&thread[0],NULL,th_funcAA,NULL); 
  pthread_create(&thread[1],NULL,th_funcBA,NULL);
  pthread_join(thread[0],NULL);   
  pthread_join(thread[1],NULL);   
  return 0;
}

void *th_funcAA(void * arg)
{  
	while(1)
	{
	fdAA = open(myfifoAA,O_RDONLY); 
        read(fdAA, str, 80); 
        printf("me:> %s", str); 
        close(fdAA); 

	}
}

void *th_funcBA(void * arg)
{  
    while (1) 
    { 
        fdBA = open(myfifoBA,O_RDONLY); 
        read(fdBA, str, 80); 
        printf("B:> %s", str); 
        close(fdBA); 
    } 

}