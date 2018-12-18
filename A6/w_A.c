#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fdAA;
    int fdAB; 
  
    char * myfifoAA = "/tmp/myfifoAA"; 
    char * myfifoAB = "/tmp/myfifoAB"; 
  
    // Creating the named file(FIFO) - mkfifo(<pathname>, <permission>) 
	mkfifo(myfifoAA, 0666); 
	mkfifo(myfifoAB, 0666); 
  
    char buffer[80]; 
    while (1) 
    { 
        fgets(buffer, 80, stdin); 

	fdAA = open(myfifoAA, O_WRONLY);         
        write(fdAA, buffer, strlen(buffer)+1); 
	close(fdAA);

    fdAB = open(myfifoAB, O_WRONLY); 
        write(fdAB, buffer, strlen(buffer)+1); 
	close(fdAB); 
  
    } 
    return 0; 
}