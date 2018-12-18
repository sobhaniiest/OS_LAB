#include<stdio.h>
#include<unistd.h>

int main()
{
  int n,f,i,fact=1;
  scanf("%d",&n);
  f=fork();
  if(f==0)
  {
    for(i=1;i<=n;i++)
      fact=fact*i;
    printf("Factorial of %d is %d\n",n,fact);
  }
  else
  {
    int temp=0;
     if(n==2)
       printf("Prime\n");
     else
     {
       for(i=2;i<=n/2;i++)
       {
         if(n%i==0)
         {
           temp=1;
           break;
         }
       }
       if(temp==0)
         printf("Prime\n");
       else
         printf("Not Prime\n");
     }   
  }
}
