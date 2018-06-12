#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
	return (a>=b)?a:b;
}
void dfs(int **a,int c[],int d1[],int d2[],int n,int v,int p)
{
	int sum1=0,sum2=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(a[v][i] && p!=i)
		{
			dfs(a,c,d1,d2,n,i,v);
			sum1+=d2[i];
			sum2+=max(d1[i],d2[i]);
		}
	}
	d1[v]=c[v]+sum1;
	d2[v]=sum2;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int c[n];
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	int di[n],de[n];
	
	int **a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;

	for(i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		a[u-1][v-1]=1;
		a[v-1][u-1]=1;
	}

	int root=0,rooti=0;
	for(i=0;i<n;i++)
	{
		int count=0;
		for(j=0;j<n;j++)
			if(a[i][j])
				count++;
		if(count>root)
			rooti=i,root=count;
	}
//	printf("%d\n",rooti);
	dfs(a,c,di,de,n,rooti,-1);
	printf("%d\n",max(di[rooti],de[rooti]));
}	
