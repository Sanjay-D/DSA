#include<stdio.h>
int max(int a, int b)
{
	return (a>b)?a:b;
}
int bargain(int n, int k)
{
	int a[n+1][k+1];
	int i,j,res;
	for(i=1;i<=n;i++)
	{
		a[i][1]=1;
		a[i][0]=0;
	}
	for(i=1;i<=k;i++)
		a[1][i]=i;
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=k;j++)
		{
			int x;
			a[i][j]=999999;
			for(x=1;x<=j;x++)
			{
				res=1+max(a[i-1][x-1],a[i][j-x]);
				if(res<a[i][j])
					{
						a[i][j]=res;
					}	
			}
		}
	}
	return a[n][k];
}
int main()
{
	int n,k;
	scanf("%d %d",&k,&n);
	printf("%d\n",bargain(n,k));
}
