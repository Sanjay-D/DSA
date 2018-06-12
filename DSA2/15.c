#include<stdio.h>
#include<math.h>
int ran(int n)
{
	int c1=0,c2=0;
	int s=n*n;
	int t1=n;
	int t2=s;
	while(t1)
	{
		c1++;
		t1/=10;
	}
	while(t2)
	{
		c2++;
		t2/=10;
	}
	if(c1%2==c2%2)
	{
		int i=(c2-c1)/2;
		s%=(int)pow(10,c2-i);
		s/=pow(10,i);	
	}
	else
	{
		int i=(c2-c1)/2;
		s%=(int)pow(10,c2-i);
		s/=pow(10,i+1);
	}
	printf("%d \n",s);
	return s;
}

int main()
{
	int i,n,t;
	scanf("%d %d",&n,&t);
	for(i=0;i<t;i++)
		n=ran(n);
}
