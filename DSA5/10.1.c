#include<stdio.h>
#include<math.h>
int fac(int n)
{
	int i,j,c=0;
	for(i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if(n/i==i)
				c++;
			else
				c+=2;	
		}
	}
	return c;
}

int main()
{
	int a,b,n,i,c=0;
	a=99990000,b=100000000,n=6;
//	scanf("%d %d %d",&a,&b,&n);
	for(i=a;i<=b;i++)
	{
		if(fac(i)==n)
			c++;
	}
	printf("%d\n",c);
}
