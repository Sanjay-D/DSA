#include<stdio.h>
#include<math.h>

int num(long long int n)
{
	int i,j=ceil((double)(log(n)/log(2)));
	long long int c=0;
	for(i=0;i<j;i++)
	{
		if(ceil((double)(log(n)/log(2)))==floor((double)(log(n)/log(2))))
		{
			c++;
			break;
		}
		else
		{
			n-=pow(2,floor((double)(log(n)/log(2))));
			c++;
		}
	}
	printf("%d\n",c);
}

int main()
{
	long long int n;
	scanf("%d",&n);
	num(n);
}
