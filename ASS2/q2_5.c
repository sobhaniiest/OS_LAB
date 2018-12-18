#include<stdio.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>

// Preventing Zombie by using signal handler

void fun()
{
  wait(NULL);
}

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
    signal(SIGCHLD,fun);
    getchar();
  }
  return 0;
}
