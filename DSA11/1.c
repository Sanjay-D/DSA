#include<stdio.h>

int max(int a, int b)
{
	return (a>=b)?a:b;
}

int cost(int a[],int n)
{
	int i,k;
	int c[n][n];
	for(k=1;k<=n;k++)
	{
		for(i=0;i<n-k+1;i++)
		{
			if(k==1)
				c[i][i+k-1]=(n-k+1)*a[i];
			else
				c[i][i+k-1]=max(c[i+1][i+k-1]+(n-k+1)*a[i],c[i][i+k-2]+(n-k+1)*a[i+k-1]);
		}
	}
	
	return c[0][n-1];
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",cost(a,n));
}
