#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

// Preventing Zombie by ignoring SIGCHLD

int main()
{
  int f;
  f=fork();
  if(f==0)
  {
     printf("Child pid : %d\n",getpid());
  }
  else
  {
    printf("Parent pid : %d\n",getpid());
    signal(SIGCHLD,SIG_IGN);
    getchar();
  }
  return 0;
}
