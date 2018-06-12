#include<stdio.h>

void fac(int x)
{
	int res[500];
	res[0]=1;
	int size=1;
	int i;
	for(i=2;i<=x;i++)
	{
		size=mult(i,res,size);
	}
	for(i=size-1;i>=0;i--)
		printf("%d",res[i]);
	printf("\n");
}

int mult(int a,int res[],int size)
{
	int carry=0,c;
	for(c=0;c<size;c++)
	{
		int p=res[c]*a+carry;
		res[c]=p%10;
		carry=p/10;
	}
	while(carry)
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
	fac(n);
}
