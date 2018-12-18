#include <stdio.h>
#include <string.h>

unsigned long long int sigma(unsigned long long int a)
{
	unsigned long long int x=0;
	while(a>0)
	{
		x+=(a%10);
		a/=10;
	}
	return x;
}

void result(unsigned long long int t, unsigned long long int n, unsigned long long int d)
{
	n=n+(t*d);
        while(n>9)
        {
        	n=sigma(n);
               	t=t+1;
        }
        printf("%llu %llu\n",n,t);
}


int main()
{
	unsigned long long int t,min,add,tadd,res,n,d,x,y;
	scanf("%llu",&t);
	int m[10][10];
	memset(m,-1,sizeof(m));
	while(t--)
	{
		res=0;
		scanf("%llu %llu",&n,&d);
		x=n;
		y=d;
		while(x>9)
		{
			x=sigma(x);
			res=res+1;
		}
		if(x==1)
		{
			printf("%llu %llu\n",x,res);
			continue;
		}
		while(y>9)
			y=sigma(y);
		if(m[x][y]>=0)
		{
			result(m[x][y],n,d);
			continue;
		}
		min=x;
		add=0;
		tadd=0;
		while(1)
		{
			x=x+y;
			add++;
			while(x<10)
			{
				x=x+y;
				add++;
			}
			x=sigma(x);
			if(x<min)
			{
				min=x;
				tadd=add;
			}
			else if(x==min)
				break;
		}
		m[x][y]=(int)tadd;
		result(m[x][y],n,d);
	}
	return 0;
}