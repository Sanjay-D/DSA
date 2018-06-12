#include<stdio.h>
#include<string.h>
int find(int n, int m, int x)
{
	int k,i,j;
	int a[n+1][x+1];
	memset(a,0,sizeof(a));
	for(j=1;j<=x && j<=m;j++)
			a[1][j]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=x;j++)
		{
			for(k=1;k<=m && k<j;k++)
				a[i][j]+=a[i-1][j-k];
		}
	}
	return a[n][x];
}
int main()
{
	int n,m,x,i;
	scanf("%d %d %d",&n,&m,&x);
	printf("%d\n",find(n,m,x));
}
