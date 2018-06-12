#include<stdio.h>
#include<math.h>

void func(int x)
{
	int res[500]={0};
	int size=1,i;
	res[0]=1;
	for(i=0;i<x;i++)
	{
		size=mult(2,size,res);
	}
	int N;
	if(size>10)
		N=9;
	else 
		N=size-1;
	for(i=N;i>=0;i--)
	{
		printf("%d",res[i]);
	}
	printf("\n");
}

int mult(int a,int size, int res[])
{
	int carry=0,i;
	for(i=0;i<size;i++)
	{
		int pr=res[i]*a+carry;
		res[i]=pr%10;
		carry=pr/10;
	}
	while(carry>0)
	{
		res[size]=carry%10;
		carry/=10;
		size++;
	}
	return size;
}

int main()
{
	int n;
	scanf("%d",&n);
	func(n);
}
