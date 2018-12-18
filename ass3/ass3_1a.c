#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <string.h>
#include <linux/unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <errno.h>

int main()
{

    int f,firstpipe[2],secondpipe[2],timepipe[2];
    char string[] = "Hello\n";
    char temp[] = "World !\n";
    char readbuffer[80];
    char tempbuffer[80];
    int n,i=0;
    struct  timeval start,end;

    pipe(firstpipe);
    pipe(secondpipe);
    pipe(timepipe); 

    f = fork();
    
    if(f==0)
    {
        printf("Child  ----> %d\n",getpid());

        for(n=0;n<5;n++)
        {
            read(firstpipe[0], readbuffer, sizeof(readbuffer));
            printf("$$$$$\n");
            printf("Received string: %s", readbuffer); 
            write(secondpipe[1], temp, strlen(temp)+1);
        }

        gettimeofday(&end,0);
        write(timepipe[1],&end,sizeof(struct timeval));   
    }
    else
    {
        double switch_time; 
        printf("Parent  ----> %d\n",getpid());
        gettimeofday(&start,0);

        for(n=0;n<5;n++)
        {
            write(firstpipe[1], string, strlen(string)+1);
            printf("#####\n");
            read(secondpipe[0], tempbuffer, sizeof(tempbuffer));
            printf("Received temp: %s", tempbuffer);
        }

        read(timepipe[0],&end,sizeof(struct timeval));
        
        wait(NULL);
        switch_time = ((end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec))/1000.0;
        printf("context switch between two processes: %0.6lfms\n",switch_time/(5*2));

    }   

    return 0;
}
