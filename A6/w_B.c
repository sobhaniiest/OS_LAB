#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fdBB;
    int fdBA; 
  
    char * myfifoBB = "/tmp/myfifoBB"; 
    char * myfifoBA = "/tmp/myfifoBA"; 
  
    // Creating the named file(FIFO) - mkfifo(<pathname>, <permission>) 
	mkfifo(myfifoBB, 0666); 
	mkfifo(myfifoBA, 0666); 
  
    char buffer[80]; 
    while (1) 
    { 
        fgets(buffer, 80, stdin); 

        fdBB = open(myfifoBB, O_WRONLY); 
        write(fdBB, buffer, strlen(buffer)+1); 
	close(fdBB);

        fdBA = open(myfifoBA, O_WRONLY); 
        write(fdBA, buffer, strlen(buffer)+1); 
	close(fdBA); 
    } 
    return 0; 
}