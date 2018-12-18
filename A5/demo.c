#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

/*
gcc -Wall -fPIC -c fact.c
gcc -Wall -fPIC -c pad.c
gcc -shared -o libA.so fact.o
gcc -shared -o libB.so pad.o
gcc -c demo.c
gcc -o demo demo.o libA.so libB.so
sudo mv libA.so /usr/lib/
sudo mv libB.so /usr/lib/
sudo ldconfig
./demo
*/

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