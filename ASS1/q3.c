#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

void delay(float number_of_seconds)
{
    int milli_seconds = (int)((float)1000 * number_of_seconds);
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

int main()
{
  int f;
  f=fork();
  if(f==0)
  {
    while(1)
    {
      printf("Child\n");
      delay(1);
    }
  }
  else
  {
    while(1)
    {
      printf("Parent\n");
      delay(1);
    }
  }
}
