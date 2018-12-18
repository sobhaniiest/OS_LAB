#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>

int main() 
{
   int pid, pidmax = 0;
   while(1) 
   {
       pid = fork();
       pidmax = getpid();
       if(pid == 0)
       {
           if(pidmax < getpid())
               pidmax = getpid();
           //printf("pid: %d, max: %d\n", getpid(), pidmax);  
           return 0;
       }

       if(pid == -1) 
       {
        printf("Maximum process: %d\n", pidmax);
        exit(-1);
       }
    }
    return 0;
}

