#include <stdio.h>
#include <string.h>
#include "test.h"

int main()
{
	long long int n;
	int len;
	char str[100];
	printf("Enter a number : ");
	scanf("%lld",&n);
	printf("Enter a string : ");
	scanf("%s",str);

    len = strlen(str);

	if(fact(n))
		printf("Factorial of %lld : %lld\n",n,fact(n));
	else
	    printf("Factorial is not possible!!!\n");
	
	if(pad(str,len))
	    printf("The string %s is palindrome\n",str);
	else
	    printf("%s is not palindrome\n",str);
	
}