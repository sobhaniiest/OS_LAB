#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

// Preventing Zombie by calling wait

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
    wait(NULL);
    getchar();
  }
  return 0;
}
