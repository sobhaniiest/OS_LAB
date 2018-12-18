p#include<stdio.h>
#include<unistd.h>

// Creating Zombie

int main()
{
  pid_t pid;
  int f;
  f=fork();
  if(f==0)
  {
    printf("Child pid : %d\n",getpid());
  }
  else
  {
    printf("Parent pid : %d\n",getpid());
    getchar();
  }
  return 0;
}
